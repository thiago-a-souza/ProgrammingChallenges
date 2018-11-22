/* Contest Scoreboard */
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define MAX 101
#define MINF -320000
#define INF  32000
typedef struct{
int erro[10];
int corretos;
int totaltime;
int participa;
int id;
} cont;

cont contest[MAX];

int compare(const void *a, const void *b){
cont *x = (cont*) a;
cont *y = (cont*) b;
	if(x->corretos < y->corretos)
	  return 1;
	if(x->corretos > y->corretos)
	  return -1;
	if(x->totaltime < y->totaltime)
	  return -1;
	if(x->totaltime > y->totaltime)
	  return 1;
	if(x->id < y->id)
	  return -1;
	if(x->id > y->id)
	  return 1;
	return 0;

}

void clearBuff(){

	for(int i=0; i<MAX; i++){
	   for(int j=0; j<10; j++)
	      contest[i].erro[j]=0;
	   contest[i].corretos=0;
	   contest[i].totaltime = 0;
	   contest[i].participa = 0;
	   contest[i].id=INF;   
	}
}

main(){
register int i, j, k;
int user, probl, time, T;
string str;
char judge;
       clearBuff();
       cin >> T;       getline(cin,str);
       getline(cin,str);
       for(i=0; i<T; i++){
          clearBuff();
       	  if(i>0)
       	    cout << endl;
          getline(cin,str);
          while(str.size()!=0){
                user = atoi(str.c_str());
                for(j=0;j<str.size(); j++)
                    if(str[j]==' ')
                       break;
                probl = atoi(str.substr(j+1).c_str());
                for(k=j+1;k<str.size();k++)
                    if(str[k]==' ')
                       break;
                time = atoi(str.substr(k+1).c_str());
                for(j=k+1;j<str.size();j++)
                    if(str[j]==' ')
                       break;
                judge = str[j+1];
                contest[user].participa = 1;
                contest[user].id = user;
                if(judge=='I')
                  contest[user].erro[probl]++;
                else
                    if(judge=='C'){
                      if(contest[user].erro[probl]>=0){
                         contest[user].totaltime += contest[user].erro[probl]*20 + time;
                         contest[user].corretos++;
                      }
                      contest[user].erro[probl]=MINF;
                    }
                getline(cin,str);   
          }
          qsort(contest,MAX,sizeof(cont),compare);
          for(j=0; j<MAX; j++)
            if(contest[j].participa==1)
             cout << contest[j].id << " " << contest[j].corretos << " " << contest[j].totaltime << endl;
             else
             	break;
       }
}
