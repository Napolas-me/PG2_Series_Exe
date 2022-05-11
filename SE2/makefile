LDFLAGS = -g
CFLAGS = -c -g

mp3.o: mp3.c mp3.h stringMan.h
	gcc $(CFLAGS) mp3.c

stringMan.o: stringMan.c stringMan.h
	gcc $(CFLAGS) stringMan.c

clean:
	rm -f *.o