/* Counting Cells in a Blob 
   Category: flood fill
*/
#include<iostream>
#include<cstdio>

using namespace std;

char mapa[30][30];
int visit[30][30], maxi, maxi2;

void floodFill(int x, int y){
        visit[x][y] = 1;
        maxi2++;
        if(x - 1 >=0 && y - 1 >= 0 && mapa[x-1][y-1] == '1' && visit[x-1][y-1] == 0)
           floodFill(x-1,y-1);
        if(x - 1 >= 0 && mapa[x-1][y] == '1' && visit[x-1][y] == 0)
           floodFill(x-1,y);
        if(x - 1 >= 0 && y + 1 < 30 && mapa[x-1][y+1] == '1' && visit[x-1][y+1] == 0)
           floodFill(x-1,y+1);
           
        if(y - 1 >= 0 && mapa[x][y-1] == '1' && visit[x][y-1] == 0)
           floodFill(x,y-1);
        if(y + 1 < 30 && mapa[x][y+1] == '1' && visit[x][y+1] == 0)
           floodFill(x,y+1);

        if(x + 1 < 30 && y - 1 >= 0 && mapa[x+1][y-1] == '1' && visit[x+1][y-1] == 0)
           floodFill(x+1,y-1);
        if(x + 1 < 30 && mapa[x+1][y] == '1' && visit[x+1][y] == 0)
           floodFill(x+1,y);
        if(x + 1 < 30 && y + 1 < 30 && mapa[x+1][y+1] == '1' && visit[x+1][y+1] == 0)
           floodFill(x+1,y+1);

}

main(){
int n, lines;
char tmp[30];


    scanf("%d",&n);
    cin.getline(tmp,30);
    cin.getline(tmp,30);
    
    while(n--){
         
         lines = 0;
         maxi = maxi2 = 0;
         for(int i=0; i<30; i++)
             for(int j=0; j<30; j++){
                 mapa[i][j] = '0';
                 visit[i][j] = 0;        
             }
                 
         while(true){
               cin.getline(tmp,30);
               if(strlen(tmp) == 0)
                  break;
               strcpy(mapa[lines],tmp);
               lines++;
         }
         for(int i=0; i<30; i++)
             for(int j=0; j<30; j++)
                 if(visit[i][j] == 0 && mapa[i][j] == '1'){
                    floodFill(i,j);
                    if(maxi2 > maxi)
                       maxi = maxi2;
                    maxi2 = 0;
                 }
         cout << maxi << endl;
         if(n != 0)    
            cout << endl;          
    }  
}

