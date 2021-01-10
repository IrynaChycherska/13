#include <iostream> 
#include <iomanip> 
#include <cmath> 
#include <math.h>

#include "dod.h" 
#include "sum.h" 
#include "var.h" 
using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
	cout << "x_p = "; cin >> x_p;
	cout << "x_k = "; cin >> x_k;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << endl;
	x = x_p;
	while (x <= x_k)
	{
		sum();

		cout << x << " "
			<< s << " "
			<< atan(x) << " "
			<< n << endl;

		x += dx;
	}

	cout << "---------------------------------------------------------------------------------" << endl;

	return 0;
}
#pragma once 
namespace nsVar {
	extern int n;
	extern double x_p, x_k, x, dx, eps, a, s, R;
};
// var.cpp 
namespace nsVar {
	double x_p, x_k, x, dx, eps, a, R, s = 0;
	int n = 0;
};
// dod.h 
#pragma once 
namespace nsDod 
{
	void dod();
};
// dod.cpp 
#include "var.h"  
#include "dod.h" 

using namespace nsVar;
void nsDod::dod() 
{
	R = pow(-1,n)* pow(x,2*n+1) / 2*n+1;
	a *= R;
}
// sumà.h 
#pragma once 
namespace nsSum {
	void sum();
};
#include <math.h> 

#include "var.h" 
#include "sum.h" 
#include "dod.h" 

using namespace nsVar;
using namespace nsDod;

void nsSum::sum() {
	n = 0;
	a = x;
	s = a;
	do {
		n++;
		dod();
		s += a;
	} while (fabs(a) >= atan(x));
}
