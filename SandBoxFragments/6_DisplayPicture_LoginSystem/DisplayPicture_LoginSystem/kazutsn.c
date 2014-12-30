#include "header.h"

int kazutsnDesktop()
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond;

    positionFond.x          = 0;
    positionFond.y          = 0;

    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); //ecriture de l'erreur
        exit(EXIT_FAILURE); //arr�t du programme
    }

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);

    // Si l'ouverture a �chou�, on le note et on arr�te
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode video : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Desktop", NULL);

    //affichage de l'�cran
    imageDeFond = SDL_LoadBMP("Resources/desktop_gyokuro.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    desktopContent(ecran);

    //mise � jour de l'�cran avec sa nouvelle couleur
    SDL_Flip(ecran);
    pause();

    //arr�t de la SDL (lib�ration de la m�moire).
    SDL_Quit();

    return 0;
}
