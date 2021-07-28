#include "p201.h"
#include "p202.h"
#include "p203.h"


typedef pair<int,int> Finalpair;




vector<Finalpair> getfinalpath(int M[R][C]){



            		
        int F[n][n];
        
        vector<mat*> W3;
        
        vector<point1*> Q3;
        
	
        	
        if(n>0){
        	point1* E = newpoint(1,1);
        	
        	Q3.push_back(E);        	
        	
        }
        
        if(n>1){
        
        
        	point1* E = newpoint(5,1);
        	
        	Q3.push_back(E);        	        
        
        
        }
        
        if(n>2){
        
        	point1* E = newpoint(10,8);
        	
        	Q3.push_back(E);           
        
        }
        
        if(n>3){
        
        	point1* E = newpoint(16,21);
        	
        	Q3.push_back(E);           
        
        }
        
        if(n>4){
        
        	point1* E = newpoint(26,7);
        	
        	Q3.push_back(E);           
        }
        
        if(n>5){
        
        	point1* E = newpoint(20,26);
        	
        	Q3.push_back(E);           
        
        
        }

        
        

      

        for(int g3 = 0; g3<n;g3++){
        	for(int g4 =0;g4<n;g4++){
        	
        			
        		
        		mat* A2 = new mat;
        		
        		
        		
        		A2->Z = findpath(M,Q3[g3],Q3[g4]);
        		
        		A2->length =  A2->Z.size() - 1;
        		
        		W3.push_back(A2);
        		
        		
        		
        		if(A2->Z.size() == 0){
        			F[g3][g4] = NAN;
        		
        		}
        		
        		else if(g3 == g4){
        		
        			F[g3][g4] = NAN;
        		}
        		
        		 
        		else {
        		
        			F[g3][g4] = A2->Z.size() - 1;
        			
        			
        			
        		}
        	}
        
        }
        

        int* D = findpro(F);
        
        vector<Finalpair> A2;
        
        if(D[0]==NAN){
        	cout << "path is not possible" << endl;
        	return A2;
        
        }
        
        
        int j = 0;
        
        
        
        for(int y3 = 0; y3<n; y3++){
        
        	
        	int r1 = D[y3];
        	
        	
        	
        	int r2 = D[y3+1];
        	
        	
        	

        	
        	int y4 = r1*n + r2;
        	
        	
        	

        	
        	vector<path1*> S2 = W3.at(y4)->Z;
        	
        	
        	
        	for(int y5 = 0; y5 <S2.size(); y5++){
        	
        		path1* U2 = S2.at(S2.size()-1-y5);
        		
        		A2.push_back(make_pair(U2->xvalue,U2->yvalue));
        		
        	
        		cout << "(" << U2->xvalue << "," <<  U2->yvalue << ")" << endl;
        		
        		
        	}
        	
        
        }
        
        
        return A2;
        

}







