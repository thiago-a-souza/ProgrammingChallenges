#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;



int main(){
int t, n;
long long max_limit;
long long sum, start, last;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n <= 0){
		  cout << "0"<< endl;
		  continue;
		}
		  
		sum = 0;
		last = n;
		max_limit = (int)sqrt(n);
		//cout <<"max_limit=" << max_limit << endl;
		for(int i=2; i<=max_limit; i++){
		    start = n/i;
		   // if((last - start)*(i-1) == n/(i-1))
		   //   sum += n/(i-1);
		   // else
		      sum += (last - start)*(i-1) + n/(i-1);
		    last = start ;
		   
		}
		start = n/(max_limit+1);
		if(n/max_limit == max_limit)
		    sum += n/max_limit;
		else 
		    sum += (last - start)*max_limit + n/max_limit;
		cout << sum << endl;
	}
	
	return 0;
}

