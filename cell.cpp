	#include "cell.h"
	
	
	Cell::Cell(double xi, double pas, double value, Cell *next): m_center(xi), m_space(pas), m_uin(value), m_next(next), m_a(xi-0.5*pas), m_b(xi+0.5*pas)
	{
	
	}
	
	Cell::Cell(const Cell &cell)
	{   
		m_a=cell.m_a;
		m_b=cell.m_b;  
		m_center=cell.m_center;
	    m_space=cell.m_space;
	    m_uin=cell.m_uin;
	    m_next=cell.m_next;
	}
	
