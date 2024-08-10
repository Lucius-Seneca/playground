all: app.o node.o
	clang++ -o ./bin/app ./bin/app.o ./bin/node.o

app.o:
	clang++ -std=c++20 -c ./app/app.cpp -o ./bin/app.o

node.o:
	clang++ -std=c++20 -I ./graph/include/graph/node.hpp -c ./graph/src/node.cpp -o ./bin/node.o
