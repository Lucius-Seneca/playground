# Graph

## Compilation

The methods described below can be used side by side.
Yet it needs to be assured that both build trees do not overlap each other, since
this could lead to problems at compilation.

### Using `g++` or `clang++`

The project can be compiled at *Ubuntu* by using the commands (if the directory `./bin` is already crated;
if not, one needs to execute the command `mkdir bin` at first)

```
g++ -I ./include/node.hpp -c ./src/node.cpp -o ./bin/node.o
ar rcs ./bin/libNodes.a ./bin/node.o
g++ ./apps/app.cpp -o ./bin/app -L./bin -lNodes
```

or in one line by entering

```
g++ -I ./include/node.hpp -c ./src/node.cpp -o ./bin/node.o && ar rcs ./bin/libNodes.a ./bin/node.o && gg++ ./apps/app.cpp -o ./bin/app -L./bin -lNodes
```

resp.

```
g++ -std=c++20 -I ./include/node.hpp -c ./src/node.cpp -o ./bin/node.o && ar rcs ./bin/libNodes.a ./bin/node.o && gg++ -std=c++20 ./apps/app.cpp -o ./bin/app -L./bin -lNodes
```

if the C++ standard needs to be specified.

and executed by the command `./bin/app`.

If errors are thrown like `warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]`, the C++-standard should be
specified by adding `-std=c++2b` to the commands above.

### Using *CMake*

An operating system independent possibility to compile the code is using *CMake*.
If *CMake* is installed at the machine, the code can be compiled by entering the commands

```
mkdir ./build && cd build && cmake .. && cd ..
cmake --build build
```

If this is done one time, the compilations simplifies to entering just the second line of both commands.
