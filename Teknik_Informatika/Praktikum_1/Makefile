.PHONY: run clean

build: clean
	cc -std=c89 -lm main.c -o main
	chmod +x main

clean:
	rm -rf *.o main

run: clean build
	./main
