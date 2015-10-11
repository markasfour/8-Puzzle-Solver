all: 
	if [ ! -d "./bin" ];\
		then mkdir bin;\
	fi
	
	g++ -std=c++11 main.cpp -o bin/main.o

clean:
	rm -rf bin
