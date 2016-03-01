#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<queue>

#define MAX 200

using namespace std;

main(){
int n;
char st1[MAX], st2[MAX];
int len1, len2;
int id1, id2, id3, id4;

		scanf("%d\n",&n);
		while(n--){
			cin.getline(st1, MAX);
			cin.getline(st2, MAX);
			len1 = strlen(st1);
			len2 = strlen(st2);
			
			id1 = -1; id2 = -1; id3 = -1; id4 = -1;
			
			for(int i=0; i<len1; i++){
			   if(st1[i] == '<'){
			     if(id1 < 0)
			       id1 = i;
			     else
			       id3 = i;
			   } else if(st1[i] == '>'){
			             if(id2 < 0)
			                id2 = i;
			             else
			                id4 = i;
			   }
			}
			
		//	printf("==> %d %d %d %d\n",id1,id2,id3,id4);
			for(int i=0; i<len1; i++)
			   if(st1[i] != '<' && st1[i] != '>')
			      printf("%c",st1[i]);
			printf("\n");
			
			for(int i=0; i<len2-3; i++)
			   printf("%c",st2[i]);

			// s4
			for(int i=(id3+1); i<id4; i++)
			    printf("%c",st1[i]);
			// s3
			for(int i=(id2+1); i<id3; i++)
			    printf("%c",st1[i]);
			// s2
			for(int i=(id1+1); i<id2; i++)
			    printf("%c",st1[i]);
			// s5
			for(int i=(id4+1); i<len1; i++)
			    printf("%c",st1[i]);
			printf("\n");    
			   
		
		}
}

