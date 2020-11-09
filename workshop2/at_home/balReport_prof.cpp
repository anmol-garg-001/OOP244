#include "Account.h"
using namespace sdds;
int main() {
   if (load("accounts_prof.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}
