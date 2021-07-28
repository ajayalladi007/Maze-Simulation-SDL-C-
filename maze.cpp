#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <climits>
#include <time.h>

#include <fstream>



using namespace std;







int main( int argc, char* args[] ){

	
	
	vector<string> textualMaze;
	ifstream XY("maze2.txt");
	string str;
	while (getline(XY, str))
	{
		textualMaze.push_back(str);
	}


	int A4[16][12];
	
	for(int i=0;i<12;i++){
		for(int j=0;j<16;j++){
			if((textualMaze[i][j])=='1'){
				
				A4[j][i] = 1;
			}
			
			else if(textualMaze[i][j]=='0') {
				A4[j][i] = 0;
			
			}
		}
	}
		

	SDL_Window* window = NULL;
	
	SDL_Surface* button_surface = NULL;
	SDL_Texture* button_texture = NULL;
	
	SDL_Renderer* renderer = NULL;
	
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("maze simulation",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	button_surface = SDL_LoadBMP("wall1.bmp");
	button_texture = SDL_CreateTextureFromSurface(renderer, button_surface);
	
	
	
	
			
	bool quit = false;

			
	
				
			

			
	while( !quit ){
		
		
		SDL_Event e;
		if(e.type == SDL_QUIT){
			quit = true;
		
		}
		
			

			

		for(int i=0;i<16;i++){
			for(int j=0;j<12;j++){
				if((A4[i][j])==1){
					SDL_Rect button_pos;
					button_pos.w = 40;
					button_pos.h = 40;
					button_pos.x = i*40;
					button_pos.y = j*40;
					SDL_RenderCopy(renderer, button_texture, NULL, &button_pos);
				}
			}
		}
			
			
		
		
		
		SDL_RenderPresent(renderer);						
							
						

	}

	
	SDL_DestroyTexture(button_texture);
	SDL_FreeSurface(button_surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
