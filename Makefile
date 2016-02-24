CC     = g++
CFLAGS = -std=c++14
LFLAGS = 
OBJS   = Parser.o
TARGET = target

Parser.o: Parser.cpp
	$(CC) -c $(CFLAGS) Parser.cpp -o Parser.o

all: $(OBJS)
	$(CC) $(CFLAGS) main.cpp -o $(TARGET) 

clean:
	rm *~ *.un *.o *.gch *.exe
