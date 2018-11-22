#include<cstdio>
#include<iostream>

using namespace std;

main(){
int n, k, c;
int tmp;
long long cima, baixo;
    while(true){
      scanf("%d %d",&n,&k);
      if( n==0 && k==0)
         break;
      c = n - k;
      if( c < k ){
        tmp = c;
        c = k;
        k = tmp;
      }
      cima = 1; baixo = 1;
      for(int i=n; i>c; i--){
          cima = cima*i;
          if(cima%k == 0 && k > 1){
             cima = cima/k;
             k--;
          }
      }
      
      for(int i=k; i>0; i--){
          baixo = baixo*i;
      }
      printf("%d\n",cima/baixo);
    }
}


