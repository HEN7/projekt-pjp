#include <allegro5/allegro.h>
//#include<allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main(){
    int width = 800;
    int height = 600;

    bool done = false;
    int pos_x = width / 2;
    int pos_y = height / 2;

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    al_init();
    //al_init_primitives_addon();
    al_install_mouse();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT *font_ttf = al_load_ttf_font("OLDENGL.ttf",45,0);
    ALLEGRO_FONT *title = al_load_ttf_font("L.ttf",60,0);

        if(!al_init())
        {
            al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
            return -1;
        }

        display = al_create_display(width, height);

        if(!display)
        {
            al_show_native_message_box(NULL, NULL, NULL, "Could not create display", NULL, NULL);
            return -1;
        }

        if(!al_install_keyboard())
        {
            al_show_native_message_box(NULL, NULL, NULL, "Could not install keyboard", NULL, NULL);
            return -1;
        }

        if(!al_install_mouse())
        {
            al_show_native_message_box(NULL, NULL, NULL, "Could not install mouse", NULL, NULL);
            return -1;
        }

        if(!al_init_ttf_addon())
        {
            al_show_native_message_box(NULL, NULL, NULL, "Could not load ttf font", NULL, NULL);
            return -1;
        }

    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    //al_hide_mouse_cursor(display);
    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            pos_x = ev.mouse.x;
            pos_y = ev.mouse.y;
        }

         else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
         {
             if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done=true;

         }

        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_textf(title,al_map_rgb(255,0,0),90,200,0,"DUNGEON EXPLORER");
        al_draw_textf(font_ttf,al_map_rgb(150,180,250),330,350,0,"new game");
        al_draw_textf(font_ttf,al_map_rgb(150,180,250),355,385,0,"records");
        al_draw_textf(font_ttf,al_map_rgb(150,180,250),355,420,0,"options");
        al_draw_textf(font_ttf,al_map_rgb(150,180,250),385,455,0,"exit");

    }

    al_destroy_display(display);
    al_destroy_font(font_ttf);
    al_destroy_font(title);
    return 0;
}
