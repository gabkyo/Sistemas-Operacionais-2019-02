#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<sys/types.h> 
#include <stdbool.h>

const char prefixo[]="gsh> ";

bool errorLog(int status,bool mensagem){//codigos de erro retorna se o processo deve continuar ou nao
    switch(status){
        case 1: //nao foi possivel ler linha
            if(mensagem){
                printf("/n1.Não foi possivel ler a linha.");
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

int mywait(){

}

int clean_and_die(){
    
}

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

int commandLoop(){
    char *linha,*temp;
    int status=0,pos,end;//status codigo de erro
    bool ok=true;//se deve continuar rodadndo
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
    return 0;
}

int main(){
    commandLoop();
    return 0;
}

