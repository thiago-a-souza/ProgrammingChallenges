/* Strategic Defense Initiative - 08/06/2007 */
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define LEN 30
#define MAX 1000

int num[MAX], p[MAX];

void printPath(int r){

	if(p[r]!=-1)
	  printPath(p[r]);
	printf("%d\n",num[r]);

}

main(){
register int i, j, k;
int seq[MAX];
int ult, n, cont;
char tmp[LEN];
bool ent;

	cin.getline(tmp,LEN);
	n = atoi(tmp);
	cin.getline(tmp,LEN);
	for(i=0; i<n; i++){
	   if(i>0)
	     cout << endl;
	   cin.getline(tmp,LEN);
	   ent = false;
	   cont = 0;
	   while(strlen(tmp)>0){
	        ent = true;
	        num[cont++] = atoi(tmp);
	        cin.getline(tmp,LEN);
	   }

	   if(ent == false)
	      cout << "Max hits: 0\n";
	   else{
	       for(j=0; j<cont; j++){
	          seq[j] = 1;
	          p[j] = -1;
	       }
	       ult = 0;
	       for(j=0; j<cont-1; j++)
	          for(k=j+1; k<cont; k++)
	             if(num[k]>num[j])
	                if(seq[j]+1 > seq[k]){
	                   seq[k] = seq[j]+1;
	   		   p[k] = j;
	   		   ult = k;
	   		}
	   	cout << "Max hits: " << seq[ult] << endl;
	   	if(seq[ult]==1)
	   	  cout << num[ult] << endl;
	   	else{
	   	  printPath(p[ult]);
	   	  cout << num[ult] << endl;
	   	}
	   }
	}	
}

