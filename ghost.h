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
 * ####   Checa se o programa deve continuar e se especificado imprime uma mensagem de erro        ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####   Codigos pre-estabelecidos de erro                                                        ####
 * ####   POS-CONDICAO                                                                             ####
 * ####   O programa deve ser capaz de impedir a continuação do programa se retorna falso          ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####   Codigo de erro status e mensagem indica se uma mensagem deve ser impressa.               ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####   true se o programa deve continuar ou false senao                                         ####
 * ####   OBSERVACAO                                                                               ####
 * ####   Nao realiza acao alem de imprimir, mais para checagem.                                   ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
bool errorLog(int status,bool mensagem);
/*###################################################################################################*/

/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####   Divide uma string em tokens separados por divisor                                        ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####   linha a ser dividida e o divisor que separa os tokens                                    ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####   array de strings onde o primeiro elemento é o numero de strings que o segue              ####
 * ####   OBSERVACAO                                                                               ####
 * ####   na posicao 0 segue n-1 onde n e o tamanho do array                                       ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
char **tokenizacao(char *linha, char *divisor);
/*###################################################################################################*/

/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####   funcao especificada no trabalho                                                          ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####   Nenhum                                                                                   ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####   Codigo de erro ou 0 para execucao normal                                                 ####
 * ####   OBSERVACAO                                                                               ####
 * ####                                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
int mywait();
/*###################################################################################################*/

/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####   funcao especificada no trabalho                                                          ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####   Nenhum                                                                                   ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####   Codigo de erro ou 0 para execucao normal                                                 ####
 * ####   OBSERVACAO                                                                               ####
 * ####                                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
int clean_and_die();
/*###################################################################################################*/

/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####   Interpreta uma string como comando da shell com argumentos                               ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####   string comando que inclui os argumentos e um bool se o processo deve ser fore ou background##
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####   Codigo de erro ou 0 para execucao normal                                                 ####
 * ####   OBSERVACAO                                                                               ####
 * ####                                                                                            ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
int lerComando(char *comando,bool foreground);
/*###################################################################################################*/

/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####   Le uma linha do console                                                                  ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####   Codigo de erro ou 0 para execucao normal                                                 ####
 * ####   OBSERVACAO                                                                               ####
 * ####   limite 300 caracteres por linha                                                          ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
char *lerlinha();
/*###################################################################################################*/

/*#####################################################################################################
 * ####   DESCRICAO                                                                                ####
 * ####   Divide linha em comandos separados por # e age de acordo                                 ####
 * ####   PRE-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   POS-CONDICAO                                                                             ####
 * ####                                                                                            ####
 * ####   PARAMETROS DE ENTRADA                                                                    ####
 * ####   string linha do console                                                                  ####
 * ####   PARAMETROS DE SAIDA                                                                      ####
 * ####   Codigo de erro ou 0 para execucao normal                                                 ####
 * ####   OBSERVACAO                                                                               ####
 * ####   Responsável por alternar processos background ou foreground                              ####
 * ####   PENDENCIA DE REVISAO OU SUPERVISAO                                                       ####
 * ####                                                                                            ##*/
int interpretar(char *linha);
/*###################################################################################################*/

# endif
