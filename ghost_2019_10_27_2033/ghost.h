# ifndef _GHOST_
# define _GHOST_
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
##################                                ***                                ##################
##################                       BIBLIOTECA ghost.h                          ##################
##################                                ***                                ##################
#######################################################################################################
#######################################################################################################
####        AUTOR: Alan do Espirito Santo Vitorino                                                 ####
####               Danilo Felicio                                                                  ####
####               Gabriel Ferrari                                                                 ####
####        DATA ABERTURA: 27 de outubro de 2019, as 18h57min                                      ####
####        LOCAL: Brasil, Espirito Santo, Vitoria,                                                ####
####                                                                                               ####
####        VERSAO  0.1                                                                            ####
####                                                                                               ####
####        OBJETIVOS                                                                              ####
####             Simular uma shell de um sistema operacional com carecteristicas definidas em do-  ####
####             cumentacao especifica pela professora (ver trab1.pdf).                            ####
####                                                                                               ####
####        DESCRICAO                                                                              ####
####                                                                                               ####
####        FUNCIONALIDADES                                                                        ####
####             *                                                                                 ####
####        ORIENTACOES:                                                                           ####
####             *                                                                                 ####
####        PENDENCIAS:                                                                            ####
####             *                                                                                 ####
####                                                                                               ####
####        ATUALIZACOES/MODIFICACOES/ACRESCIMOS                                                   ####
####             *                                                                                 ####
####             * 2019_10_xx_xxhxxmin:                                                            ####
####                  - Conclusao v 1.0                                                            ####
####                                                                                               ####
#####################################################################################################*/

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
bool errorLog(int status,bool mensagem);
/*###################################################################################################*/

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
int mywait();
/*###################################################################################################*/

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
int clean_and_die();
/*###################################################################################################*/

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
int lerComando(char *comando);
/*###################################################################################################*/

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
char *lerlinha();
/*###################################################################################################*/

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
int interpretar(char *linha);
/*###################################################################################################*/

# endif
