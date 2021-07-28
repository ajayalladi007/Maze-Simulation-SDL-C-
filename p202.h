#include <bits/stdc++.h>
using namespace std;

#define R 31

#define C 28

#define NAN INT_MAX

struct point1{

	int x;
	int y;


};


struct path1{


	int xvalue;
	int yvalue;

};


struct cell{

	int parentx;
	int parenty;
	
	int Hval;
	
	
};


point1* newpoint(int k1 , int k2);

int Hueristicvalue(int g1 , int g2 , point1* l);

bool inmatrix(int x,int y);

vector<path1*> getpath(cell M[R][C],point1* p);

vector<path1*> findpath(int K[R][C],point1* s1 , point1* s2);
