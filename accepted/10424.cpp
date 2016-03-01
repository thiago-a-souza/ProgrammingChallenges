#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 1000

using namespace std;

main(){
char name1[MAX], name2[MAX];
int len1, len2, sum1, sum2, aux;

		while(cin.getline(name1, MAX)){
		     cin.getline(name2, MAX);
		     
		     len1 = strlen(name1);
		     len2 = strlen(name2);
		     
		     sum1 = 0; sum2 = 0;
		     
		     for(int i=0; i<len1; i++){
		        if(name1[i] >= 'A' && name1[i] <= 'Z')
		           sum1 += ((int)name1[i] - 64);
		        else if(name1[i] >= 'a' && name1[i] <= 'z')
		                 sum1 += ((int)name1[i] - 96);
		     }
		     
   		     for(int i=0; i<len2; i++){
		        if(name2[i] >= 'A' && name2[i] <= 'Z')
		           sum2 += ((int)name2[i] - 64);
		        else if(name2[i] >= 'a' && name2[i] <= 'z')
		                 sum2 += ((int)name2[i] - 96);
		     }
		     
		     while(sum1 > 9){
		          aux = sum1;
		          sum1 = 0;
		          while(aux > 0){
		               sum1 += aux%10;
		               aux = aux/10;
		          }
		     }

		     while(sum2 > 9){
		          aux = sum2;
		          sum2 = 0;
		          while(aux > 0){
		               sum2 += aux%10;
		               aux = aux/10;
		          }
		     }
		     
		     if(sum1 < sum2)
		        printf("%.2lf %%\n",((double)sum1/sum2)*100.0);
		     else
		        printf("%.2lf %%\n",((double)sum2/sum1)*100.0);
		     

		        
		}


}