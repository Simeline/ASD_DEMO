//---------------------------------------------------------
// Fichier        : 01_vect_sort.cpp
// Version        : 01 - 2022-03-03
// Auteur(s)      : BREGUET Guy-Michel
// But            : tri d'un vector
// Modifications  :
// Remarque(s)    : NILL
// Application    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm> // generate et sort

using namespace std;

//------------------------------------------------------
int generateur();

//------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, vector<T> v);

//------------------------------------------------------
template <typename T>
vector<T> create(size_t taille);

//------------------------------------------------------
template <typename T>
void sortVecteur(vector<T>& v);

//------------------------------------------------------
template <typename T, typename Fonction>
void sortVecteurFct(vector<T>& v, Fonction fct);

//------------------------------------------------------
template <typename Iterator>
void sortIterator(Iterator begin, Iterator end);

//------------------------------------------------------
// main
//------------------------------------------------------
int main () {

   // vecteurs de travail
   vector<int> v1, v2, v3;
   v1 = v2 = v3 = create<int>(5);

   sortVecteur(v1);
   cout << v1 << endl;

   sortIterator(v2.begin(), v2.end());
   cout << v2 << endl;

   sortVecteurFct(v3, std::sort);
   cout << v3 << endl;

   return EXIT_SUCCESS;
}  // main

//------------------------------------------------------
template <typename T>
ostream& operator<< (ostream& os, vector<T> v) {
   os << "[";
   for (size_t i=0; i<v.size(); ++i) {
      if (i)
         os << ", ";
      os << v[i];
   }
   os << "]";
   return os;
}

//------------------------------------------------------
template <typename T>
vector<T> create(size_t taille) {
   vector<T> resultat(taille);
   generate(resultat.begin(), resultat.end(), generateur);
   return resultat;
}

//------------------------------------------------------
template <typename T>
void sortVecteur(vector<T>& v) {
   sortIterator(v.begin(), v.end());
}

//------------------------------------------------------
template <typename T, typename Fonction>
void sortVecteurFct(vector<T>& v, Fonction fct) {
   sort(v.begin(), v.end());
}

//------------------------------------------------------
template <typename Iterator>
void sortIterator(Iterator begin, Iterator end) {
   sort(begin, end);
}

//------------------------------------------------------
int generateur() {
   // initialisation du générateur
   static bool first = true;
   if (first) {
      srand((unsigned)time(NULL));
      first = false;
   }

   // generation d'une valeur aléatoire
   return rand() % numeric_limits<int>::max();
}
