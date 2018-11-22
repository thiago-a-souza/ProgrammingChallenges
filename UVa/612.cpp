#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 101

using namespace std;

typedef struct {
char str[MAX];
int swap;
} DNA;

bool comp(DNA a, DNA b){
     if(a.swap < b.swap)
        return true;
     return false;
}

main(){
int M, nn, mm;
DNA dna[MAX];

		scanf("%d",&M);
		while(M--){
		     scanf("%d %d", &nn, &mm);
		     
		     for(int a=0; a<mm; a++){
		        scanf("%s", dna[a].str);
		        dna[a].swap = 0;
		        for(int i=0; i<nn; i++)
		           for(int j=i+1; j<nn; j++)
		               if(dna[a].str[i] > dna[a].str[j])
		                 dna[a].swap += 1;
		     }
		     stable_sort(dna, dna+mm, comp);
		     for(int i=0; i<mm; i++)
		         printf("%s\n",dna[i].str);
		     if(M != 0)
		        printf("\n");
		}
		  

}

