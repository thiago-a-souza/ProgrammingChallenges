#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

bool isPalindrome(int h, int m){

	if((h == 0 && m < 10 )||(h == 0 && m/10 == m%10))
	   return true;
	
	if(h == 0 && m/10 != m%10)
	   return false;
	if(h < 10 && m%10 == h%10)
	   return true;
	if(h < 10)
	   return false;
	if(h/10 == m%10 && h%10 == m/10)
	   return true;
	return false;
	
	
	
}

main(){
char str[10];
int n;
int h, m;

		scanf("%d",&n);
		while(n--){
		     scanf("%s",str);
		     h = atoi(&str[0]);
		     m = atoi(&str[3]);
		     while(true){
		           if(m + 1 == 60)
		              h = (h + 1)%24;
		           m = (m + 1)%60;
		           if(isPalindrome(h,m)){
		              printf("%02d:%02d\n",h,m);
		              break;
		           }
		     }
		}
}
