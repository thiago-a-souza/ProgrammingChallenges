#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack> 
#include <set>
#include <map>
#include <queue>

#define INF 55555

using namespace std;

void insertionSort(int *v, int a, int &len){
    if(len == 0){
       v[0] = a;
       len++;
    } else {
	   for(int i=0; i<=len; i++)
	      if(a < v[i] || i == len){
	         len++;
	         for(int j=len-1; j>i; j--)
	            v[j] = v[j-1];
	         v[i] = a;
	         return;
	     } 
	}
}

void removeElement(int *v, int position, int &len){
   
   for(int i=position; i<len; i++)
       v[i] = v[i+1];
   if(len > 0)
      len--;
}

main(){
int tests, aux, tmp, sum;
int left[1010], right[1010]; 
int szleft=0, szright;
int a, b, c, d;
int ans[20000], pos;
bool first = true;

	scanf("%d", &tests);
	while(tests--){
	     scanf("%d",&szright);
	     
	     
	     for(int i=0; i<szright; i++){
	        scanf("%d",&aux);
	        tmp = i;
	        insertionSort(right, aux, tmp);
	         	        
	     }
	    sum = 0; pos = 0; szleft = 0;
	    
         while(szright > 0){             
              a = (szright >= 1) ? right[0] : INF;
              b = (szright >= 2) ? right[1] : INF;
              c = (szright >= 4) ? right[szright-2] : INF;
              d = (szright >= 3) ? right[szright-1] : INF;
              if(szright >= 4){
                insertionSort(left, c, szleft);
                insertionSort(left, d, szleft);
                removeElement(right, szright-1, szright);
                removeElement(right, szright-1, szright); 
                if(2*b + a + d < 2*a + c + d){
                   ans[pos++] = a; ans[pos++] = b;
                   ans[pos++] = a;
                   ans[pos++] = c; ans[pos++] = d;
                   ans[pos++] = b;
                   sum += 2*b + a + d;
                } else {
                   ans[pos++] = a; ans[pos++] = d;
                   ans[pos++] = a; 
                   ans[pos++] = a; ans[pos++] = c;
                   ans[pos++] = a;   
                   sum += 2*a + c + d;
                }
              } else if(szright >= 3){
                        insertionSort(left, a, szleft);
                        insertionSort(left, b, szleft);
                        insertionSort(left, d, szleft);
                        removeElement(right, 0, szright);
                        removeElement(right, 0, szright);
                        removeElement(right, 0, szright);
                        ans[pos++] = a; ans[pos++] = b;
                        ans[pos++] = a;
                        ans[pos++] = a; ans[pos++] = d;
                        sum += b + a + d;
              } else if(szright >= 2){
                        insertionSort(left, a, szleft);
                        insertionSort(left, b, szleft);
                        removeElement(right, 0, szright);
                        removeElement(right, 0, szright);
                        ans[pos++] = a; 
                        ans[pos++] = b; 
                        sum += b;
              } else if(szright == 1){
                        insertionSort(left, a, szleft);
                        removeElement(right, 0, szright);
                        ans[pos++] = a; 
                        sum += a;
              }
         }
         if(first)
            first = false;
         else 
            printf("\n");  
         printf("%d\n",sum);
         for(int i=0; i<pos; i+=3){
             printf("%d",ans[i]);
             if(i+1 < pos)
                printf(" %d",ans[i+1]);
             printf("\n");
             if(i+2 < pos)
                printf("%d\n",ans[i+2]);
         }
         
    }
}

