#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "mouvement.h"
#include "personnages_init.h"
#include "collision.h"
#include <string.h>
int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL, /**zozor = NULL*/ *bg= NULL;//*freeman = NULL,*mc = NULL;
    SDL_Rect positionbg;
    perso zozor,mc;
    //zozor.place="zozor.bmp";
    strcpy(zozor.place,"zozor.bmp");
    strcpy(mc.place,"th.jpg");
    mc.pos.x=200;
    mc.pos.y=150;
    //mc.place="mc.png";
    //perso* pt;
    //pt=&zozor;
    positionbg.x=0;
    positionbg.y=0;
    SDL_Event event;
    //mc->h=600;
    //mc->w=600;
    //positionmc.x = 200;
    //positionmc.y = 150;

    SDL_Init(SDL_INIT_VIDEO|SDL_DOUBLEBUF);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Gestion des �v�nements en SDL", NULL);

    bg=IMG_Load("lac_en_montagne.bmp");
    //zozor=IMG_Load("zozor.bmp");
    //init_pers(&bg,ecran,"lac_en_montagne.bmp",positionbg);
    init_pers(&zozor,ecran);
    init_pers(&mc,ecran);

    /* On centre Zozor � l'�cran */

    //zozor.pos.x = 1;
    //zozor.pos.y = ecran->h / 2 - zozor.nom->h / 2;


    int continuer = 1;
    SDL_EnableKeyRepeat(1, 1);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        if (box(zozor.pos,mc.pos)==0)
                    {
                       SDL_SetColorKey(zozor.nom, SDL_SRCCOLORKEY, SDL_MapRGB(zozor.nom->format, 0, 0, 255));
                        deplacer(event,&zozor.pos,&continuer);
                    }

                    else
                    {
                        SDL_SetColorKey(zozor.nom, SDL_SRCCOLORKEY, SDL_MapRGB(zozor.nom->format, 0, 0, 0));
                        deplacer(event,&zozor.pos,&continuer);
                    }
        SDL_BlitSurface(bg, NULL, ecran, &positionbg);
        SDL_BlitSurface(mc.nom,NULL,ecran,&mc.pos);
        SDL_BlitSurface(zozor.nom, NULL, ecran, &zozor.pos);


        SDL_Flip(ecran);

    }

    SDL_FreeSurface(zozor.nom);
    SDL_FreeSurface(mc.nom);
    SDL_FreeSurface(bg);
    SDL_Quit();

    return EXIT_SUCCESS;
}
