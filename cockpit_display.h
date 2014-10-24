#ifndef COCKPIT_DISPLAY_H_INCLUDED
#define COCKPIT_DISPLAY_H_INCLUDED

int cockpit_display(int vdev, int window_h, int window_w, float altitude, float atitude, float h_dist, float vel_x, float vel_y, float fuel, float fuel_rate, float force_r, float force_t, char *landing_status);

#endif