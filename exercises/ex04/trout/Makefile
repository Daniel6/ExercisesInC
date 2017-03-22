all: main

main: main.c trout util
	gcc -g -o main.out main.c util.out trout.out

trout: trout.c util
	gcc -g -o trout.out trout.c util.out

util: util.c
	gcc -g -o util.out util.c
