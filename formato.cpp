#include <iostream>
#include "formato.hpp"
#include "Persona.hpp"

// para stringstream
#include <sstream>
// para string
#include <string>

// Para evitar todo el codigo de doctest al compilar.
// Util cuando se mezcla implementacion con pruebas en el mismo fichero
//#define DOCTEST_CONFIG_DISABLE
#include "doctest.h"

using namespace std;


//==========================
// Clase FormatoBreve
//==========================
std::string FormatoBreve::a_texto(const Persona* ppersona) const {
    //return "Persona(" + ppersona->get_nombre() + ")";
    std::stringstream ss;
    ss << "Persona(" << ppersona->get_nombre() << ")";
    return ss.str();
}
TEST_CASE( "Probando FormatoBreve::a_texto" ) {
    Persona p("Nombre", new FormatoBreve());
    //REQUIRE( p.aTexto() == "Persona(Nombre" );
    /* ASI NO COMPILA
    FormatoBreve f();
    REQUIRE( f.aTexto(&p) == "Persona(Nombre)" );*/
    // ASI SI COMPILA
    FormatoPersona *pf = new FormatoBreve();
    REQUIRE( pf->a_texto(&p) == "Persona(Nombre)" );
}


//==========================
// Clase FormatoLargo
//==========================

std::string FormatoLargo::a_texto(const Persona* ppersona) const {
    return "Persona(nombre=" + ppersona->get_nombre() + ")";
    /*std::stringstream ss;
    ss << "Persona(nombre=" << ppersona->get_nombre() << ")";
    return ss.str();*/
}
TEST_CASE( "Probando FormatoLargo::a_texto" ) {
    Persona p("Nombre", new FormatoBreve());
    //REQUIRE( p.aTexto() == "Persona(Nombre" );
    /* ASI NO COMPILA
    FormatoBreve f();
    REQUIRE( f.aTexto(&p) == "Persona(Nombre)" );*/
    // ASI SI COMPILA: necesita trabajar a partir de puntero a formato
    FormatoPersona *pf = new FormatoLargo();
    REQUIRE( pf->a_texto(&p) == "Persona(nombre=Nombre)" );
}

