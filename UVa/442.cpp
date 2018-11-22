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

#define MAX 1000

using namespace std;

main(){
map<char, pair< int, int > > mat;
stack< pair<int, int> > s;
char str[MAX], ch;
int n, len, rows, cols, ans;
pair< int, int > a, b;
bool error;


	scanf("%d\n",&n);
    for(int i=0; i<n; i++){
        ch = getchar();
        scanf("%d %d\n", &rows, &cols);
        mat[ch] = make_pair(rows, cols);
    }
    
    while(cin.getline(str,MAX)){
          len = strlen(str);
          ans = 0;
          error = false;
          for(int i=0; i<len; i++){
             if(str[i] >= 'A' && str[i] <= 'Z')
                s.push(mat[str[i]] );
             else if(str[i] == ')'){
                     if(s.size() < 2){
                        error = true;
                        printf("error\n");
                        break;
                     }
                     else {
                       b = s.top();
                       s.pop();
                       a = s.top();
                       s.pop();
                       if(a.second != b.first){
                           error = true;
                           printf("error\n");
                           break;
                       } else {
                           ans += (a.first*a.second*b.second);
                           s.push(make_pair(a.first,b.second));
                       }
                     }
             }
          }
          if(!error)
             cout  << ans << endl;

    }
	     
	        
	

}

