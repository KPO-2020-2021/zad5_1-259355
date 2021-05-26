#ifndef SCENA_HH
#define SCENA_HH

#include "Prostopadl.hh"
#include "Drone.hh"

/**
 * \brief Klasa sceny
 * 
 * Klasa pozwalajaca operowac na odpowiednich figurach
 * 
 */
class scena : public Drone{

    public:
    Drone drone1;   ///< Dron nr 1
    
    Drone drone2;   ///< Dron nr 2

    void Make_Path(PzG::LaczeDoGNUPlota &Lacze, double choosen_drone, const char *Name_of_Path, double lenght_of_path, double angletemp);   ///<Funkcja rysujaca i wpisujaca do pliku trase przelotu
    
};

#endif