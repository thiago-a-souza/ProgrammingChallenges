#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 200005

using namespace std;

int a[MAX];
char S[MAX], P[MAX];
int n, m;

void prefix() {
int i = 0, j = -1;
    a[0] = -1;
    while(i < m){            
        while (j >= 0 && P[i] != P[j]) 
            j = a[j];
        i++;
        j++;
        a[i] = j;
    }
}

int kmp(){
int i = 0, j = 0;


	prefix();
    while(i < n){
        while (j >= 0 && S[i] != P[j])
                j = a[j];
        i++;
        j++;
        if(j == m) 
          return j;
    }
    return j;
	
}

main(){
int sz;
		while(scanf("%s",S) != EOF){
		     n = strlen(S);
		     m = n;
		     memset(P, '\0', sizeof(P));
		     for(int i=n-1, j=0; i>=0; i--, j++)
		         P[j] = S[i];
	
		     int idx = kmp();
		     printf("%s", S);
		     for(int i=idx; i<m; i++)
		         printf("%c",P[i]);
		     cout << endl;
		     	        
		        
		     
		}


}
