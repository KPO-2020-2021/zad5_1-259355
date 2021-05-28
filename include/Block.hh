#pragma once

#include "GranBlock.hh"
#include "Vector3.hh"
#include "matrix3.hh"

/**
 * \brief Klasa Block
 * 
 * Klasa pozwalajaca operowac na Blocku - Rotorze 
 * Klasa dziedziczy po klasie GranBlock
 * 
 */
class Block : public GranBlock
{
    private:

    Vector3 rotor[28];
    
    public:

    // double vect_in_use2;

	// double vect_used2;

    Block(){};    /**< Konstruktor poczatkowy */

    // Block(Vector3 tmp[28]);     /**< Konstruktor */

    Block(const char * StrmWe, const char * StrmWy, 
    double scalex, double scaley, double scalez, double trans_x, 
    double trans_y, double trans_z, double angle);     /**< Konstruktor */

    // double &operator()(unsigned int row, unsigned int column); ///<Odpowiednie operatory indeksowania i poruszania sie po wierzcholkach Blocku

    // const double &operator () (unsigned int row, unsigned int column) const;    ///<Odpowiednie operatory indeksowania i poruszania sie po wierzcholkach Blocku

    // const Vector3 &operator () (unsigned int row) const;    ///<Odpowiednie operatory indeksowania i poruszania sie po wierzcholkach Blocku

    // Block InitOne (const char * StrmWe, const char * StrmWy, 
    // double scalex, double scaley, double scalez, double trans_x, 
    // double trans_y, double trans_z, double angle);  ///<Funkcja inicjujaca figure 

};