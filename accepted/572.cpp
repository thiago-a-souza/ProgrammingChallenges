/* Oil Deposits 
   Category: flood fill 
*/
#include<iostream>

#define f(i, n) for(int i=0; i<n; i++)
#define MAX 100

using namespace std;

int m, n, counter;
char buff[MAX][MAX];
int mapa[MAX][MAX];

void floodFill(int x, int y){

     if(x >= 0 && x < m && y>=0 && y<n)
        if(buff[x][y] == '@' && mapa[x][y] == 0){
           mapa[x][y] = counter;
           floodFill(x, y-1);
           floodFill(x, y+1);
           floodFill(x-1,y-1);
           floodFill(x-1,y);
           floodFill(x-1,y+1);
           floodFill(x+1,y-1);
           floodFill(x+1,y);
           floodFill(x+1,y+1);
        }
     
     
}


int main(){

    while(true){
          scanf("%d %d",&m,&n);
          if(m == 0)
             return 0;
          f(i, m)
            scanf("%s",buff[i]);
        
          for(int i=0; i<m; i++)
             for(int j=0; j<n; j++)
              mapa[i][j] = 0;
          counter = 0;
  
/*          for(int i=0; i<m; i++)
             cout << buff[i] << endl; */
          
          for(int i=0; i<m; i++)
              for(int j=0; j<n; j++)
                  if(buff[i][j] == '@' && mapa[i][j] == 0){
                     counter++;
                     floodFill(i, j);              
                  }
          cout << counter << endl;
    }
 
}

    
