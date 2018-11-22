#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>

using namespace std;

main(){
long long L, H, V, tmp, aux, val;

		while(true){
		     scanf("%llu %llu",&L,&H);
		     if(L > H){
		        tmp = L;
		        L = H;
		        H = tmp;
		     }
		     if(!L && !H)
		        break;
		     V = 1;
		     val = 1;
		     for(int i=L; i<=H; i++){
		        tmp = i;
		        aux = 0;
		        do {
		             aux++;
		             if(tmp%2 == 0)
		                tmp = tmp/2;
		             else
		                tmp = (3*tmp)+1;
		        } while(tmp != 1);
		        if(aux > V){
		           V = aux;
		           val = i;
		        }
		     }
		     printf("Between %llu and %llu, %llu generates the longest sequence of %llu values.\n",L,H,val,V);
		}

}

