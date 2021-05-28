#include "Block.hh"

// /******************************************************************************
//  |  Konstruktor klasy Block.                                                 |
//  |  Argumenty:                                                                |
//  |      Brak argumentow.                                                      |
//  |  Zwraca:                                                                   |
//  |      Block wypelnione wartoscia 0.                                       |
//  */
// Block::Block() {
//     for (int i = 0; i < 28; ++i) {
//         for(int j = 0; j < SIZE; ++j) {
//         rotor[i][j] = 0;
//     }
//     }
// }


// /**
//  * Metoda przyjmujaca jeden argument pozwalajaca poruszac sie po tablicy wierzcholkow
//  * @param tablica wektorow 3D
//  * @return nothing
//  */ 
// Block::Block(Vector3 tmp[28]) {
//     for (int i = 0; i < 28; ++i) {
//         for(int j = 0; j < SIZE; ++j) {
//         rotor[i][j] = tmp[i][j];
//     }
//     }
// }

// /**
//  * Przeciazenie operatora indeksowania pilnujaca czy nie wychodzi poza zakres
//  * Przyjmuje dwa argument: 
//  * @param int numer wiersza
//  * @param int numer kolumny 
//  * @return tablica wierzcholkow
//  */ 
// double &Block::operator()(unsigned int row, unsigned int column) {

//     if (row >= 28) {
//         throw std::out_of_range("Error: Macierz jest poza zasiegiem");
//     }

//     if (column >= SIZE) {
//         throw std::out_of_range("Error: Macierz jest poza zasiegiem");
//     }

//     return rotor[row][column];
// }


// /**
//  * Funktor Wektora (const) pilnujacy czy nie wychodzimy poza tablice wektora
//  * @param int numer wiersza
//  * @return wektor
//  */ 
// const Vector3 &Block::operator () (unsigned int row) const {

//     if (row >= 28) {
//         throw std::out_of_range("Error: Vector jest poza zasiegiem");
//     }

//     return rotor[row];
// }

// /**
//  * Przeciazenie operatora () (const) indeksowania dla Blocka z odpowiednimi zabezpieczeniami
//  * @param int numer wiersza
//  * @param int numer kolumny 
//  * @return Tablica wierzcholkow
//  */ 
// const double &Block::operator () (unsigned int row, unsigned int column) const {

//     if (row >= 28) {
//         throw std::out_of_range("Error: Blockoscian jest poza zasiegiem");
//     }

//     if (column >= SIZE) {
//         throw std::out_of_range("Error: Blockoscian jest poza zasiegiem");
//     }

//     return rotor[row][column];
// }


/**
 * Funkcja inicjujaca poszczegolne Blocki - rotory
 * @param const char *StrmWe
 * @param const char *StrmWy
 * @param Vector3 scale
 * @param double angle
 * @param Vector3 trans
 * @return Block rotor
 */
Block::Block(const char * StrmWe, const char * StrmWy, Vector3 scale,
 Vector3 trans, double angle){
    
    this->Init_The_Figure(StrmWe,StrmWy,28,scale, trans, angle);
    // this->vect_in_use2 += this->vect_in_use;
    // this->vect_used2 += this->vect_used;
    // return *this;
}






