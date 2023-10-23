TARGET = lottery

CFLAGS = -fsanitize=address,undefined -Wall -Wextra -O2 -g 

SOURCES = $(TARGET).cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS) 
	g++ $(CFLAGS) -o $@ $(OBJECTS)

.cpp.o:
	g++ $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJECTS)

run: all 
	./$(TARGET)