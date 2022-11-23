CC=mpicc
CCFLAGS= -Wall -g -O3
LIBFLAGS= -lm
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

EXEC= model validate

all: $(EXEC)

model: model.o harmonics.o
	$(CC) $^ $(LIBFLAGS) -o $@
validate: validate.o harmonics.o
	$(CC) $^ $(LIBFLAGS) -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

run:
	mpiexec model --d ETOPO1_small.csv --m mymodel.txt --n 1000 --l 10
clean:
	rm -f $(OBJ) $(EXEC)
