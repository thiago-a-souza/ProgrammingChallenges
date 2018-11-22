/*
Categoria: Simulação
Algoritmo: preencher array com zeros, percorrer e marcar como visitada a i-ésima posição até encontrar um i que faça com que a 2a posição do array (indice 1) seja a última visitada.
*/
#include<iostream>
#include<cstdio>
#define MAX 151

using namespace std;

int findMin(int n){
int v[MAX];
int count, last, temp_count;

     for(int i=2; i<=100000; i++){
        count = n-1; 
      //  printf("count=%d\n",count);
        for(int j=0; j<n; j++) 
            v[j] = 0;
        v[0] = 1;
        last = 0;
        temp_count = 0;
        while(count > 0){
             for(int j=1; j<n; j++){
                 if(v[j] == 0){
                     temp_count++;
                     if(temp_count == i){
                        v[j] = 1;
                        last = j;
                        count--;
                        temp_count=0;
                     }
                 }
             }
        }
       // printf("i=%d last = %d, count=%d\n",i,last,count);
        if(last == 1)
           return i;
     }
     return -1;
         

}

main(){
int n;

        while(true){
             scanf("%d",&n);
             if( n == 0)
                break;
             printf("%d\n",findMin(n));
        }

}

