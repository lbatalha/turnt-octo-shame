CFLAGS=-O2 -march=native -ansi -pedantic -Wall
LDFLAGS=-lg2 -lpthread -lm

eagle2014: main.o cockpit_display.o draw_data.o file_ops.o ship_draw.o spec_input.o mouse_control.o fisica.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm -f *.o
	rm -f eagle2014