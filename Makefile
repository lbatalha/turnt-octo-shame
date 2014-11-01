#Grupo 74
#
#	63282 - Artur Guilherme Rodrigues de Vasconcelos
#>	70037 - Luis Filipe Ramos Batalha
#
#Projecto Eagle2014 - https://github.com/lbatalha/turnt-octo-shame
#
#
CFLAGS=-O0 -march=native -ansi -ggdb -pedantic -Wall
LDFLAGS=-lg2 -lpthread -lm

eagle2014: main.o cockpit_display.o draw_data.o file_ops.o ship_draw.o spec_input.o mouse_control.o fisica.o pos_graph.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm -f *.o
	rm -f eagle2014