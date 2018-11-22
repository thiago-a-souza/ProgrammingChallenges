/* Super long sums - 19/06/2007 */
#include<iostream>

using namespace std;

#define MAX 1000001

main(){
register int i, j, k;
int m, n, sobeum, tmp;
char num1[MAX], num2[MAX];

	cin >> n;
	for(i=0; i<n; i++){
	   if(i>0)
	     cout << endl;
	   cin >> m;
	   for(j=0; j<=m; j++){
	      num1[j]='0';
	      num2[j]='0';
	   }
	   for(j=1; j<=m; j++){
	      cin >> num1[j];
	      cin >> num2[j];
	   }
	   sobeum=0;
	   for(j=m; j>=0; j--){
	      tmp = (int)num1[j]+(int)num2[j]+sobeum - 96;
	      if(tmp>9){
	        tmp = tmp%10;
	        sobeum = 1;
	      }
	      else
	        sobeum = 0;
	      num1[j]=tmp+48;
	   }
	   for(j=0; j<=m; j++)
	      if(num1[j]!='0')
	        break;
	   for(k=j; k<=m; k++)
	      cout << num1[k];
	   cout << endl;
	   
	}
}
