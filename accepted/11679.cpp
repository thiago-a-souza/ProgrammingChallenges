#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int b, n;
int r[50], deben[50][3];
int visited[50];

main(){
bool yes;

		while(true){
		    scanf("%d %d",&b,&n);
		    if(b == 0 && n == 0)
		       break;
		    for(int i=1; i<=b; i++)
		        scanf("%d",&r[i]);
		    for(int i=0; i<n; i++)
		       scanf("%d %d %d",&deben[i][0], &deben[i][1], &deben[i][2]);
		    for(int i=0; i<n; i++){
		        r[deben[i][0]] = r[deben[i][0]] - deben[i][2];
		        r[deben[i][1]] = r[deben[i][1]] + deben[i][2];
		    }
		    yes = true;
		    for(int i=1; i<=b; i++)
		        if(r[i] < 0){
		           yes = false;
		           break;
		        }
		    if(yes)
		      printf("S\n");
		    else
		      printf("N\n");
		        
		    
		}
}

