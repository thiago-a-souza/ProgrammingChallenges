#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

#define MAX 100
#define HONEST true
#define DISHONEST false
using namespace std;

main(){
char str[MAX];
int guess;
bool ans[11];

	while(true){
	     for(int i=1; i<=10; i++)
	         ans[i] = true;
	     while(true){
	       scanf("%d",&guess);
	       if(guess == 0)
	          return 0;
	       cin.getline(str,MAX);
	       if(strcmp(str,"right on") == 0){
	          if(ans[guess])
	            cout << "Stan may be honest" << endl;
	          else
	            cout << "Stan is dishonest" << endl;
	          break;
	       }   
	       if(strcmp(str,"too high") == 0)
              for(int i=guess; i<=10; i++)
                  ans[i] = false;
	       if(strcmp(str,"too low") == 0)
              for(int i=1; i<=guess; i++)
                 ans[i] = false;
	       
	       
	     }
	     
	     
	}

}
