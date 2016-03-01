/* What Goes Up */
#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

vector<int> find_lis(vector<T> a){
vector<int> b, p(a.size());
int u, v;

	if (a.size() < 1) return b;

	b.push_back(0);
	for (int i = 1; i < (int)a.size(); i++) {
		if (a[b.back()] < a[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}

		if (u <= v && a[i] < a[b[u]]) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}

	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
	return b;
}

int main(){
register int i;
vector<int> v, result;
int tmp;

	while((scanf("%d",&tmp))!=EOF)
	     v.push_back(tmp);
	result = find_lis(v);
	cout << result.size() << endl << "-" << endl;
	for(i=0; i<result.size(); i++)
	   cout << v[result[i]] << endl;
	
	return 0;
}

