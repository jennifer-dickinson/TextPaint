CC = gcc
CFLAGS = -g -O2 -Wall -Werror
OBJECTS = main.o commands.o saveload.o draw.o formatting.o canvas.o

paint.out : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o paint.out

%.o : %.c
	$(CC) $(CFLAGS) -c $<