#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

int main()
{
    int width = 800;
    int height = 600;

    bool done = false;
    bool menu = true;
    bool game = false;
    bool opt = false;
    bool rec = false;


    int pos_x = width / 2;
    int pos_y = height / 2;
    int pos_point = 330;

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT *font_ttf = al_load_ttf_font("OLDENGL.ttf",45,0);
    ALLEGRO_FONT *title = al_load_ttf_font("L.ttf",60,0);
    ALLEGRO_BITMAP *pnt = al_load_bitmap("lol.png");
    ALLEGRO_FONT *esc = al_create_builtin_font();

    display= al_create_display(width, height);

////////////////////////////////////
//        ERROR MESSAGES          //
////////////////////////////////////
        if(!pnt)
        {
        al_show_native_message_box(display, "ERROR", NULL,
        "Cannot load bitmap", NULL, ALLEGRO_MESSAGEBOX_ERROR);
         return -1;
        }

        if(!al_init())
        {
            al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
            return -1;
        }

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

//////////////////////////////////////////////////
//               EVENTS                         //
/////////////////////////////////////////////////
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_hide_mouse_cursor(display);  //hiding mouse cursor on screen
    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
       /* else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)          //mouse event
        {
            pos_x = ev.mouse.x;
            pos_y = ev.mouse.y;
        }
         else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
         {
             if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done = true;
         }*/
         if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
         {
            switch (ev.keyboard.keycode)
            {
            case  ALLEGRO_KEY_ESCAPE:           //closing program with escape button
                done = true;
                break;
            case ALLEGRO_KEY_DOWN:              //moving down in main menu
                pos_point +=35;
                if (pos_point <= 330)
                {
                    pos_point = 400;
                }
                else if (pos_point > 400)
                {
                    pos_point = 330;
                }
                break;
            case ALLEGRO_KEY_UP:                //moving up in main menu
                pos_point-= 35;
                if (pos_point >= 400)
                {
                    pos_point = 320;
                }
                else if(pos_point <= 320)
                {
                    pos_point = 400;
                }
                break;
            case ALLEGRO_KEY_ENTER:
                if(pos_point<=330)
                {
                    menu=!menu;
                    game=!game;
                }
                else if(pos_point<=365)
                {
                    menu=!menu;
                    rec=!rec;
                }
                else if(pos_point<=400)
                {
                    menu=!menu;
                    opt=!opt;
                }
                break;
            }
        }
        if(menu)
            {
            al_draw_textf(title,al_map_rgb(255,0,0),90,200,0,"DUNGEON EXPLORER");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),320,350,0,"new game");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),345,385,0,"records");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),345,420,0,"options");
            al_draw_text (esc,al_map_rgb(255,0,0),650,590,0,"press esc to exit");
            //al_draw_textf(font_ttf,al_map_rgb(150,180,250),375,455,0,"exit");
            al_draw_bitmap(pnt, 200, pos_point, 0);
            al_convert_mask_to_alpha(pnt, al_map_rgb(255,105,180));
            }
        if(game)
        {
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),240,50,0,"tu powinna byc gra");
        }
        if(opt)
        {
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),320,50,0,"options:");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,100,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,150,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,200,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,250,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,300,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,350,0,"placeholder");
        }
        if(rec)
        {
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),320,50,0,"records:");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,100,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,150,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,200,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,250,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,300,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,350,0,"placeholder");
        }
            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));
    }

    al_destroy_display(display);
    al_destroy_font(font_ttf);
    al_destroy_font(title);
    al_destroy_bitmap(pnt);
    al_destroy_font(esc);
    return 0;
}
