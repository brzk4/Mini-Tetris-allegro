#include <allegro.h>
#include <iostream>
#define wys_tab 21
#define szer_tab 12
#include "gra.h"
#include "start.h"
#include "silnik.h"
#include "rozgrywka.h"



int main()
{
start k_start;
rozgrywka k_rozgrywka;

int p = k_start.startuj();
if (p==0) {k_start.allegro_off(); return 0;}
if (p==1) {k_start.allegro_off(); k_rozgrywka.play();}

 return 0;
}
END_OF_MAIN()




