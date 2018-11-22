#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 150

using namespace std;

main(){
int tests, n;
char str[MAX];
bool visited[MAX];
int ans;
int line = 1;

	scanf("%d",&tests);
	while(tests--){
		scanf("%d",&n);
		memset(str, '\0', sizeof(str));
		memset(visited, false, sizeof(visited));
		scanf("%s",str);
		ans = 0;
		for(int i=0; i<n; i++){
		   if( !visited[i] && !visited[i+1] && !visited[i+2] &&
		       str[i] == '.' && str[i+1] == '.' && str[i+2] == '.'){
		      visited[i] = true; visited[i+1] = true; visited[i+2] = true;
		      ans++;
		   } else if(!visited[i] && !visited[i+1] &&
		             str[i] == '.' && str[i+1] == '.'){
		   	         visited[i] = true; visited[i+1] = true;
		   	         ans++;
		   } else if(!visited[i] && !visited[i+1] && !visited[i+1] &&
		              str[i] == '.' && str[i+1] == '#' && str[i+2] == '.' ){ 
		              visited[i] = true; visited[i+1] = true; visited[i+2] = true;
		              ans++;
		   } else if(!visited[i] && str[i] == '.'){
		             visited[i] = true;
		             ans++;
		   }
		}
		printf("Case %d: %d\n",line++,ans);
		      
	}
}

