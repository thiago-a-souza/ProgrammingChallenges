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

using namespace std;

typedef struct {
char name[50];
int points, wins, losses, ties, scored, against, games;
} Team;

Team t[50];
map<string, int> tmap;


void parseString(char *s){
int len, teama, scorea, teamb, scoreb;
int pos;
char tmp[50];
bool first = true;

	len = strlen(s);
	for(int i=0; i<len; i++){
	    if(s[i] == '#'){
	       if(first){
	          first = false;
	          pos = i;
	          memset(tmp, '\0', sizeof(tmp));
	          for(int j=0; j<i; j++)
	              tmp[j] = s[j];
	          teama = tmap[tmp];
	       } else {
              memset(tmp, '\0', sizeof(tmp));
              for(int j=i+1, k=0; j<len; j++, k++)
                  tmp[k] = s[j];
              teamb = tmap[tmp];
              break;
	       }
	    } else if(s[i] == '@'){
	              memset(tmp, '\0', sizeof(tmp));
	              for(int j=pos+1, k=0; j<i; j++,k++)
	                  tmp[k] = s[j];
	              scorea = atoi(tmp);
                  
	              memset(tmp, '\0', sizeof(tmp));
	              for(int j=i+1, k=0; j<len && s[j] != '#'; j++,k++)
	                  tmp[k] = s[j];
	              scoreb = atoi(tmp);
	    }
	}
	
	t[teama].games++;
	t[teamb].games++;
	t[teama].against += scoreb;
	t[teamb].against += scorea;	
	t[teama].scored += scorea;
	t[teamb].scored += scoreb;
	
	if(scorea > scoreb){
	   t[teama].wins++;
	   t[teama].points += 3;
	   t[teamb].losses++;
	} else if(scoreb > scorea){
              t[teamb].wins++;
	          t[teamb].points += 3;
	          t[teama].losses++;
	} else {
	        t[teama].ties++;
	        t[teamb].ties++;
	        t[teama].points++;
	        t[teamb].points++;
	}
}

int cmp(const void *x, const void *y){
Team a, b;
char s1[50], s2[50];
int l1, l2;

	a = *(Team*)x;
	b = *(Team*)y;
	
	if(a.points < b.points)
	   return 1;
	if(a.points > b.points)
	   return -1;
	if(a.wins < b.wins)
	   return 1;
	if(a.wins > b.wins)
	   return -1;
	if((a.scored - a.against) < (b.scored - b.against))
	   return 1;
	if((a.scored - a.against) > (b.scored - b.against))
	   return -1;
	if(a.scored < b.scored)
	   return 1;
	if(a.scored > b.scored)
	   return -1;
	if(a.games < b.games)
	   return -1;
	if(a.games > b.games)
	   return 1;
	strcpy(s1, a.name);
	strcpy(s2, b.name);   
	l1 = strlen(s1);
	l2 = strlen(s2);

	for(int i=0; i<l1; i++)
	   s1[i] = tolower(s1[i]);
	for(int i=0; i<l2; i++)
	   s2[i] = tolower(s2[i]);
	   
	return strcmp(s1, s2);
}


main(){
int tests, n, g;
char tournament[110], str[1000];
bool first = true;

	scanf("%d\n",&tests);
	while(tests--){
	      cin.getline(tournament, 110);
	      scanf("%d\n",&n);
	      tmap.clear();
	      for(int i=0; i<n; i++){
	          memset(t[i].name, '\0', sizeof(t[i].name));
	          t[i].points = 0; t[i].wins = 0; t[i].scored = 0;
	          t[i].against = 0; t[i].games = 0;
	          t[i].losses = 0; t[i].ties = 0;
	      }
	      for(int i=0; i<n; i++){
	         cin.getline(str, 1000);
	         tmap[str] = i;
	         strcpy(t[i].name, str);
	      }
	      	      
	      scanf("%d\n",&g);
	      for(int i=0; i<g; i++){
	         cin.getline(str,1000);
	         parseString(str);
	      }
	      if(first)
	         first = false;
	      else
	         printf("\n");
	      qsort(t, n, sizeof(Team), cmp);
	     
	      printf("%s\n",tournament);
	      for(int i=0; i<n; i++)
	         printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1, t[i].name,
	          t[i].points, t[i].games, t[i].wins, t[i].ties, t[i].losses, 
	          t[i].scored-t[i].against, t[i].scored, t[i].against);
	}
}

