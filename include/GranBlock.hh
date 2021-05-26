#pragma once

#include "Vector3.hh"
#include "matrix3.hh"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>

/**
 * \brief Klasa Drona
 * 
 * Klasa pozwalajaca operowac na figurze 
 * 
 */
class GranBlock{

	private:

	Vector3 figure[28]; /**< Pomocnicza figura ktora pozwala dzialac na prostopadloscianie i rotorach */

	public:

	GranBlock();	/**< Konstruktor poczatkowy */

    GranBlock(Vector3 tmp[28]);  /**< Konstruktor */

    double &operator()(unsigned int row, unsigned int column); ///<Odpowiednie operatory indeksowania i poruszania sie po wierzcholkach figury

    const double &operator () (unsigned int row, unsigned int column) const;	///<Odpowiednie operatory indeksowania i poruszania sie po wierzcholkach figury

    const Vector3 &operator () (unsigned int row) const;	///<Odpowiednie operatory indeksowania i poruszania sie po wierzcholkach figury

    double toradians(double angle); ///< Funkcja zmieniajaca kat na radiany

	void TurnByOZ(double angle, double &x_position, double &y_position);	///<Funkcja dokonujaca obrotu wokol osi Oz

	GranBlock Init_The_Figure(const char * StrmWe, const char * StrmWy, double num_of_peak, double scalex, double scaley, double scalez,
 	double trans_x, double trans_y, double trans_z, double angle); ///<Funkcja inicjujaca figury i odpowiednio je zmienia, obraca, wykonuje translacje i skaluje

};