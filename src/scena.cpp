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
    StrmWy << drone1.position[0] << std::endl
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

void scena::make_obstacle1(PzG::LaczeDoGNUPlota &Lacze,Vector3 begin_position, Vector3 scale, char choice){
    static int count1 = 1, count2 = 1, count3 = 1;
    Prostopadl temp;
    Vector3 begin_vec;
    double arg[] = {1,1,1};
    begin_vec = Vector3(arg);
    switch(choice){
        case '1':{
            std::string stream1 = "../dat/gora_z_dluga_grania" + std::to_string(count1) + ".dat"; 
            char *strm1 = new char[stream1.size() + 1];
            strcpy(strm1, stream1.c_str());
            std::cout << "Init obstacle type 1" << std::endl;
            Init_The_Obstacle("../bryly_wzorcowe/gora_z_dluga_grania.dat",strm1,NOPOINTS,scale,begin_position,'1');
            Lacze.DodajNazwePliku(strm1);
            this->Obstacles.push_back(stream1);
            Lacze.Rysuj();
            count1 += 1;
        break;}

        case '2':{
            std::string stream2 = "../dat/gora_z_ostrym_szczytem" + std::to_string(count2) + ".dat"; 
            char *strm2 = new char[stream2.size() + 1];
            strcpy(strm2, stream2.c_str());
            std::cout << "Init obstacle type 2" << std::endl;
            Init_The_Obstacle("../bryly_wzorcowe/gora_z_ostrym_szczytem.dat",strm2,NOPOINTS,scale,begin_position,'2');
            Lacze.DodajNazwePliku(strm2);
            this->Obstacles.push_back(stream2);
            Lacze.Rysuj();
            count2 += 1;
        break;}

        case '3':{
            std::string stream3 = "../dat/plaskowyz" + std::to_string(count3) + ".dat"; 
            char *strm3 = new char[stream3.size() + 1];
            strcpy(strm3, stream3.c_str());
            std::cout << "Init obstacle type 3" << std::endl;
            Init_The_Obstacle("../bryly_wzorcowe/plaskowyz.dat",strm3,NOPOINTS,scale,begin_position,'3');
            this->Obstacles.push_back(stream3);           
            Lacze.DodajNazwePliku(strm3);
            Lacze.Rysuj();
            count3 += 1;
        break;}
    }
    // this->Obstacles.push_back(temp);
}


void scena::Init_The_Obstacle(const char * StrmWe, const char * StrmWy, double num_of_peak, Vector3 scale,
 Vector3 trans, char choice){
// GranBlock::GranBlock(const char * StrmWe, const char * StrmWy, double num_of_peak, double scalex, double scaley, double scalez,
// double trans_x, double trans_y, double trans_z, double angle){
    std::ifstream FileWe(StrmWe);
    std::ofstream FileWy(StrmWy);
    FileWe.clear();
    FileWe.seekg(0);
    double x,y,z;
    assert(FileWe.good());
    assert(FileWy.good());
    for(int i = 0; i < num_of_peak; ++i){
        FileWe >> x >> y >> z;
        switch (choice){
            case '1':{
                if(z > 0.5){
                    if(x < 0){ x = fabs(x);}
                }
            break;}
            case '2':{
                if(z > 0.5){
                    x = 0;
                    y = 0;
                }
                else if(z == 0.5){
                    x /= 2;
                    y /= 2;
                }
            break;}
        }
        double arg[] = {x,y,z};
        Vector3 vec = Vector3(arg);
        x = vec[0];
        y = vec[1];
        z = vec[2]; 
        vec[0] = (x * scale[0]) + trans[0] ;
        vec[1] = (y * scale[1]) + trans[1] ;
        vec[2] = (z * scale[2]) + trans[2] ;

        // this->vect_used += figure.size();
        if(i%4 == 0){
        FileWy << std::endl;
        FileWy << vec << std::endl;
        }
        else{
        FileWy << vec << std::endl;}
        // this->figure.pop_back();
        // this->vect_in_use += figure.size();
    } 
    FileWe.close();
    FileWy.close();
}
