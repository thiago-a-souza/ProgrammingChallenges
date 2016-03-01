#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define MAXCOINS 6
#define MAXCHANGE 1005
#define INF 2147483645

using namespace std;


int freq[MAXCOINS];
int coins[MAXCOINS] = {5, 10, 20, 50, 100, 200};
int minCoins[MAXCHANGE];

int changeDP(int n, int index){

	if(n < -500 || n > 500)
	   return INF;
    if(n <= 0 && index < 0)
       return minCoins[-n];
    if(index < 0)
       return INF;
    if(freq[index] <= 0)
       return changeDP(n, index-1);
    else {
       freq[index]--;
       int a = changeDP(n - coins[index], index);
       freq[index]++;
       int b = changeDP(n, index - 1);
       return MIN(a + 1, b);
    }
}


int main(){
int x, y;


	for(int i=0; i<MAXCHANGE; i++)
	    minCoins[i] = INF;
    minCoins[0] = 0;

	for(int i=0; i < MAXCOINS; i++){
	   for(int j=coins[i]; j < MAXCHANGE; j++){
	      minCoins[j] = MIN(minCoins[j], minCoins[j-coins[i]] + 1);
	   }
	}
    
	while(true){
        for(int i=0; i<6; i++)
            scanf("%d", &freq[i]);
        
        if(freq[0] == 0 && freq[1] == 0 && freq[2] == 0 && 
           freq[3] == 0 && freq[4] == 0 && freq[5] == 0)
           break;   
            
        scanf("%d.%d",&x,&y);
        
        x = x*100 + y;
        
        printf("%3d\n",changeDP(x,5));
            
	
	}
	return 0;
	
}