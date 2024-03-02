# include <iostream>
# include <SDL.h>
# include <SDL_image.h>
# include "defsTictactoe.h"
# include "graphicsTictactoe.h"

using namespace std;

void waitUntillPressed(){
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type ==  SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN) )
            return;
        SDL_Delay(100);
    }
}

void processClick(int x, int y, Tictactoe& game, bool &quit) {
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;
    game.move(clickedRow, clickedCol);
    game.checkEndGame();
    if(game.endGame == true){
        quit = true;
    }
}

int main(int argc, char* argv[]){

    Graphics graphics;
    graphics.init();

    Tictactoe game;
    game.init();
    graphics.render(game);

    int x,y;
    SDL_Event button;
    bool quit = false;
    while(! quit){
        SDL_PollEvent( &button);
        switch( button.type){
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState(&x, &y);
                processClick(x, y, game, quit);
                graphics.render(game);
                break;
        }
        SDL_Delay(100);
    }

    waitUntillPressed();
    graphics.quit();
    return 0;
}
