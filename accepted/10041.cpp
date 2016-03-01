/* Vito's Family */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

main(){
register int i, j;
int N, F, tmp, min;
vector <int> v;

	cin >> N;
	for(i=0; i<N; i++){
	   cin >> F;
	   for(j=0; j<F; j++){
	      cin >> tmp;
	      v.push_back(tmp);
	   }
	   sort(v.begin(),v.end());
	   min = 0;
	   for(j=0; j<v.size(); j++)
	      min += abs(v[j]-v[v.size()/2]);
	   cout << min << endl;
	   v.clear();
	}
}


