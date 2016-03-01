/*  Integer Inquiry - 15/09/2007 */
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


#define PB push_back
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))

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

};

main(){
bigint a, b;
char str[200];


	a = bigint("0");
	while(true){
		scanf("%s",str);
		if(strlen(str) == 1 && str[0] =='0')
		  break;
		b = bigint(str);
		a += b;
	}
	cout << a << endl;

}


