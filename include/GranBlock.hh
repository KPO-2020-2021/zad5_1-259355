#pragma once

#include "Prostopadl.hh"
#include "Block.hh"
#include "Vector3.hh"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>


class GranBlock{

	public:

    double toradians(double angle);

	void TurnByOZ(double angle, double &x_position, double &y_position);

};