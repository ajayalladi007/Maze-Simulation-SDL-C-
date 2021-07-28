compile :

	g++ p201.cpp p202.cpp p203.cpp main.cpp -Wall -pthread -std=c++11 `pkg-config --cflags --libs opencv` -w -lSDL2 -lSDL2_image -o p1.o


execute :

	./p1.o

	
