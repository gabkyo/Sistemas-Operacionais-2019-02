target=
all:
	javac $(target).java
	java $(target)
clean:
	rm *.class
	