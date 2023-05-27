// Para evitar la inclusion de este modulo mas de una vez.
// Pero pragma once no esta soportado en todos los compiladores
//#pragma once
#ifndef PERSONA_h
#define PERSONA_h

// Descripcion del modulo

// Includes necesarios para usar este modulo
#include <string>
//#include "formato.hpp"
//Para resolver las dependencias circulares
class FormatoPersona;

// Variables globales (mejor que no existan). Por ejemplo:
//extern int version_modulo = 1;

// Interfases de funciones

//using namespace std;

/** Clase para manejar datos de una persona.
* Al constructor se le pasa un puntero a un objeto de tipo
* FormatoPersona que sera el usado al generar texto con los datos de persona
* en el metodo aTexto().
* Cambiando el objeto FormatoPersona cambiaremos el comportamiento
* del metodo aTexto().
*/
class Persona {
public:
    Persona(std::string nom, FormatoPersona* form);
    std::string get_nombre() const;
    /** Delega sus acciones al metodo aTexto() del objeto
    * apuntado por formato.
    */
    std::string a_texto() const;
private:
    std::string nombre;
    FormatoPersona* formato;
};

#endif // PERSONA_h
