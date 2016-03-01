/* ID Codes - 20/06/2007 */
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

main(){
char str[60];
int size, i;

	cin >> str;
	while(strcmp(str,"#")!=0){
	     size = strlen(str);	        
	     if(next_permutation(str,str+size))
	       cout << str << endl;
	     else
	       cout << "No Successor\n";
	     cin >> str;
	}
}

