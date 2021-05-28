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

// void scena::Engage2_both(double angle1, double angle2, double x_position, double y_position, double z_position, double x_position2, double y_position2, double z_position2, const char *NamesFilesLocal1[],const char *NamesFilesLocal2[], const char *NamesFilesProper1[], const char *NamesFilesProper2[], int step){
//     #define SKALA_JED 1,1,1

//     drone1.Init(NamesFilesLocal1, step);
//     drone2.Init(NamesFilesLocal2, step);


//     drone1.InitPros(NamesFilesLocal1[0],NamesFilesProper1[0], SKALA_JED, angle1, x_position, y_position, z_position);
//     drone2.InitPros(NamesFilesLocal2[0],NamesFilesProper2[0], SKALA_JED, angle2, x_position2, y_position2, z_position2);

//     for(unsigned int Idx = 1; NamesFilesLocal1[Idx]!= nullptr; ++Idx){
//         drone1.InitOne(NamesFilesLocal1[Idx], NamesFilesProper1[Idx], SKALA_JED, x_position, y_position, z_position, angle1);
//         drone2.InitOne(NamesFilesLocal2[Idx], NamesFilesProper2[Idx], SKALA_JED, x_position2, y_position2, z_position2, angle2);
//     }
// }



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
// void scena::Relocate_both(Vector3 begin_position, double angle1, double angle2, double lenght_of_path1, double lenght_of_path2, PzG::LaczeDoGNUPlota &Lacze, const char *NamesFilesLocal1[], const char *NamesFilesProper1[], const char *NamesFilesLocal2[], const char *NamesFilesProper2[]){
// {
    // int step = 0;
    // double x_position1, y_position1, z_position1;
    // double x_position2, y_position2, z_position2;

    //     x_position1 = drone1.position[0][0];
    //     y_position1 = drone1.position[0][1];
    //     z_position1 = drone1.position[0][2];
    
    //     x_position2 = drone2.position[0][0];
    //     y_position2 = drone2.position[0][1];
    //     z_position2 = drone2.position[0][2];
    

    // double angletemp1 = 0;
    // double angletemp2 = 0;

    // std::cout << std::endl << "Up ..." << std::endl;
    // for(;z_position1 <= 80; z_position1 += 2, z_position2 += 2){
    //     step = 1;
    //     this->Engage2_both(angletemp1, angletemp2 ,x_position1,y_position1,z_position1,x_position2,y_position2,z_position2, NamesFilesLocal1, NamesFilesProper1, NamesFilesLocal2, NamesFilesProper2, step);
    //     usleep(100000);
    //     Lacze.Rysuj();
    // }
    // z_position1 -= 2;
    // z_position2 -= 2;

    // std::cout << "Change of the orientation..." << std::endl;
    // if(angle > 0){
    // for(; angletemp <= angle; angletemp += 5 ){
    //     step = 2;
    //     this->Engage2_both(angletemp1, angletemp2 ,x_position1,y_position1,z_position1,x_position2,y_position2,z_position2, NamesFilesLocal1, NamesFilesProper1, NamesFilesLocal2, NamesFilesProper2, step);
    //     usleep(100000);
    //     Lacze.Rysuj();
    // }
    // angletemp -= 5;}
    // else if(angle < 0){
    // for(; angletemp >= angle; angletemp -= 5 ){
    //     step = -2;
    //     this->Engage2_both(angletemp1, angletemp2 ,x_position1,y_position1,z_position1,x_position2,y_position2,z_position2, NamesFilesLocal1, NamesFilesProper1, NamesFilesLocal2, NamesFilesProper2, step);
    //     usleep(100000);
    //     Lacze.Rysuj();
    // }
    // angletemp += 5; 
    // }

    // double x_of_turn = 1;
    // double y_of_turn = 1;

    // x_of_turn = this->x_of_end(x_position,angletemp,lenght_of_path);
    // x_of_turn = (x_of_turn - x_position)/60;
    // y_of_turn = this->y_of_end(y_position,angletemp,lenght_of_path);
    // y_of_turn = (y_of_turn - y_position)/60;

    // std::cout << "Going forward ..." << std::endl;
    // for(int i = 0; i <= 60; x_position += x_of_turn, y_position += y_of_turn, ++i){
    //     step = 3;
    //     this->Engage2_both(angletemp1, angletemp2 ,x_position1,y_position1,z_position1,x_position2,y_position2,z_position2, NamesFilesLocal1, NamesFilesProper1, NamesFilesLocal2, NamesFilesProper2, step);
    //     usleep(100000);
    //     Lacze.Rysuj();
    // }
    // x_position -= 1;
    // y_position -= 1;

    // std::cout << "Going down ..." << std::endl;
    // for(;z_position1 >= 0; z_position1 -= 2, z_position2 -=2){
    //     step = 4;
    //     this->Engage2_both(angletemp1, angletemp2 ,x_position1,y_position1,z_position1,x_position2,y_position2,z_position2, NamesFilesLocal1, NamesFilesProper1, NamesFilesLocal2, NamesFilesProper2, step);
    //     usleep(100000);
    //     Lacze.Rysuj();
    // }

// }
