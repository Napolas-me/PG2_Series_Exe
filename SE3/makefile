LDFLAGS = -g
CFLAGS = -c -g

mp3App: mp3App.o mp3.o manage.o tableRead.o dinamicArray.o stringMan.o
	gcc $(LDFLAGS) mp3App.o mp3.o manage.o tableRead.o dinamicArray.o stringMan.o -o mp3App
	make clean

mp3.o: mp3.c mp3.h stringMan.h
	gcc $(CFLAGS) mp3.c

manage.o: manage.c manage.h
	gcc $(CFLAGS) manage.c

tableRead.o: tableRead.c tableRead.h manage.h
	gcc $(CFLAGS) tableRead.c

dinamicArray.o: dinamicArray.c dinamicArray.h mp3.h
	gcc $(CFLAGS) dinamicArray.c

mp3App.o: mp3App.c mp3.h stringMan.h
	gcc $(CFLAGS) mp3App.c

stringMan.o: stringMan.c stringMan.h
	gcc $(CFLAGS) stringMan.c

clean:
	rm -f *.o