CC = gcc
CFLAGS = -g -Wall -Werror
OBJECTS = main.o commands.o saveload.o draw.o arguments.o canvas.o

paint.out : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o paint.out -lm

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) paint.out