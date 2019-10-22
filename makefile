target=main.c
executable=trabalho
all:
	@gcc $(target) -o $(executable) 
	./$(executable)
clean:
	rm -rf $(executable)