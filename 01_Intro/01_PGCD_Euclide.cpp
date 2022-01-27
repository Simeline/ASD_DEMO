//---------------------------------------------------------
// Fichier        : 01_PGCD_Euclide.cpp
// Version        : 01 - 2021-12-05
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'algorithme PGCD par Euclide
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------
int PGDC(int a, int b) {
   int r;
   while((r = a % b)) {
      a = b;
      b = r;
   }
   return b;
}

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   int a = 49;
   int b =  7;
   cout << "PGDC(" << a << ", " << b << ") = " << PGDC(a, b) << endl;

   return EXIT_SUCCESS;
}  // main
