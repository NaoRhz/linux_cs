/*
Ejemplo de uso de herencia, composicion, delegacion, 
e inyeccion de dependencias en el constructor.
Muy similar al trabajo de C++ del curso.
*/
//Entrada/salida en C++
// para std::cin,cout,cerr; std::endl
#include <iostream>
//Entrada/salida en C y en C++
//#include <stdio.h>

//para EXIT_SUCCESS
#include <stdlib.h>

// para smart pointers: std::shared_ptr, std::make_shared, ...
#include <memory>

//cabecera/s de modulo/s usado/s

#include <string>

#include "Persona.hpp"
#include "formato.hpp"

// espacio de nombres de C++
// para usar por ejemplo std::endl como endl
using namespace std;



int main() {
    // ??? posible cambio de new FormatoBreve()
    //  por   std::make_shared<FormatoBreve>()
    cout << "== Persona con formato breve: ==" << endl;
    Persona p1("Antonio", new FormatoBreve());
    //Persona p1("Antonio", std::make_shared<FormatoBreve>());
    cout << p1.a_texto() << endl;

    cout << "== Persona con formato largo: ==" << endl;
    Persona p2("Maria", new FormatoLargo());
    cout << p2.a_texto() << endl;

  // Sustituye a return 0 por si en algun sistema retornar 0
  //  no significa "terminar bien"
  return EXIT_SUCCESS;
  //return EXIT_FAILURE;
  // En C++ puede no haber return y se interpreta como correcto
}
