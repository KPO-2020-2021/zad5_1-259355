#include "Drone.hh"

/**
 * Funkcja inicjujaca poczatkowego drona 
 * Inicjuje prostopadaloscian (cialo drona)
 * Inicjuje poszczegolne rotory oraz odpowiada za animacje ich obrotu
 */
void Drone::Init(const char *NamesFilesLocal[], int step){

    static double angle_rotors_lf = 0;
    static double angle_rotors_rf = 0;
    static double angle_rotors_lb = 0;
    static double angle_rotors_rb = 0;
    static double angletemp = 0;


    // this->InitPros(SZESCIAN_WZ,NamesFilesLocal[0], PROSTOPADL_SCALE, 0, 0, 0, 2);
    new Prostopadl(SZESCIAN_WZ,NamesFilesLocal[0], PROSTOPADL_SCALE, 0, 0, 0, 2);

    // this->rotor[0].InitOne(ROTORY_BEF, NamesFilesLocal[1], ROTATOR_SCALE, TRANSLATION_LEFT_FRONT, angle_rotors_lf);
    // this->rotor[1].InitOne(ROTORY_BEF, NamesFilesLocal[2], ROTATOR_SCALE, TRANSLATION_RIGHT_FRONT, angle_rotors_rf);
    // this->rotor[2].InitOne(ROTORY_BEF, NamesFilesLocal[3], ROTATOR_SCALE, TRANSLATION_LEFT_BACK, angle_rotors_lb);
    // this->rotor[3].InitOne(ROTORY_BEF, NamesFilesLocal[4], ROTATOR_SCALE, TRANSLATION_RIGHT_BACK, angle_rotors_rb);

    this->rotor[0] = new Block(ROTORY_BEF, NamesFilesLocal[1], ROTATOR_SCALE, TRANSLATION_LEFT_FRONT, angle_rotors_lf);
    this->rotor[1] = new Block(ROTORY_BEF, NamesFilesLocal[2], ROTATOR_SCALE, TRANSLATION_RIGHT_FRONT, angle_rotors_rf);
    this->rotor[2] = new Block(ROTORY_BEF, NamesFilesLocal[3], ROTATOR_SCALE, TRANSLATION_LEFT_BACK, angle_rotors_lb);
    this->rotor[3] = new Block(ROTORY_BEF, NamesFilesLocal[4], ROTATOR_SCALE, TRANSLATION_RIGHT_BACK, angle_rotors_rb);

    #define TURN_OF_ROTOR_UP_DOWN 10
    #define TURN_OF_ROTOR_FORWARD_BACK 15
    #define TURN_OF_ROTOR_FORWARD_FRONT 7
    if(step == 1){
        angle_rotors_lf -= TURN_OF_ROTOR_UP_DOWN;
        angle_rotors_rf += TURN_OF_ROTOR_UP_DOWN;
        angle_rotors_lb += TURN_OF_ROTOR_UP_DOWN;
        angle_rotors_rb -= TURN_OF_ROTOR_UP_DOWN;
    }
    else if(step == 2){
        angle_rotors_lf -= TURN_OF_ROTOR_UP_DOWN + 5;
        angle_rotors_rf += TURN_OF_ROTOR_UP_DOWN - 4;
        angle_rotors_lb += TURN_OF_ROTOR_UP_DOWN - 4;
        angle_rotors_rb -= TURN_OF_ROTOR_UP_DOWN + 5;
    }
    else if(step == -2){
        angle_rotors_lf -= TURN_OF_ROTOR_UP_DOWN - 5;
        angle_rotors_rf += TURN_OF_ROTOR_UP_DOWN + 4;
        angle_rotors_lb += TURN_OF_ROTOR_UP_DOWN + 4;
        angle_rotors_rb -= TURN_OF_ROTOR_UP_DOWN - 5;
    }
    else if(step == 3){
        angle_rotors_lf -= TURN_OF_ROTOR_FORWARD_FRONT;
        angle_rotors_rf += TURN_OF_ROTOR_FORWARD_FRONT;
        angle_rotors_lb += TURN_OF_ROTOR_FORWARD_BACK;
        angle_rotors_rb -= TURN_OF_ROTOR_FORWARD_BACK;
    }
    else if(step == 4){
        angletemp += 0.5;
        angle_rotors_lf -= TURN_OF_ROTOR_UP_DOWN - angletemp;
        angle_rotors_rf += TURN_OF_ROTOR_UP_DOWN - angletemp;
        angle_rotors_lb += TURN_OF_ROTOR_UP_DOWN - angletemp;
        angle_rotors_rb -= TURN_OF_ROTOR_UP_DOWN - angletemp;
    }
    else{}

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
void Drone::Engage2(double angle, double x_position, double y_position, double z_position, const char *NamesFilesLocal[], const char *NamesFilesProper[], int step){
    #define SKALA_JED 1,1,1

    this->Init(NamesFilesLocal, step);

    new Prostopadl(NamesFilesLocal[0],NamesFilesProper[0], SKALA_JED, angle, x_position, y_position, z_position);
    
    for(unsigned int Idx = 1; NamesFilesLocal[Idx]!= nullptr; ++Idx){
        rotor[Idx] = new Block(NamesFilesLocal[Idx], NamesFilesProper[Idx], SKALA_JED, x_position, y_position, z_position, angle);
        // rotor[Idx] = InitOne(NamesFilesLocal[Idx], NamesFilesProper[Idx], SKALA_JED, x_position, y_position, z_position, angle);
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
    int step = 0;
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
        step = 1;
        this->Engage2(angletemp,x_position,y_position,z_position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    z_position -= 2;

    std::cout << "Change of the orientation..." << std::endl;
    if(angle > 0){
    for(; angletemp <= angle; angletemp += 5 ){
        step = 2;
        this->Engage2(angletemp,x_position,y_position,z_position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    angletemp -= 5;}
    else if(angle < 0){
    for(; angletemp >= angle; angletemp -= 5 ){
        step = -2;
        this->Engage2(angletemp,x_position,y_position,z_position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    angletemp += 5; 
    }

    double x_of_turn = 1;
    double y_of_turn = 1;

    x_of_turn = this->x_of_end(x_position,angletemp,lenght_of_path);
    x_of_turn = (x_of_turn - x_position)/60;
    y_of_turn = this->y_of_end(y_position,angletemp,lenght_of_path);
    y_of_turn = (y_of_turn - y_position)/60;

    std::cout << "Going forward ..." << std::endl;
    for(int i = 0; i <= 60; x_position += x_of_turn, y_position += y_of_turn, ++i){
        step = 3;
        this->Engage2(angletemp,x_position,y_position,z_position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    x_position -= 1;
    y_position -= 1;

    std::cout << "Going down ..." << std::endl;
    for(;z_position >= 0; z_position -= 2){
        step = 4;
        this->Engage2(angletemp,x_position,y_position,z_position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }

}


