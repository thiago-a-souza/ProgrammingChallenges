#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>

#define MAXSIZE 20000


using namespace std;


int result[MAXSIZE][MAXSIZE];
bool solved[MAXSIZE][MAXSIZE];
map< pair< int, int>, string> mref;

void findIndex(int *r, int *c, int start, string src){
int end = src.length();
int last = start;
int pow = 1;
int i, row = 0, col = 0;

	while(last < end && src[last] >= 'A' && src[last] <= 'Z')
	     last++;

	i = last-1;
	while(i >= start){	   
	     col += ((int)src[i] - 64)*pow;
	     pow = pow * 26;
	     i--;
	}
	
	if(col > 0)
	   col--;

	start = last;
	while(last < end && src[last] >= '0' && src[last] <= 'Z')
	     last++;
	
	i = last - 1;
	pow = 1;
	while(i >= start){
	      row += ((int)src[i] - 48)*pow;
	      pow = pow * 10;
	      i--;
	}
	if(row > 0)
	   row--;
	   	
    *r = row;
    *c = col;

}

int findSolution(int x, int y){
string s;
int len, r, c;
int ans = 0;
bool flag = false;

	s = mref[make_pair(x,y)];
	len = s.length();
	for(int i=0; i<len; i++){
	   if(s[i] == '=' || s[i] == '+' || (s[i] >= '0' && s[i] <= '9'))
	      continue;
	   findIndex(&r, &c, i, s);

	   if(solved[r][c])
	      ans += result[r][c];
	   else
	      ans += findSolution(r,c);
	   while( i < len && s[i] >= 'A' && s[i] <= 'Z')
	         i++;
	}
	result[x][y] = ans;
	solved[x][y] = true;
	return ans;
}

int main(){
int tests, rows, cols;
string sheet;


	scanf("%d",&tests);
	while(tests--){
		  scanf("%d %d", &cols, &rows);
		  mref.clear();
		  for(int i=0; i<rows; i++)
		     for(int j=0; j<cols; j++){
		        cin >> sheet;
		        if(sheet[0] != '='){
		           solved[i][j] = true;
		           result[i][j] = atoi(sheet.c_str());
		        } else {
		           solved[i][j] = false;
		           mref[make_pair(i,j)] = sheet;
		        }
		     }
		     
		   for(int i=0; i<rows; i++)
		      for(int j=0; j<cols; j++)
		         if(!solved[i][j]){
		            result[i][j] = findSolution(i,j);
		         }
		
		   for(int i=0; i<rows; i++){
		      for(int j=0; j<cols; j++){
		          if(j > 0)
		             printf(" ");
		          printf("%d", result[i][j]);     
		      }
		      printf("\n");
		   }
		         

	}

}

