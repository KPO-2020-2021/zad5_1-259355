#include "Drone.hh"

/**
 * Funkcja inicjujaca poczatkowego drona 
 * Inicjuje prostopadaloscian (cialo drona)
 * Inicjuje poszczegolne rotory oraz odpowiada za animacje ich obrotu
 * @param const char *NamesFilesLocal[]
 * @param int step
 */
void Drone::Init(const char *NamesFilesLocal[], int step){

    static double angle_rotors_lf = 0;
    static double angle_rotors_rf = 0;
    static double angle_rotors_lb = 0;
    static double angle_rotors_rb = 0;
    static double angletemp = 0;

    new Prostopadl(SZESCIAN_WZ,NamesFilesLocal[0], arg_pros_sc, 0, init_args);

    this->rotor[0] = new Block(ROTORY_BEF, NamesFilesLocal[1], arg_rotator_sc, arg_lf, angle_rotors_lf);
    this->rotor[1] = new Block(ROTORY_BEF, NamesFilesLocal[2], arg_rotator_sc, arg_rf, angle_rotors_rf);
    this->rotor[2] = new Block(ROTORY_BEF, NamesFilesLocal[3], arg_rotator_sc, arg_lb, angle_rotors_lb);
    this->rotor[3] = new Block(ROTORY_BEF, NamesFilesLocal[4], arg_rotator_sc, arg_rb, angle_rotors_rb);

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
 * @param Vector3 position
 * @param const char *NamesFilesLocal[]
 * @param const char *NamesFilesProper[]
 */
void Drone::Engage2(double angle, Vector3 position, const char *NamesFilesLocal[], const char *NamesFilesProper[], int step){

    this->Init(NamesFilesLocal, step);

    new Prostopadl(NamesFilesLocal[0],NamesFilesProper[0], arg_jed, angle, position);
    
    for(unsigned int Idx = 1; NamesFilesLocal[Idx]!= nullptr; ++Idx){
        rotor[Idx] = new Block(NamesFilesLocal[Idx], NamesFilesProper[Idx], arg_jed, position, angle);
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
    Vector3 position;

    if(drone_num == 1){
        position[0] = begin_position[0];
        position[1] = begin_position[1];
        position[2] = begin_position[2];
    }
    else if(drone_num == 2){
        position[0] = begin_position[0];
        position[1] = begin_position[1];
        position[2] = begin_position[2];
    }
    else{}

    double angletemp = 0;

    std::cout << std::endl << "Up ..." << std::endl;
    for(;position[2] <= 80; position[2] += 2){
        step = 1;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    position[2] -= 2;

    std::cout << "Change of the orientation..." << std::endl;
    if(angle > 0){
    for(; angletemp <= angle; angletemp += 5 ){
        step = 2;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    angletemp -= 5;}
    else if(angle < 0){
    for(; angletemp >= angle; angletemp -= 5 ){
        step = -2;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    angletemp += 5; 
    }

    double x_of_turn = 1;
    double y_of_turn = 1;

    x_of_turn = this->x_of_end(position[0],angletemp,lenght_of_path);
    x_of_turn = (x_of_turn - position[0])/60;
    y_of_turn = this->y_of_end(position[1],angletemp,lenght_of_path);
    y_of_turn = (y_of_turn - position[1])/60;

    std::cout << "Going forward ..." << std::endl;
    for(int i = 0; i <= 60; position[0] += x_of_turn, position[1] += y_of_turn, ++i){
        step = 3;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    position[0] -= 1;
    position[1] -= 1;

    std::cout << "Going down ..." << std::endl;
    for(;position[2] >= 0; position[2] -= 2){
        step = 4;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }

}

void Drone::Scouting(Vector3 begin_position,double drone_num, double angle, PzG::LaczeDoGNUPlota &Lacze, const char *NamesFilesLocal[], const char *NamesFilesProper[]){

    int step = 0;
    Vector3 position;
    double circuit = 0;
    double tmp = 0;

    if(drone_num == 1){
        position[0] = begin_position[0];
        position[1] = begin_position[1];
        position[2] = begin_position[2];
    }
    else if(drone_num == 2){
        position[0] = begin_position[0];
        position[1] = begin_position[1];
        position[2] = begin_position[2];
    }
    else{}

    double angletemp = angle;

    std::cout << std::endl << "Up ..." << std::endl;
    for(;position[2] <= 80; position[2] += 2){
        step = 1;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    position[2] -= 2;

    circuit = M_PI * (2*40);
    tmp = circuit/72;

    double x_of_turn = 1;
    double y_of_turn = 1;

    x_of_turn = this->x_of_end(position[0],angletemp,40);
    x_of_turn = (x_of_turn - position[0])/60;
    y_of_turn = this->y_of_end(position[1],angletemp,40);
    y_of_turn = (y_of_turn - position[1])/60;

    std::cout << "Going forward ..." << std::endl;
    for(int i = 0; i <= 60; position[0] += x_of_turn, position[1] += y_of_turn, ++i){
        step = 3;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    position[0] -= 1;
    position[1] -= 1;

    std::cout << "Change of the orientation..." << std::endl;
    for(; angletemp <= 90+angle; angletemp += 5 ){
        step = 2;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }

    angletemp -= 5; 
    double tmpang;
    tmpang = angletemp+angle;
    std::cout << "Change of the orientation..." << std::endl;
    for(; angletemp <= tmpang+360; angletemp += 5 ){
        x_of_turn = this->x_of_end(position[0],angletemp,tmp);
        x_of_turn = (x_of_turn - position[0]);
        y_of_turn = this->y_of_end(position[1],angletemp,tmp);
        y_of_turn = (y_of_turn - position[1]);
        position[0] += x_of_turn;
        position[1] += y_of_turn;
        step = 2;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    angletemp -= 5; 
    tmpang = angletemp;
    std::cout << "Change of the orientation..." << std::endl;
    for(; angletemp <= 90+tmpang; angletemp += 5 ){
        step = 2;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    angletemp -= 5; 
    x_of_turn = this->x_of_end(position[0],angletemp,40);
    x_of_turn = (x_of_turn - position[0])/60;
    y_of_turn = this->y_of_end(position[1],angletemp,40);
    y_of_turn = (y_of_turn - position[1])/60;

    std::cout << "Going forward ..." << std::endl;
    for(int i = 0; i <= 60; position[0] += x_of_turn, position[1] += y_of_turn, ++i){
        step = 3;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }
    position[0] -= 1;
    position[1] -= 1;

    std::cout << "Going down ..." << std::endl;
    for(;position[2] >= 0; position[2] -= 2){
        step = 4;
        this->Engage2(angletemp,position, NamesFilesLocal, NamesFilesProper, step);
        usleep(100000);
        Lacze.Rysuj();
    }

}