#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "mouvement.h"
void deplacer(SDL_Event event,SDL_Rect* pos,int* continuer)
{
switch(event.type)
        {
            case SDL_QUIT:
                *continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT: // Flèche droite
                        pos->x++;
                        break;
                    case SDLK_LEFT: // Flèche gauche
                        pos->x--;
                        break;
                    case SDLK_UP:
                        pos->y--;
                        break;
                    case SDLK_DOWN:
                        pos->y++;
                        break;
                }
                break;
            case SDL_MOUSEMOTION:
                {
                    pos->x = event.motion.x;
                }
                break;
        }
}