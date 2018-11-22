/* Lotto - 03/10/2007 */
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

main(){
int a[14], n;
int ite=0;

	while(true){
	     scanf("%d",&n);
	     if(n == 0)
		break;
	     if(ite != 0)
		cout << endl;
	     ite++;
	     for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);

	     for(int i=0; i<n-5; i++)
		for(int j=i+1; j<n-4; j++)
		   for(int k=j+1; k<n-3; k++)
		      for(int r=k+1; r<n-2; r++)
			 for(int s=r+1; s<n-1; s++)
			    for(int t=s+1; t<n; t++)
				printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[r],a[s],a[t]);

	
	}



}


