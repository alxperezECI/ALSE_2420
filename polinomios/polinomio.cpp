#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include "polinomio.h"

using namespace std;

typedef std::pair<int, float> termino;

Polinomio::Polinomio(char var) {
    _grado = -1;
    _variable = var;
}

Polinomio::Polinomio(string pol) {
    _grado = -1;
    _variable = 0;
    redefinir( pol );
}
  
Polinomio::Polinomio(const Polinomio &c){
  if( this != &c ){
    _variable = c._variable;
    _grado = c._grado;
    _terminoL = c._terminoL;
  }
}

Polinomio::~Polinomio(){
    borrar();
}

Polinomio Polinomio::operator=( const Polinomio &a ){
    if( this != &a ){
        _variable = a._variable;
        _grado = a._grado;
        _terminoL = a._terminoL;
    }
    return *this;
}

Polinomio Polinomio::operator+( const Polinomio &a ){
    Polinomio c('X');
    list<termino>::const_iterator it;
    for(it = _terminoL.begin(); it != _terminoL.end(); ++it){
        c.nuevoTermino( it->second, it->first );
    }
    for(it = a._terminoL.begin(); it != a._terminoL.end(); ++it){
        c.nuevoTermino( it->second, it->first);
    }
    c.simplificar();
    return c;
  }
  /// @brief 
  /// @param a 
  /// @return 

  Polinomio Polinomio::operator-( const Polinomio &a ){
    Polinomio c('X');
    list<termino>::const_iterator it;
    for(it = _terminoL.begin(); it != _terminoL.end(); ++it){
        c.nuevoTermino( it->second, it->first );
    }
    for(it = a._terminoL.begin(); it != a._terminoL.end(); ++it){
        c.nuevoTermino( -(it->second), it->first );
    }
    c.simplificar();
    c.ordenar();
    return c;
  }

    Polinomio Polinomio::operator*( const Polinomio &a ){
        Polinomio c('X');
        list<termino>::const_iterator it1, it2;
        for(it1 = _terminoL.begin(); it1 != _terminoL.end(); ++it1){
            for(it2 = a._terminoL.begin(); it2 != a._terminoL.end(); ++it2){
                c.nuevoTermino( it1->second * it2->second, it1->first + it2->first );
            }
        }
        c.simplificar();
        c.ordenar();
        return c;
    }

    Polinomio Polinomio::operator/( const double &a ){
        Polinomio c('X');
        list<termino>::const_iterator it,it2;
        for(it = _terminoL.begin(); it != _terminoL.end(); ++it){
            c.nuevoTermino( it->second / a , it->first );
        }
        c.simplificar();
        c.ordenar();
        return c;
    }


 bool Polinomio::operator==( const Polinomio &a ) {
    if (_variable != a._variable) {
        return false;
    }
    if (_grado != a._grado) {
        return false;
    }
    if (_terminoL.size() != a._terminoL.size()) {
        return false;
    }
    list<termino>::const_iterator it1 = _terminoL.begin();
    list<termino>::const_iterator it2 = a._terminoL.begin();
    while (it1 != _terminoL.end() && it2 != a._terminoL.end()) {
        if (it1->second != it2->second) {
            return false;
        }
        if (it1->first != it2->first) {
            return false;
        }
        ++it1;
        ++it2;
    }
    return true;
}


ostream& operator<<(std::ostream& out, Polinomio a){
    out << a.getString();
    return out;
}

bool Polinomio::borrar(){
    _terminoL.clear();
    _grado = -1;
    return true;
}

bool Polinomio::ordenar(){
    _terminoL.sort();
    _terminoL.reverse();
    return true;
}
  
void Polinomio::nuevoTermino(float c, int p) {
    termino a(p,c);
    _terminoL.push_back( a );
    return;
}
  
bool Polinomio::redefinir(string pol) {
    borrar();
    string term;
    //cout << pol << endl;
    size_t posM, posm, posT1, posT2, found;
    posT1 = posT2 = 0;
    float coeff = 0.;
    int power = 0;

    while( posT2 != string::npos ){
        // Encontrando cada termino
        posM = pol.find_first_of("+", posT1 + 1 );
        posm = pol.find("-", posT1 + 1);
        // cout << posM << " " << posm << endl;
        if( posM != string::npos )
            posT2 = min(posM, posm);
        else if( posM == string::npos )
            posT2 = posm;
        else
            posT2 = posM;

        //cout << posT1 << " " << posT2 << endl;
        term = pol.substr( posT1, posT2 - posT1 );
        posT1 = posT2;
       // cout << term << endl;

        // Porcesando el termino
        if(_variable == 0){
            //cout << "variable" << endl;
            found = term.find_first_not_of("+-1234567890.,");
            //cout << term[found] << endl;
            if (found != std::string::npos)
              _variable = term[found] ;
        }

        found = term.find( _variable );
        if( found == string::npos ){
            //cout << "independiente" << endl;
            coeff = atof( term.c_str() );
            power = 0;
        }else{
            found = term.find( '^' );
            if( found != string::npos ){ // Tiene potencia > 1
                //cout << "pot >1" << endl;
                power = atoi( term.substr( found+1 ).c_str() );
                coeff = atof( term.substr( 0, term.size() - found +1 ).c_str() );
            }else{
                power = 1;
                coeff = atof( term.substr( 0, term.size() - 1 ).c_str() );
            }
        }

        //cout << "coeff: " << coeff << " y power: " << power << endl;
        // Adicionar el término encontrado
        nuevoTermino( coeff, power );
        _grado = power > _grado ? power : _grado ;
    }
    //cout << getString() << endl;
    return true;
}
  
bool Polinomio::simplificar() {
    list<termino>::iterator it1 = _terminoL.begin();
    while (it1 != _terminoL.end()) {
        list<termino>::iterator it2 = next(it1);
        while (it2 != _terminoL.end()) {
            if (it1->first == it2->first) {
                it1->second += it2->second;
                it2 = _terminoL.erase(it2);
            } else {
                ++it2;
            }
        }
        if (it1->second == 0) {
            it1 = _terminoL.erase(it1);
        } else {
            ++it1;
        }
    }

    if (_terminoL.empty()) {
        it1= _terminoL.insert(it1, termino(0, 0));
    }
    
    return true;
}

string  Polinomio::getString(){
    stringstream stream;
    std::list<termino>::iterator it;
    for(it = _terminoL.begin(); it != _terminoL.end(); ++it){
        if(it->second > 0) stream << "+";
            stream << it->second ;
        if(it->first > 0 ){
            stream << _variable;
            if( it->first > 1 )
                stream << "^" << it->first;
        }
    }
    return stream.str();
}