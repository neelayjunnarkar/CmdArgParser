CC     = g++
CFLAGS = -std=c++14
OBJS   = Parser.o
TARGET = target

all: $(OBJS)
	$(CC) $(CFLAGS) main.cpp $(OBJS) -o $(TARGET) 
	
Parser.o: Parser.cpp
	$(CC) -c $(CFLAGS) Parser.cpp -o Parser.o

clean:
	rm *.o *.gch *.exe
