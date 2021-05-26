#include "Drone.hh"

/**
 * Funkcja inicjujaca poczatkowego drona 
 * Inicjuje prostopadaloscian (cialo drona)
 * Inicjuje poszczegolne rotory oraz odpowiada za animacje ich obrotu
 */
void Drone::Init(const char *NamesFilesLocal[]){

    static double angle_rotors = 0;

    this->InitPros(SZESCIAN_WZ,NamesFilesLocal[0], PROSTOPADL_SCALE, 0, 0, 0, 2);

    this->rotor[0].InitOne(ROTORY_BEF, NamesFilesLocal[1], ROTATOR_SCALE, TRANSLATION_LEFT_FRONT, angle_rotors);
    this->rotor[1].InitOne(ROTORY_BEF, NamesFilesLocal[2], ROTATOR_SCALE, TRANSLATION_RIGHT_FRONT, angle_rotors);
    this->rotor[2].InitOne(ROTORY_BEF, NamesFilesLocal[3], ROTATOR_SCALE, TRANSLATION_LEFT_BACK, angle_rotors);
    this->rotor[3].InitOne(ROTORY_BEF, NamesFilesLocal[4], ROTATOR_SCALE, TRANSLATION_RIGHT_BACK, angle_rotors);

    #define TURN_OF_ROTOR 10

    angle_rotors += TURN_OF_ROTOR;
}

/**
 * Funkcja inicjujaca drona
 * Inicjuje prostopadaloscian (cialo drona), obraca go i odpowiada za sposob przelotu
 * Inicjuje poszczegolne rotory oraz odpowiada za ich sposob przelotu wzgledem ciala oraz ich poczatkowy obrot
 * @param double angle
 * @param double x_position
 * @param double y_position
 * @param double z_position
 * @param const char *NamesFilesLocal[]
 * @param const char *NamesFilesProper[]
 */
void Drone::Engage2(double angle, double x_position, double y_position, double z_position, const char *NamesFilesLocal[], const char *NamesFilesProper[]){
    #define SKALA_JED 1,1,1

    this->Init(NamesFilesLocal);

    this->InitPros(NamesFilesLocal[0],NamesFilesProper[0], SKALA_JED, angle, x_position, y_position, z_position);
    
    for(unsigned int Idx = 1; NamesFilesLocal[Idx]!= nullptr; ++Idx){
        this->rotor[Idx].InitOne(NamesFilesLocal[Idx], NamesFilesProper[Idx], SKALA_JED, x_position, y_position, z_position, angle);
    }
}

/**
 * Funkcja inicjujaca drona
 * Inicjuje prostopadaloscian (cialo drona), obraca go i odpowiada za sposob przelotu
 * Inicjuje poszczegolne rotory oraz odpowiada za ich sposob przelotu wzgledem ciala oraz ich poczatkowy obrot
 * @param Vector3 begin_position
 * @param double drone_num
 * @param double angle
 * @param double lenght_of_path
 * @param PzG::LaczeDoGNUPlota &Lacze
 * @param const char *NamesFilesLocal[]
 * @param const char *NamesFilesProper[]
 */
void Drone::Relocate(Vector3 begin_position,double drone_num, double angle, double lenght_of_path, PzG::LaczeDoGNUPlota &Lacze, const char *NamesFilesLocal[], const char *NamesFilesProper[])
{

    double x_position, y_position, z_position;
    if(drone_num == 1){
        x_position = begin_position[0];
        y_position = begin_position[1];
        z_position = begin_position[2];
    }
    else if(drone_num == 2){
        x_position = begin_position[0];
        y_position = begin_position[1];
        z_position = begin_position[2];
    }
    else{}

    double angletemp = 0;

    std::cout << std::endl << "Up ..." << std::endl;
    for(;z_position <= 80; z_position += 2){
        this->Engage2(angletemp,x_position,y_position,z_position, NamesFilesLocal, NamesFilesProper);
        usleep(100000);
        Lacze.Rysuj();
    }
    z_position -= 2;

    std::cout << "Change of the orientation..." << std::endl;
    for(; angletemp <= angle; angletemp += 5 ){
        this->Engage2(angletemp,x_position,y_position,z_position, NamesFilesLocal, NamesFilesProper);
        usleep(100000);
        Lacze.Rysuj();
    }
    angletemp -= 5;

    double x_of_turn = 1;
    double y_of_turn = 1;

    x_of_turn = this->x_of_end(x_position,angletemp,lenght_of_path);
    x_of_turn = (x_of_turn - x_position)/60;
    y_of_turn = this->y_of_end(y_position,angletemp,lenght_of_path);
    y_of_turn = (y_of_turn - y_position)/60;

    std::cout << "Going forward ..." << std::endl;
    for(int i = 0; i <= 60; x_position += x_of_turn, y_position += y_of_turn, ++i){
        this->Engage2(angletemp,x_position,y_position,z_position, NamesFilesLocal, NamesFilesProper);
        usleep(100000);
        Lacze.Rysuj();
    }
    x_position -= 1;
    y_position -= 1;

    std::cout << "Going down ..." << std::endl;
    for(;z_position >= 0; z_position -= 2){
        this->Engage2(angletemp,x_position,y_position,z_position, NamesFilesLocal, NamesFilesProper);
        usleep(100000);
        Lacze.Rysuj();
    }

}


