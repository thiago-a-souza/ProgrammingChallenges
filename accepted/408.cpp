#include<iostream>
#include<cstdio>
#include<set>

#define MAX 10 000 000

using namespace std;

main(){
int step, mod, ans, tot;
set<int> s;


        while(scanf("%d %d",&step,&mod) != EOF ){

             s.clear();
             ans = 0;
             tot = mod;
             for(int i=0; i<mod; i++){
                ans = (ans + step)%mod;
                //printf("ans = %d %d\n",ans,visited[ans]);
                if(s.count(ans) > 0)
                    break;
                s.insert(ans);
                tot--;
             }
             if(tot == 0)
                printf("%10d%10d    Good Choice\n\n",step, mod);             
             else
                printf("%10d%10d    Bad Choice\n\n",step, mod);
        }


}

