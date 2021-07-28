#include "p202.h"

typedef pair<int , pair<int,int>> Ppair;





point1* newpoint(int k1 , int k2){

	point1* p1 = new point1;
	
	p1->x = k1;
	p1->y = k2;
}




int Hueristicvalue(int g1 , int g2 , point1* l){
	
	return abs(g1-l->x)+abs(g2-l->y);

}


bool inmatrix(int x,int y){

	return (x>-1 && x<R && y>-1 && y<C);

}


vector<path1*> getpath(cell M[R][C],point1* p){


	int d1 = p->x;
	int d2 = p->y;
	
	vector<path1*> Q;
	
	int j = 0;
	
	while(!(M[d1][d2].parentx == d1 && M[d1][d2].parenty == d2 )){
		
		
		
		path1* D = new path1;
		
		D->xvalue = d1;
		D->yvalue = d2;
		
		Q.push_back(D);
		
		
		int k1 = M[d1][d2].parentx;
		int k2 = M[d1][d2].parenty;
		
		d1 = k1;
		d2 = k2;
		
		j++;
	}
	


	return Q;
	
	


}





vector<path1*> findpath(int K[R][C],point1* s1 , point1* s2){

	
	

	bool obtained = false;
	
	
	
	if(s1->x == s2->x && s1->y == s2->y){
	
		
		
		vector<path1*> X;
		
		return X;
	}
	
	
	
	
	bool visited[R][C];
	cell M[R][C];
	
	for(int y1 = 0; y1<R;y1++){
		for(int y2 =0;y2<C;y2++){
			visited[y1][y2] = false;
			
			M[y1][y2].Hval = NAN;
			M[y1][y2].parentx = -1;
			M[y1][y2].parenty = -1;
		}
	}
	
	
	
	M[s1->x][s1->y].Hval = 0;
	M[s1->x][s1->y].parentx = s1->x;
	M[s1->x][s1->y].parenty = s1->y;

	
	set<Ppair> g;
	
	g.insert(make_pair(0,make_pair(s1->x,s1->y)));
	
	
	while(!g.empty()){
	
		
		
		
	
	
		Ppair Rpair = *g.begin();
		
		g.erase(g.begin());
		
		int k1 = Rpair.second.first;
		int k2 = Rpair.second.second;
		
		
		
		visited[k1][k2] = true;
		
		if(inmatrix(k1,k2-1) && K[k1][k2-1]==1){
		
			
			if(k1 == s2->x && k2-1== s2->y){
			
				M[k1][k2-1].parentx = k1;
				M[k1][k2-1].parenty = k2;
			
				vector<path1*> X = getpath(M,s2);
				
				path1* A = new path1;
	
				A->xvalue = s1->x;
				A->yvalue = s1->y;
					
				X.push_back(A);
	
				
				
				
				obtained = true;
				
				return X;
			
				
			}
			
			else if(!visited[k1][k2-1]){
			
				int d = 1 + M[k1][k2].Hval +  Hueristicvalue(k1,k2-1,s2);
				
				if(M[k1][k2-1].Hval > d ){
				
					M[k1][k2-1].Hval = d;
					M[k1][k2-1].parentx = k1;
					M[k1][k2-1].parenty = k2;
					
					g.insert(make_pair(d,make_pair(k1,k2-1)));
				
				}
			
			}
		
		}
		
		
		if(inmatrix(k1,k2+1) && K[k1][k2+1]==1){
		
			
		
			if(k1 == s2->x && k2+1== s2->y){
			
				M[k1][k2+1].parentx = k1;
				M[k1][k2+1].parenty = k2;
			
				vector<path1*> X = getpath(M,s2);
				
				obtained = true;
				
				
				path1* A = new path1;
	
				A->xvalue = s1->x;
				A->yvalue = s1->y;
					
				X.push_back(A);
	
			
				
				return X;
				
				
				
				
			
				
			}
			
			else if(!visited[k1][k2+1]){
			
				int d = 1 + M[k1][k2].Hval +  Hueristicvalue(k1,k2+1,s2);
				
				if(M[k1][k2+1].Hval > d){
				
					M[k1][k2+1].Hval = d;
					M[k1][k2+1].parentx = k1;
					M[k1][k2+1].parenty = k2;
					
					g.insert(make_pair(d,make_pair(k1,k2+1)));
				
				}
			
			}
		
		}
		
		if(inmatrix(k1+1,k2) && K[k1+1][k2]==1){
		
			
			
			
			
			if(k1+1 == s2->x && k2== s2->y){
			
				
				M[k1+1][k2].parentx = k1;
				M[k1+1][k2].parenty = k2;
			
				vector<path1*> X =  getpath(M,s2);
				
				obtained = true;
				
				path1* A = new path1;
	
				A->xvalue = s1->x;
				A->yvalue = s1->y;
					
				X.push_back(A);
	
						
				return X;
			}
			
			else if(!visited[k1+1][k2]){
			
				
			
				int d = 1 + M[k1][k2].Hval +  Hueristicvalue(k1+1,k2,s2);
				
				if(M[k1+1][k2].Hval > d ){
				
					
				
					M[k1+1][k2].Hval = d;
					M[k1+1][k2].parentx = k1;
					M[k1+1][k2].parenty = k2;
					
					g.insert(make_pair(d,make_pair(k1+1,k2)));
				
				}
			
			}
			
		}
		
		
		if(inmatrix(k1-1,k2) && K[k1-1][k2]==1){
		
			
		
			if(k1-1 == s2->x && k2== s2->y){
			
				M[k1-1][k2].parentx = k1;
				M[k1-1][k2].parenty = k2;
			
				vector<path1*> X = getpath(M,s2);
				
				obtained = true;
				
				path1* A = new path1;
	
				A->xvalue = s1->x;
				A->yvalue = s1->y;
					
				X.push_back(A);
	
				
				return X;
			}
			
			else if(!visited[k1-1][k2]){
			
				int d = 1 + M[k1][k2].Hval +  Hueristicvalue(k1-1,k2,s2);
				
				if(M[k1-1][k2].Hval > d){
				
					M[k1-1][k2].Hval = d;
					M[k1-1][k2].parentx = k1;
					M[k1-1][k2].parenty = k2;
					
					g.insert(make_pair(d,make_pair(k1-1,k2)));
				
				}
			
			}
			
		}
		
		
	}
	
	if(!obtained){
	
		vector<path1*> X;
		return X;
	}
	
	
	
}



	
	














