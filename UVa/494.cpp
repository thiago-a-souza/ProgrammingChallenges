/* Kindergarten Counting Game */
/* Category: Ad Hoc */
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


main(){
char lin[1000];
bool isWord=false;
int size, count;


	while(cin.getline(lin,1000)){
	     size = strlen(lin);
	     count = 0;
		 f(i,size){
		   if((lin[i]>='a' && lin[i]<='z') || (lin[i]>='A' && lin[i]<='Z')){
		     while( i < size && ((lin[i]>='a' && lin[i]<='z') || (lin[i]>='A' && lin[i]<='Z')) )
		           i++;
		     count++;
		   }
		 }
		 cout << count << endl;
	
	}
}




