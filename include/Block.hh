#pragma once

#include "GranBlock.hh"
#include "Vector3.hh"

class Block
{
    private:

    Vector3 rotor[28];
    
    public:

    Block();

    Block(Vector3 tmp[28]);  

    double &operator()(unsigned int row, unsigned int column); 

    const double &operator () (unsigned int row, unsigned int column) const;

    const Vector3 &operator () (unsigned int row) const;

    Block InitOne (const char * StrmWe, const char * StrmWy, 
    double scalex, double scaley, double scalez, double trans_x, 
    double trans_y, double trans_z, double angle);

};