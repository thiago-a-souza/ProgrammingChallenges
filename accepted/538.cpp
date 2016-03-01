/* Balancing Bank Accounts - 16/11/2007 */
/* Categoria: Sorting */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack> 
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define mp(a,b) make_pair((a),(b))
#define all(c) (c).begin(),(c).end()
#define ff(i,v,n) for(int i=v; i<n; i++)
#define f(i,n) ff(i,0,n)
#define pb push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))
#define debug(x) 

using namespace std;

typedef struct{
string nome;
int saldo;
}TPerson;

int cmp(const void *a, const void *b){
TPerson *x, *y;

	x = (TPerson*)a;
	y = (TPerson*)b;
	if(x->saldo < y->saldo)
	  return -1;
	if(x->saldo > y->saldo)
	  return 1;
	return 0;

}


main(){
map< string, int > personId;
TPerson people[20];
string tmp1, tmp2;
int n, t, id, amount;
int ite = 1;
int index, val;

	while(true){
	     scanf("%d %d",&n,&t);
	     if(!n && !t)
	        return 0;
	     personId.clear();
	     id = 0;
	     f(i,n){
	       cin >> tmp1;
	       personId[tmp1] = id;
	       people[id].nome = tmp1;
	       people[id++].saldo = 0;
	     }
	     f(i,t){
	       cin >> tmp1 >> tmp2 >> amount;
	       people[personId[tmp1]].saldo += -amount;
	       people[personId[tmp2]].saldo += amount;
	     }

	     qsort(people, id, sizeof(TPerson), cmp);
     
	     index = 0;
	     cout << "Case #" << ite << endl; ite++;
	     while(index < id){
	     	  if(people[index].saldo > 0)
	     	     break;
	     	  for(int j = id-1; j >= 0; j--){
	     	     if(people[index].saldo == 0 || people[j].saldo < 0)
	     	        break;
	     	     if(people[j].saldo == 0)
	     	        continue;
	     	     if(people[j].saldo > -people[index].saldo)
	     	       val = -people[index].saldo;
	     	     else
	     	       val = people[j].saldo;
	     	     people[j].saldo -= val;
	     	     people[index].saldo += val;
	     	     cout << people[j].nome << " " << people[index].nome << " " << val << endl;
	     	  }
	     	  index++;
	     }
	     cout << endl;
	     f(i,n){
	       people[i].saldo = 0;
	       people[i].nome = "";
	     }
	}


}


