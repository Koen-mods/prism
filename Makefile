CC = clang
C_SRC = main.c ./lexing/*.c
C_OUTPUT = test
C_DEBUG = debug_test

$(C_OUTPUT): $(C_SRC)
	$(CC) $(C_SRC) -o $(C_OUTPUT)

$(C_DEBUG): $(C_SRC)
	$(CC) $(C_SRC) -g -o $(C_DEBUG)

test: $(C_OUTPUT)
debug: $(C_DEBUG)