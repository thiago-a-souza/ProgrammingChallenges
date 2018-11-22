#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map> 
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack> 
#include <climits>

#define MAX 10000
using namespace std;

main(){
int t, len, ans, line = 1;;
char str[MAX];

		gets(str);
		t = atoi(str);
		while(t--){
		    gets(str);
		    len = strlen(str);
		    ans = 0;
		    for(int i=0; i<len; i++){
		        if(str[i] == 'a' || str[i] == 'd' || str[i] == 'g' || str[i] == 'j' ||
		           str[i] == 'm' || str[i] == 'p' || str[i] == 't' || str[i] == 'w' ||
		           str[i] == ' ')
		           ans++;
		        else if(str[i] == 'b' || str[i] == 'e' || str[i] == 'h' || str[i] == 'k' ||
		                str[i] == 'n' || str[i] == 'q' || str[i] == 'u' || str[i] == 'x')
		                ans += 2;
		        else if(str[i] == 'c' || str[i] == 'f' || str[i] == 'i' || str[i] == 'l' ||
		                str[i] == 'o' || str[i] == 'r' || str[i] == 'v' || str[i] == 'y')
		                ans += 3;
		        else if(str[i] == 's' || str[i] == 'z')
		                ans += 4;
		    }
		    printf("Case #%d: %d\n",line,ans);
		    line++;
		      
		}
}

