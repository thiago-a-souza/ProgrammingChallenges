#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 10000

using namespace std;

typedef struct {
int bb, jj;
} TSoldier;

int cmp(const void *a, const void *b){ 
TSoldier *x, *y;

    x = (TSoldier*)a;
    y = (TSoldier*)b;
    if(x->jj < y->jj)
      return 1;
    if(x->jj > y->jj)
      return -1;
    if(x->bb > y->bb)
       return 1;
    if(x->bb < y->bb)
       return -1;
    return 0;

}


int main(){
TSoldier s[MAX];
int n, t1, t2;
int tInstructor, tMax;
int line = 1;
	while(true){
		scanf("%d",&n);
		if(n == 0)
		   break;
		for(int i=0; i<n; i++){
		   scanf("%d %d", &t1, &t2);
		   s[i].bb = t1; 
		   s[i].jj = t2;
		}
		
		qsort(s, n, sizeof(TSoldier), cmp);
	    tInstructor = 0; tMax = 0;
	    for(int i=0; i<n; i++){
	        tInstructor += s[i].bb;
	        if(tInstructor + s[i].jj > tMax)
	           tMax = tInstructor + s[i].jj;
	    }
	    
	    printf("Case %d: %d\n", line++, tMax);
	}

	return 0;
}

