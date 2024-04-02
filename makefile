# Compiler
CC            = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

# Flags
WARNING_CFLAG = -Wall -Wextra -Werror
DEBUG_CFLAG   = -g
CFLAGS        = $(DEBUG_CFLAG) $(WARNING_CFLAG) -c -I$(SOURCE_FOLDER)



run: all
	@./bin/MainApp
all: build
build: main
clean:
	rm -r $(OUTPUT_FOLDER)/*.o $(OUTPUT_FOLDER)/MainApp

main:
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/pcolor/pcolor.cpp -o $(OUTPUT_FOLDER)/pcolor.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/main/main.cpp -o $(OUTPUT_FOLDER)/main.o 
	@$(CC) bin/*.o -o $(OUTPUT_FOLDER)/MainApp
	@echo Linking object files and generate elf32...
	@rm -f *.o