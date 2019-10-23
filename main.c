#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<sys/types.h> 
#include<sys/wait.h> 
#include <stdbool.h>

bool errorLog(int status){
    switch(status){
        case 1: //nao foi possivel ler linha
            printf("/nNão foi possivel ler a linha.");
            break;
        case 2:
            printf("/nErro de alocação.");
            break;

    }
    return true;
}

int lerComando(char *linha){
    int contador=0;
    char **args,*token;
    args=malloc(2*sizeof(char*));
    if(!args){
        free(args);
        return 2;
    }
    token=strtok(linha," ");
    while(token){
        strcpy(args[contador],token);
        contador++;
        args=realloc(args,(contador+2)*sizeof(char*));
        token=strtok(linha," ");
    }
    if(contador<2){
        return 0;
    }

    return 0;
}

char *lerlinha(){
    char *linha,c;
    int pos=0,len=1;
    linha=(char*)malloc((len)*sizeof(char));
    c=getchar();
    while(c!=EOF && c!='\n'){
        len++;
        linha=(char*)malloc((len)*sizeof(char));
        linha[pos]=c;
        c=getchar();
        pos++;
    }
    return linha;
}

int commandLoop(){
    char *linha,c;
    int status=0,len,pos;
    bool ok=true;
    do{
        printf("gsh> ");
        linha=lerlinha();
        if(strlen(linha)>5){
            status=lerComando(linha);
        }
        ok=errorLog(status);
        free(linha);
    }while(ok);
    return 0;
}

int main(){
    commandLoop();
    return 0;
}

