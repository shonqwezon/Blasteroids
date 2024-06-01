#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

int main() {
    // Initialize Allegro
    if (!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro!\n");
        return -1;
    }

    // Initialize display
    ALLEGRO_DISPLAY *display = al_create_display(800, 600);
    if (!display) {
        fprintf(stderr, "Failed to create display!\n");
        return -1;
    }

    // Initialize primitives addon
    if (!al_init_primitives_addon()) {
        fprintf(stderr, "Failed to initialize primitives addon!\n");
        al_destroy_display(display);
        return -1;
    }

    // Initialize image addon
    if (!al_init_image_addon()) {
        fprintf(stderr, "Failed to initialize image addon!\n");
        al_destroy_display(display);
        return -1;
    }

    // Initialize font addon
    if (!al_init_font_addon()) {
        fprintf(stderr, "Failed to initialize font addon!\n");
        al_destroy_display(display);
        return -1;
    }

    // Initialize ttf addon
    if (!al_init_ttf_addon()) {
        fprintf(stderr, "Failed to initialize ttf addon!\n");
        al_destroy_display(display);
        return -1;
    }

    // Clear the display to black
    al_clear_to_color(al_map_rgb(0, 0, 0));

    // Draw a white rectangle
    al_draw_filled_rectangle(100, 100, 200, 200, al_map_rgb(255, 255, 255));

    // Update the display
    al_flip_display();

    // Wait for 5 seconds
    al_rest(5.0);

    // Cleanup
    al_destroy_display(display);

    return 0;
}
