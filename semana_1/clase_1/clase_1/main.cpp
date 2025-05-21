//
//  main.cpp
//  clase_1
//
//  Created by Santiago Cacho Herrera on 19/05/25.
//

#include <iostream>
#include "MiprimerObjeto.cpp"
using namespace std;

int main() {
    Persona persona1("Juan", 25, "varitono");
    persona1.presentarse();
    
    Persona persona2("Jesus", 40, "tenor");
    persona2.presentarse();
    
    persona2.cantar();
    persona2.tono();
    
    return 0;
}
