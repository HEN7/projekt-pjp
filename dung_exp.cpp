#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

int map_x=0,map_y=0;

    ALLEGRO_BITMAP *area = NULL;
    ALLEGRO_BITMAP *buffer = NULL;
    ALLEGRO_BITMAP *ludek = NULL;
    ALLEGRO_BITMAP *enemy = NULL;
    ALLEGRO_BITMAP *sciana1 = NULL;
    ALLEGRO_BITMAP *sciana2 = NULL;
    ALLEGRO_BITMAP *sciana3 = NULL;
    ALLEGRO_BITMAP *lava1 = NULL;
    ALLEGRO_BITMAP *portal = NULL;
    ALLEGRO_BITMAP *wulkan = NULL;
    ALLEGRO_BITMAP *siarka = NULL;


int map[] =
{
      2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,0,4,0,0,0,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5,5,5,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,5,5,0,0,0,0,0,0,0,0,4,4,0,4,0,0,0,0,0,0,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,4,4,0,0,0,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
      2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
      2,0,0,0,0,5,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
      2,0,0,0,5,5,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
      2,0,0,0,5,5,0,0,5,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
      2,5,5,5,5,5,0,0,5,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,2,
      2,5,5,5,5,5,5,5,5,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,2,
      2,5,5,5,5,5,5,5,5,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,2,
      2,5,5,5,0,0,0,5,5,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,2,
      2,5,5,5,0,0,0,5,5,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,2,
      2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};



int main()
{
    int width = 800;
    int height = 600;

    bool done = false;
    bool menu = true;
    bool game = false;
    bool opt = false;
    bool rec = false;
    bool k[4]={false,false,false,false};
    enum K{UP,DOWN,LEFT,RIGHT};
    bool e = false;
    bool render = false;


    int pos_x = width / 2;
    int pos_y = height / 2;
    int pos_point = 330;

    int xOff = 0;
    int yOff = 0;

    int mapCollumn = 24;
    int mapSize = 960;
    int tileSize = 20;



    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   // ALLEGRO_TIMER *timer;


    al_init();
    al_init_image_addon();
    al_install_mouse();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT *font_ttf = al_load_ttf_font("OLDENGL.ttf",45,0);
    ALLEGRO_FONT *title = al_load_ttf_font("L.ttf",60,0);
    ALLEGRO_BITMAP *pnt = al_load_bitmap("lol.png");
    ALLEGRO_FONT *esc = al_create_builtin_font();

    ALLEGRO_BITMAP *ludek1 = al_load_bitmap("ludzik.bmp");
    ALLEGRO_BITMAP *sciana1 = NULL;//al_load_bitmap("sciana.bmp");
    ALLEGRO_BITMAP *ziemia1 = al_load_bitmap("ziemia.bmp");
    ALLEGRO_BITMAP *sciana2 = al_load_bitmap("sciana1.bmp");
    ALLEGRO_BITMAP *sciana3 = al_load_bitmap("sciana2.bmp");
    ALLEGRO_BITMAP *kamien1 = al_load_bitmap("kamien.bmp");
    ALLEGRO_BITMAP *grzyb = al_load_bitmap("grzyb.bmp");
    ALLEGRO_BITMAP *lava1 = al_load_bitmap("lava1.bmp");
    ALLEGRO_BITMAP *portal = al_load_bitmap("portal.bmp");
    ALLEGRO_BITMAP *wulkan = al_load_bitmap("wulkan.bmp");
    ALLEGRO_BITMAP *siarka = al_load_bitmap("siarka.bmp");
    //ALLEGRO_BITMAP *buffer = NULL;

    sciana1 = al_load_bitmap("sciana.bmp");

    buffer = al_create_bitmap(800,600);

    display = al_create_display(width, height);

    int portal_x, portal_y, portal_s=40, portal_w=40;

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
            al_show_native_message_box(display, "ERROR", NULL,
            "Could not initialize Allegro 5", NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

        if(!display)
        {
            al_show_native_message_box(display, "ERROR", NULL,
            "Could not create display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

        if(!al_install_keyboard())
        {
            al_show_native_message_box(display, "ERROR", NULL,
            "Could not install keyboard", NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

        if(!al_install_mouse())
        {
            al_show_native_message_box(display, "ERROR", NULL,
            "Could not install mouse", NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

        if(!al_init_ttf_addon())
        {
            al_show_native_message_box(display, "ERROR", NULL,
            "Could not load ttf font", NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }
    event_queue = al_create_event_queue();
    //timer = al_create_timer(1.0 / 60);

//////////////////////////////////////////////////
//               EVENTS                         //
/////////////////////////////////////////////////
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    //al_register_event_source(event_queue, al_get_timer_event_source(timer));

    //al_start_timer(timer);

    al_hide_mouse_cursor(display);  //hiding mouse cursor on screen
    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
              switch(ev.keyboard.keycode)
                    {
                    case ALLEGRO_KEY_UP:
                        //pos_y -= 15;
                        k[UP]=true;
                        break;
                    case ALLEGRO_KEY_DOWN:
                        //pos_y += 15;
                        k[DOWN]=true;
                        break;
                    case ALLEGRO_KEY_LEFT:
                        //pos_x -= 15;
                        k[LEFT]=true;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        //pos_x += 15;
                        k[RIGHT]=true;
                        break;
                    }
        }
        if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
              switch(ev.keyboard.keycode)
                    {
                    case ALLEGRO_KEY_UP:
                        //pos_y -= 15;
                        k[UP]=false;
                        break;
                    case ALLEGRO_KEY_DOWN:
                        //pos_y += 15;
                        k[DOWN]=false;
                        break;
                    case ALLEGRO_KEY_LEFT:
                        //pos_x -= 15;
                        k[LEFT]=false;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        //pos_x += 15;
                        k[RIGHT]=false;
                        break;
                    }
        }
        if(k[UP]) pos_y -= 5;
        if(k[DOWN]) pos_y += 5;
        if(k[LEFT]) pos_x -= 5;
        if(k[RIGHT]) pos_x += 5;

        if(pos_y <= 20){pos_y = 20;}
        if(pos_y >=560){pos_y = 560;}
        if(pos_x <=20){pos_x = 20;}
        if(pos_x >=760){pos_x = 760;}
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
            case  ALLEGRO_KEY_ESCAPE:
                if(e = true)
                {
                    game=false;
                    menu=true;
                    rec=false;
                    opt=false;
                }
                    break;
            case ALLEGRO_KEY_DOWN:              //moving down in main menu
                pos_point +=35;
                if (pos_point <= 330)
                {
                    pos_point = 440;
                }
                else if (pos_point > 440)
                {
                    pos_point = 330;
                }
                break;
            case ALLEGRO_KEY_UP:                //moving up in main menu
                pos_point-= 35;
                if (pos_point >= 435)
                {
                    pos_point = 320;
                }
                else if(pos_point <= 320)
                {
                    pos_point = 435;
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
                else if(pos_point<=440)
                {
                    done = true;
                }
                break;
            }
        }
        /*else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            xOff -= k[RIGHT] = 5;
            xOff += k[LEFT] = 5;
            yOff -= k[DOWN] = 5;
            yOff += k[UP] = 5;

            render = true;
        }

*/
        if(menu)
            {
            al_draw_textf(title,al_map_rgb(255,0,0),90,200,0,"DUNGEON EXPLORER");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),320,350,0,"new game");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),345,385,0,"records");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),345,420,0,"options");
            //al_draw_text (esc,al_map_rgb(255,0,0),650,590,0,"press esc to exit");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),375,455,0,"exit");
            al_draw_bitmap(pnt, 200, pos_point, 0);
            al_convert_mask_to_alpha(pnt, al_map_rgb(255,105,180));
            }
        if(game)
        {
            al_clear_to_color(al_map_rgb(120,90,130));
            al_draw_bitmap(ludek1, pos_x, pos_y, 0);
            al_draw_bitmap(sciana2,0,0,0);
            al_draw_bitmap(sciana2,0,580,0);
            al_draw_bitmap(sciana3,0,0,0);
            al_draw_bitmap(sciana3,780,0,0);
            al_draw_bitmap(portal,400,100,0);
            al_convert_mask_to_alpha(ludek1, al_map_rgb(255,255,255));
            al_convert_mask_to_alpha(portal, al_map_rgb(255,255,255));

            /*for(int i = 0; i < mapSize; i++)
            {
                al_draw_bitmap_region(sciana1, mapSize * map[i],0,tileSize,tileSize,
                xOff +tileSize *(i%mapCollumn),yOff +tileSize*(i/mapCollumn),0);
            }
*/
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
    al_destroy_bitmap(ludek1);
    al_destroy_bitmap(sciana2);
    al_destroy_bitmap(sciana3);
    al_destroy_bitmap(sciana1);
    return 0;
}
