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

#define MAX 2000
using namespace std;

main(){
char str[MAX];
int len;
long long sum;
int degree, digits;
		while(true){
		     scanf("%s",str);
		     len = strlen(str);
		     if(len == 1 && str[0] == '0')
		        break;
		     sum = 0;
		     for(int i=0; i<len; i++){
		        sum += (int)(str[i] - '0');
		     }
//		     printf("sum =%llu\n",sum);
		     if(sum == 9){
		       printf("%s is a multiple of 9 and has 9-degree 1.\n",str);
		       continue;
		     } else if(sum%9 != 0){
		       printf("%s is not a multiple of 9.\n",str);
		       continue;
		     }
		     degree = 1;
		     digits = 0;
		     
		     while(true){
		          while(sum > 0){
		             digits += sum%10;
		             sum = sum/10;
		          }
		          degree++;
		          if(sum%9 != 0){
       		         printf("%s is not a multiple of 9.\n",str);
       		         break;
		          }else if(digits == 9){
		             printf("%s is a multiple of 9 and has 9-degree %d.\n",str,degree);
		             break;
		          }
   		          
		          sum = digits;
		          digits = 0;
		        
		     }
		     
		}
}