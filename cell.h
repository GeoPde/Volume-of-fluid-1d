#ifndef CELL_H
#define CELL_H


class Cell
{
    
    
public:

    // CONSTRUCTEUR
    Cell() = default;

    Cell(double xi, double pas, double value, Cell* next=nullptr) ; // Par défaut


    Cell(const Cell &cell); // Par recopie


private :

	friend class Mesh;
    // ATTRIBUTS
    
    Cell* m_prev {nullptr};// L'adresse du suivant.
    Cell* m_next {nullptr};// L'adresse du suivant.

	double m_a{0.};
	double m_b{0.};
    double m_center{0.}; 
    double m_space{0.}; // largeur de la cellule 
    double m_uin{0.};   // valeur de u_i^n dans la cellule

};

#endif // CELL_H
