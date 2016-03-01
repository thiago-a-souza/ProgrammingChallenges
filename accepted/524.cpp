/* Prime Ring Problem - 10/09/2007*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <stack>  

#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define MP(a,b) make_pair((a),(b))
#define ALL(c) (c).begin(),(c).end()
#define FOR(i,v,n) for(int i=v; i<n; i++)
#define FORD(i,v,n) for(int i=(n-1); i>=v; i--)
#define REP(i,n) FOR(i,0,n)
#define REPD(i,n) FORD(i,0,n)
#define PB push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define MAX_V 101
#define MAX_A 101
#define INF 10e9
#define PRINT(x)
const double PI = acos(-1.0);

using namespace std;

int n;
int grauPrime[17]={0,6,5,6,5,5,4,5,5,5,4,4,3,4,4,5,4};
int primes[17][6]={{},{2,4,6,10,12,16},{3,5,9,11,15},{2,4,8,10,14,16},{3,7,9,13,15},
                   {2,6,8,12,14},{5,7,11,13},{4,6,10,12,16},{3,5,9,11,15},
                   {2,4,8,10,14},{3,7,9,13},{2,6,8,12},{5,7,11},
                   {4,6,10,16},{3,5,9,15},{2,4,8,14,16},{3,7,13,15}};

void processSol(int *a){

      if(a[n-2]==2 || a[n-2]==4 || a[n-2]==6 || a[n-2]==10 || a[n-2]==12 || a[n-2]==16){
          cout << "1";
          for(int i=0; i<n-1; i++)
             cout << " " << a[i];
          cout << endl;
      }


}

void construct(int *a, int *c, int k, int *ncand){
int in_perm[17], p;

    *ncand = 0;
    if(k == 0){
      for(int i=0; i<grauPrime[1]; i++){
         if(primes[1][i] > n)
           break;
         c[*ncand] = primes[1][i];
         *ncand += 1;
      }
    }
    else{
        memset(in_perm, 0, sizeof(in_perm));
        for(int i=0; i<k; i++)
           in_perm[a[i]] = 1;
        p = a[k-1];
        for(int i=0; i<grauPrime[p]; i++){
           if(primes[p][i] > n)
              break;
           if(in_perm[primes[p][i]] == 0){
             c[*ncand] = primes[p][i];
             *ncand = *ncand + 1;
           }
        }
    }
}


void backtrack(int *a, int k){
int c[16],cand;

    if(k == n-1)
      processSol(a);
    else{
        construct(a,c,k,&cand);
        k++;
        REP(i, cand){
           a[k-1] = c[i];
           backtrack(a,k);
        }
    }
}

main(){
int a[17], ite=1;

    while(scanf("%d",&n) == 1){
         if(ite > 1)
           printf("\n");
         printf("Case %d:\n",ite);
         ite++;
         backtrack(a, 0);
         
    }

}

