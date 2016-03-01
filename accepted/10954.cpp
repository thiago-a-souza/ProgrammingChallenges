#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

main(){
int n, v, sum, tmp, tmp2;
priority_queue<int> heap;

        while(true){
             scanf("%d",&n);
             if(n == 0)
                break;
             for(int i=0; i<n; i++){
                scanf("%d",&v);
                heap.push(-v);
             }  
                          
             sum  = 0;
             while(!heap.empty()){
                  tmp = -heap.top();
                  heap.pop();
                  if(heap.empty())
                     break;
                  tmp2 = -heap.top();
                  heap.pop();
                  sum += tmp + tmp2;
                  heap.push(-(tmp + tmp2));
             }
             cout << sum << endl;
        }

}

