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

#include "p201.h"
#include "p202.h"
#include "p203.h"


using namespace std;

typedef pair<int,int> P1pair;







int main( int argc, char* args[] ){

	
	
	vector<string> textualMaze;
	ifstream file("src/maze1.txt");
	string str;
	
	
	while (getline(file, str))
	{
		textualMaze.push_back(str);
	}


	int A4[31][28];
	
	for(int i=0;i<31;i++){
		for(int j=0;j<28;j++){
			if((textualMaze[i][j])=='|'){
				
				A4[i][j] = 0;
			}
			
			else {
				A4[i][j] = 1;
			
			}
		}
	}
	
	vector<P1pair> L1;
	
        if(n>0){
        	
        	
        	L1.push_back(make_pair(1,1));        	
        	
        }
        
        if(n>1){
        
        
        
        	
        	L1.push_back(make_pair(5,1));        	        
        
        
        }
        
        if(n>2){
        
        	
        	
        	L1.push_back(make_pair(10,8));           
        
        }
        
        if(n>3){
        
        	
        	
        	L1.push_back(make_pair(16,21));           
        
        }
        
        if(n>4){
        
        	
        	
        	L1.push_back(make_pair(26,7));           
        }
        
        if(n>5){
        
        	
        	
        	L1.push_back(make_pair(20,26));           
        
        
        }

        
        	
		

	vector<Finalpair> E = getfinalpath(A4);
	
	
	SDL_Window* window = NULL;
	
	SDL_Surface* button_surface = NULL;
	SDL_Texture* button_texture = NULL;
	
	
	SDL_Surface* pac_surface = NULL;
	SDL_Texture* pac_texture = NULL;
	
	SDL_Surface* path_surface = NULL;
	SDL_Texture* path_texture = NULL;
	
	SDL_Surface* map_surface = NULL;
	SDL_Texture* map_texture = NULL;
	
	SDL_Surface* stone_surface = NULL;
	SDL_Texture* stone_texture = NULL;
	
	
	SDL_Renderer* renderer = NULL;
	
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Simulation of TSP",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,310,280,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	button_surface = SDL_LoadBMP("src/wall.bmp");
	button_texture = SDL_CreateTextureFromSurface(renderer, button_surface);
	
	pac_surface = SDL_LoadBMP("src/man.bmp");
	pac_texture = SDL_CreateTextureFromSurface(renderer, pac_surface);
	
	path_surface = SDL_LoadBMP("src/path.bmp");
	path_texture = SDL_CreateTextureFromSurface(renderer, path_surface);
	
	map_surface = SDL_LoadBMP("src/map.bmp");
	map_texture = SDL_CreateTextureFromSurface(renderer, map_surface);
	
	stone_surface = SDL_LoadBMP("src/stone.bmp");
	stone_texture =  SDL_CreateTextureFromSurface(renderer, stone_surface);
	
	
	
			
	bool quit = false;

			
	
	
	
	int count = 0;
				
			
	
			
	while( (!quit) && count < E.size() ){
		
		
		SDL_Event e;
		
		if(e.type == SDL_QUIT){
			quit = true;
			break;
		
		}
		
			

		SDL_RenderClear(renderer);

		for(int i=0;i<31;i++){
			for(int j=0;j<28;j++){
				if((A4[i][j])==0){
					SDL_Rect button_pos;
					button_pos.w = 10;
					button_pos.h = 10;
					button_pos.x = i*10;
					button_pos.y = j*10;
					SDL_RenderCopy(renderer, button_texture, NULL, &button_pos);
				}
				
				else {
					SDL_Rect map_rect;
					map_rect.w = 10;
					map_rect.h = 10;
					map_rect.x = i*10;
					map_rect.y = j*10;
					SDL_RenderCopy(renderer, map_texture, NULL, &map_rect);
				}
			}
			
		}
		
		for(int l1 = 0; l1<L1.size();l1++){
		
			SDL_Rect stone_rect;
			
			stone_rect.w = 10;
			stone_rect.h = 10;
			stone_rect.x = L1.at(l1).first * 10;
			stone_rect.y = L1.at(l1).second * 10;
			
			SDL_RenderCopy(renderer, stone_texture, NULL, &stone_rect);
			
		
		}
		

			
		if(E.size()==0){
			quit = true;
			
		}
		
			
		
		else{
		
		
		
			for(int m2 = 0; m2<count;m2++){
			
				SDL_Rect path_rect;
				
				path_rect.w = 10;
				path_rect.h = 10;
				path_rect.x = (E.at(m2).first)*10;
				path_rect.y = (E.at(m2).second)*10;
				
				SDL_RenderCopy(renderer, path_texture, NULL, &path_rect);

			}
			
						
			SDL_Rect pac_pos;
			pac_pos.w = 10;
			pac_pos.h = 10;
			pac_pos.x = (E.at(count).first)*10;
			pac_pos.y = (E.at(count).second)*10;
			
			SDL_RenderCopy(renderer, pac_texture, NULL, &pac_pos);
			
			count++;			
		
		
		}
		
	
		
		
		
		SDL_RenderPresent(renderer);
		
		SDL_Delay(500);						
							
	}

	
	SDL_DestroyTexture(button_texture);
	SDL_FreeSurface(button_surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
