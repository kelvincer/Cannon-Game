eval g++ *.cpp */*.cpp $(pkg-config --libs --cflags raylib) -o o -g -std=c++20
leaks --atExit --list  -- ./o