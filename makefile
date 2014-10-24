CFLAGS=-O2 -march=native -ansi -pedantic -Wall
LDFLAGS=-lg2

eagle2014: main.o cockpit_display.o draw_data.o spec_input.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm -f *.o
	rm -f eagle2014