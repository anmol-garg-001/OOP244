#include "Student.h"
using namespace sdds;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}