#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

char str[100];
int len;

bool isPalindrome(int start, int end){
 for(int i=start, j=end, k=0; k<(end-start+1); i++, j--, k++)
     if(str[i] != str[j])
        return false;
 
 return true;
}



main(){
set<string> s;
char tmp[100];
string t;
set<string> :: iterator it;
		while(cin.getline(str,100)){
		      s.clear();
		      len = strlen(str);
		      
		      for(int i=0; i<len; i++){
		          t = str[i];
		          s.insert(t);
		      }
		      for(int i=0; i<len; i++)
		         for(int j=len-1; j>=i; j--)
		             if(isPalindrome(i,j)){
		                memset(tmp, '\0', sizeof(tmp));
		                for(int k=i, l=0; k<=j; k++, l++)
		                   tmp[l] = str[k];
		                s.insert(tmp);
		             }		             
		       cout << "The string '" << str << "' contains " << s.size() << " palindromes." << endl;         
		          
		}
}

