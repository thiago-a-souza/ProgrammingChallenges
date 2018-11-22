/* Closest Sums - 24/07/2007 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

#define min(a,b) (a<b ? a : b)
#define INF 3200000

main(){
int n, q, tmp, a, b, c, val, caso=1;
set<int> s;
vector<int> v, soma;
vector<int> :: iterator it;

	cin >> n;
	while(n){
	     while(n--){
	          cin >> tmp;
	     	  s.insert(tmp);
	     }
	     v.assign(s.begin(),s.end());
	     for(int i=0; i<v.size()-1; i++)
	        for(int j=i+1; j<v.size(); j++)
	           soma.push_back(v[i]+v[j]);
	     sort(soma.begin(),soma.end());
//     	     for(int i=0; i<soma.size(); i++)
//	        cout << soma[i] << " ";
//	     cout << endl;
//    	     for(int i=0; i<v.size(); i++)
//	        cout << v[i] << " ";
//	     cout << endl;	     
	     cin >> q;
	     printf("Case %d:\n",caso); caso++;
	     while(q--){
	          cin >> tmp;
	          printf("Closest sum to %d is ",tmp);
	          if(soma.size()>0){
	            it = lower_bound(soma.begin(),soma.end(),tmp);
	            if(*it==tmp || it==soma.begin())
	              cout << *it;
	            else if(it==soma.end())
	                   cout << *(it-1);
	            else{
	                a=c=INF;
	                b = *it;
	                if(it-soma.begin()>0)
	                  a = *(it-1);
	                if(it-soma.begin() < soma.size())
	                  c = *(it+1);
	                val = min(abs(tmp-a),min(abs(tmp-b),abs(tmp-c)));
	                if(val == abs(tmp-a))
	                  cout << a;
	                else if(val == abs(tmp-b))
	                       cout << b;
	                else cout << c;
	            }
	            
	          }
	          else
	            cout << "0";
	          cout << ".\n";
	     }
	     v.clear(); soma.clear(); s.clear();
	     cin >> n;
	}
}


