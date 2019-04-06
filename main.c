#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include "mouvement.h"
#include "personnages_init.h"
#include "collision.h"
int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL, *zozor = NULL, *bg= NULL,*freeman = NULL,*mc = NULL;
    SDL_Rect positionZozor,positionbg,positionmc;
    positionbg.x=0;
    positionbg.y=0;
    SDL_Event event;
    //mc->h=600;
    //mc->w=600;
    positionmc.x = 200;
    positionmc.y = 150;

    SDL_Init(SDL_INIT_VIDEO|SDL_DOUBLEBUF);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Gestion des événements en SDL", NULL);

    //bg=IMG_Load("lac_en_montagne.bmp");
    //zozor=IMG_Load("zozor.bmp");
    init_pers(&bg,ecran,"lac_en_montagne.bmp",positionbg);
    init_pers(&zozor,ecran,"zozor.bmp",positionZozor);
    init_pers(&mc,ecran,"th.jpg",positionmc);

    /* On centre Zozor à l'écran */
    positionZozor.x = 1;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;



    int continuer = 1;
    SDL_EnableKeyRepeat(1, 1);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        if (box(positionZozor,positionmc)==0)
                    {
                       SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
                        deplacer(event,&positionZozor,&continuer);
                    }

                    else
                    {
                        SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 0));
                        deplacer(event,&positionZozor,&continuer);
                    }
        SDL_BlitSurface(bg, NULL, ecran, &positionbg);
        SDL_BlitSurface(mc,NULL,ecran,&positionmc);
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);


        SDL_Flip(ecran);

    }

    SDL_FreeSurface(zozor);
    SDL_FreeSurface(mc);
    SDL_FreeSurface(freeman);
    SDL_Quit();

    return EXIT_SUCCESS;
}

