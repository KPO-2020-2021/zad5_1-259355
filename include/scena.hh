#ifndef SCENA_HH
#define SCENA_HH

#include "Prostopadl.hh"
#include "Drone.hh"
#include <string.h>
#include <list>

const char *NamesFilesLoc_V1[] = {SZESCIAN_ZM_LOC,ROTORYLOC_1,ROTORYLOC_2,ROTORYLOC_3,ROTORYLOC_4, nullptr};
const char *NamesFilesProp_V1[] = {SZESCIAN_ZM,ROTORY_1,ROTORY_2,ROTORY_3,ROTORY_4, nullptr};

const char *NamesFilesLoc_V2[] = {SZESCIAN_ZM_LOC_V2,ROTORYLOC_1_V2,ROTORYLOC_2_V2,ROTORYLOC_3_V2,ROTORYLOC_4_V2, nullptr};
const char *NamesFilesProp_V2[] = {SZESCIAN_ZM_V2,ROTORY_1_V2,ROTORY_2_V2,ROTORY_3_V2,ROTORY_4_V2, nullptr};

/**
 * \brief Klasa sceny
 * 
 * Klasa pozwalajaca operowac na odpowiednich figurach
 * 
 */
class scena : public Drone{
    
    public:

    std::list<std::string> Obstacles;

    std::list<Prostopadl> Obstacles1;

    Drone drone1;   ///< Dron nr 1
    
    Drone drone2;   ///< Dron nr 2

    void Make_Path(PzG::LaczeDoGNUPlota &Lacze, double choosen_drone, const char *Name_of_Path, double lenght_of_path, double angletemp);   ///<Funkcja rysujaca i wpisujaca do pliku trase przelotu
    
    void make_obstacle1(PzG::LaczeDoGNUPlota &Lacze, Vector3 begin_position, Vector3 scale, char choice);

    void Init_The_Obstacle(const char * StrmWe, const char * StrmWy, double num_of_peak, Vector3 scale,
    Vector3 trans, char choice);

};


#endif