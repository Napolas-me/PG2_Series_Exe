LDFLAGS = -g
CFLAGS = -c -g

unpackint: unpackint.o func.o
	gcc $(LFLAGS) -o unpackint unpackint.o func.o

func.o: func.c func.h
	gcc $(CFLAGS) func.c

unpackint.o: unpackint.c func.h
	gcc $(CFLAGS) unpackint.c
clean:
	rm *.o unpackint

debug: unpackint
	insight unpackint
