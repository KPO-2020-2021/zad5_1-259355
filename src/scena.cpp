#include "scena.hh"


/**
 * Funkcja tworzaca i dodajaca sciezke lotu drona 
 * @param PzG::LaczeDoGNUPlota &Lacze
 * @param double choosen_drone
 * @param const char *Name_of_Path
 * @param double lenght_of_path
 * @param double angletemp
 */
void scena::Make_Path(PzG::LaczeDoGNUPlota &Lacze, double choosen_drone, const char *Name_of_Path, double lenght_of_path, double angletemp){

    std::ofstream StrmWy(Name_of_Path); 

    if(!StrmWy.is_open()){
        std::cerr << std::endl
            << "Couldnt open the file: " << Name_of_Path << std::endl
            << std::endl;
    }

    drone1.position[1][0] = drone1.x_of_end(drone1.position[0][0],angletemp,lenght_of_path) ; 
    drone1.position[1][1] = drone1.y_of_end(drone1.position[0][1],angletemp,lenght_of_path) ; 

    drone2.position[1][0] = drone2.x_of_end(drone2.position[0][0],angletemp,lenght_of_path) ;
    drone2.position[1][1] = drone2.y_of_end(drone2.position[0][1],angletemp,lenght_of_path) ;

    if(choosen_drone == 1){
    StrmWy << this->drone1.position[0] << std::endl
           << this->drone1.position[0][0] << " " << this->drone1.position[0][1] << " 80" << std::endl
           << drone1.position[1][0] << " " << drone1.position[1][1] << " 80" << std::endl
           << drone1.position[1][0] << " " << drone1.position[1][1] << " 0" << std::endl;
    Lacze.DodajNazwePliku(Path_V1);
    Lacze.Rysuj();}
    else if(choosen_drone == 2){
    StrmWy << this->drone2.position[0] << std::endl
           << this->drone2.position[0][0] << " " << this->drone2.position[0][1] << " 80 " << std::endl
           << drone2.position[1][0] << " " << drone2.position[1][1] << " 80 " << std::endl
           << drone2.position[1][0] << " " << drone2.position[1][1] << " 0 " << std::endl;
    Lacze.DodajNazwePliku(Path_V2);
    Lacze.Rysuj();}
}