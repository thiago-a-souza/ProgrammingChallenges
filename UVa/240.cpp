/* Variable Radix Huffman Encoding - 24/01/2008 */
/* Category: greedy */
/* OBS.: na fila de prioridade em caso de empate entre um novo nó e um nó de letra, o novo nó vence. Em caso de empate entre novos nós, o primeiro nó vence
*/
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

typedef pair<int,int> ii;
typedef struct{
	int value, parent, side;
} THuff;

THuff tree[100];
int freq[30], n, r, pad;
int path[30][100], grau[30];
double average;


void getPath(int lb, int index){

	if(tree[lb].parent == -1)
	   return;
	path[index][grau[index]++] = tree[lb].side;
	getPath(tree[lb].parent, index);

}

void getAverage(){
int sum=0, total_freq=0;

	memset(grau, 0, sizeof(grau));
	
	ff(i,pad,pad+n){
	  getPath(i,i);
	  sum += grau[i]*freq[i];
	  total_freq += freq[i];
	}
	average =  (double)sum/total_freq;  

}

void huffman(){
priority_queue< ii, vector<ii>, greater<ii> > q;
int lim, vl, lb, nodes;

	f(i,pad+n){
	  q.push(mp(freq[i],i+1000));//para o nó perder, em caso de empate, com um nó novo
	  tree[i].value = freq[i];
	  tree[i].parent = -1;
	}
	
	
	ff(i,pad+n,100)
	  tree[i].value = 0, tree[i].parent = -1;

	if(r == 2) 
	   lim = n -1;
	else
	   lim = (pad+n)/(r-1);
	nodes = pad + n;
	
	f(i, lim){
	  f(j, r){
		vl = q.top().first; lb = q.top().second; q.pop(); 
		if(lb >= 1000)
		  lb = lb - 1000;	  
	    tree[lb].parent = nodes;
	    tree[lb].side = j;
	    tree[nodes].value += vl;
	  }
	  q.push(mp(tree[nodes].value,nodes));
	  nodes++;
	}  
}

int howMany(){
int count, max;


	if(n - r < 0)
	   return r - n;

	if(r == 2)
	   return 0;

	count = 0;
	ff(i,r,n)
	   if(count == 0)
	     count = r-2;
	   else if(count == 1)
	           count = 0;
	   else count--;
	return count;
	
}

main(){
int ite=1;



	while(true){
		scanf("%d",&r);
		if(r == 0)
		   break;
		
		scanf("%d",&n);

		pad = howMany();
		f(i,pad)
		  freq[i] = 0;
		
		ff(i,pad,pad+n)
		   scanf("%d",&freq[i]);

		huffman();
	
		getAverage();
		printf("Set %d; average length %.2lf\n",ite,average);
		ite++;		
		ff(i,pad,pad+n){
		  printf("    %c: ",i+65-pad);
		  for(int j=grau[i]-1; j>=0; j--)
		     cout << path[i][j];
		  cout << endl;
		}
		cout << endl;
	
	}

}


