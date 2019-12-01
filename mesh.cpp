#include "mesh.h"
#include"cell.h"
#include <math.h> 
	
	Mesh::Mesh() // par défaut
	{
	    tete=queue=nullptr;
	    nb_cell=0;
	
	}
	
	Mesh::Mesh(const Mesh &source) // par copie
	{
	    //initialisation
	    tete=queue=nullptr;
	    nb_cell=0;
	
	    // copie de la liste
	    auto* lecteur=source.tete;
	
	    while (lecteur!=nullptr)
	    {
	        add_end(lecteur->m_center, lecteur->m_space, lecteur->m_uin);
			lecteur=lecteur->m_next;
	
	    }
	
	}
	
	Mesh::~Mesh()
	{
	
	}
	
	// METHODES MODIFICATION
	int Mesh::add_end(double center, double dx, double valeur)
	{
	    Cell *nouveau =new Cell( center, dx, valeur);
	
	    if (nouveau == nullptr){return 1;}  // Y avait-il assez de mémoire
	
	
	    queue->m_next = nouveau; // La queue pointe sur le nouveau.
	
	    queue = nouveau;      // Le nouveau devient la queue.
	
	    if (nb_cell== 0) // Si c'est le seul maillon,
	
	        tete = nouveau;    // alors c'est aussi la tête.
	
	    ++nb_cell;
	
	    return 0;
	
	}
	
	int Mesh::add_head(double center, double dx, double valeur)//ajout en tete
	{
	    Cell * nouveau =new Cell(center, dx, valeur);
	
	    nouveau->m_next=tete;
	    tete=nouveau;
	    if(nb_cell==0)
	    {
	        queue=nouveau;
	    }
	
	    ++nb_cell;
	    
	    return 0;
	
	}
	
	int Mesh::add_position(int position, double centre , double dx, double valeur)//ajout en queue
	{
	    if (position<=0)
	        return add_head(centre, dx, valeur);
	
	    else if(position>=nb_cell)
	        return add_end(centre,dx,valeur);
	
	    else
	    {
	        Cell * nouveau=new Cell(centre, dx ,  valeur);
	        Cell * precedent =tete;
	
	
	        // on se place sur le precedent
	        for (int i = 0; i < position - 1; ++i)
	        {
	            precedent = precedent->m_next;
	        }
	        // on ajuste les pointeurs
	        nouveau->m_next=precedent->m_next;
	        precedent->m_next=nouveau;
	
	        ++nb_cell;
	
	        return 0;
	    }
	
	
	}
	
	void Mesh:: remov_head()// retrait en tete
	{
	    if (nb_cell > 0)
	    {
	        //effacement
	        Cell*a_effacer=tete;
	        tete=tete->m_next;
	        delete a_effacer;
	
	        //Ajuster la queue si 1 seule cellule
	        --nb_cell;
	        if(nb_cell == 0)
	            queue=nullptr;
	    }
	
	
	}
	
	void Mesh::remov_end()//retrait en queue
	{
	    if (nb_cell>0)
	    {
	        if (nb_cell>1)
	        {
	            delete tete;
	            queue=tete=nullptr;
	
	        }
	        else
	        {
	            //On se place sur l'avant derniere cellule
	
	            Cell *avant_dernier=tete;;
	            for(int i=0;i< nb_cell -1; ++i)
	                avant_dernier=avant_dernier->m_next;
	
	            //effacement de la cellule
	
	            delete avant_dernier->m_next;
	            avant_dernier->m_next=nullptr;
	            queue=avant_dernier;
	
	        }
	        --nb_cell;
	    }
	
	
	}
	
	void Mesh::remov_position(int position)//supprimer a une position
	{
	    if(position>=0 && position < nb_cell)
	    {
	        if (position==0)
	            remov_head();
	        else
	        {
	            // on se place sur le precedent
	
	            Cell *precedent=tete;
	            for(int i=0;i<position-1;++i)
	                precedent=precedent->m_next;
	
	            //On retire la cellule
	
	            Cell *a_effacer=precedent->m_next;
	            precedent->m_next=a_effacer->m_next;
	            delete a_effacer;
	
	            --nb_cell;
	
	        }
	    }
	}
	
	void Mesh::empty() //vider
	{
	    while (nb_cell>0)
	        remov_head();
	
	}
	
	//METHODES CONSULTATION
	
	double Mesh::consult_position(int position)
	{
		double valeur;
	    if (position < 0 && position >= nb_cell)
	
	        return 1.0;
	
	    // on se place sur la position
	
	    Cell*cible=tete;
	    for (int i = 0; i < position; ++i)
	        cible = cible->m_next;
	
	    valeur=cible->m_uin;
	
	    return valeur;
	
	
	}
	
	double  Mesh::consult_h(int position ) 
	{
		
		double pas;
	    if (position < 0 && position >= nb_cell)
	
	        return 1.0;
	
	    // on se place sur la position
	
	    Cell*cible=tete;
	    for (int i = 0; i < position; ++i)
	        cible = cible->m_next;
	 
	     pas=cible->m_space ;
	
	    return pas;
		
		
		
		
		
	}
	
	double  Mesh::consult_left(int position ) 
	{
		
		double left;
	    if (position < 0 && position >= nb_cell)
	
	        return 1.0;
	
	    // on se place sur la position
	
	    Cell*cible=tete;
	    for (int i = 0; i < position; ++i)
	        cible = cible->m_next;
	 
	     left=cible->m_a ;
	
	    return left;
		
		
		
		
		
	}
	
double  Mesh::consult_right(int position ) 
	{
		
		double right;
	    if (position < 0 && position >= nb_cell)
	
	        return 1.0;
	
	    // on se place sur la position
	
	    Cell*cible=tete;
	    for (int i = 0; i < position; ++i)
	        cible = cible->m_next;
	 
	     right=cible->m_a ;
	
	    return right;
		
			
		
	}
	
		
void refine()
{
	
	
	
	
	
}
	
	
	int Mesh::get_nbcell()
	{
		return nb_cell;
		}
	
	// SURCHARGE D’OPERATEUR
	 double Mesh:: operator[] (int pos)
	{
		double k;
		k=consult_position(pos) ;
		return k;
		}
	
	
//friend ostream & operator<<(ostream &, const maillage &)
//{
	
	
	
	
//}
