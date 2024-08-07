# Graph

## Compilation

The methods described below can be used side by side.
Yet it needs to be assured that both build trees do not overlap with each other, since
this could lead to problems.

### Using `clang++`

The project can be compiled on the Terminal using the commands (if the directory `./bin` is already crated;
if not, one needs to execute the command `mkdir bin` at first)

``` bash
clang++ -I ./include/graph/node.hpp -c ./src/node.cpp -o ./bin/node.o
ar rcs ./bin/libNodes.a ./bin/node.o
clang++ ./apps/app.cpp -o ./bin/app -L./bin -lNodes
```

or in one line by entering

``` bash
clang++ -I ./include/graph/node.hpp -c ./src/node.cpp -o ./bin/node.o && ar rcs ./bin/libNodes.a ./bin/node.o && clang++ ./apps/app.cpp -o ./bin/app -L./bin -lNodes
```

If errors are thrown like `warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]`, the `C++`-standard should be
specified by adding `-std=c++2b` to the commands above,

``` bash
clang++ -std=c++20 -I ./include/graph/node.hpp -c ./src/node.cpp -o ./bin/node.o && ar rcs ./bin/libNodes.a ./bin/node.o && clang++ -std=c++20 ./apps/app.cpp -o ./bin/app -L./bin -lNodes
```

The resulting file can be executed by the command `./bin/app`.

### Using `make`

This project also contains a `makefile` that can be used to compile the files into an executable.
To do that, just run `make` from the command line. The resulting executable will be created in
`./bin/app` and can be run from the command line by executing `./bin/app` from there.
(In case the folder `./bin/` does not already exist, it can be created by running the command `mkdir bin`.)

### Using *CMake*

An operating system independent possibility to compile the code is using *CMake*.
If *CMake* is installed at the machine, the code can be compiled by entering the commands

``` bash
mkdir ./build && cd build && cmake .. && cd ..
cmake --build build
```

If this is done one time, the compilations simplifies to entering just the second line of these two.
