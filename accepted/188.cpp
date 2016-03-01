#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>

#define MAX 10000
#define INF 999999999
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int C, n;
vector<int> w;

int calculate() {

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if((C/w[i])%n == (C/w[j])%n) {
                C = MIN((C/w[i]+1)*w[i], (C/w[j]+1)*w[j]);
                return 0;
            }
            
        }
    }
    return 1;
}


int main(){
char line[MAX];
int i, start, len, nbr, pow;
int ans, tmp;
bool flag;

	while(cin.getline(line, MAX)){
	      len = strlen(line);
	      i = 0;
	      w.clear();
	      while(i < len){
	      	    start = i;
	      	    while(i < len && line[i] >= 'a' && line[i] <= 'z')
	      	          i++;
	      	          
	      	    pow = 1; nbr = 0;
	      	    for(int j=i-1; j>=start; j--){
	      	       nbr += ((int)(line[j]) - 96)*pow;
	      	       pow = pow*32;
	      	    }
	      	    w.push_back(nbr);
	      	    while(i < len && !(line[i] >= 'a' && line[i] <= 'z'))
	      	          i++;
	      }   
	      n = w.size();
	      
	      C = INF;
	      for(int i=0; i<n; i++)
	         C = MIN(C, w[i]);    
	      
	      while(!calculate()) 
	          ;
	      
          printf("%s\n%d\n\n", line, C);
	      

	}

}

