#include "GranBlock.hh"

/******************************************************************************
 |  Konstruktor klasy GranBlock.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      GranBlock wypelnione wartoscia 0.                                       |
 */
GranBlock::GranBlock() {
    for (int i = 0; i < 28; ++i) {
        for(int j = 0; j < SIZE; ++j) {
        figure[i][j] = 0;
    }
    }
}


/**
 * Metoda przyjmujaca jeden argument pozwalajaca poruszac sie po tablicy wierzcholkow
 * @param tablica wektorow 3D
 * @return nothing
 */ 
GranBlock::GranBlock(Vector3 tmp[28]) {
    for (int i = 0; i < 28; ++i) {
        for(int j = 0; j < SIZE; ++j) {
        figure[i][j] = tmp[i][j];
    }
    }
}

/**
 * Przeciazenie operatora indeksowania pilnujaca czy nie wychodzi poza zakres
 * Przyjmuje dwa argument: 
 * @param int numer wiersza
 * @param int numer kolumny 
 * @return tablica wierzcholkow
 */ 
double &GranBlock::operator()(unsigned int row, unsigned int column) {

    if (row >= 28) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return figure[row][column];
}


/**
 * Funktor Wektora (const) pilnujacy czy nie wychodzimy poza tablice wektora
 * @param int numer wiersza
 * @return wektor
 */ 
const Vector3 &GranBlock::operator () (unsigned int row) const {

    if (row >= 28) {
        throw std::out_of_range("Error: Vector jest poza zasiegiem");
    }

    return figure[row];
}

/**
 * Przeciazenie operatora () (const) indeksowania dla GranBlocka z odpowiednimi zabezpieczeniami
 * @param int numer wiersza
 * @param int numer kolumny 
 * @return Tablica wierzcholkow
 */ 
const double &GranBlock::operator () (unsigned int row, unsigned int column) const {

    if (row >= 28) {
        throw std::out_of_range("Error: Blockoscian jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Blockoscian jest poza zasiegiem");
    }

    return figure[row][column];
}

/**
 * Funkcja obracajaca punkty x i y wokol osi Oz
 * @param double angle
 * @param double &x_position
 * @param double &y_position
 */
void GranBlock::TurnByOZ(double angle, double &x_position, double &y_position){

    angle = this->toradians(angle);
    
    double sn = sin(angle), cn = cos(angle);

    x_position = x_position*cn - y_position*sn;
    y_position = x_position*sn + y_position*cn; 

}

/**
 * Funkcja zmieniajaca liczbe na radiany
 * @param double angle
 * @return double angle
 */
double GranBlock::toradians(double angle){
    angle = (angle * M_PI)/180;
    return angle;
}

/**
 * Funkcja inicjujaca poszczegolne Blocki - rotory
 * @param const char *StrmWe
 * @param const char *StrmWy
 * @param double num_of_peak
 * @param double scalex
 * @param double scaley
 * @param double scalez
 * @param double angle
 * @param double trans_x
 * @param double trans_y
 * @param double trans_z
 * @return GranBlock figure
 */
GranBlock GranBlock::Init_The_Figure(const char * StrmWe, const char * StrmWy, double num_of_peak, double scalex, double scaley, double scalez,
 double trans_x, double trans_y, double trans_z, double angle){
    
    std::ifstream FileWe(StrmWe);
    std::ofstream FileWy(StrmWy);

    Matrix3 matrixturn;
    FileWe.clear();
    FileWe.seekg(0);
    double x,y,z;
    assert(FileWe.good());
    assert(FileWy.good());
    matrixturn.angle = angle;
    matrixturn.toradians();
    for(int i = 0; i < num_of_peak; ++i){
        FileWe >> x >> y >> z;
        double arg[] = {x,y,z};
        Vector3 vec = Vector3(arg);
        this->figure[i] = vec;
        vec = matrixturn.after_z() * vec;   
        x = vec[0];
        y = vec[1];
        z = vec[2]; 
        figure[i][0] = x * scalex + trans_x ;
        figure[i][1] = y * scaley + trans_y ;
        figure[i][2] = z * scalez + trans_z ;

        if(i%4 == 0){
        FileWy << std::endl;
        FileWy << figure[i][0] << " " << figure[i][1] << " " << figure[i][2] << std::endl;
        }
        else{
        FileWy << figure[i][0] << " " << figure[i][1] << " " << figure[i][2] << std::endl;}
    } 

    return *this;
}

