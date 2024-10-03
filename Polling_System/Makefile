# Makefile for Polling System
CXX = g++
CXXFLAGS = -std=c++11 -pthread -O2
TARGET = polling_system

all: $(TARGET)

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(TARGET) *.o
