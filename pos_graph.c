#include <stdio.h>
#include <stdlib.h>
#include <g2.h>
#include <g2_X11.h>


int pos_graph(float altitude, float h_dist, int x_origin, int y_origin)
{
	int window_h = 600, window_w = 800; /* Holds the window height and width */
	int pdev = -1; /* Device ident for g2 */
	
	pdev = g2_open_X11(window_w , window_h);
	g2_clean(pdev);
	g2_line(x_origin, 
	
	
	
	return pdev;
}