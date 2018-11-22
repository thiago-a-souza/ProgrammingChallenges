#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

#define MAX 15
using namespace std;

int main(){
char current[MAX], birthdate[MAX];
int tests;
int d1, m1, y1;
int d2, m2, y2;
int age;
int t = 1;
	scanf("%d", &tests);
	while(tests--){
		scanf("%s", current);
		scanf("%s", birthdate);
		d1 = atoi(&current[0]);
		m1 = atoi(&current[3]);
		y1 = atoi(&current[6]);
		
		d2 = atoi(&birthdate[0]);
		m2 = atoi(&birthdate[3]);
		y2 = atoi(&birthdate[6]);
				
		printf("Case #%d: ",t++);
		if(y1 < y2){
		   printf("Invalid birth date\n");
		   continue;
		}
		if(y1 == y2){
		   if(m1 < m2){
		      printf("Invalid birth date\n");
		      continue;
		   } else if(m1 == m2 && d1 < d2){
		             printf("Invalid birth date\n");
		             continue;
		   }
		} 
		
		if(d1 == d2 && m1 == m2 && y1 == y2){
		   printf("0\n");
		   continue;
		} 
		
		age = y1 - y2;
		if(age > 0){
		   if(m1 < m2 || (m1 == m2 && d1 < d2))
		       age--;
		}
		if(age > 130)
		   printf("Check birth date\n");
		else 
		   printf("%d\n", age);
	}
 return 0;
}
