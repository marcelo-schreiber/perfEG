PROJ_NAME=perfEG
 
# .c files
C_SOURCE=$(wildcard ./src/*.c)
 
# .h files
H_SOURCE=$(wildcard ./src/*.h)
 
# Object files
OBJ=$(subst .c,.o,$(subst src,objects,$(C_SOURCE)))
 
# Compiler and linker
CC=gcc
 
# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -O3      \
         -march=native      \
         -mavx     


# LIKWID_FLAGS=-DLIKWID_PERFMON \
# 						 -I/usr/local/include\
# 						 -L/usr/local/includelib\
# 						 -llikwid

# Command used at clean target
RM = rm -rf
 
all: objFolder $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
		@ echo 'Building binary using GCC linker: $@'
# $(CC) $(LIKWID_FLAGS) $^ -o $@ -llikwid
		$(CC) $^ -o $@
		@ echo 'Finished building binary: $@'
		@ echo ' '
 
./objects/%.o: ./src/%.c ./src/%.h
		@ echo 'Building target using GCC compiler: $<'
		$(CC) $< $(CC_FLAGS) -o $@
		@ echo ' '
 
./objects/main.o: ./src/main.c $(H_SOURCE)
		@ echo 'Building target using GCC compiler: $<'
		$(CC) $< $(CC_FLAGS) -o $@
		@ echo ' '
 
objFolder:
		@ mkdir -p objects

purge:
		@ $(RM) ./objects/*.o $(PROJ_NAME) *~
		@ rmdir objects
 
check:
		tail -n 4 sistemas.dat | ./$(PROJ_NAME) | grep "Solution: 1.00 3.00 -2.00"

.PHONY: all purge
