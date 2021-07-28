#include "p201.h"










typedef pair<int, point*> PAIR;



int findmin(int K[n]){

	int h = K[0];

	for(int j = 1; j < n; j++) {
		if(K[j]< h){
			h = K[j];
		}
	}

	return h;
}




void makerow(int K[n][n] , int i){

	for(int u = 0; u<n; u++){
		K[i][u] = NAN;
	}
	

}


void makecol(int K[n][n] , int i){

	for(int u = 0; u<n; u++){
		K[u][i] = NAN;
	}


}






int colred(int K[n][n]){

	int sum = 0;

	

	for(int y = 0; y<n ; y++){

		int S[n];

		for(int k1 = 0; k1<n; k1++){
			
			S[k1] = K[k1][y];

		}

		int d = findmin(S);

		if(d != NAN){

			sum = sum + d;

			for (int k2 = 0; k2<n; k2++){
			
				if(K[k2][y] != NAN){
				
					K[k2][y] = K[k2][y] - d;
				}
				 
			}
		}

	}

	return sum;


}






int rowred(int K[n][n]){


	int sum = 0;



	for(int y = 0; y <n ; y++){

		int d = findmin(K[y]);

		if(d != NAN){

			sum = sum + d;

			for(int h = 0; h<n; h++){
			
				
				if(K[y][h]!=NAN){
					K[y][h] = K[y][h] - d;
				
				}
				
			}
		}
		
	}

	return sum;

}


int reducedcost(int K[n][n]){

	int k1 = rowred(K);
	int k2 = colred(K);

	return k1 + k2;

}



point* newpoint(int R[n][n],vector<pair<int,int>> const &path ,int r, int p,int k){


	point* p1 = new point;
	
	p1->path = path;
	
	int P[n][n];
	
	
	for(int k1 = 0;k1<n;k1++){
		for(int k2 =0;k2<n;k2++){
			 P[k1][k2] = R[k1][k2];
		}
	}
	
	if(p!=0){
	
		p1->path.push_back(make_pair(k,r));
		makerow(P,k);
		makecol(P,r);
	
		
	}
	
	
	P[r][0] = NAN;
	
	for(int k1 = 0;k1<n;k1++){
		for(int k2 =0;k2<n;k2++){
			p1 -> costmatrix[k1][k2] = P[k1][k2]; 
		}
	}
	
	

	p1 -> ref = r;

	p1 -> position = p;
	
	

	



}






int* findpro(int K[n][n]){


	
	
	set<PAIR> pairlist;
	
	

	vector<pair<int,int>> v;
	
	

	int b =  reducedcost(K);

	point* g = newpoint(K,v,0,0,0);
	
	g->cost = b;
	
	
	
	pairlist.insert(make_pair(b,g));
	
	
	
	
	
	
	


	while(!pairlist.empty()){


		PAIR p3 = *pairlist.begin();
		
		pairlist.erase(pairlist.begin());
		
		
		point* s = p3.second;
		
		int t = p3.first;
		
		
		

		
		
		
		int y1 = s->ref;
		
		
		
		
		
		

		


		if(s->position == n-1){
		
			vector<pair<int,int>> v1;
			
			v1 = s->path;
			
			cout << v1.size() << endl;
			
			static int T[n+1];
			
			T[0] = 0;
			
			

			for(int y = 0; y< v1.size(); y++){
			
				T[y+1] = v1[y].second;
				
				cout << v1[y].first << " ---->" << v1[y].second << endl; 
			}
			
			T[n] = 0;
			
			

			cout<<  s->cost << endl;
			
			return T;

		}
		
		

		for(int j =0 ; j < n ; j++){
		
		
			
			
			if(s->costmatrix[y1][j] != NAN){
			
				
				
				point* o = newpoint(s->costmatrix,s->path,j,s->position + 1,s->ref);
				
				
				
				o->cost = reducedcost(o->costmatrix) + s->cost + s->costmatrix[y1][j];
				
				
				
				pairlist.insert(make_pair(o->cost,o)); 
					
				
				
			}
			
		}

		

		

		
		
		
	}
	
	static int T[1];
	
	T[0] = NAN;
	
	return T;
	
	


}








