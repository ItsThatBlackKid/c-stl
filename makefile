LIB_DIR = lib/
BIN_DIR = bin/
EG_DIR = examples/

SRC = $(wildcard $(LIB_DIR)*.c)
OBJ = $(patsubst %.c, $(BIN_DIR)%.o,$(SRC))


TARGETS = vec linked_list stl

all: $(TARGETS)

vec: vec.o $(EG_DIR)vectors.c 
	gcc -Wall -Werror -o $@ $(EG_DIR)vectors.c $(patsubst %,$(BIN_DIR)%,$<) -g

%.o : $(LIB_DIR)%.c
	gcc -Wall -Werror -c $^ -o $(BIN_DIR)$@ -g


linked_list: $(EG_DIR)linked_list.c $(BIN_DIR)linked_list.o
	gcc -Wall -Werror -o $@ $< $(patsubst $(LIB_DIR)%,$(BIN_DIR)%,$<)

stl: $(OBJ)
	gcc -Wall -Werror -c $(patsubst $(LIB_DIR)%,$(BIN_DIR)%,$<) -o $@
clean:
	- rm $(BIN_DIR)*.o
	- rm $(EG_DIR)*.o
	- rm $(TARGETS)

clean_vec: 
	- rm vec
