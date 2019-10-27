# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
# include <unistd.h>
# include <sys/types.h> 
# include <stdbool.h>
# include "ghost.h"

/* ####################################################################################################
 * ##########################   FUNCOES QUE IMPLEMENTAM A GHOST SHELL    ##############################
 * ##################################################################################################*/

/*#####################################################################################################
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####                                                                                            ##*/
bool errorLog(int status,bool mensagem){//codigos de erro retorna se o processo deve continuar ou nao
    switch(status){
        case 1: //nao foi possivel ler linha
            if(mensagem){
                printf("1.Não foi possivel ler a linha.\n");
            }
            break;
        case 2:
            if(mensagem){
                printf("/n2.Erro de alocação.");
            }
            break;
    }
    return true;
}
/* ####   OBSERVACAO:                                                                              ####
 * ####        Nenhuma.                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO:                                                      ####
 * ####        Nenhuma.                                                                            ####
 * ##################################################################################################*/


/*#####################################################################################################
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####                                                                                            ##*/
int mywait(){

}
/* ####   OBSERVACAO:                                                                              ####
 * ####        Nenhuma.                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO:                                                      ####
 * ####        Nenhuma.                                                                            ####
 * ##################################################################################################*/

/*#####################################################################################################
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####                                                                                            ##*/
int clean_and_die(){
    
}
/* ####   OBSERVACAO:                                                                              ####
 * ####        Nenhuma.                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO:                                                      ####
 * ####        Nenhuma.                                                                            ####
 * ##################################################################################################*/

/*#####################################################################################################
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####                                                                                            ##*/
int lerComando(char *comando){ //interpreta 1 comando / retorna errorcode
    int tamanho=strlen(comando);
    if(comando[0]==' '){
        for (int i = 1; i <= tamanho; i++){
            comando[i-1]=comando[i];
        }
        
    }
    printf(comando);
    printf("\n");
    return 0;
}
/* ####   OBSERVACAO:                                                                              ####
 * ####        Nenhuma.                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO:                                                      ####
 * ####        Nenhuma.                                                                            ####
 * ##################################################################################################*/

/*#####################################################################################################
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####                                                                                            ##*/
char *lerlinha(){//le ate eof ou \n e retorna o que leu
    char *linha=malloc(300*sizeof(char));
    if(fgets(linha,300,stdin)==NULL){
        free(linha);
        linha=NULL;
    }
    if(linha[strlen(linha)-1]=='\n'){
        linha[strlen(linha)-1]='\0';
    }
    return linha;
}
/* ####   OBSERVACAO:                                                                              ####
 * ####        Nenhuma.                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO:                                                      ####
 * ####        Nenhuma.                                                                            ####
 * ##################################################################################################*/

/*#####################################################################################################
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####                                                                                            ##*/
int interpretar(char *linha){ //divide linha em comandos e excuta os comandos / retorna codigo de erro
    char *token;
    int tamanho=0,codigo;
    token=strchr(linha,'#');
    if(!token){ //um comando
        return lerComando(linha);
    }else{
        token=strtok(linha,"#");
        while (token){
            codigo=lerComando(token);
            if(codigo!=0 && !errorLog(codigo,false)){ //codigo diferente de 0 e o programa nao pode continuar
                return codigo;
            }
            token=strtok(NULL,"#");
        }
        
    }
}
/* ####   OBSERVACAO:                                                                              ####
 * ####        Nenhuma.                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO:                                                      ####
 * ####        Nenhuma.                                                                            ####
 * ##################################################################################################*/

// TEMPLATE
/*#####################################################################################################
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####                                                                                            ####
 * ####                                                                                            ##*/
/* ####   OBSERVACAO:                                                                              ####
 * ####        Nenhuma.                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO:                                                      ####
 * ####        Nenhuma.                                                                            ####
 * ##################################################################################################*/

