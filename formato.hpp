// Para evitar la inclusion de este modulo mas de una vez.
// Pero pragma once no esta soportado en todos los compiladores
//#pragma once
#ifndef FORMATO_h
#define FORMATO_h

// Descripcion del modulo

// Includes necesarios para usar este modulo

// Variables globales (mejor que no existan). Por ejemplo:
//extern int version_modulo = 1;

// Interfases de funciones

//#include "Persona.hpp"
//Para resolver las dependencias circulares
class Persona;

//using namespace std;

/** Esta es una clase abstracta, no se puede instanciar
* puesto que tiene un metodo virtual puro.
* Es la base de todas las clases formato.
*/
class FormatoPersona {
public:
    /** Metodo para retornar como texto los datos de una persona.
    * Es virtual (palabra clave virtual) para que se pueda
    * sobreescribir en las clases herederas.
    * Y virtual pura (=0) para que no se pueda escribir en esta clase.
    */
    virtual std::string a_texto(const Persona* ppersona) const =0;
};

class FormatoBreve : public FormatoPersona {
public:
    virtual std::string a_texto(const Persona* ppersona) const;
};

class FormatoLargo : public FormatoPersona {
public:
    virtual std::string a_texto(const Persona* ppersona) const;
};

#endif  // FORMATO_h
