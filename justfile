run-cube: build
     ./build/cube/cube

build: make-release build-release

build-release:
    cmake --build build/

make-release:
    cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Release
