#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "personnages_init.h"
void init_pers(perso* zozor,SDL_Surface* ecran)
{
    zozor->nom = IMG_Load(zozor->place);
    SDL_BlitSurface(zozor->nom, NULL, ecran, &zozor->pos);

}
