CC = gcc
CFLAGS = -Wall -g
OBJ = sed_simplified.o utils.o
EXEC = sed_simplified

# Основная цель
all: $(EXEC)

$(EXEC): $(OBJ)
        $(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

sed_simplified.o: sed_simplified.c sed_simplified.h
        $(CC) $(CFLAGS) -c sed_simplified.c

utils.o: utils.c sed_simplified.h
        $(CC) $(CFLAGS) -c utils.c

clean:
        rm -f *.o $(EXEC)

test:
        ./sed_simplified input.txt -r "old" "new"
        ./sed_simplified input.txt -d "delete"
        ./sed_simplified input.txt -i -f "insert_front"
        ./sed_simplified input.txt -i -b "insert_back"
