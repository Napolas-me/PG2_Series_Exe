LDFLAGS = -g
CFLAGS = -c -g

mp3.o: mp3.c mp3.h stringMan.h
	gcc $(CFLAGS) mp3.c

stringMan.o: stringMan.c stringMan.h
	gcc $(CFLAGS) stringMan.c

mp3App.o: mp3App.c mp3.h stringMan.h
	gcc $(CFLAGS) mp3App.c

mp3App: mp3App.o mp3.o stringMan.o
	gcc $(LDFLAGS) mp3App.o mp3.o stringMan.o -o mp3App

clean:
	rm -f *.o