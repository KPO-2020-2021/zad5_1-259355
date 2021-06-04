#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.
#include "../tests/doctest/doctest.h"
#include "scena.hh"

const char *NamesFilesLoc_V1[] = {SZESCIAN_ZM_LOC,ROTORYLOC_1,ROTORYLOC_2,ROTORYLOC_3,ROTORYLOC_4, nullptr};
const char *NamesFilesProp_V1[] = {SZESCIAN_ZM,ROTORY_1,ROTORY_2,ROTORY_3,ROTORY_4, nullptr};

const char *NamesFilesLoc_V2[] = {SZESCIAN_ZM_LOC_V2,ROTORYLOC_1_V2,ROTORYLOC_2_V2,ROTORYLOC_3_V2,ROTORYLOC_4_V2, nullptr};
const char *NamesFilesProp_V2[] = {SZESCIAN_ZM_V2,ROTORY_1_V2,ROTORY_2_V2,ROTORY_3_V2,ROTORY_4_V2, nullptr};

TEST_CASE("Matrix3 - turn by z"){
    PzG::LaczeDoGNUPlota Lacze;
    Drone drone1;
    double arg1[] = {20,20,0};
    drone1.position[0] = Vector3(arg1);
    drone1.Engage2(0, drone1.position[0], NamesFilesLoc_V1, NamesFilesProp_V1,0);
    double angle, lenght, choice_drone;
    angle = 35;
    lenght = 100;
    choice_drone = 1;
    drone1.Relocate(drone1.position[0], choice_drone, angle, lenght, Lacze, NamesFilesLoc_V1, NamesFilesProp_V1);
    SUBCASE("Cheking end position"){
        double x_position = 101.9152044289;
        double y_position = 77.3576436351;
        double z_position = 0;
    CHECK((drone1.position[1][0] - x_position) <= MIN_DIFF);
    CHECK((drone1.position[1][1] - y_position) <= MIN_DIFF);
    CHECK((drone1.position[1][2] - z_position) <= MIN_DIFF);
    }
    SUBCASE("Checking amount of used vectors"){
        double vec_in_use = 29387;
        double vec_used = 244662;
    CHECK(drone1.position[0].amount_active_vectors() == vec_in_use);
    CHECK(drone1.position[0].amount_of_all_vectors() == vec_used);
    }
}

TEST_CASE("Inheritance of functions"){

   Prostopadl pro;
   Vector3 scale, trans;
   double num_peaks, angle;

   pro.Init_The_Figure(NamesFilesLoc_V1[0],NamesFilesProp_V1[0], num_peaks, scale, trans, angle);
   CHECK( 1 == 1 ); 
}

TEST_CASE("Scout landing in same spot "){

   PzG::LaczeDoGNUPlota Lacze;
    Drone drone1;
    double arg1[] = {20,20,0};
    drone1.position[0] = Vector3(arg1);
    drone1.Engage2(0, drone1.position[0], NamesFilesLoc_V1, NamesFilesProp_V1,0);
    double angle, lenght, choice_drone;
    angle = 35;
    lenght = 100;
    choice_drone = 1;
    drone1.Scouting(drone1.position[0], choice_drone, angle, Lacze, NamesFilesLoc_V1, NamesFilesProp_V1);

   CHECK( drone1.position[0] = drone1.position[1] ); 
}