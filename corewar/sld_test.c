#include <SDL/SDL.h>
 void pause()

{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
int main( int argc, char* args[] ) { 
	SDL_Surface *ecran;

	SDL_Init( SDL_INIT_EVERYTHING ); 
	ecran = SDL_SetVideoMode(640, 480,32 ,SDL_HWSURFACE);
	SDL_WM_SetCaption("Brahim va encore tout efface !", NULL);
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));
	SDL_Flip(ecran);
	pause();
	SDL_Quit(); 
 
	return 0; 
}


