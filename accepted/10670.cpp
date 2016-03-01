#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 10000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

typedef struct {
char name[20];
int cost;
} TAgency;


int cmp(const void *a, const void *b){ 
TAgency *x, *y;

    x = (TAgency*)a;
    y = (TAgency*)b;
    if(x->cost < y->cost)
      return -1;
    if(x->cost > y->cost)
      return 1;
    
    return strcmp(x->name, y->name);
    

}


int main(){
int tests, v1, v2;
int N, M, L;
char str[MAX];
int len, index;
int minCost, tasks;
int line = 1;
TAgency ag[MAX];

	scanf("%d\n", &tests);
	while(tests--){
	    scanf("%d %d %d\n",&N, &M, &L);
	    for(int i=0; i<L; i++){
	         cin.getline(str, MAX);
	         len = strlen(str);
	         for(index=0; index<len; index++){
	             if(str[index] == ':'){
	                ag[i].name[index] = '\0';
	                break;
	             }
	             ag[i].name[index] = str[index];
	         }
	         v1 = atoi(&str[++index]);
	         while(index < len && str[index] != ',')
	               index++;
	         v2 = atoi(&str[++index]);
	         
// 	         printf("v1 = %d, v2 = %d\n", v1, v2);
	         minCost = 0.0;
	         tasks = N;
	         while(tasks > M){
// 	               printf("tasks = %d, cost=%d\n", tasks, minCost);
	               if(tasks/2 >= M && v2 < (tasks/2)*v1 ){
	                  tasks = tasks/2;
	                  minCost += v2;
// 	                  printf("if => tasks = %d, cost=%d\n", tasks, minCost);
	               } else if(tasks > M){
	                         minCost = minCost + ((tasks - M)*v1);
	                         tasks = M;
// 	                         printf("else tasks = %d, cost=%d\n", tasks, minCost);
	               }
	         }
	         ag[i].cost = minCost;
// 	         printf("=>%s<= %d %d => %d\n\n", ag[i].name, v1, v2,minCost);       
	    }
	    qsort(ag, L, sizeof(TAgency), cmp);
	    printf("Case %d\n", line++);
	    for(int i=0; i<L; i++)
	       printf("%s %d\n", ag[i].name, ag[i].cost);
	    
	}
	return 0;
}

