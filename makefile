# Compiler
CC            = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin
TEST_FOLDER = test

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

clean_session:
	find * -name 'peda*' -delete
	
main:
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/pcolor/pcolor.cpp -o $(OUTPUT_FOLDER)/pcolor.o 

	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Exception/Exception.cpp -o $(OUTPUT_FOLDER)/Exception.o 

	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Config/Config.cpp -o $(OUTPUT_FOLDER)/Config.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Config/GameConfig.cpp -o $(OUTPUT_FOLDER)/GameConfig.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Config/AnimalConfig.cpp -o $(OUTPUT_FOLDER)/AnimalConfig.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Config/PlantConfig.cpp -o $(OUTPUT_FOLDER)/PlantConfig.o
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Config/ProductConfig.cpp -o $(OUTPUT_FOLDER)/ProductConfig.o
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Config/RecipeConfig.cpp -o $(OUTPUT_FOLDER)/RecipeConfig.o
	
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/GameObject/GameObject.cpp -o $(OUTPUT_FOLDER)/GameObject.o

	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Animal/Animal.cpp -o $(OUTPUT_FOLDER)/Animal.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Animal/Carnivore.cpp -o $(OUTPUT_FOLDER)/Carnivore.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Animal/Herbivore.cpp -o $(OUTPUT_FOLDER)/Herbivore.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Animal/Omnivore.cpp -o $(OUTPUT_FOLDER)/Omnivore.o 

	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Plant/Plant.cpp -o $(OUTPUT_FOLDER)/Plant.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Plant/MaterialPlant.cpp -o $(OUTPUT_FOLDER)/MaterialPlant.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Plant/FruitPlant.cpp -o $(OUTPUT_FOLDER)/FruitPlant.o 

	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Product/Product.cpp -o $(OUTPUT_FOLDER)/Product.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Product/FoodProduct.cpp -o $(OUTPUT_FOLDER)/FoodProduct.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Product/MaterialProduct.cpp -o $(OUTPUT_FOLDER)/MaterialProduct.o 
	
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Building/Building.cpp -o $(OUTPUT_FOLDER)/Building.o 

	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/input/InputHandler.cpp -o $(OUTPUT_FOLDER)/InputHandler.o
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/input/FileHandler.cpp -o $(OUTPUT_FOLDER)/FileHandler.o 

	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Player/Player.cpp -o $(OUTPUT_FOLDER)/Player.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Player/Walikota.cpp -o $(OUTPUT_FOLDER)/Walikota.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Player/Petani.cpp -o $(OUTPUT_FOLDER)/Petani.o 
	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Player/Peternak.cpp -o $(OUTPUT_FOLDER)/Peternak.o 

	@$(CC) $(CFLAGS) $(SOURCE_FOLDER)/Matrix2/Matrix2.cpp -o $(OUTPUT_FOLDER)/Matrix2.o 

	@pwd && $(CC) $(CFLAGS) $(SOURCE_FOLDER)/main/main.cpp -o $(OUTPUT_FOLDER)/main.o 
	@pwd && $(CC) bin/*.o -o $(OUTPUT_FOLDER)/MainApp
	@echo Linking object files...
	@rm -f *.o