#include "Drone.hh"

void Drone::Init(){

    static double angle_rotors = 0;

    std::ifstream FileWe_Prostopadl(SZESCIAN_WZ);
    std::ofstream FileWy_Prostopadl(SZESCIAN_ZM_LOC);
    std::ofstream FileWy_V2_Prostopadl(SZESCIAN_ZM_LOC_V2);
    this->InitPros(FileWe_Prostopadl,FileWy_Prostopadl, PROSTOPADL_SCALE, 0, 0, 0, 2);
    this->InitPros(FileWe_Prostopadl,FileWy_V2_Prostopadl, PROSTOPADL_SCALE, 0, 0, 0, 2);

    this->rotor_V2[0].InitOne(ROTORY_BEF, ROTORYLOC_1_V2, ROTATOR_SCALE, TRANSLATION_LEFT_FRONT, angle_rotors);
    this->rotor_V2[1].InitOne(ROTORY_BEF, ROTORYLOC_2_V2, ROTATOR_SCALE, TRANSLATION_RIGHT_FRONT, angle_rotors);
    this->rotor_V2[2].InitOne(ROTORY_BEF, ROTORYLOC_3_V2, ROTATOR_SCALE, TRANSLATION_LEFT_BACK, angle_rotors);
    this->rotor_V2[3].InitOne(ROTORY_BEF, ROTORYLOC_4_V2, ROTATOR_SCALE, TRANSLATION_RIGHT_BACK, angle_rotors);

    this->rotor[0].InitOne(ROTORY_BEF, ROTORYLOC_1, ROTATOR_SCALE, TRANSLATION_LEFT_FRONT, angle_rotors);
    this->rotor[1].InitOne(ROTORY_BEF, ROTORYLOC_2, ROTATOR_SCALE, TRANSLATION_RIGHT_FRONT, angle_rotors);
    this->rotor[2].InitOne(ROTORY_BEF, ROTORYLOC_3, ROTATOR_SCALE, TRANSLATION_LEFT_BACK, angle_rotors);
    this->rotor[3].InitOne(ROTORY_BEF, ROTORYLOC_4, ROTATOR_SCALE, TRANSLATION_RIGHT_BACK, angle_rotors);

    #define TURN_OF_ROTOR 10

    angle_rotors += TURN_OF_ROTOR;
}

void Drone::Engage2(double angle, double x_position, double y_position, double z_position, const char *NamesFilesLocal[], const char *NamesFilesProper[]){
    #define SKALA_JED 1,1,1

    this->Init();

    std::ifstream FileWe_Prostopadl(NamesFilesLocal[0]);
    std::ofstream FileWy_Prostopadl(NamesFilesProper[0]);

    this->InitPros(FileWe_Prostopadl,FileWy_Prostopadl, SKALA_JED, angle, x_position, y_position, z_position);
    
    for(unsigned int Idx = 1; NamesFilesLocal[Idx]!= nullptr; ++Idx){
        this->rotor[Idx].InitOne(NamesFilesLocal[Idx], NamesFilesProper[Idx], SKALA_JED, x_position, y_position, z_position, angle);
    }
}




void Drone::Relocate(double drone_num, double angle, double lenght_of_path, PzG::LaczeDoGNUPlota &Lacze, const char *NamesFilesLocal[], const char *NamesFilesProper[])
{

    double x_position, y_position, z_position;

    if(drone_num == 1){
        x_position = 20;
        y_position = 20;
        z_position = 0;
    }
    else if(drone_num == 2){
        x_position = 20;
        y_position = 60;
        z_position = 0;
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
    y_of_turn = this->y_of_end(y_position,angletemp,lenght_of_path);
    y_of_turn = (y_of_turn - y_position)/(x_of_turn - x_position);

    std::cout << "Going forward ..." << std::endl;
    for(int i = 0; i <= x_of_turn; x_position += 1, y_position += y_of_turn, ++i){
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
