/* Globetrotter - 15/06/2007 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<map>

using namespace std;

#define RADIUS 6378 /* raio da esfera */
#define PI 3.141592653589793
#define MAX 110


double spherical_distance(double lat1,double lon1,double lat2,double lon2) {

double dlon = lon2 - lon1;
double dlat = lat2 - lat1;
double a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
double c = 2 * atan2(sqrt(a), sqrt(1-a));
double d = RADIUS* c;

return d;
} 

main(){
int cont, ct1, ct2, scenario=0;
double lati[MAX], longi[MAX], dist;
char city1[MAX], city2[MAX];
map<string,int> names;


	while((scanf("%s",city1))!=EOF){
	     cont = 1;
	     while(strcmp(city1,"#")!=0){
	          names[city1]=cont;
	          cin >> lati[cont] >> longi[cont];
	          lati[cont] = (lati[cont]*PI)/180.0;
	          longi[cont] = (longi[cont]*PI)/180.0;
	          cont++;
	          cin >> city1;
	     }
	     cin >> city1;
	     cin >> city2;
	     while(strcmp(city1,"#")!=0 || strcmp(city2,"#")!=0){
	          ct1 = names[city1];
	          ct2 = names[city2];
	          cout << city1 << " - " << city2 << endl;
	          if(ct1>0 && ct2>0 && cont>1){
	            dist =  spherical_distance(lati[ct1],longi[ct1],lati[ct2],longi[ct2]);
	            dist += 0.5;
	            dist = (int)dist;
	            printf("%d km\n",(int)dist);
	          }
	          else
	             printf("Unknown\n");
	          cin >> city1;
	          cin >> city2;
	     }
	    names.clear();
	}
}
