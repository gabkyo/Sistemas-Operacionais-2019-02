/*#####################################################################################################
####                                                                                               ####
####             UNIVERSIDADE FEDERAL DO ESPIRITO SANTO                                            ####
####             CENTRO TECNOLOGICO                                                                ####
####             DEPARTAMENTO DE INFORMATICA                                                       ####
####             ENGENHARIA DE COMPUTACAO                                                          ####
####             Sistemas Operacionais 2019/2                                                      ####
####             Professora Roberta Lima Gomes                                                     ####
####                                                                                               ####
#######################################################################################################
#######################################################################################################
#######################################################################################################
####        AUTOR: Gabriel Ferrari                                                                 ####
####        DATA ABERTURA:                                                                         ####
####        LOCAL:                                                                                 ####
####        OBJETIVOS                                                                              ####
####             *                                                                                 ####
####        DESCRICAO                                                                              ####
####             *                                                                                 ####
####        FUNCIONALIDADES                                                                        ####
####             *                                                                                 ####
####        ORIENTACOES:                                                                           ####
####             *                                                                                 ####
####        PENDENCIAS:                                                                            ####
####             *                                                                                 ####
####                                                                                               ####
####        ATUALIZACOES/MODIFICACOES/ACRESCIMOS                                                   ####
####             *                                                                                 ####
####                                                                                               ####
#####################################################################################################*/
# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
# include <unistd.h>
# include <sys/types.h> 
# include <stdbool.h>
# include "ghost.h"

const char prefixo[]="gsh> ";

/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####                                                                                            ####
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
/* ####                                                                                            ####
 * ####                                                                                            ####
 *###################################################################################################*/


/* ####################################################################################################
 * ##########################                    main                    ##############################
 * ##################################################################################################*/
int main(){
    commandLoop();
    return 0;
}
/* ####   OBSERVACAO:                                                                              ####
 * ####        Nenhuma.                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO:                                                      ####
 * ####        Nenhuma.                                                                            ####
 * ##################################################################################################*/







