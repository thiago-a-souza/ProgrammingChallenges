/* The Grand Dinner - 17/08/2007*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

#define pb push_back
#define all(c) (c).begin(),(c).end()

using namespace std;

typedef struct {
int num;
int index;
} TReg;


bool cmp(const TReg a, const TReg b){

	return (a.num > b.num);
}

main(){
int m, n, tmp, count;
vector<TReg> teams;
vector<TReg> tables;
vector<int> path[100];
TReg treg;
bool b;

	scanf("%d %d",&m, &n);
	while(m && n){
		for(int i=0; i<m; i++){
		   scanf("%d",&tmp);
		   treg.num = tmp;
		   treg.index = i+1;
		   teams.pb(treg);
		}
		for(int i=0; i<n; i++){
		   scanf("%d",&tmp);
		   treg.num = tmp;
		   treg.index = i+1;
		   tables.pb(treg);
		}
		sort(all(teams),cmp);
		sort(all(tables),cmp);
		b = true;
		for(int i=0; i<m; i++){
		   count = 0;
		   for(int j=0; j<n && count<teams[i].num; j++)
		      if(tables[j].num > 0){
		        count++;
		        tables[j].num--;
		        path[teams[i].index-1].pb(tables[j].index);
		      }
		   if(count != teams[i].num){
		      b = false;
		      break;
		   }
		}
		if(b){
			printf("1\n");
			for(int i=0; i<m; i++){
			   for(int j=0; j<path[i].size(); j++){
			      printf("%d",path[i][j]);
			      if(j+1 < path[i].size())
			        printf(" ");  
			   }
		        printf("\n");
			}
		}
		else printf("0\n");
		teams.clear();
		tables.clear();
		for(int i=0; i<m; i++)
		   path[i].clear();
		scanf("%d %d",&m, &n);
	}
}






