#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <ctime>
#include <cstring>
#include <sstream>

    int width = 800;
    int height = 600;

    bool done = false;
    bool menu = true;
    bool game = false;
    bool opt = false;
    //bool rec = false;

    bool s = false;

    int iloscdiam = 10;
    int diam_s_x = 20, diam_s_y = 20;
    int score = 0;
    int ilosc_zyc = 3;
        ///////////////std::ostringstream convert;
int map[] =
{
      0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,
      0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,
      0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
      0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
      0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,
      0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,
      };

void update_diam(int diam_x[], int diam_y[])
{
    for(int i = 0; i<iloscdiam; i++){
        diam_x[i] = 20+rand()%20*35;
        diam_y[i] = 20+rand()%20*25;

    }

}

void update_enemy(int enemy_x[], int enemy_y[])
{
    for(int i = 0; i<iloscdiam; i++){
        enemy_x[i] = 20+rand()%20*35;
        enemy_y[i] = 20+rand()%20*25;
    }
}


int main()
{

    bool k[4]={false,false,false,false};
    enum K{UP,DOWN,LEFT,RIGHT};
    bool e = false;

    int pos_x = width / 2;
    int pos_y = height / 2;

    int pos_point = 330;

    int xOff = 0;
    int yOff = 0;

    int mapCollumn = 40;
    int mapSize = 1200;
    int tileSize = 20;

    int diam_x[iloscdiam];
    int diam_y[iloscdiam];
    int enemy_x[iloscdiam];
    int enemy_y[iloscdiam];

    int tmp_life = ilosc_zyc;
    srand(time(NULL));
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    al_init();
    al_init_image_addon();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    display = al_create_display(width, height);
    ALLEGRO_FONT *font_ttf = al_load_ttf_font("OLDENGL.ttf",45,0);
    ALLEGRO_FONT *title = al_load_ttf_font("L.ttf",60,0);
    ALLEGRO_BITMAP *pnt = al_load_bitmap("lol.png");
    //ALLEGRO_FONT *esc = al_create_builtin_font();

    ALLEGRO_BITMAP *ludek1 = al_load_bitmap("ludzik.bmp");
    ALLEGRO_BITMAP *portal = al_load_bitmap("portal.bmp");
    ALLEGRO_BITMAP *teren = NULL;

    ALLEGRO_BITMAP *diam[iloscdiam];
    ALLEGRO_BITMAP *enemy[iloscdiam];

    for(int i = 0; i<iloscdiam; i++){
        diam[i] = al_load_bitmap("diament.bmp");
        enemy[i] = al_load_bitmap("enemy.bmp");
        diam_x[i] = 20+rand()%20*35;
        diam_y[i] = 20+rand()%20*25;
        enemy_x[i] = 20+rand()%20*35;
        enemy_y[i] = 20+rand()%20*25;
    }
    int d = 0;
    teren = al_load_bitmap("teren.bmp");



    ////////////////////////////////////
    //        ERROR MESSAGES          //
    ////////////////////////////////////
       if(!pnt)
        {
            al_show_native_message_box(display, "ERROR",
            "Cannot load bitmap", NULL,NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

        if(!al_init())
        {
            al_show_native_message_box(display, "ERROR",
            "Could not initialize Allegro 5", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

        if(!display)
        {
            al_show_native_message_box(display, "ERROR",
            "Could not create display", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

        if(!al_install_keyboard())
        {
            al_show_native_message_box(display, "ERROR",
            "Could not install keyboard", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

        if(!al_init_ttf_addon())
        {
            al_show_native_message_box(display, "ERROR",
            "Could not load ttf font", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

    event_queue = al_create_event_queue();

//////////////////////////////////////////////////
//               EVENTS                         //
//////////////////////////////////////////////////
    al_register_event_source(event_queue, al_get_display_event_source(display));
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
        if(k[UP]) pos_y -= 2;
        if(k[DOWN]) pos_y += 2;
        if(k[LEFT]) pos_x -= 2;
        if(k[RIGHT]) pos_x += 2;

        if(pos_y <= 0){pos_y = 0;}
        if(pos_y >=580){pos_y = 580;}
        if(pos_x <=0){pos_x = 0;}
        if(pos_x >=780){pos_x = 780;}

         if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
         {
            switch (ev.keyboard.keycode)
            {
            case  ALLEGRO_KEY_ESCAPE:
                if(e = true)
                {
                    game=false;
                    menu=true;
                    //rec=false;
                    opt=false;
                    s= false;
                }
                    break;
            case ALLEGRO_KEY_DOWN:              //moving down in main menu
                pos_point +=35;
                if (pos_point <= 330)
                {
                    pos_point = 410;
                }
                else if (pos_point > 410)
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
                    menu=false;
                    game=true;
                }
                else if(pos_point<=365)
                {
                    menu=false;
                    opt=true;
                                    }
                /*else if(pos_point<=400)
                {
                    menu=false;
                    rec=true;
                                   }*/
                else if(pos_point<=400)
                {
                    done = true;
                }

                break;
            }

        }

        if(menu == true)
            {
            al_draw_textf(title,al_map_rgb(255,0,0),90,200,0,"DUNGEON EXPLORER");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),320,350,0,"new game");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),345,385,0,"options");
            //al_draw_textf(font_ttf,al_map_rgb(255,0,0),345,420,0,"records");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),375,420,0,"exit");
            al_draw_bitmap(pnt, 200, pos_point, 0);
            al_convert_mask_to_alpha(pnt, al_map_rgb(255,105,180));

            }
        if(game == true)
        {
            menu == false;
            al_clear_to_color(al_map_rgb(120,90,130));


            for(int i = 0; i < mapSize; i++)
            {
                al_draw_bitmap_region(teren, tileSize * map[i],0,tileSize,tileSize, xOff + tileSize *(i%mapCollumn),yOff +tileSize*(i/mapCollumn),0);

            }
             al_draw_textf(font_ttf,al_map_rgb(255,0,0),10,20,0,"SCORE: %i", score);
             al_draw_textf(font_ttf,al_map_rgb(255,0,0),450,20,0,"LIFE: %i", tmp_life);

            if(score < 50)
            {
            for(int i =0; i<2; i++){
            al_draw_bitmap(diam[i],diam_x[i],diam_y[i],0);
            al_convert_mask_to_alpha(diam[i], al_map_rgb(255,255,255));
            al_draw_bitmap(enemy[i],enemy_x[i],enemy_y[i],0);
            al_convert_mask_to_alpha(enemy[i], al_map_rgb(255,0,255));

            }
            d = 2;
            }else
            if(score < 100)
            {
            for(int i =0; i<4; i++)
            {
            al_draw_bitmap(diam[i],diam_x[i],diam_y[i],0);
            al_convert_mask_to_alpha(diam[i], al_map_rgb(255,255,255));
            al_draw_bitmap(enemy[i],enemy_x[i],enemy_y[i],0);
            al_convert_mask_to_alpha(enemy[i], al_map_rgb(255,0,255));

            }
            d = 4;
            }else
            if(score < 200){
            for(int i =0; i<6; i++)
            {
            al_draw_bitmap(diam[i],diam_x[i],diam_y[i],0);
            al_convert_mask_to_alpha(diam[i], al_map_rgb(255,255,255));
            al_draw_bitmap(enemy[i],enemy_x[i],enemy_y[i],0);
            al_convert_mask_to_alpha(enemy[i], al_map_rgb(255,0,255));

            }
            d = 6;
            }else

            if(score < 400)
            {
            for(int i =0; i<8; i++){
            al_draw_bitmap(diam[i],diam_x[i],diam_y[i],0);
            al_convert_mask_to_alpha(diam[i], al_map_rgb(255,255,255));
            al_draw_bitmap(enemy[i],enemy_x[i],enemy_y[i],0);
            al_convert_mask_to_alpha(enemy[i], al_map_rgb(255,0,255));

            }
            d = 8;
            }
            else
            {
            for(int i =0; i<iloscdiam; i++){
            al_draw_bitmap(diam[i],diam_x[i],diam_y[i],0);
            al_convert_mask_to_alpha(diam[i], al_map_rgb(255,255,255));
            al_draw_bitmap(enemy[i],enemy_x[i],enemy_y[i],0);
            al_convert_mask_to_alpha(enemy[i], al_map_rgb(255,0,255));

            }
            d = iloscdiam;
            }
            al_draw_bitmap(portal, 50,60,0);
            al_convert_mask_to_alpha(portal, al_map_rgb(255,255,255));
            al_draw_bitmap(ludek1, pos_x, pos_y, 0);
            al_convert_mask_to_alpha(ludek1, al_map_rgb(255,255,255));



            if(pos_x>=50 && pos_x<=60&&pos_y>=50&&pos_y<=60)
            {
                s=true;
                game=false;

            }


            for(int i =0; i<d; i++){
                if(pos_x > diam_x[i] && pos_x < diam_x[i]+diam_s_x && pos_y > diam_y[i] && pos_y < diam_y[i]+diam_s_y)
                    {
                    update_diam(diam_x, diam_y);
                    score+=10;
                    break;
                    }
                if(pos_x > enemy_x[i] && pos_x < enemy_x[i]+diam_s_x && pos_y > enemy_y[i] && pos_y < enemy_y[i]+diam_s_y)
                    {
                    update_enemy(enemy_x, enemy_y);
                    tmp_life-=1;
                    break;
                    }
            }

            if(tmp_life == 0)
            {
            s = true;
            game = false;
            tmp_life = ilosc_zyc;
            }
        }

        if(opt == true)
        {
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),320,50,0,"Options:");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),210,120,0,"Character movement");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),260,170,0,"Arrow key UP");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),215,220,0,"Arrow key DOWN");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),235,270,0,"Arrow key LEFT");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),210,320,0,"Arrow key RIGHT");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),210,420,0,"To exit press ESC");

        }


        /*if(rec == true)
        {
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),320,50,0,"records:");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,100,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,150,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,200,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,250,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,300,0,"placeholder");
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),290,350,0,"placeholder");

        }*/
        if(s == true)
        {
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_textf(font_ttf,al_map_rgb(255,0,0),300,300,0,"SCORE: %i", score);
        }

            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));
    }



    al_destroy_display(display);
    al_destroy_font(font_ttf);
    al_destroy_font(title);
    al_destroy_bitmap(pnt);
    al_destroy_bitmap(ludek1);
    al_destroy_bitmap(portal);
    for(int i=0; i<iloscdiam; i++)
    {
    al_destroy_bitmap(diam[i]);
    al_destroy_bitmap(enemy[i]);
    al_destroy_bitmap(teren);
    }
    return 0;
}
