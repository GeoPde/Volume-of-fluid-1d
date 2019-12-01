	#ifndef MESH_H
	#define MESH_H
	
	#include "cell.h"
	
	class Mesh
	{
	public:
	    //constructeurs
	    Mesh(); //par defaut
	
	    Mesh(const Mesh &source); // par copie
	
	    //destructeur
	    ~Mesh();// DESTRUCTEUR
	    
	    // SURCHARGE D’OPERATEUR
	    // Donner la valeur de u_i^n dans maille d’indice=position
	    double operator[] (int position);
	
	    // ajout en tete en queue a une position
	    int add_end(double valeur,double centre, double dx);
	    int add_head(double valeur,double centre, double dx);
	    int add_position(int position, double center ,double valeur, double dx);// ajout a une position donnée
	    void remov_head();// retrait en tete
	    void remov_end();//retrait en queue
	    void remov_position(int position);//retirer une cellule
	    void empty(); //vider
	    //consultation
	    double consult_position(int position ) ;  //, double & valeur)const
	    double consult_h(int position ) ;
	    double consult_left(int position ) ;
	    double consult_right(int position ); 
	    int get_nbcell();
	    void refine();
	
	    private:
	    Cell *tete; // Pointeur sur la premiere cellule.
	    Cell *queue; // Pointeur sur la derniere cellule.
	    int nb_cell;// nombre cellules du maillage
	};
	
	#endif // MESH_H
	
