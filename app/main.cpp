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

const char *NamesFilesLoc_V1[] = {SZESCIAN_ZM_LOC,ROTORYLOC_1,ROTORYLOC_2,ROTORYLOC_3,ROTORYLOC_4, nullptr};
const char *NamesFilesProp_V1[] = {SZESCIAN_ZM,ROTORY_1,ROTORY_2,ROTORY_3,ROTORY_4, nullptr};

const char *NamesFilesLoc_V2[] = {SZESCIAN_ZM_LOC_V2,ROTORYLOC_1_V2,ROTORYLOC_2_V2,ROTORYLOC_3_V2,ROTORYLOC_4_V2, nullptr};
const char *NamesFilesProp_V2[] = {SZESCIAN_ZM_V2,ROTORY_1_V2,ROTORY_2_V2,ROTORY_3_V2,ROTORY_4_V2, nullptr};

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
  cout << "k - end" << endl;

  double arg1[] = {20,20,0};
  Scena.drone1.position[0] = Vector3(arg1);
  Scena.drone1.Engage2(0,20,20,0, NamesFilesLoc_V1, NamesFilesProp_V1,0);
  double arg2[] = {20,60,0};
  Scena.drone2.position[0] = Vector3(arg2);
  Scena.drone2.Engage2(0,20,60,0, NamesFilesLoc_V2, NamesFilesProp_V2,0);
  Lacze.Rysuj();
  Scena.drone1.position[1] = Scena.drone1.position[0];
  Scena.drone2.position[1] = Scena.drone2.position[0];

  double choice_drone;

  char choice = 'a';
  while (choice != 'k'){
  
    Lacze.Rysuj();
    switch( choice ){

      case 'p':{ 
        double angle, lenght;
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
      // case 'b':{ 
      //   double angle1, angle2, lenght1, lenght2;
      //   cout << "Enter the direction for drone 1 (angle in degrees): " << endl << Scena.drone1.position[0] << endl;
      //   cin >> angle1;
      //   cout << "Enter the lenght of the flight: ";
      //   cin >> lenght2;
      //   cout << "Enter the direction for drone 2 (angle in degrees): " << endl << Scena.drone2.position[0] << endl;
      //   cin >> angle2;
      //   cout << "Enter the lenght of the flight: ";
      //   cin >> lenght2;
      //   choice_drone = 1;
      //     Scena.Make_Path(Lacze, choice_drone, Path_V1, lenght1, angle1);
      //     Lacze.Rysuj();
      //     Scena.drone1.Relocate(Scena.drone1.position[0], choice_drone, angle1, lenght1, Lacze, NamesFilesLoc_V1, NamesFilesProp_V1);
      //     Scena.drone1.position[0] = Scena.drone1.position[1];
      //     Lacze.UsunNazwePliku(Path_V1);
        
      //     Scena.Make_Path(Lacze, choice_drone, Path_V2, lenght2, angle2);
      //     Lacze.Rysuj();
      //     Scena.drone2.Relocate(Scena.drone2.position[0],choice_drone, angle2,lenght2, Lacze, NamesFilesLoc_V2, NamesFilesProp_V2);
      //     Scena.drone2.position[0] = Scena.drone2.position[1];
      //     Lacze.UsunNazwePliku(Path_V2);

      // break;}

      case 'm':{
        cout << "m - menu" << endl;
        cout << "a - choose active drone" << endl;
        cout << "p - parameters of the flight" << endl;
        cout << "w - number of used vectors" << endl;
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


      case 'k':{
        cout << "the end" << endl;
        break;}

      case 'a':{
        choice_drone = '_';
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
          choice = 'a';
        }
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


