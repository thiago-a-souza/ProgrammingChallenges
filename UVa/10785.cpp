#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 1000 
#define MAXC 5
#define MAXV 21

using namespace std;

int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}


int main(){
int tests;
int n;
int freq[MAX];
int line = 1;
int cons[MAX][3], grau[MAX];
int vow[5] = {0, 20, 4, 14, 8};
int ansC[MAX], nC, ansV[MAX], nV;
bool flag; 

	memset(grau, 0, sizeof(grau));
    cons[0][grau[0]++] = 9;  cons[0][grau[0]++] = 18; 
    cons[1][grau[1]++] = 1;  cons[1][grau[1]++] = 10; cons[1][grau[1]++] = 19;
    cons[2][grau[2]++] = 2;  cons[2][grau[2]++] = 11;
    cons[3][grau[3]++] = 3;  cons[3][grau[3]++] = 12; cons[3][grau[3]++] = 21;
    cons[4][grau[4]++] = 13; cons[4][grau[4]++] = 22; 
    cons[5][grau[5]++] = 5;  cons[5][grau[5]++] = 23;
    cons[6][grau[6]++] = 6;  cons[6][grau[6]++] = 15; cons[6][grau[6]++] = 24;
    cons[7][grau[7]++] = 7;  cons[7][grau[7]++] = 16; cons[7][grau[7]++] = 25;
    cons[8][grau[8]++] = 17;

	scanf("%d",&tests);
	while(tests--){
		scanf("%d",&n);
		memset(freq, 0, sizeof(freq));
		printf("Case %d: ", line++);
		nC = 0; nV = 0;
		for(int i=0; i<n; i++){
		    if(i%2 != 0){
		       flag = true;
		       for(int ii=0; ii<9 && flag; ii++)
		          for(int jj=0; jj<grau[ii] && flag; jj++){
		             if(freq[cons[ii][jj]] < MAXC){
		                ansC[nC++] = cons[ii][jj];
		                freq[cons[ii][jj]]++;
		                flag = false;
		             }
		          }		              
		    } else {
		        for(int ii=0; ii<5; ii++)
		           if(freq[vow[ii]] < MAXV){
                      ansV[nV++] = vow[ii];
		              freq[vow[ii]]++;
		              break;
		           }
		    }
		}
		qsort(ansC, nC, sizeof(int), cmp);
		qsort(ansV, nV, sizeof(int), cmp);		
		for(int i=0; i<n; i++){
		   if(i < nV)
		      printf("%c", ansV[i]+65);
		   if(i < nC)
		      printf("%c", ansC[i]+65);
		}
		
		printf("\n");
	}

	return 0;
}

