// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include "scena.hh"
#include "exampleConfig.h"
#include "example.h"
#include "Vector3.hh"
#include "Prostopadl.hh"
#include "Drone.hh"
#include "matrix.hh"
#include "../include/lacze_do_gnuplota.hh"

using namespace std;


/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

int main() {
  std::cout << "Project Rotation 3D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;

PzG::LaczeDoGNUPlota Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku Prostopadla

 scena Scena;

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();
  Lacze.UstawZakresX(0,200);
  Lacze.UstawZakresY(0,200);
  Lacze.UstawZakresZ(0,120);

  Lacze.UstawRotacjeXZ(64,65);
   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "Prostopadl.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku(PLASZCZYZNA_WZ);
  
  PzG::InfoPlikuDoRysowania *col_corp = &Lacze.DodajNazwePliku(SZESCIAN_ZM);
  PzG::InfoPlikuDoRysowania *col_rot1 = &Lacze.DodajNazwePliku(ROTORY_1);
  PzG::InfoPlikuDoRysowania *col_rot2 = &Lacze.DodajNazwePliku(ROTORY_2);
  PzG::InfoPlikuDoRysowania *col_rot3 = &Lacze.DodajNazwePliku(ROTORY_3);
  PzG::InfoPlikuDoRysowania *col_rot4 = &Lacze.DodajNazwePliku(ROTORY_4);

  col_corp->ZmienKolor(1);
  col_rot1->ZmienKolor(2);
  col_rot2->ZmienKolor(2);
  col_rot3->ZmienKolor(2);
  col_rot4->ZmienKolor(2);

  PzG::InfoPlikuDoRysowania *col_corp_v2 = &Lacze.DodajNazwePliku(SZESCIAN_ZM_V2);
  PzG::InfoPlikuDoRysowania *col_rot1_v2 = &Lacze.DodajNazwePliku(ROTORY_1_V2);
  PzG::InfoPlikuDoRysowania *col_rot2_v2 = &Lacze.DodajNazwePliku(ROTORY_2_V2);
  PzG::InfoPlikuDoRysowania *col_rot3_v2 = &Lacze.DodajNazwePliku(ROTORY_3_V2);
  PzG::InfoPlikuDoRysowania *col_rot4_v2 = &Lacze.DodajNazwePliku(ROTORY_4_V2);

  col_corp_v2->ZmienKolor(3);
  col_rot1_v2->ZmienKolor(4);
  col_rot2_v2->ZmienKolor(4);
  col_rot3_v2->ZmienKolor(4);
  col_rot4_v2->ZmienKolor(4);

  
  Lacze.Rysuj();
  
  cout << "Beginning" << endl;

  Vector3 position;
  cout << "m - menu" << endl;
  cout << "a - choose active drone" << endl;
  cout << "p - parameters of the flight" << endl;
  cout << "w - number of used vectors" << endl;
  cout << "s - scout" << endl;
  cout << "a - add obstacle" << endl;
  cout << "d - delete obstacle" << endl;
  cout << "k - end" << endl;

  double arg1[] = {20,20,0};
  Scena.drone1.position[0] = Vector3(arg1);
  Scena.drone1.Engage2(0, Scena.drone1.position[0], NamesFilesLoc_V1, NamesFilesProp_V1,0);
  double arg2[] = {20,60,0};
  Scena.drone2.position[0] = Vector3(arg2);
  Scena.drone2.Engage2(0, Scena.drone2.position[0], NamesFilesLoc_V2, NamesFilesProp_V2,0);
  Lacze.Rysuj();
  Scena.drone1.position[1] = Scena.drone1.position[0];
  Scena.drone2.position[1] = Scena.drone2.position[0];

  double choice_drone;
  double angle=0;
  char choice = 'a';
  while (choice != 'k'){
  
    Lacze.Rysuj();
    switch( choice ){

      case 'p':{ 
        double lenght;
        cout << "Enter the direction (angle in degrees): ";
        cin >> angle;
        cout << "Enter the lenght of the flight: ";
        cin >> lenght;
        if(choice_drone == 1){
          Scena.Make_Path(Lacze, choice_drone, Path_V1, lenght, angle);
          Lacze.Rysuj();
          Scena.drone1.Relocate(Scena.drone1.position[0], choice_drone, angle, lenght, Lacze, NamesFilesLoc_V1, NamesFilesProp_V1);
          Scena.drone1.position[0] = Scena.drone1.position[1];
          Lacze.UsunNazwePliku(Path_V1);
          }
        else if(choice_drone == 2){
          Scena.Make_Path(Lacze, choice_drone, Path_V2, lenght, angle);
          Lacze.Rysuj();
          Scena.drone2.Relocate(Scena.drone2.position[0],choice_drone, angle,lenght, Lacze, NamesFilesLoc_V2, NamesFilesProp_V2);
          Scena.drone2.position[0] = Scena.drone2.position[1];
          Lacze.UsunNazwePliku(Path_V2);
        }
        else{
          cout << "You have choosen wrong drone " << endl;
        }
      break;}

      case 'm':{
        cout << "m - menu" << endl;
        cout << "a - choose active drone" << endl;
        cout << "p - parameters of the flight" << endl;
        cout << "w - number of used vectors" << endl;
        cout << "s - scout" << endl;
        cout << "a - add obstacle" << endl;
        cout << "d - delete obstacle" << endl;
        cout << "k - end" << endl;
        break;}

      case 'w':{
        if(choice_drone == 1){
        cout << "Amount of Vectors in use: " << Scena.drone1.position[0].amount_active_vectors() << endl;
        cout << "Amount of Vectors used: " << Scena.drone1.position[0].amount_of_all_vectors() << endl;}
        else if(choice_drone == 2){
        cout << "Amount of Vectors in use: " << Scena.drone2.position[0].amount_active_vectors() << endl;
        cout << "Amount of Vectors used: " << Scena.drone2.position[0].amount_of_all_vectors() << endl;}
        break;}

      case 's':{
        if(choice_drone == 1){
        Scena.drone1.Scouting(Scena.drone1.position[0], choice_drone, angle, Lacze, NamesFilesLoc_V1, NamesFilesProp_V1);}
        else if(choice_drone == 2){
        Scena.drone2.Scouting(Scena.drone1.position[0], choice_drone, angle, Lacze, NamesFilesLoc_V1, NamesFilesProp_V1);}
        break;}

      case 'k':{
        cout << "the end" << endl;
        break;}
      case 'o':{
        char obs_choice;
        Vector3 beg_position;
        Vector3 scale;
        cout << "which type of obstacle you want to add ? You can choose 1,2,3 " << endl;
        cin >> obs_choice;
        cout << "where do you want the middle of obstacle write position x,y,z" << endl;
        cin >> beg_position[0];
        cin >> beg_position[1];
        cout << "Choose the scale on x side, y side, z side (for example 10 10 60): " << std::endl;
        cin >> scale;
        // Scena.full_by_ones();
        Scena.make_obstacle1(Lacze,beg_position,scale,obs_choice);
        break;
      }
      case 'd':{
        int i = 1;
        unsigned int num_obs;
        list<string>::iterator it = Scena.Obstacles.begin();
        cout << "choose which obstacle you want to delete : " << endl;
        for( string n : Scena.Obstacles){
        cout << i << " " << n << endl;
        ++i;}
        cin >> num_obs;
        advance(it,num_obs-1);
        Lacze.UsunNazwePliku(*it);
        Scena.Obstacles.erase(it);
        Lacze.Rysuj();
        break;
      }
      case 'a':{
        choice_drone = '_';
        while(choice_drone != 1 && choice_drone != 2){
        cout << "choose which drone would you fly" << endl;
        cin >> choice_drone;
        if(choice_drone == 1){
          cout << "You have choosen first drone at the position: " << endl;
          cout << Scena.drone1.position[0] << endl;
          }
        else if(choice_drone == 2){
          cout << "You have choosen first drone at the position: " << endl;
          cout << Scena.drone2.position[0] << endl;
        } 
        else{
          cerr << "You have choosen wrong one, try again: " << endl;
        }}
        break;}

      default:{
        cout << "Wrong Option" << endl;
      }}
      cout << "Your choice?  (m-menu) >" << endl;
      cin >> choice;
    }

  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}


