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

    Vector3 vec_use;

    Drone drone1;   ///< Dron nr 1
    
    Drone drone2;   ///< Dron nr 2

    void Make_Path(PzG::LaczeDoGNUPlota &Lacze, double choosen_drone, const char *Name_of_Path, double lenght_of_path, double angletemp);   ///<Funkcja rysujaca i wpisujaca do pliku trase przelotu
    
    void Engage2_both(double angle1, double angle2, double x_position, double y_position, double z_position, double x_position2, double y_position2, double z_position2, const char *NamesFilesLocal1[],const char *NamesFilesLocal2[], const char *NamesFilesProper1[], const char *NamesFilesProper2[], int step);

    // void Relocate_both(Vector3 begin_position, double angle1, double angle2, double lenght_of_path1, double lenght_of_path2, PzG::LaczeDoGNUPlota &Lacze, const char *NamesFilesLocal1[], const char *NamesFilesProper1[], const char *NamesFilesLocal2[], const char *NamesFilesProper2[]);

};

#endif