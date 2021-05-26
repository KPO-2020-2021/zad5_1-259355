#pragma once

#include "Vector3.hh"
#include "matrix3.hh"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>


class GranBlock{

	private:

	Vector3 figure[28];

	public:

	GranBlock();

    GranBlock(Vector3 tmp[28]);  

    double &operator()(unsigned int row, unsigned int column); 

    const double &operator () (unsigned int row, unsigned int column) const;

    const Vector3 &operator () (unsigned int row) const;

    double toradians(double angle);

	void TurnByOZ(double angle, double &x_position, double &y_position);

	GranBlock Init_The_Figure(const char * StrmWe, const char * StrmWy, double num_of_peak, double scalex, double scaley, double scalez,
 	double trans_x, double trans_y, double trans_z, double angle);

};