but : Main

OFILES=	main.o \
        menu.o \
        initiaalea.o \
        initiagrille.o \
        grille.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g -lgraph

main.o : main.h menu.h initiaalea.h initiagrille.h grille.h
menu.o : menu.h
initiaalea.o : initiaalea.h
initiagrille.o : initiagrille.h
grille.o : grille.h

Main : $(OFILES)
	$(CC) -o Main $(OFILES) -lgraph 

clean :
	-rm -f $(OFILES) Main