#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>

using namespace std;

main(){
int count = 1;
map<string, int> m;
map<string, int> m2;
string s;
char input[100];


	for(int i=97; i <= 122; i++){
	    s = (char)i;
	    m[s] = count++;
	   // cout << s << " -> " << m[s] << endl;
	}
	
	for(int i=97; i<=122; i++){
	   for(int j=i+1; j<=122; j++){
	       s = (char)i; 
	       s += (char)j;
	    m[s] = count++;
	    //cout << s << " -> " << m[s] << endl;
	   }
	}
	
	for(int i=97; i<=122; i++){
	   for(int j=i+1; j<=122; j++){
	      for(int k=j+1; k<=122; k++){
	       s = (char)i; 
	       s += (char)j;
	       s += (char)k;
	    m[s] = count++;
	  //  cout << s << " -> " << m[s] << endl;
	    }
	   }
	}
	
	for(int i=97; i<=122; i++){
	   for(int j=i+1; j<=122; j++){
	      for(int k=j+1; k<=122; k++){
	          for(int l=k+1; l<=122; l++){
	       s = (char)i; 
	       s += (char)j;
	       s += (char)k;
	       s += (char)l;
	    m[s] = count++;
	//    cout << s << " -> " << m[s] << endl;
	    }
	    }
	   }
	}
	
	for(int i=97; i<=122; i++)
	   for(int j=i+1; j<=122; j++)
	      for(int k=j+1; k<=122; k++)
	          for(int l=k+1; l<=122; l++)
	           for(int m=l+1; m<=122; m++){
	       s = (char)i; 
	       s += (char)j;
	       s += (char)k;
	       s += (char)l;
	       s += (char)m;
	     //  cout << count << " " << s << endl;
	       m2[s] = count++;

	  //  cout << s << " -> " << m[s] << endl;
	    }
	    
	   while(scanf("%s",input) != EOF){
	        if(strlen(input) == 5){
	           cout << m2[input] << endl;
	        } else {
	           cout << m[input] << endl;
	        }
	   }
	

}

