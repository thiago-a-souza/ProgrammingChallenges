/* Fibonacci Numbers - 15/09/2007*/
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

const int DIG = 4;
const int BASE = 10000;
const int TAM = 2048;

struct bigint{
  int v[TAM], n;
  bigint(int x = 0): n(1){
	   memset(v, 0, sizeof(v));
	   v[n++] = x; fix();
  }
  bigint(char *s): n(1){
  	memset(v, 0, sizeof(v));
  	int sign = 1;
  	while(*s && !isdigit(*s)) if(*s++ == '-') sign *= -1;
  	char *t = strdup(s), *p = t + strlen(t);
  	while(p > t){
  		*p = 0; p = max(t, p - DIG);
  		sscanf(p, "%d",&v[n]);
  		v[n++] *= sign;
  	}
  	free(t); fix();
  }
  bigint& fix(int m = 0){
  	n = max(m, n);
  	int sign = 0;
  	for(int i=1, e=0; i<=n || e && (n=i); i++){
  		v[i] += e; e = v[i]/BASE; v[i] %= BASE;
  		if(v[i]) sign = (v[i] > 0) ? 1 : -1;
  	}
  	for(int i = n-1; i > 0; i--)
  	   if(v[i]*sign < 0){ v[i] += sign*BASE; v[i+1] -= sign;}
  	   while(n && !v[n]) n--;
  	   return *this;
  }
  
  operator string() const{
  	ostringstream s; s << v[n];
  	for(int i = n - 1; i > 0; i--){
  		s.width(DIG); s.fill('0'); s << abs(v[i]);
  	}
  	return s.str();
  }
  friend ostream& operator <<(ostream& o, const bigint& x){
  	return o << (string) x;
  }
  bigint& operator +=(const bigint& x){
  	for(int i = 1; i <= x.n; i++) v[i] += x.v[i];
  	return fix(x.n);
  }
  bigint operator +(const bigint& x){ return bigint(*this) += x;}

};

main(){
bigint a, b, c;
int n;
vector<string> v;

	v.PB("0");
	v.PB("1");
	v.PB("1");
	a = bigint("1");
	b = bigint("1");
	for(int i=3; i<=4780; i++){
		c = a + b;
		a = b;
		b = c;
		v.PB((string)c);	
	}
	   
	while(scanf("%d",&n) == 1){
		cout << v[n] << endl;
	}
}


