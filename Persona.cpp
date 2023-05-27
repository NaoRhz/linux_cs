
// Includes
//#include <iostream>
#include "Persona.hpp"
#include "formato.hpp"

// para stringstream
#include <sstream>

// Para evitar todo el codigo de doctest al compilar.
// Util cuando se mezcla implementacion con pruebas en el mismo fichero
//#define DOCTEST_CONFIG_DISABLE
#include "doctest.h"

// Variables globales (mejor que no existan). Por ejemplo:
//int version_modulo = 1;

using namespace std;

Persona::Persona(string nom, FormatoPersona* form) {
    nombre = nom;
    formato = form;
}
string Persona::get_nombre() const {
    return nombre;
}

/** Lo unico que hace es invocar al metodo aTexto() del objeto
* apuntado por formato para que genere texto con los datos
* de este objeto (puntero this).
*/
string Persona::a_texto() const {
    return formato->a_texto(this);
}

TEST_CASE( "Probando Persona::a_texto" ) {
    Persona p("Nombre", new FormatoBreve());
    REQUIRE( p.a_texto() == "Persona(Nombre)" );

    Persona p2("Nombre", new FormatoLargo());
    REQUIRE( p2.a_texto() == "Persona(nombre=Nombre)" );
}


