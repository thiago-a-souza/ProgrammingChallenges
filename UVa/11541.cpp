#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

main(){
int t, len;
int nbr, line=1;
char str[300];

	scanf("%d",&t);
	while(t--){
	      scanf("%s",str);
	      len = strlen(str);
	      printf("Case %d: ",line);
	      line++;
	      for(int i=0; i<len; i++){
	          if(!(str[i] >= '0' && str[i] <= '9'))
	             continue;
	          nbr = atoi(&str[i]);
	          for(int j=0; j<nbr; j++)
	              printf("%c",str[i-1]);

	          while(i < len && str[i] >= '0' && str[i] <= '9')
	                i++;
	          
	      }
	      printf("\n");
	}

}

