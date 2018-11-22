/* The Circumference of the Circle - 05/10/2007 */
#include<iostream>
#include<cmath>

using namespace std;

#define X first
#define Y second

typedef pair<double,double> TPoint;

typedef struct {
double A, B, C;
} TLine;

typedef struct{
TPoint C;
double R;
} TBall;

/* constroi a reta do tipo ax + by + c = 0 */
/* pelo determinante (y1 - y2)x + (x2 - x1)y + x1y2 - x2y1 */
/* m = -A/B */
TLine createLine(TPoint a, TPoint b){
TLine l;

	l.A = a.Y - b.Y;
	l.B = b.X - a.X;
	l.C = a.X*b.Y - b.X*a.Y;

	return l;
}

double pointToPointDistance(TPoint a, TPoint b){

	return sqrt((b.X - a.X)*(b.X - a.X) + (b.Y - a.Y)*(b.Y - a.Y));

}

/* retorna distancia de um ponto a reta */
double lineToPointDistance(TLine l, TPoint p){
double numer, den;

	numer = l.A*p.X + l.B*p.Y + l.C;
	if( numer < 0)
	  numer = -numer;
	den = sqrt(l.A*l.A + l.B*l.B);

	return numer/den;
}

/* Retorna o ponto de intersecao entre duas retas */
/* OBS.: verificar antes se sao retas paralelas */
TPoint intersectionPoint(TLine l1, TLine l2){
double D, Dx, Dy;
TPoint p;	
	D = l1.A*l2.B - l1.B*l2.A;

	if(D == 0) // sao retas paralelas
	   return p;

	Dx = -l1.C*l2.B + l1.B*l2.C;
	Dy = -l1.A*l2.C + l1.C*l2.A;

	p.X = Dx/D;
	p.Y = Dy/D;

	return p;
}

/* Retorna a reta perpendicular em relacao a l1,
   em funcao do ponto p */
TLine perpendicularLine(TLine l1, TPoint p){
TLine l_ans;

	l_ans.A = l1.B;
	l_ans.B = -l1.A;
	l_ans.C = l1.A*p.Y - l1.B*p.X;
	
	return l_ans;
}

/* Retorna o ponto do centro da circuferencia.
   Encontra o ponto de encontro entre as retas AB e BC */
TBall circleWithThreePoints(TPoint a, TPoint b, TPoint c){
TLine l_ab, l_bc, perp_ab, perp_bc;
TPoint point, m1, m2;
TBall ball;

	l_ab = createLine(a,b);
	l_bc = createLine(b,c);

	m1.X = (a.X + b.X)/2.0;  
	m1.Y = (a.Y + b.Y)/2.0; 
	m2.X = (b.X + c.X)/2.0;  
	m2.Y = (b.Y + c.Y)/2.0;

	perp_ab = perpendicularLine(l_ab, m1);
	perp_bc = perpendicularLine(l_bc, m2);
	point = intersectionPoint(perp_ab, perp_bc);

	ball.C.X = point.X;
	ball.C.Y = point.Y;
	ball.R = pointToPointDistance(point, b);

	return ball;
}

main(){
TPoint a, b, c;
TBall ball;


	while(scanf("%lf %lf %lf %lf %lf %lf",&a.X,&a.Y,&b.X,&b.Y,&c.X,&c.Y) == 6){
	      ball = circleWithThreePoints(a,b,c);
	      printf("%.2lf\n",2.0*3.141592653589793*ball.R);
	}
}




