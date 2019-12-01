CC=g++
CFLAGS= -Wall -lm
EXEC_NAME= exe
OBJ=$(main.o  mesh.o cell.o utils.o)
SOURCES= main.cpp cell.cpp mesh.cpp utils.cpp
ENTETES= cell.hpp mesh.hpp utils.hpp 



all: $(EXEC_NAME)


$(EXEC_NAME) : $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXEC_NAME) 



main.o: main.cpp
	$(CC)  -c main.cpp  cell.h mesh.h utils.h  
	

cell.o: cell.cpp cell.h
	$(CC) -c  cell.cpp 

mesh.o: mesh.cpp cell.h
	$(CC) -c mesh.cpp cell.h

utils.o: utils.cpp 
	$(CC) -c utils.cpp 



%.o: %.cpp
	$(CC) -o $@ -cpp $< $(CFLAGS)	 
	


clean :
	rm *.o exe







