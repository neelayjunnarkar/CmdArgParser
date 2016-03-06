CC     = g++
CFLAGS = -std=c++14
OBJS   = Parser.o
TARGET = target

Parser.o: Parser.cpp
	$(CC) -c $(CFLAGS) Parser.cpp -o Parser.o

all: $(OBJS)
	$(CC) $(CFLAGS) main.cpp $(OBJS) -o $(TARGET) 

clean:
	rm *.o *.gch *.exe
