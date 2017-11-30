// ConsoleApplication45.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
class A {
protected:
	float val_A;
};
class B : public A{
protected:
	float val_B;
};
class C: public B {
	float val_C, x1, x2, Des;
public:
	C(float A, float B, float C) {
		val_A = A;
		val_B = B;
		val_C = C;
	}
	void findroot(){
		Des = val_B*val_B - 4 * val_A*val_C;
		if (Des < 0){
			cout << "Does not have decision"<<endl;
		}
		else {
			x1 = (-val_B + sqrt(Des)) / (2 * val_A);
			x2 = (-val_B - sqrt(Des)) / (2 * val_A);
			cout << x1 << " " << x2 << endl;
		}
	}
};

int main()
{
	C lol = C(1, 3, 4);
	lol.findroot();
    return 0;
}

