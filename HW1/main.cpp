#include <iostream>
#include "BMP.h"
#include <cmath>

void MidpointEllipse(int a, int b){
	BMP bmpNew(800,900,false);
  bmpNew.fill_region(0, 0, 800, 900, 0, 0, 0, 0);

	int x = 0;
	int y = b;
	
	//b^2 - a^2*b + .25 * a^2
	//decision parameter of region 1 of first quadrant
	double d1 = pow(b, 2) - (pow(a,2)*b) + (0.25 * pow(a,2));

	//partial derivative of x = 2xb^2
	//partial derivative of y = 2ya^2
	//dy > dx
	//dy/dx = -(2xb^2/2ya^2)

	//
	while(pow(a,2)*(y-0.5)> pow(b,2)*(x+1)){
		if (d1 < 0){
			d1 += pow(b,2)*(2*x + 3);
		}
		else{
			d1 += pow(b,2)*(2*x + 3) + pow(a,2)*(-2*y + 2);
			y--;
		}
		x++;
		bmpNew.set_pixel(x + 400, y, 255, 255, 255, 0);
		bmpNew.set_pixel(-x + 400, y, 255, 255, 255, 0);
	}

	//decision parameter of region 2 of first quadrant
	double d2 = pow(b,2)*pow((x+0.5),2) + pow(a,2)*pow((y-1),2) - pow(a,2)*pow(b,2);
	while(y > 0){
		if (d2 < 0){
			d2 += pow(b,2)*(2*x+2) + pow(a,2)*(-2*y+3);
			x++;
		}
		else{
			d2 += pow(a,2)*(-2*y+3);
		}
		y--;
		bmpNew.set_pixel(x + 400,y, 255, 255, 255, 0);
		bmpNew.set_pixel(-x + 400, y, 255, 255, 255, 0);
	}
	
	bmpNew.write("output.bmp");
}


int main() {
	MidpointEllipse(384, 768);
	MidpointEllipse(-384, 768);


}
