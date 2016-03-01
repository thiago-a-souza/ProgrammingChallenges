/* Tour de France */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;


main(){
int f, t, tmp;
vector<int> frente, tras;
vector<double> res;
double maiordiff;

	cin >> f;
	while(f!=0){
	     cin >> t;
	     for(int i=0; i<f; i++){
	        cin >> tmp;
	        frente.push_back(tmp);
	     }
	     for(int j=0; j<t; j++){
	        cin >> tmp;
	        tras.push_back(tmp);
	     }
	     for(int i=0; i<t; i++)
	        for(int j=0; j<f; j++)
	           res.push_back(((double)tras[i]/frente[j]));
	     sort(res.begin(),res.end());
	     maiordiff=-1;
	     for(int i=res.size()-1; i>0; i--)
		if(res[i]/res[i-1] > maiordiff)
		  maiordiff = res[i]/res[i-1];
	     frente.clear();
	     tras.clear();
	     res.clear();
	     printf("%.2lf\n",maiordiff);
	     cin >> f;
	}
}
