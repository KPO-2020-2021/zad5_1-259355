#include "Block.hh"

/******************************************************************************
 |  Konstruktor klasy Block.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Block wypelnione wartoscia 0.                                       |
 */
Block::Block() {
    for (int i = 0; i < 28; ++i) {
        for(int j = 0; j < SIZE; ++j) {
        rotor[i][j] = 0;
    }
    }
}


/**
 * Metoda przyjmujaca jeden argument pozwalajaca poruszac sie po tablicy wierzcholkow
 * @param tablica wektorow 3D
 * @return nothing
 */ 
Block::Block(Vector3 tmp[28]) {
    for (int i = 0; i < 28; ++i) {
        for(int j = 0; j < SIZE; ++j) {
        rotor[i][j] = tmp[i][j];
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
double &Block::operator()(unsigned int row, unsigned int column) {

    if (row >= 28) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return rotor[row][column];
}


/**
 * Funktor Wektora (const) pilnujacy czy nie wychodzimy poza tablice wektora
 * @param int numer wiersza
 * @return wektor
 */ 
const Vector3 &Block::operator () (unsigned int row) const {

    if (row >= 28) {
        throw std::out_of_range("Error: Vector jest poza zasiegiem");
    }

    return rotor[row];
}

/**
 * Przeciazenie operatora () (const) indeksowania dla Blocka z odpowiednimi zabezpieczeniami
 * @param int numer wiersza
 * @param int numer kolumny 
 * @return Tablica wierzcholkow
 */ 
const double &Block::operator () (unsigned int row, unsigned int column) const {

    if (row >= 28) {
        throw std::out_of_range("Error: Blockoscian jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Blockoscian jest poza zasiegiem");
    }

    return rotor[row][column];
}



Block Block::InitOne(const char * StrmWe, const char * StrmWy, double scalex, double scaley, double scalez,
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
    for(int i = 0; i < 28; ++i){
        FileWe >> x >> y >> z;
        double arg[] = {x,y,z};
        Vector3 vec = Vector3(arg);
        this->rotor[i] = vec;
        vec = matrixturn.after_z() * vec;   
        x = vec[0];
        y = vec[1];
        z = vec[2]; 
        rotor[i][0] = x * scalex + trans_x ;
        rotor[i][1] = y * scaley + trans_y ;
        rotor[i][2] = z * scalez + trans_z ;

        if(i%4 == 0){
        FileWy << std::endl;
        FileWy << rotor[i][0] << " " << rotor[i][1] << " " << rotor[i][2] << std::endl;
        }
        else{
        FileWy << rotor[i][0] << " " << rotor[i][1] << " " << rotor[i][2] << std::endl;}
    } 

    return *this;
}






