CC = gcc
C_SRC = main.c ./lexing/*.c
C_OUTPUT = test

$(C_OUTPUT): $(C_SRC)
	$(CC) $(C_SRC) -o $(C_OUTPUT)

test: $(C_OUTPUT)