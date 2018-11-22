#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>

using namespace std;

#define S1_MAX 9876543210


int main(){
long long s1, s2, s2_max, n;
int tests;
long long aux;
bool check[10], repeated;
bool first = true;

	scanf("%d", &tests);
	while(tests--){
		scanf("%llu", &n);
		if(!first)
		  printf("\n");
		first = false;
		s1 = n; 
		s2 = 1;
		s2_max = S1_MAX/n;
		while(s2 <= s2_max && s1 <= S1_MAX){
			 if(s1%s2 == 0 && s1/s2 == n){
			    repeated = false;
			    memset(check, 0, sizeof(check));
			    aux = s1;   
			    while(aux > 0){
			         if(check[aux%10] == true){
			            repeated = true;
			            break;
			         }
			         check[aux%10] = true;
			         aux = aux/10;
			    }
			    if(!repeated){			       
			       memset(check, 0, sizeof(check));
			       aux = s2;
			       while(aux > 0){
			            if(check[aux%10] == true){
			               repeated = true;
			               break;
			            }
			            check[aux%10] = true;
			            aux = aux/10;
			       }
			    } 
			    if(!repeated)
			       printf("%llu / %llu = %llu\n", s1, s2, n);
			 }
			 s1 += n;
			 s2++;
			 
		}
	
	}
		
	
	return 0;
}