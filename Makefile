CXX=g++
# CXXFLAGS=-lglut -lGLU -lGL

all: main

main: main.o vertex.o
	$(CXX) -o main main.o vertex.o

main.o:	main.cpp
	$(CXX) -c -g main.cpp

vertex.o: vertex.cpp vertex.hpp
	$(CXX) -c -g vertex.cpp

clean: 
	rm main *.o