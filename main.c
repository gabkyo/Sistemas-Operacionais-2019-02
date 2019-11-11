/*#####################################################################################################
####                                                                                               ####
####             UNIVERSIDADE FEDERAL DO ESPIRITO SANTO                                            ####
####             CENTRO TECNOLOGICO                                                                ####
####             DEPARTAMENTO DE INFORMATICA                                                       ####
####             ENGENHARIA DE COMPUTACAO                                                          ####
####             Sistemas Operacionais 2019/2                                                      ####
####             Professora Roberta Lima Gomes                                                     ####
####                                                                                               ####
#####################################################################################################*/
# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
# include <unistd.h>
# include <sys/types.h> 
# include <stdbool.h>
#include <signal.h>
# include <sys/wait.h> 
# include "ghost.h"

const char prefixo[]="gsh> ";
pid_t original=0;


/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####   Loop de leitura de comandos                                                             ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####   OBSERVACAO                                                                               ####
 * ####                                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
void commandLoop(){
    char *linha,*temp;
    int status=0,pos,end;//status codigo de erro
    bool ok=true;//se deve continuar rodando
    do{
        printf(prefixo);
        linha=lerlinha();
        if(strlen(linha)<1){
            status=1;
        }else{
            status=interpretar(linha);
        }
        ok=errorLog(status,true);
        free(linha);
        status=0;
    }while(ok);
}
 /*###################################################################################################*/

/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####   Funcao que lida com SIGINT                                                               ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####   OBSERVACAO                                                                               ####
 * ####                                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
void sigint_handler(int sig){
    char resposta[100];
    if (original==getpid()){
        if(waitpid(-1,NULL,WNOHANG)==0){
            printf("\nEncerrar a SHELL? Y/*\n");
            fflush(stdin);
            fgets(resposta,100,stdin);
            if(strcmp(resposta,"Y")==0){
                mywait();
                exit(0);
            }else commandLoop();
        }else{
            printf("\nSem filhos, morrerei.\n");
            mywait();
            exit(0);
        }
    }else waitpid(original,NULL,__W_CONTINUED | 0);
}
 /*###################################################################################################*/


/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####   funcao que lida com SIGSTOP                                                              ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####   OBSERVACAO                                                                               ####
 * ####                                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
void sigstop_handler(int sig){
    if(original!=getpid()){
        printf("\nSou %d, filho de SHELL, morrerei.\n",getpid());
        fflush(stdin);
        exit(0);
    }else{
        printf("\nMatando descendentes...\n");
        fflush(stdin);
        pid_t grupo=getpgrp();
        setpgid(0,grupo);
        char comando[100]="kill -9 ",temp[10];
        sprintf(temp,"%d",grupo);
        strcat(comando,temp);
        if(system(comando)==-1){
            errorLog(7,true);
        }
        commandLoop();
    }    
}
/*###################################################################################################*/


/* ####################################################################################################
 * ##########################                    main                    ##############################
 * ##################################################################################################*/
int main(){
    original=getpid();
    signal(SIGINT,sigint_handler);
    signal(SIGTSTP,sigstop_handler);
    signal(SIGSTOP,sigstop_handler);
    commandLoop();
    return 0;
}
/* ####   OBSERVACAO:                                                                              ####
 * ####        Nenhuma.                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO:                                                      ####
 * ####        Nenhuma.                                                                            ####
 * ##################################################################################################*/





