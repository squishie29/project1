#ifndef PERSONNAGES_H_INCLUDED
#define PERSONNAGES_H_INCLUDED
typedef struct perso
{
  SDL_Surface* nom;
  char place[50];
  SDL_Rect pos;
}perso;
void init_pers(perso* zozor,SDL_Surface* ecran);
#endif
