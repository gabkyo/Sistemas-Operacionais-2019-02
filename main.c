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
    int tamanho,pos=0,b,e;
    beg=strstr(str,substr);
    if(beg==NULL){
        return str;
    }
    end=beg+strlen(substr);
    tamanho=strlen(str)-strlen(substr)+1;
    retorno=(char*)malloc(tamanho*sizeof(char));
    tamanho=strlen(str);
    b=(int)(beg-str[0]);
    e=(int)(end-str[0]);
    for(int i=0;i<i+tamanho;i++){
        if(i<b || i>e){
            retorno[pos]=str[i];
            pos++;
        }
    }
    return retorno; 
}

int lerComando(char *comando){ //interpreta 1 comando / retorna errorcode
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
    return linha;
}

int interpretar(char *linha){ //divide linha em comandos e excuta os comandos / retorna codigo de erro
    char **tokens,*temp;
    int tamanho=0;
    temp=strchr(linha,'#');
    if (temp==NULL){
        lerComando(linha);
    }else{
        temp=strtok(linha,"#");
        while (temp!=NULL){
            tamanho++;
            tokens=realloc(tokens,tamanho*sizeof(char*));
            tokens[tamanho-1]=temp;
            temp=strtok(NULL,"#");
        }
        for (int i = 0; i < tamanho; i++)
        {
            lerComando(tokens[i]);
            free(tokens[i]);
        }
        free(tokens);
        free(temp);
    }
    
    
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

