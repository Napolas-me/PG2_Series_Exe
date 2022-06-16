LDFLAGS = -g
CFLAGS = -c -g

mp3App: mp3App.o mp3.o manage.o tableRead.o dinamicArray.o stringMan.o linkedList.o binTree.o annex.o
	gcc $(LDFLAGS) mp3App.o mp3.o manage.o tableRead.o dinamicArray.o stringMan.o linkedList.o binTree.o annex.o -o mp3App
	make clean

mp3App.o: mp3App.c manage.h tableRead.h
	gcc $(CFLAGS) mp3App.c	

mp3.o: mp3.c mp3.h stringMan.h
	gcc $(CFLAGS) mp3.c

manage.o: manage.c manage.h dinamicArray.h binTree.h annex.h
	gcc $(CFLAGS) manage.c

tableRead.o: tableRead.c tableRead.h manage.h
	gcc $(CFLAGS) tableRead.c

dinamicArray.o: dinamicArray.c dinamicArray.h mp3.h
	gcc $(CFLAGS) dinamicArray.c

stringMan.o: stringMan.c stringMan.h
	gcc $(CFLAGS) stringMan.c

linkedList.o: linkedList.c linkedList.h mp3.h
	gcc $(CFLAGS) linkedList.c 

binTree.o: binTree.c binTree.h annex.h linkedList.h
	gcc $(CFLAGS) binTree.c

annex.o: annex.c annex.h binTree.h
	gcc $(CFLAGS) annex.c

clean:
	rm -f *.o