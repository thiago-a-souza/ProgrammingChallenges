#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define MAX 1000
#define INF 9999999

using namespace std;

int max(int a, int b){
	if(a > b)
	   return a;
	return b;
}

int min(int a, int b){
	if(a < b)
	   return a;
	return b;
}

int distance(int x1, int y1, int x2, int y2){
int x = x1 - x2;
int y = y1 - y2;

	if(x < 0)
	   x = -x;
	if(y < 0)
	   y = -y;
	return x + y;
}

main(){
char mat[MAX][MAX];
int n, ans, tmp;
vector< pair< int, int > > threes, ones;

	while(scanf("%d",&n) != EOF){
		 for(int i=0; i<n; i++){
		    scanf("%s",mat[i]);
		 }
		 threes.clear();
		 ones.clear();
		    
		 for(int i=0; i<n; i++)
		    for(int j=0; j<n; j++){
		        if(mat[i][j] == '3')
		           threes.push_back(make_pair(i,j));
		        else if(mat[i][j] == '1')
		                ones.push_back(make_pair(i,j));
		    }
		 ans = -INF;
		 for(int i=0; i<ones.size(); i++){
		     tmp = INF;
		     for(int j=0; j<threes.size(); j++){
		        tmp = min(tmp, distance(ones[i].first, ones[i].second, 
		                                threes[j].first, threes[j].second));
		     
		     }
		     ans = max(ans, tmp);
		 
		 }
		 cout << ans << endl;
		       
		 
	}


}