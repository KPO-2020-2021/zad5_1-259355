#pragma once

#include "Prostopadl.hh"
#include "Block.hh"
#include "Vector3.hh"


class Drone: public Block, public Prostopadl
{

    private:

    Vector3 location;

    Block rotor[4];

    Block rotor_V2[4];

    public:

    Vector3 position_V1[2];

    Vector3 position_V2[2];

    Prostopadl corp[NOPOINTS];

    void Init();

    void Engage2(double angle, double x_position, double y_position, double z_position, const char *NamesFilesLocal[], const char *NamesFilesProper[]);

    void Init_position(const char * StrmWe, const char * StrmWy, double x_position, double y_position, double z_position, double angle);

    void Relocate(double drone_num, double angle, double lenght_of_path, PzG::LaczeDoGNUPlota &Lacze, const char *NamesFilesLocal[], const char *NamesFilesProper[]);


};