##
# Makefile para compilar y enlazar todo el codigo del programa
##

# Macros para identificar los directorios.
INCLUDE=./include
OBJ=./obj
SRC=./src
DOC=./doc
BIN=./bin

# Macros para identificar el ejecutable y los archivos objeto.
EXECUTABLE= $(BIN)/digits
HEADERS= $(wildcard $(INCLUDE)/*.h)
SOURCES= $(wildcard $(SRC)/*.cc)
OBJECTS= $(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SOURCES))

# Flags usados al compilar y enlazar
FLAGS= -Wall -std=c++11


# El objetivo global es el ejecutable.
all: $(EXECUTABLE)

# Generación del ejecutable a partir de ficheros objeto.
$(EXECUTABLE): $(OBJECTS)
	g++ -o $@ $(OBJECTS) $(FLAGS)

# Generación de ficheros objeto.
$(OBJ)/%.o: $(SRC)/%.cc $(HEADERS)
	g++ -o $@ -I$(INCLUDE) -c $< $(FLAGS)


# Documentación
clean:
	@rm $(OBJ)/*.o $(BIN)/* && echo "Borrados ficheros objeto."

documentacion:
	@doxygen $(DOC)/doxys/Doxyfile

