#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long t,a,temp,b,x,y;
	cin >> t;
	while(t--){
		cin >> a >> b >> x >> y;
		if (a<b){		//make a bigger
			temp=a;
			a=b;
			b=temp;
		}
		if(x<y){		//make x bigger
			temp=x;
			x=y;
			y=temp;
		}
		if(a>x && b>y){
			cout << "Escape is possible.\n";
			continue;
		}
		double d_a=(double)a,d_b=(double)b,d_x=(double)x,d_y=(double)y;
		
		/*
		double h = a*cos(atan(d_a/d_b));
		// cout << h <<'\n';
		double ratio = (h-(d_x/2));
		// cout << ratio <<'\n';
		ratio = (ratio/h);
		// cout << ratio <<'\n';
		double q_lim = ratio*sqrt(d_a*d_a+d_b*d_b);
		// cout << q_lim << '\n';
		*/


		double temp;
		temp=((d_b*sqrt(d_b*d_b+d_a*d_a)) - (d_x*d_b))/d_a;

		// temp = (2.0*d_x*d_y*d_b + (d_y*d_y - d_x*d_x)*(sqrt(d_x*d_x + d_y*d_y - d_b*d_b )));
		// temp = temp / (d_x*d_x + d_y*d_y);
		if((d_y-temp)<0.0000001)
			cout << "Escape is possible.\n";
		else
			cout << "Box cannot be dropped.\n";
	}
}