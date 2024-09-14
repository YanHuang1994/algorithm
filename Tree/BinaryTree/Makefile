CC = g++
CFLAGS = -std=c++11

SOURCES = BinaryTree.cpp BinarySearchTree.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = BinaryTree_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
