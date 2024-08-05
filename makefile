all: app.o node.o
	clang++ -o ./bin/app ./bin/app.o ./bin/node.o

app.o:
	clang++ -std=c++20 -c ./apps/app.cpp -o ./bin/app.o

node.o:
	clang++ -std=c++20 -I ./include/graph/node.hpp -c ./src/node.cpp -o ./bin/node.o
