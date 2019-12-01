	#ifndef DEF_UTILS
	#define DEF_UTILS
	#include "cell.h"
	#include "mesh.h"
	#include <math.h> 
	
	
	
	
	//intégration
	double simpson( double a, double b, int n, double (*ptr)(double));
	
	// fonction de transport
	
	double flux(double ul, double ur);
	
	
	//Lax-Friedriech Flux
	
	void Lax(double ul, double ur, double dx, double (*ptf)(double, double));
	
	
	#endif
	
