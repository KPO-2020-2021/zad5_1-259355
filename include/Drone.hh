#pragma once

#include "Prostopadl.hh"
#include "Block.hh"
#include "Vector3.hh"


/**
 * \brief Klasa Drona
 * 
 * Klasa pozwalajaca operowac na dronie 
 * Klasa dziedziczy po klasie Block oraz Prostopadl
 * 
 */
class Drone: public Block, public Prostopadl
{

    private:

    Block rotor[4]; /**< 4 rotory */

    Prostopadl corp[NOPOINTS]; /**< Korpus Drona */

    public:

    Vector3 position[2];    /**< Wektor przetrzymujacy wspolrzedne poczatku lotu i konca*/

    void Init(const char *NamesFilesLocal[]);   /**< Funkcja inicjujaca poczatkowego drona */

    void Engage2(double angle, double x_position, double y_position, double z_position, const char *NamesFilesLocal[], const char *NamesFilesProper[]); /**< Funkcja wykonujaca operacje na dronie obraca, inicjuje i transponuje */

    void Relocate(Vector3 begin_position,double drone_num, double angle, double lenght_of_path, PzG::LaczeDoGNUPlota &Lacze, const char *NamesFilesLocal[], const char *NamesFilesProper[]);    /**< Funkcja wykonujaca animacje lotu drona */

};