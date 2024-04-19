run:
	g++ -g -std=c++20 -Wall -Wextra main.cpp -o main

mem:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./main 