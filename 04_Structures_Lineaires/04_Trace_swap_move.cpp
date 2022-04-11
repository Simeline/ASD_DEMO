//---------------------------------------------------------
// Fichier        : 04_Trace_swap_move.cpp
// Version        : 01 - 2022-04-11
// Auteur(s)      : BREGUET Guy-Michel
// But            : démontrer l'effect des constructeurs et destructeurs
//                : avec swap et move
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//---------------------------------------------------------
class Trace {
   friend ostream& operator<< (ostream& os, const Trace& t) {
      return os << t.data;
   }
   
public:
   Trace()           : data(0)               { cout << "C0(" << data << ") ";   }

   Trace(int data)   : data(data)            { cout << "Ci(" << data << ") ";   }

   Trace(const Trace& other)                 { this->data = other.data;
                                               cout << "CC(" << data << ") ";   }
   Trace(Trace&& other) noexcept
   : data(other.data)                        { other.data = 0;
                                               cout << "CD(" << data << ") ";   }

   ~Trace()                                  { cout << "D("  << data << ") ";   }

   void swap(Trace& other) noexcept          { using std::swap;
                                               std::swap(data, other.data);
                                               cout << "swap(" << data << ") "; }

   Trace& operator=(const Trace& other)      { this->data = other.data;
                                               cout << "=C("  << data << ") ";
                                               return *this;                    }

   Trace& operator=(Trace&& other) noexcept  { this->swap(other);
                                               cout << "=D(" << data << ") ";
                                               return *this;                    }
private:
   int data;
};

//---------------------------------------------------------
// pas utilisé dans ce code
void swap(Trace& lhs, Trace& rhs) noexcept   { lhs.swap(rhs); }

//---------------------------------------------------------
int main() {
   
   cout << endl;
   cout << "----------------------------------------" << endl;
   cout << "   constructeurs"                         << endl;
   cout << "----------------------------------------" << endl;
   Trace trace1a;                                cout << endl;
   Trace trace1b(1);                             cout << endl;
   Trace trace1c(trace1a);                       cout << endl;
   Trace trace1d(Trace(2));                      cout << endl;
   vector<Trace> vect(3, Trace(2));              cout << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   affectations"                          << endl;
   cout << "----------------------------------------" << endl;
   Trace trace2a(2);                             cout << endl;
   trace2a = trace1a;                            cout << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   destructeurs"                          << endl;
   cout << "----------------------------------------" << endl;
   Trace* ptr = new Trace(4);
   delete ptr;
   ptr = nullptr;
   cout << endl << endl;

   cout << "----------------------------------------" << endl;
   cout << "   swap"                                  << endl;
   cout << "----------------------------------------" << endl;
   cout << "trace1a : " << trace1a                    << endl;
   cout << "trace1b : " << trace1b                    << endl;
   trace1a.swap(trace1b);                        cout << endl;
   cout << "trace1a : " << trace1a                    << endl;
   cout << "trace1b : " << trace1b                    << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   déplacement"                           << endl;
   cout << "----------------------------------------" << endl;
   cout << "trace1a : " << trace1a                    << endl;
   cout << "trace1b : " << trace1b                    << endl;
   trace1a = std::move(trace1b);                 cout << endl;
   cout << "trace1a : " << trace1a                    << endl;
   cout << "trace1b : " << trace1b                    << endl;
   cout << endl;

   cout << "----------------------------------------" << endl;
   cout << "   sortie de main"                        << endl;
   cout << "----------------------------------------" << endl;
   return EXIT_SUCCESS;
}


//      ----------------------------------------
//         constructeurs
//      ----------------------------------------
//      C0(0)
//      Ci(1)
//      CC(0)
//      Ci(2)
//      Ci(2) CC(2) CC(2) CC(2) D(2)
//
//      ----------------------------------------
//         affectations
//      ----------------------------------------
//      Ci(2)
//      =C(0)
//
//      ----------------------------------------
//         destructeurs
//      ----------------------------------------
//      Ci(4) D(4)
//
//      ----------------------------------------
//         swap
//      ----------------------------------------
//      trace1a : 0
//      trace1b : 1
//      swap(1)
//      trace1a : 1
//      trace1b : 0
//
//      ----------------------------------------
//         déplacement
//      ----------------------------------------
//      trace1a : 1
//      trace1b : 0
//      swap(0) =D(0)
//      trace1a : 0
//      trace1b : 1
//
//      ----------------------------------------
//         sortie de main
//      ----------------------------------------
//      D(0) D(2) D(2) D(2) D(2) D(0) D(1) D(0) Program ended with exit code: 0