#ifndef SCENA_HH
#define SCENA_HH

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
    
    private:

    std::vector<Drone> drones;  ///<Kontener dronow

    unsigned int Active_drone;  ///<Aktywny dron

    public:

    std::list<Prostopadl> Obstacles;   ///<Lista mieszczaca przeszkody

    std::list<std::string> Obstacles_names;   ///<Lista mieszczaca przeszkody

    Drone *getdrone(){return (&drones[Active_drone]);}; ///<Funkcja dajaca dostep do danego drona

    Drone GetActiveDrone(int ind){return(drones[ind]);};    ///<

    void choose_drone(unsigned int choice){ Active_drone = choice - 1;};    ///<Funkcja zwracajaca index wybranego drona

    void Add_drone(Drone tmp){ drones.push_back(tmp);}; ///<Funkcja dodajaca drona do kontenera

///<Funkcja tworzaca sciezke przelotu drona
void Make_Path(PzG::LaczeDoGNUPlota &Lacze, double choosen_drone, const char *Name_of_Path, double lenght_of_path, double angletemp){    

    std::ofstream StrmWy(Name_of_Path); 

    if(!StrmWy.is_open()){
        std::cerr << std::endl
            << "Couldnt open the file: " << Name_of_Path << std::endl
            << std::endl;
    }

    // drone1.position[1][0] = drone1.x_of_end(drone1.position[0][0],angletemp,lenght_of_path) ; 
    // drone1.position[1][1] = drone1.y_of_end(drone1.position[0][1],angletemp,lenght_of_path) ; 

    // drone2.position[1][0] = drone2.x_of_end(drone2.position[0][0],angletemp,lenght_of_path) ;
    // drone2.position[1][1] = drone2.y_of_end(drone2.position[0][1],angletemp,lenght_of_path) ;

    if(choosen_drone == 1){
    drones[0].position[1][0] = drones[0].x_of_end(drones[0].position[0][0],angletemp,lenght_of_path) ; 
    drones[0].position[1][1] = drones[0].y_of_end(drones[0].position[0][1],angletemp,lenght_of_path) ; 
    StrmWy << drones[0].position[0] << std::endl
           << this->drones[0].position[0][0] << " " << this->drones[0].position[0][1] << " 80" << std::endl
           << drones[0].position[1][0] << " " << drones[0].position[1][1] << " 80" << std::endl
           << drones[0].position[1][0] << " " << drones[0].position[1][1] << " 0" << std::endl;
    Lacze.DodajNazwePliku(Path_V1);
    Lacze.Rysuj();}
    else if(choosen_drone == 2){
    drones[1].position[1][0] = drones[1].x_of_end(drones[1].position[0][0],angletemp,lenght_of_path) ;
    drones[1].position[1][1] = drones[1].y_of_end(drones[1].position[0][1],angletemp,lenght_of_path) ;
    StrmWy << this->drones[1].position[0] << std::endl
           << this->drones[1].position[0][0] << " " << this->drones[1].position[0][1] << " 80 " << std::endl
           << drones[1].position[1][0] << " " << drones[1].position[1][1] << " 80 " << std::endl
           << drones[1].position[1][0] << " " << drones[1].position[1][1] << " 0 " << std::endl;
    Lacze.DodajNazwePliku(Path_V2);
    Lacze.Rysuj();}
};

///<Funkcja tworzaca przeszkode i dodajaca ja do lacza
void make_obstacle1(PzG::LaczeDoGNUPlota &Lacze,Vector3 begin_position, Vector3 scale, char choice){
    static int count1 = 1, count2 = 1, count3 = 1;
    Vector3 begin_vec;
    double arg[] = {1,1,1};
    begin_vec = Vector3(arg);
    switch(choice){
        case '1':{
            std::string stream1 = "../dat/gora_z_dluga_grania" + std::to_string(count1) + ".dat"; 
            char *strm1 = new char[stream1.size() + 1];
            strcpy(strm1, stream1.c_str());
            std::cout << "Init obstacle type 1" << std::endl;
            Lacze.DodajNazwePliku(strm1);
            this->Obstacles_names.push_back(strm1);
            this->Obstacles.push_back(Init_The_Obstacle("../bryly_wzorcowe/gora_z_dluga_grania.dat",strm1,NOPOINTS,scale,begin_position,'1'));
            Lacze.Rysuj();
            count1 += 1;
        break;}

        case '2':{
            std::string stream2 = "../dat/gora_z_ostrym_szczytem" + std::to_string(count2) + ".dat"; 
            char *strm2 = new char[stream2.size() + 1];
            strcpy(strm2, stream2.c_str());
            std::cout << "Init obstacle type 2" << std::endl;
            Lacze.DodajNazwePliku(strm2);
            this->Obstacles_names.push_back(strm2);
            this->Obstacles.push_back(Init_The_Obstacle("../bryly_wzorcowe/gora_z_ostrym_szczytem.dat",strm2,NOPOINTS,scale,begin_position,'2'));
            Lacze.Rysuj();
            count2 += 1;
        break;}

        case '3':{
            std::string stream3 = "../dat/plaskowyz" + std::to_string(count3) + ".dat"; 
            char *strm3 = new char[stream3.size() + 1];
            strcpy(strm3, stream3.c_str());
            std::cout << "Init obstacle type 3" << std::endl;
            this->Obstacles_names.push_back(strm3);
            this->Obstacles.push_back(Init_The_Obstacle("../bryly_wzorcowe/plaskowyz.dat",strm3,NOPOINTS,scale,begin_position,'3'));           
            Lacze.DodajNazwePliku(strm3);
            Lacze.Rysuj();
            count3 += 1;
        break;}
    }
};

///<Funkcja odpowiednio zmieniajaca wierzcholki z pliku tak by powstala odpowiednia przeszkoda
Prostopadl Init_The_Obstacle(const char * StrmWe, const char * StrmWy, double num_of_peak, Vector3 scale,
Vector3 trans, char choice){
    Prostopadl temp;
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
                    if(x < 0){ 
                        x = fabs(x);
                    }
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
        temp(i,0) = (x * scale[0]) + trans[0] ;
        temp(i,1) = (y * scale[1]) + trans[1] ;
        temp(i,2) = (z * scale[2]) + trans[2] ;

        if(i%4 == 0){
        FileWy << std::endl;
        FileWy << temp(i) << std::endl;
        }
        else{
        FileWy << temp(i) << std::endl;}
    } 
    FileWe.close();
    FileWy.close();

    return temp;
};

};


#endif