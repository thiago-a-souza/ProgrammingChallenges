/* Heavy Cargo - 13/06/2007 */
#include<iostream>
#include<map>
#include<string>

using namespace std;

#define MAX 202
#define INF 320000
#define min(a,b) (a<b ? a : b)
#define max(a,b) (a>b ? a : b)


int w[MAX][MAX];


void floydMaxMin(int n){
register int i, j, k;
int maior;

	for(k=1; k<=n; k++)
	   for(i=1; i<=n; i++)
	      for(j=1; j<=n; j++)
	      	  w[i][j] = max(w[i][j],min(w[i][k],w[k][j]));
	      
}

void initialize(int n){
register int i, j;

	for(i=0; i<=n; i++)
	   w[i][i]=0;
}

main(){
register int i, j;
int n, r, peso, count, city1, city2, scenario;
map<string,int> names;
string str1, str2;

	cin >> n >> r;
	scenario = 1;
	while(n!=0 && r!=0){
	     count = 1;
	     initialize(n);
	     for(i=0; i<r; i++){
	        cin >> str1;
	        cin >> str2;
	        cin >> peso;
	        if(names[str1]==0)
	          names[str1]=count++;
	        if(names[str2]==0)
	          names[str2]=count++;
	        city1=names[str1];
	        city2=names[str2];
	        w[city1][city2] = peso;
	        w[city2][city1] = peso;
	     }
	     cin >> str1;
	     cin >> str2;
	     city1 = names[str1];
	     city2 = names[str2];
	     floydMaxMin(n);

	     cout << "Scenario #" << scenario << endl;
	     cout << w[city1][city2] << " tons\n\n";
	     scenario++;
	     names.clear();
	     cin >> n >> r;
	}
}


