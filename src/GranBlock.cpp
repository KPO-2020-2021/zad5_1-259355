#include "GranBlock.hh"

void GranBlock::TurnByOZ(double angle, double &x_position, double &y_position){

    angle = this->toradians(angle);
    
    double sn = sin(angle), cn = cos(angle);

    x_position = x_position*cn - y_position*sn;
    y_position = x_position*sn + y_position*cn; 

}

double GranBlock::toradians(double angle){
    angle = (angle * M_PI)/180;
    return angle;
}

