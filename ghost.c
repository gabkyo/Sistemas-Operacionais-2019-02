# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
# include <unistd.h>
# include <sys/types.h> 
# include <stdbool.h>
#include <signal.h>
#include <sys/wait.h>
# include "ghost.h"

bool errorLog(int status,bool mensagem){//codigos de erro retorna se o processo deve continuar ou nao
    switch(status){
        case 1: //nao foi possivel ler linha
            if(mensagem){
                printf("1.Não foi possivel ler a linha.\n");
            }
            break;
        case 2:
            if(mensagem){
                printf("2.Erro de alocação.\n");
            }
            break;
        case 3:
            if(mensagem){
                printf("3.Muitos comandos na mesma linha.\n");
            }
        break;
        case 4:
            if(mensagem){
                printf("4.Nao foi possivel ler o comando.\n");
            }
        break;
        case 5:
            if(mensagem){
                printf("5.Nao foi possivel criar processo.\n");
            }
        break;
        case 6:
            if(mensagem){
                printf("6.Argumentos demais.\n");
            }
        break;
        case 7:
            if(mensagem){
                printf("7.Erro na execucao do comando.\n");
            }
        break;
    }
    return true;
}

char **tokenizacao(char *linha, char *divisor){ //retorna n tokens onde na posicao [0] 
    char **tokens,*copia,*temp;
    int contador=0;
    copia=(char*)malloc(sizeof(linha));
    tokens=(char**)malloc((contador+1)*sizeof(char*));
    strcpy(copia,linha);
    temp=strtok(linha,divisor);
    while(temp){
        contador++;
        tokens=(char**)realloc(tokens,(contador+1)*sizeof(char*));
        tokens[contador]=temp;
        temp=strtok(NULL,divisor);
    }
    contador++;
    tokens=(char**)realloc(tokens,(contador+1)*sizeof(char*));
    tokens[1]=linha;
    tokens[0]=(char*)malloc(sizeof(char));
    tokens[0][0]=contador;
    return tokens;
}


int mywait(){
    pid_t pid=getpid();
    char command[300]="kill -17 ",temp[10];
    sprintf(temp,"%d",pid);
    strcat(command,temp);
    if(system(command)==-1){
        return 7;
    }
    return 0;
}


int clean_and_die(){
    pid_t grupo=getpgrp();
    setpgid(0,grupo+1);
    char comando[100]="kill -9 ",temp[10];
    sprintf(temp,"%d",grupo);
    strcat(comando,temp);
    if(system(comando)==-1){
        return 7;
    }
    exit(0);
}




int lerComando(char *comando,bool foreground){ //interpreta 1 comando / retorna errorcode
    char **tokens,**args;
    int tamanho=strlen(comando),status;
    pid_t pid,p1,p2;
    if(comando[0]==' '){
        for (int i = 1; i <= tamanho; i++){
            comando[i-1]=comando[i];
        }
        
    }
    if(strcmp(comando,"clean&die")==0){
        return clean_and_die();
    }
    if(strcmp(comando,"mywait")==0){
        return mywait();
    }
    p1=fork();
    if(p1>0){
        waitpid(p1,&status,0);

    }else if(p1==0){
        if(rand()%2){
            p2=fork();
        }
        system(comando);
        fflush(stdout);
        exit(0);
    }else return 5;
    return 0;
}


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


int interpretar(char *linha){ //divide linha em comandos e excuta os comandos / retorna codigo de erro
    char **tokens,div1[]="#",div2[]="";
    int tamanho,erro;
    pid_t grupo;
    bool foreground=true;
    tokens=tokenizacao(linha,"#");
    tamanho=tokens[0][0];
    if(tamanho>1){
        foreground=false;
        grupo=getgid();
        setpgid(0,0);
    }
    for (int i = 1; i < tamanho; i++){
        erro=lerComando(tokens[i],foreground);
        if(erro){
            if(!errorLog(erro,true)){
                return 0;
            }
        }
    }
    setpgid(0,grupo);
    return 0;
}


