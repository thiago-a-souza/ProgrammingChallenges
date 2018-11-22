#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>

using namespace std;

main(){
long long n, v1, v2, sum;
long long digit, nbr=1; 
set<int> s;

		scanf("%llu",&n);
		while(n--){
		     scanf("%llu",&v1);
		     v2 = v1;
             s.clear();
             s.insert(v1);
             
		     while(true){
       		      sum = 0;
		          while(v2 > 0){
		               digit = v2%10;
		               sum += digit*digit;
   		               v2 = v2/10;
		          }
		          v2 = sum;
		          
		          if(sum == 1 || s.count(sum) > 0)
		             break; 
		          s.insert(sum);
		          
		     }
		     if(sum == 1)
		       printf("Case #%llu: %llu is a Happy number.\n",nbr, v1);
		     else
		       printf("Case #%llu: %llu is an Unhappy number.\n",nbr,v1);
		     nbr++;
		}

}

