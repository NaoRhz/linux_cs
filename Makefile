#CXX = arm-linux-gnueabihf-g++

#CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
#CXXFLAGS =	-std=c++17 -O3 -Wextra -Wall -pedantic
CXXFLAGS =	-std=c++20 -O3 -Wextra -Wall -pedantic

# Descargar doctest.h con wget "https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h"

# Fuentes de los modulos, ficheros .cpp, a excepcion del main del programa
# y de los fuentes de pruebas
# Es necesario que por cada fichero .cpp de modulo exista otro .hpp 
SRCS =		Persona.cpp formato.cpp

LIBS =

# Ejecutable final, debe existir el fichero $(TARGET).cpp con el main
TARGET =	EjPersona

# Ejecutable de pruebas, debe existir el fichero $(TARGET_TEST).cpp con el main
TARGET_TEST =	main_test

# Crear la lista de los ficheros .o a partir de los .cpp
# Son los objetos de los modulos
OBJS =		$(SRCS:.cpp=.o)

# Crear la lista de los ficheros de cabecera .hpp a partir de la lista de los .cpp
# Son las cabeceras de los modulos
HDRS =		$(SRCS:.cpp=.hpp)

OBJS_TEST =	$(SRCS:.cpp=_test.o)

$(TARGET):	$(TARGET).o $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^ $(LIBS)

all:	$(TARGET)

deploy:	all
	scp -P 2222  $(TARGET) pi@localhost:proy/ 
#	rsync -av -e "ssh -p 2222" . pi@localhost:proy/ 

# Significado:
#  $@ es target
#  $< es el primer prerrequisito
#  $^ son todos los prerrequisitos separados por un espacio sin duplicidades

#Compila la prueba de los modulos y los modulos si hace falta
$(TARGET_TEST): $(TARGET_TEST).o $(OBJS_TEST) #$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(TARGET_TEST).o : $(TARGET_TEST).cpp doctest.h
	$(CXX) $(CXXFLAGS) -c $<

%_test.o: %.cpp $(HDRS)
	# Compilar fichero.cpp a fichero.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<
# Construir fichero.o si cambia fichero.cpp o cualquier cabecera
%.o: %.cpp $(HDRS)
	# Compilar fichero.cpp a fichero.o
	$(CXX) $(CXXFLAGS) -D DOCTEST_CONFIG_DISABLE -c $<

#Compila si hace falta y ejecuta el programa
run: $(TARGET)
	./$(TARGET)

#Compila si hace falta y ejecuta la prueba
test: $(TARGET_TEST)
	./$(TARGET_TEST)

clean:
	#rm -f $(OBJS) $(TARGET) main_test main_test.o factorial_test.o
	rm -f *.o $(TARGET) $(TARGET_TEST)

