# Graph

## Compilation

The methods described below can be used side by side.
Yet it needs to be assured that both build trees do not overlap with each other, since
this could lead to problems.

### Using `clang++`

The project can be compiled on the Terminal using the commands (if the directory `./bin` is already crated;
if not, one needs to execute the command `mkdir bin` at first)

``` bash
clang++ -I ./graph/include/graph/node.hpp -c ./graph/src/node.cpp -o ./bin/node.o
ar rcs ./bin/libNodes.a ./bin/node.o
clang++ ./app/app.cpp -o ./bin/app -L./bin -lNodes
```

or in one line by entering

``` bash
clang++ -I .graph/include/graph/node.hpp -c ./graph/src/node.cpp -o ./bin/node.o && ar rcs ./bin/libNodes.a ./bin/node.o && clang++ ./app/app.cpp -o ./bin/app -L./bin -lNodes
```

If errors are thrown like `warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]`, the `C++`-standard should be
specified by adding `-std=c++2b` to the commands above,

``` bash
clang++ -std=c++20 -I .graph/include/graph/node.hpp -c ./graph/src/node.cpp -o ./bin/node.o && ar rcs ./bin/libNodes.a ./bin/node.o && clang++ -std=c++20 ./app/app.cpp -o ./bin/app -L./bin -lNodes
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

### Using *Bazel*

The most easy option to compile the source is using [*Bazel*](https://bazel.build/start/cpp).
To command *Bazel* to run and also build the app, you just need to type `bazel run //app`.
If you just like to build the app, you can type `bazel build //app` or just `bazel build ...`.
To compile the used library only, you can execute `bazel build //graph` (which is automatically
done in case of the aforementioned commands).

For an installation guide for *Bazel*, see https://bazel.build/install. The easiest way is probably
downloading the recent *Bazelisk* release from https://github.com/bazelbuild/bazelisk/releases and
adding it as `bazel` to `PATH` resp. moving it to `/usr/local/bin/` as `bazel` on *Linux* distributions
and make it executable via the command `chmod +x /usr/local/bin`.

## Use GTEST to run unit tests

The [*GoogleTest*](https://github.com/google/googletest) library is a very convenient way
to write and execute unit tests. It is embedded in this project using *CMake* and using
*Bazel* build workflows (while making it automatically running using manually written
*make* files is too complex for the scope of this project).

### Compiling and running the tests using *CMake*

To build run the unit tests using *Cmake* you just need to run the command

``` bash
cmake --build build --target test
```

Alternatively, you can also just compile the whole project using the usual *Cmake* build
command `cmake --build build` and then navigate to the build folder and run the command
`ctest` from there. Is automatically executes all unit tests from the build folder.
You just need to ensure that all your unit tests are registered in the `CMakeLists.txt`
files via the `add_test(NAME <test_name> COMMAND <command to run>)` command.

### Compiling and running the tests using *Bazel*

To build and run the unit tests using *Bazel* is also very easy. You just need to run
the command

``` bash
bazel test ...
```

from the command line to automatically build and run all unit tests that are specified in
the bazel *BUILD* files using the command [`cc_test`](https://bazel.build/reference/be/c-cpp#cc_test).
