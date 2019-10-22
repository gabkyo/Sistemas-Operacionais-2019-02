#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<bool.h>
#include<sys/types.h> 
#include<sys/wait.h> 

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
    args=malloc(sizeof(char*));
    if(!args){
        free(args);
        return 2;
    }
    token=strtok(linha," ");
    while(token){
        strcpy(args[contador],token);
        contador++;
        args=realloc(args,(contador+1)*sizeof(char*));
        token=strtok(linha," ");
    }
    if(contador==0){
        return 1;
    }

    return 0;
}

int commandLoop(){
    char *linha;
    size_t len=0;
    int status=0;
    bool ok=true;
    do{
        printf("gsh> ");
        if(fgetline(linha,&len,stdin)!=-1){
            status=lerComando(linha);
        }else status=1;
        ok=errorLog(status);
        free(linha);
    }while(ok);
    
    
    return 0;
}

int main(){
    commandLoop();
    return 0;
}

