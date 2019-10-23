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

char *remove_substr(char *str,char *substr){//retorna copia de str sem primeira incidencia de substr
    char *end, *beg,*retorno;
    int tamanho,pos=0;
    beg=strstr(str,substr);
    if(beg==NULL){
        return str;
    }
    end=beg+strlen(substr);
    tamanho=strlen(str)-strlen(substr)+1;
    retorno=(char*)malloc(tamanho*sizeof(char));
    tamanho=strlen(str);
    for(int i=0;i<tamanho;i++){
        if(i<beg || i>end){
            retorno[pos]=str[i];
            pos++;
        }
    }
    return retorno; 
}

int lerComando(char *comando){ //interpreta 1 comando / retorna errorcode
    return 0;
}

char *lerlinha(){//le ate eof ou \n e retorna o que leu
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

int interpretar(char *linha){ //divide linha em comandos e excuta os comandos / retorna codigo de erro
    char **tokens,*temp;
    int codigo=0,tamanho=0,pos;
    bool continua=true;
    if(strchr(linha,'#')==NULL){//um comando
        return lerComando(linha);
    }else{
        
        temp=strtok(linha,'#');
        while(temp!=NULL){
            tamanho++;
            tokens=(char**)realloc(tokens,tamanho*(sizeof(char*)));
            tokens[pos]=temp;
            pos++;
            temp=strtok(linha,'#');
        }
        tamanho++;
        tokens=(char**)realloc(tokens,tamanho*(sizeof(char*)));
        strcpy(tokens[pos],linha);
        for (int i = 0; i < tamanho; i++){
            codigo=lerComando(tokens[i]);
            continua=errorLog(codigo,false);
            if(!continua){
                return codigo;
            }
        }
        
    }
    return 0;
}

int commandLoop(){
    char *linha,*temp;
    int status=0,pos,end;//status codigo de erro
    bool ok=true;//se deve continuar rodadndo
    do{
        printf(prefixo);
        linha=lerlinha();
        temp=remove_substr(linha,prefixo);
        free(linha);
        linha=temp; temp=NULL;
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

