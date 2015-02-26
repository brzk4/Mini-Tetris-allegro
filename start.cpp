#include <allegro.h>
#include "start.h"

start::start()
{
       BITMAP * tlo = NULL;
       mx = 0;
       my = 0;
       mb = 0;
}

int start::startuj()
{
 allegro_on();
 ////////////////
     install_mouse();
    show_mouse( tlo );
    unscare_mouse();
 while(!key[KEY_ESC])
{
blit( tlo , screen , 0 ,0 ,0 ,0, 800, 600);
myszka();
if (mx>320 && mx<480 && my>175 && my<260 &&   mb!=0)  { return 1;  }          // przycisk graj
if (mx>300 && mx<480 && my>320 && my<380 &&   mb!=0)  { return 0;  }          // przycisk wyjdz
}
 //////////////
allegro_off();
}

void start::myszka()
{
    if( mx != mouse_x || my != mouse_y || mb != mouse_b )
    {
        mx = mouse_x;
        my = mouse_y;
        mb = mouse_b;
    }
};
void start::allegro_on()
{
 allegro_init();
    install_keyboard();
    set_color_depth( 16 );
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0 );
    clear_to_color( screen, makecol( 128, 128, 128 ) );





     tlo = load_bmp("start.bmp" , default_palette);
    if (!tlo)
    {
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
    allegro_message( "nie moge zaladowac tla!" );
    }

}

void start::allegro_off()
{

        remove_mouse();
        destroy_bitmap(tlo);
        allegro_exit();
}

