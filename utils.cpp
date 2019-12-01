		#include "utils.h"
#include "cell.h"
#include "mesh.h"
#include <math.h> 
#include <iostream>
	
		
			
		// intégration de simpson
		
		double simpson( double a, double b, int n, double (*ptr)(double) )
		{
		  double h,x, Iapp0, Iapp1, Iapp2, Iapp;
		  int NN, i;
		  
		
		  // Etape 1
		  h = (b-a) / n;
		
		  // Etape 2
		  Iapp0 = ptr(a) + ptr(b);
		  Iapp1 = 0.0;
		  Iapp2 = 0.0;
		
		  // Etape 3
		  NN = n -1;
		  for (i=1; i<=NN; i++)
		    {
		      // Etape 4
		      x= a+ i*h;
		      // Etape 5
		      if ((i%2) == 0)
		        Iapp2 = Iapp2 + ptr(x);
		      else
		        Iapp1 = Iapp1 + ptr(x);
		    }
		
		  // Etape 6
		  Iapp = (Iapp0 + 2.0 * Iapp2 + 4.0 * Iapp1) * h / 3.0;
		
		  // Etape 7
		  return (Iapp);
		
		}
		
		//u0
		double uinit_sinus(double x)// definition de u0(x) creneau
		{
			
			
				return sin(x);
		
			}
		
		double uinit_creneau(double x)// definition de u0(x) creneau
		{
			
			if(x<=0)
				return 0.;
			
			else
				return 1.;
		
			}
		// fonction f
		
		double flux(double ul, double ur)
		{
			double sigma(0.);
			if (ul==ur || (ul*ul-(ur*ur))/(ul-ur)==0 ) 
				
				sigma=0.5*ul*ul;
				
			else if ( (ul*ul-ur*ur)/(ul-ur) > 0)
				
				sigma=0.5*ul*ul;
				
			else if (  (ul*ul-ur*ur)/(ul-ur) < 0)
				
				sigma=0.5*ur*ur;
			
		    return sigma;
		}
		
//Lax-Friedriech 
		
void Lax( double a, double b,double Tmax,double (*ptf)(double, double))
		{  
			int N(100);
			double dx; double dt ;
			double T(0.);
			double tmp;double ul; double uc;double ur;double cnt;
			dx=(b-a)/N;
			dt=0.25*dx;
			Mesh Maillage_prev;//temps précédent
			Mesh Maillage_maj;//temps suivant "mise a jour"
			//Mailler le domaine entre a et b
			Maillage_prev.add_head(a, dx , uinit_sinus(a));// bord gauche du domaine
			
			for (int i=1;i<=N;++i)
			{
			
			 Maillage_prev.add_position(i, a+i*dx, dx , uinit_sinus(a+i*dx));//position centre dx valeur
			
			 }
			 
			 Maillage_prev.add_end( b, dx , uinit_sinus(b));// bord droit du domaine
		     Maillage_maj.add_head(a, dx , uinit_sinus(a));// bord gauche  
		     Maillage_maj.add_end( b, dx , uinit_sinus(b));//bord droit

while(T<Tmax)	  
		{
				// Boucle Itérative en espace
		
		for (int i=1;i<Maillage_prev.get_nbcell()-1;++i)
			{
								 			     		
			ul=Maillage_prev.consult_position(i-1);
			uc=Maillage_prev.consult_position(i);
			ur=Maillage_prev.consult_position(i+1);
										
								
		    tmp=dx/dt*0.5*(ptf(ul,uc)+ptf(uc,ur))-0.5*(ul-ur);
		    dx=Maillage_prev.consult_h(i);
		    cnt=Maillage_prev.consult_left(i)+0.5*dx;
		    Maillage_maj.add_position(i,cnt,dx,tmp);
									 
	    }
						    						    
		    T+=dt;
		    //Maillage_prev.empty();
		    delete &Maillage_prev  ;
		    //Mesh M( Maillage_maj);  

	
			
}
		
	}
