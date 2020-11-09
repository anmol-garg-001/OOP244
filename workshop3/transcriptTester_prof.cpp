// Workshop 3:
// Version: 0.9
// Date: 10/02/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include "Transcript.h"
using namespace sdds;
int main() {
   Transcript T;
   T.init("Fred Soley", 21);
   T.add("APS145", 65);
   T.add("CPR101", 85);
   T.add("IPC144", 75);
   T.add("COM111", 95);
   T.add("ULI101", 88);
   T.add("DBS211", 80);
   T.add("DCF255", 80);
   T.add("OOP244", 88);
   T.add("WEB222", 90);
   T.add("EAC150", 75);
   T.add("DBS311", 100);
   T.add("OOP345", 98);
   T.add("SYD366", 75);
   T.add("WEB322", 85);
   T.add("WTP100", 60);
   T.add("CPA331", 88);
   T.add("BCI433", 90);
   T.add("EAC594", 87);
   T.add("JAC444", 77);
   T.add("SYS466", 65);
   T.display();
   T.add("WEB422", 100);
   // Premature call to display will result an error
   T.display();
   T.deallocate();
   return 0;
}