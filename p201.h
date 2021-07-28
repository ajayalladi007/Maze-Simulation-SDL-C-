#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <climits>
#include <set>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


#define NAN INT_MAX

#define n 6


int findmin(int K[n]);

void makerow(int K[n][n] , int i);


void makecol(int K[n][n] , int i);


int colred(int K[n][n]);


int rowred(int K[n][n]);

int reducedcost(int K[n][n]);





int* findpro(int K[n][n]);




struct point{
 


	int costmatrix[n][n];

	int position;

	int ref;

	int cost;
	
	vector<pair<int,int>> path;
	

};



point* newpoint(int R[n][n],vector<pair<int,int>> const &path ,int r, int p,int k);

