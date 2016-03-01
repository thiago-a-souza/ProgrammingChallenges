#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

main(){
map<string, string> m;
int test = 1;
char str[100];

	m["HELLO"] = "ENGLISH";
	m["HOLA"] = "SPANISH";
	m["HALLO"] = "GERMAN";
	m["BONJOUR"] = "FRENCH";
	m["CIAO"] = "ITALIAN";
	m["ZDRAVSTVUJTE"] = "RUSSIAN";
	
	while(true){
	     scanf("%s",str);
	     if(strcmp(str,"#") == 0)
	        break;
	     if(m.count(str) > 0)
  	       cout << "Case " << test<< ": " << m[str] << endl;
  	     else
           cout << "Case " << test<< ": UNKNOWN" << endl;  	       
	     test++;
	}
}

