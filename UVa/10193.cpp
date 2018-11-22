#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

#define MAX 50
using namespace std;

int gcd(int a, int b){
      if( b == 0)
         return a;
    return gcd(b,a%b);
}

int binToDec(char *str){
int nbr = 0;
int len, mul;

	len = strlen(str);
	mul = 1;
	for(int i=len-1; i>=0; i--){
	    if(str[i] == '1')
	       nbr += mul;
	    mul = mul*2;
	}
	return nbr;
}

main(){
int n, v1, v2, ncase = 1;
char s1[MAX], s2[MAX];

		scanf("%d",&n);
		while(n--){
			 scanf("%s",s1);
			 scanf("%s",s2);
			 v1 = binToDec(s1);
			 v2 = binToDec(s2);
			 if(gcd(v1,v2) > 1)
			    printf("Pair #%d: All you need is love!\n", ncase);
			 else
			    printf("Pair #%d: Love is not all you need!\n",ncase);
			 ncase++;
			
		}
		
}

