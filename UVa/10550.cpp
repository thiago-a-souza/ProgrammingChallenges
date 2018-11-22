#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>

using namespace std;

main(){
int a, b, c, d;
int ans;

	while(true){
	    scanf("%d %d %d %d",&a,&b,&c,&d);
	    if(a == 0 && b == 0 && c == 0 && d == 0)
	       break;
        ans = 1080;
        if(b > a)
          ans += (40-(b-a))*9;
        else
          ans += (a-b)*9;
          
        if(c > b)
          ans += (c-b)*9;
        else
          ans += (40-(b-c))*9;
          
        if(d > c)
           ans += (40-(d-c))*9;
        else
           ans += (c-d)*9;
        printf("%d\n",ans);
        
	
	}
}

