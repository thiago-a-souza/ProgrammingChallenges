#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>

#define MAX 2100
using namespace std;

typedef struct {
char country[MAX];
int count;
} TCountry;


main(){
int n, index, sz, aux;
TCountry countries[MAX];
char str[MAX], tmp[MAX];
map<string, int> cmap;

		while(scanf("%d\n",&n) != EOF){
		      for(int i=0; i<MAX; i++)
		         countries[i].count = 0;
		      cmap.clear();
		      sz = 0;
		      
		      for(int i=0; i<n; i++){
		          cin.getline(str,MAX);
		          index = 0;
		      
		          for(int i=0; i<MAX; i++)
		             if(str[i] == ' '){
		               index = i;
		               break;
		             }
		          memset(tmp, '\0', sizeof(tmp));
		          strncpy(tmp, str,index);
		          if(cmap.count(tmp) > 0)
		            index = cmap[tmp];
		          else {
		            index = sz++;
		            cmap[tmp] = index;
		            strcpy(countries[index].country, tmp);

		          }
		          
		          countries[index].count++;
		      }

			  for(int i=0; i<sz-1; i++)
			     for(int j=i+1; j<sz; j++)
			         if(strcmp(countries[i].country, countries[j].country) > 0){
			           memset(tmp, '\0', sizeof(tmp));
			           strcpy(tmp,countries[i].country);
			           strcpy(countries[i].country, countries[j].country);
			           strcpy(countries[j].country, tmp);
			           
			           aux = countries[i].count;
			           countries[i].count = countries[j].count;
			           countries[j].count = aux;
			           
			         }
		      for(int i=0; i<sz; i++)
		         printf("%s %d\n",countries[i].country, countries[i].count);
		              
		}
}

