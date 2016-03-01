#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 210
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int gcd(int p, int q, int &x, int &y){
int x1,y1; /* previous coefficients */
int g;

    if (q > p)
        return( gcd(q, p, y, x) );
    if(q == 0){
       x = 1;
       y = 0;
       return(p); 
    }
    g = gcd(q, p%q, x1, y1);
    x = y1;
    y = (x1 - floor(p/q)*y1);
    
    return(g); 
}

int lcm(int x, int y){
int a, b;

	return (x*(y/gcd(x, y, a, b)));
}

int cycleLength(int *seq, int N){
int cyc[MAX], index;
int count, i, j;
int ans;
bool visited[MAX];

    memset(visited, 0, sizeof(visited));
    index = 0;
    
	for(i=0; i<N; i++){
	   if(!visited[i]){
	      count = 0;
	      j = i;
	      while(true){
	            visited[j] = true;
	            count++;
	            if(seq[j] == i)
	               break;
	            j = seq[j];
	      }
	      cyc[index++] = count;
	   }
	}
	ans = cyc[0];
	for(i=1; i<index; i++)
	    ans = lcm(ans, cyc[i]);
	   
	return ans;    

	

}

int main(){
int N, K;
int seq[MAX];
char text[MAX], aux[MAX];
int len;
int cycLength;
	while(true){
	     scanf("%d", &N);
	     if(N == 0)
	        break;
	     for(int i=0; i<N; i++){
	         scanf("%d",&seq[i]);
	         seq[i]--;
	     }
	     
	     cycLength = cycleLength(seq, N);

	    while(true){
	          scanf("%d",&K);
	          if(K == 0)
	             break;
	          getchar();
	          memset(text, '\0', sizeof(text));
	          memset(aux, '\0', sizeof(aux));
	          cin.getline(text, MAX);
	          len = strlen(text);
	          for(int i=len; i<N; i++){
	              text[i] = ' ';
	              aux[i] = ' ';
	          }
	          for(int i=0; i<K%cycLength; i++){
	              for(int j=0; j<N; j++){
	                  if(i%2 == 0)
	                     aux[seq[j]]  = text[j];
	                  else
	                     text[seq[j]] = aux[j];
	              }
	          }
	          if((K%cycLength)%2 == 0)
	             printf("%s\n", text);
	          else
	             printf("%s\n", aux); 
	    }  
	    printf("\n");    
	}
	return 0;
}

