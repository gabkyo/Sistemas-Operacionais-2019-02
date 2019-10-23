target=main.c
executable=trabalho
all:
	@gcc $(target) -o $(executable) -std=c99 
	./$(executable)
clean:
	rm -rf $(executable)