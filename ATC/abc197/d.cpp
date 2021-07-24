#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

const double PI=3.1415926535897932384626433832795028841971; 
int n;
double x;
double y;
double x_, y_;

int main(void){
	cin >> n;
	cin >> x >> y;
	cin >> x_ >> y_;

	//calc center 
	double xc = (x + x_)/2.0;
	double yc = (y + y_)/2.0;

	//move center to (0,0)
	x -= xc;
	y -= yc;
	
	//rotate theta 
	const double theta = 2*PI/n;
	auto ansx =  cos(theta)*x - sin(theta)*y + xc;
	auto ansy =  sin(theta)*x + cos(theta)*y + yc;
	
	cout << ansx << " " << ansy << endl;
	return 0;
}
