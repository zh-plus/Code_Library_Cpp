#include <iostream>
#include <cmath>
using namespace std;
int main() {
	const int R=6317;
	const float pi=3.14159;
	cout <<"The first city:"<<' ';
	char x[30];
	cin.getline(x,30);
	cout <<"The latitude and longitude of first city:"<<' ';
	float latitude1,longitude1;
	cin >>latitude1>>longitude1;
	cin.ignore();
	cout <<"The second city:"<<' ';
	char b[30];
	cin.getline(b,30);
	cout <<"The latitude and longitude of second city:"<<' ';
	float latitude2,longitude2;
	cin >>latitude2>>longitude2;
	float phi1,phi2,a,c,d;
	phi1=(90-latitude1)*pi/180;
	phi2=(90-latitude2)*pi/180;
	a=(longitude1-longitude2)*pi/180;
	c= sin(phi1) * sin(phi2) * cos(a) +cos(phi1) * cos(phi2);
	d=R*acos(c);
	cout <<"The distance between "<<x<<" and "<<b<<" is "<<d<<" km";

	string s;
	for (size_t i = 0, len = s[20].size(); )

	return 0;
}
