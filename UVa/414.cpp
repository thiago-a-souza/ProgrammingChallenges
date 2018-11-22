#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

using namespace std;

main(){
int N, blanks[50], min, sum;
char str[50][50];

		while(true){
		     scanf("%d\n",&N);
		     if(N == 0)
		        break;
		        
		     memset(blanks, 0, sizeof(blanks));
		        
		     for(int i=0; i<N; i++){
		        cin.getline(str[i], 50);
		     }

		     min = 25; sum = 0;
		     for(int i=0; i<N; i++){
		        for(int j=0; j<25; j++)
		           if(str[i][j] == ' ')
		              blanks[i]++;
		        sum += blanks[i];
		        if(blanks[i] < min)
		          min = blanks[i];
		     } 
		     sum = sum - min*N;
		     printf("%d\n",sum); 
		     
		}
}

