#######################################################################################################
####                                                                                               ####
####             UNIVERSIDADE FEDERAL DO ESPIRITO SANTO                                            ####
####             CENTRO TECNOLOGICO                                                                ####
####             DEPARTAMENTO DE INFORMATICA                                                       ####
####             ENGENHARIA DE COMPUTACAO                                                          ####
####             Sistemas Operacionais 2019/2                                                      ####
####             Professora Roberta Lima Gomes                                                     ####
####                                                                                               ####
####        powered by Alanesvit                                                                   ####
####        DATA : 27 de outubro de 2019, as 20h07min                                              ####
####        LOCAL: Brasil, Espirito Santo, Vitoria                                                 ####
####        VERSAO  0.1                                                                            ####
####                                                                                               ####
#######################################################################################################
target_01 = main
target_02 = ghost
executable= booo

ALL: Clear_Screen Compile Linkage Execute Clear_Files
Clear_Screen:
	clear
Compile:
	gcc -c $(target_01).c -std=c99 
	gcc -c $(target_02).c -std=c99 
Linkage:
	gcc -o $(executable) $(target_01).o $(target_02).o -std=c99 
Execute:
	./$(executable)
Clear_Files:
	-rm *.exe *.o
	
