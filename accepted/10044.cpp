/* ERDOS NUMBERS */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define MAX 10000
#define BRANCO '1'
#define CINZA '2'
#define PRETO '3'
#define INF 32000

vector <int> adj[MAX];
char cor[MAX];
int d[MAX];

void BFS(int s, int limit){
register int i;
int u;
queue<int> Q;

	for(i=0;i<limit;i++){
	   cor[i]=BRANCO;
	   d[i]=INF;
	}
	cor[s]=CINZA;
	d[s]=0;
	Q.push(s);
	while(!(Q.empty())){
	      u=Q.front();
	      Q.pop();
	      for(i=0;i<adj[u].size();i++)
		  if(cor[adj[u][i]]==BRANCO){
		    cor[adj[u][i]]=CINZA;
		    d[adj[u][i]]=d[u]+1;
		    Q.push(adj[u][i]); 
		  }
	     cor[u]=PRETO;
	}
}

int main(){
register int i, j, k, r,s;
int T, P, N, contstr, cont, last;
string str;
map<string,int>names;
char ch;
vector <int> seq;

	cin >> T;
	for(i=0; i<T; i++){
	   cin >> P;
	   cin >> N;
	   contstr = 1;
	   ch = getchar();
	   for(j=0; j<P; j++){
	      ch = getchar();
	      while(ch!='\n'){
	            str = str + ch;
	            ch = getchar();
	      }
	      cont = 0;
	      last = 0;
	      for(k=0; k<str.size(); k++){
	         if(str[k]==',')
	           cont++;
	         if(cont==2 || str[k]==':'){
	            if(names[str.substr(last,k-last)]==0){
	               seq.push_back(contstr); 
	               names[str.substr(last,k-last)]=contstr++;
	            }
	            else
	               seq.push_back(names[str.substr(last,k-last)]);
	            cont = 0;
	            last = k + 2;
	         }
	         if(str[k]==':')
	            break;
	      }
	      for(k=0; k<seq.size()-1; k++)
	         for(r=k+1; r<seq.size(); r++){	
	           for(s=0; s<adj[seq[k]].size(); s++)
		       if(adj[seq[k]][s]==seq[r])
	                  s = adj[seq[k]].size()+1;
		       if(s==adj[seq[k]].size()){
		         adj[seq[k]].push_back(seq[r]);
		         adj[seq[r]].push_back(seq[k]);
		       }   
		 }
	      str.erase();
	      seq.clear();

	   }

	   BFS(names["Erdos, P."],contstr);
	   for(k=0; k<N; k++){
	    	ch = getchar();
	    	while(ch!='\n'){
	    	      str = str + ch;
	    	      ch = getchar();
	    	}
	    	if(k==0)
	    	  cout << "Scenario "<< i+1<< endl;
	    	int tmp;
	    	tmp = names[str];
	    	if(d[tmp]!=INF)
	    	  cout << str << " " << d[tmp] << endl;
	    	else
	    	  cout << str << " infinity\n";
	    	str.erase();
	    }
            for(k=0; k<contstr; k++){
	        adj[k].clear();
	        names.clear();   
	    }
	}
return 0;
}

