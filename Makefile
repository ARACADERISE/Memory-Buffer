.PHONY: main.c

main.c:
	gcc -Wall -o main.o main.c buffer_.c buffer_engine.c

run: main.c buffer_.c buffer_engine.c
	./main.o