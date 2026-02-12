FILES = main.c ./src/list-utils.c ./src/list-push.c ./src/list-pop.c ./src/list-get.c ./src/list-foreach.c

build-all:
	gcc -Wno-unused-variable -Wno-implicit-function-declaration -o programma.exe -I./include $(FILES)
	./programma.exe