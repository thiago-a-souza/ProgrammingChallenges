#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<queue>

#define MAX 100
using namespace std;

main(){
char str[MAX];
int nbr[MAX];
int ans, mul;

		while(cin.getline(str,MAX)){
		     if(strcmp(str,"___________") == 0)
		        continue;
		     for(int i=1; i<10; i++){
		        if(i == 6)
		           continue;
		        
		        if(str[i] == ' ')
		           nbr[i] = 0;
		        else if(str[i] == 'o')
		                nbr[i] = 1;
		   //     printf("%c => %d\n",str[i],nbr[i]);
		     }
		     mul = 1;
		     ans = 0;
		     for(int i=9; i>0; i--){
		        if(i == 6)
		           continue;
		        ans += nbr[i]*mul;
		        mul = mul*2;
		     }
		     printf("%c",(char)ans);
		        
		}

		

}