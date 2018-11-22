/* Graphical Editor - 30/06/2007 */
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

#define MAX 300

char map[MAX][MAX];
int sizel, sizec;
char cor, corfonte;

void show(){

	for(int i=1; i<=sizel; i++){
	   for(int j=1; j<=sizec; j++)
	      cout << map[i][j];
	   cout << endl;
	}
}

void fill(int i, int j){

	if(i>0 && j>0 && i<=sizel && j<=sizec)
	  if(map[i][j]!=cor)
	    if(map[i][j]==corfonte){
	     map[i][j] = cor;
	     fill(i-1,j-1);
	     fill(i-1,j);
	     fill(i-1,j+1);
	     fill(i,j-1);
	     fill(i,j+1);
	     fill(i+1,j-1);
	     fill(i+1,j);
	     fill(i+1,j+1);
	    }
}

int main(){
register int i, j;
int x1, x2, y1, y2, temp;
char opt, ch;
string nome;

	while(1){
	    cin >> opt;
	    if(opt=='X')
	      break;
	    switch(opt){
	    	case 'I':
	    	        cin >> sizec >> sizel;
	    		  for(i=1; i<=sizel; i++)
	    		     for(j=1; j<=sizec; j++)
	    		       map[i][j] = 'O';
	    		break;
	        case 'C':
	        	for(i=1; i<=sizel; i++)
	        	   for(j=1; j<=sizec; j++)
	        	       map[i][j] = 'O';
	        	break;
	        case 'L':
	        	cin >> y1 >> x1 >> cor;
	        	map[x1][y1] = cor;
	        	break;
	        case 'V':
	        	cin >> x1 >> y1 >> y2 >> cor;
	        	if(y1>y2){
	        	  temp = y2;
	        	  y2 = y1;
	        	  y1 = temp;
	        	}
	        	for(i=y1; i<=y2 && i<=sizel; i++)
	        	   map[i][x1] = cor;
	        	break;
	        case 'H':
	        	cin >> x1 >> x2 >> y1 >> cor;
	        	if(x1 > x2){
	        	  temp = x2;
	        	  x2 = x1;
	        	  x1 = temp;
	        	}
	        	for(i=x1; i<=x2 && i<=sizec; i++)
	        	      map[y1][i] = cor;
	        	break;
	        case 'K':
	        	cin >> x1 >> y1 >> x2 >> y2 >> cor;
	        	if(x1>x2){
	        	  temp = x1;
	        	  x1 = x2;
	        	  x2 = temp;
	        	  temp = y1;
	        	  y1 = y2;
	        	  y2 = temp;
	        	}
	        	else if(x1==x2 && y1>y2){
	        	        temp = y1;
	        	        y1 = y2;
	        	        y2 = temp;
	        	     }
	        	for(i=y1; i<=y2 && i<=sizel; i++)
	        	    for(j=x1; j<=x2 && j<=sizec; j++)
	        	       map[i][j] = cor;
	        	break;
	        case 'F':
	        	cin >> x1 >> y1 >> cor;
	        	corfonte = map[y1][x1];
	        	fill(y1,x1);
	        	break;
	        case 'S':
			cin >> nome;
	        	cout << nome << endl;
	        	show();
	        	break;
	        default :
	        	while((ch=getchar())!='\n')
	        	  if(ch==EOF)
	        	    return 0;
	        	break;
	    }
	    
	}
	return 0;
}
