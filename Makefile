PROJ_NAME=perfEG
 
# .c files
C_SOURCE=$(wildcard ./src/*.c)
 
# .h files
H_SOURCE=$(wildcard ./src/*.h)
 
# Object files
OBJ=$(subst .c,.o,$(subst src,objects,$(C_SOURCE)))

# List of files to be zipped
DISTFILES = src/*.c src/*.h README* Makefile src/data/sistemas.dat src/likwid.py
DISTDIR = `basename ${PWD}`

# Compiler and linker
CC=gcc
 
# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -O3      \
         -march=native      \
         -mavx     


 LIKWID_FLAGS=-DLIKWID_PERFMON \
 						 -I/usr/local/include\
 						 -L/usr/local/includelib

# Command used at clean target
RM = rm -rf
 
all: objFolder $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
		$(CC) $(LIKWID_FLAGS) $^ -o $@ -llikwid
#		$(CC) $^ -o $@
		@ echo 'Finished building binary: $@'
		@ echo ' '
 
./objects/%.o: ./src/%.c ./src/%.h
		$(CC) $< $(CC_FLAGS) -o $@
 
./objects/main.o: ./src/main.c $(H_SOURCE)
		$(CC) $< $(CC_FLAGS) $(LIKWID_FLAGS) -o $@ -llikwid

objFolder:
		@ mkdir -p objects

purge:
		@ $(RM) ./objects/*.o ./src/data/results.log $(PROJ_NAME) $(DISTDIR).tar *~
		@ rmdir objects

clean:
		@ $(RM) *~ *.bak

dist:
		@ echo "Gerando arquivo de distribuição ($(DISTDIR).tar) ..."
		@ ln -s . $(DISTDIR)
		@ tar -cvf $(DISTDIR).tar $(addprefix ./$(DISTDIR)/, $(DISTFILES))
		@ rm -f $(DISTDIR)

check:
		tail -n 4 sistemas.dat | ./$(PROJ_NAME) | grep "Solution: 1.00 3.00 -2.00"

.PHONY: all purge
