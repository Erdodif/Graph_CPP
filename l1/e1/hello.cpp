
// SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

// standard
#include <iostream>
#include <sstream>

int main( int argc, char* args[] )
{
	//
	// 1. lépés: inicializáljuk az SDL-t
	//

	// Állítsuk be a hiba Logging függvényt.
	SDL_LogSetPriority(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR);
	// a grafikus alrendszert kapcsoljuk csak be, ha gond van, akkor jelezzük és lépjünk ki
	if ( SDL_Init( SDL_INIT_VIDEO ) == -1 )
	{
		// irjuk ki a hibat es termináljon a program
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "[SDL initialization] Error during the SDL initialization: %s", SDL_GetError());
		return 1;
	}

	// Miután az SDL Init lefutott, kilépésnél fusson le az alrendszerek kikapcsolása.
	// Így akkor is lefut, ha valamilyen hiba folytán lépünk ki.
	std::atexit(SDL_Quit);

	// hozzuk létre az ablakunkat
	SDL_Window *win = nullptr;
	win = SDL_CreateWindow( "Hello SDL!",		// az ablak fejléce
							100,						// az ablak bal-felső sarkának kezdeti X koordinátája
							100,						// az ablak bal-felső sarkának kezdeti Y koordinátája
							800,						// ablak szélessége
							600,						// és magassága
							SDL_WINDOW_SHOWN);			// megjelenítési tulajdonságok


	// ha nem sikerült létrehozni az ablakot, akkor írjuk ki a hibát, amit kaptunk és lépjünk ki
	if (win == nullptr)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "[Window creation] Error during the SDL initialization: %s", SDL_GetError());
		return 1;
	}

	//
	// 3. lépés: hozzunk létre egy renderelőt, rajzolót
	//

	SDL_Renderer *ren = nullptr;
	ren = SDL_CreateRenderer(	win, // melyik ablakhoz rendeljük hozzá a renderert
							  -1,  // melyik indexű renderert inicializáljuk
							  // a -1 a harmadik paraméterben meghatározott igényeinknek megfelelő első renderelőt jelenti
							  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);	// az igényeink, azaz
	// hardveresen gyorsított és vsync-et beváró
	if (ren == nullptr)
	{
		SDL_LogError( SDL_LOG_CATEGORY_ERROR, "[Renderer creation] Error during the creation of an SDL renderer: %s", SDL_GetError() );
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}


	//
	// 3. lépés: töröljük az ablak háttérszínét, rajzoljunk egy vonalat és várjunk 2 másodpercet
	//

	// aktuális rajzolási szín legyen fekete és töröljük az aktuális rajzolási színnel az ablak kliensterületét
	SDL_SetRenderDrawColor(	ren,	// melyik renderelőnek állítjuk be az aktuális rajzolási színét
							0,		// vörös intenzitás - 8 bites előjel nélküli egész szám
							0,		// zöld intenzitás - 8 bites előjel nélküli egész szám
							0,		// kék intenzitás - 8 bites előjel nélküli egész szám
							255);	// átlátszóság - 8 bites előjel nélküli egész szám
	SDL_RenderClear(ren);

	// aktuális rajzolási szín legyen zöld és rajzoljunk ki egy vonalat
	SDL_SetRenderDrawColor(	ren,	// renderer címe, aminek a rajzolási színét be akarjuk állítani
							0,		// piros
							255,	// zöld
							0,		// kék
							255);	// átlátszatlanság

	SDL_RenderDrawLine(	ren,	// renderer címe, amivel vonalat akarunk rajzolni
						10, 10, // vonal kezdőpontjának (x,y) koordinátái
						10, 60);// vonal végpontjának (x,y) koordinátái
    SDL_RenderDrawLine(ren, 10,30,30,30);
    SDL_RenderDrawLine(ren, 30,10,30,60);

    SDL_RenderPresent(ren);
	SDL_Delay(2000);
    SDL_SetRenderDrawColor(ren,255,0,0,255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
    SDL_Delay(2000);
    SDL_SetRenderDrawColor(ren,0,255,0,255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
    SDL_Delay(2000);
    SDL_SetRenderDrawColor(ren,0,0,255,255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
    SDL_Delay(2000);

    
	// jelenítsük meg a backbuffer tartalmát
	SDL_RenderPresent(ren);

	// várjunk 2 másodpercet

	//
	// 4. lépés: lépjünk ki
	// 
	SDL_DestroyRenderer( ren );
	SDL_DestroyWindow( win );

	return 0;
}
