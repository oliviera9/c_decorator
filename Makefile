.PHONY: all clean

all: app

clean:
	rm -f app *.o

app:	main.c functions.c shm.c
	gcc $^ -o $@
