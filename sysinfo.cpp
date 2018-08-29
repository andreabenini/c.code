#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call

using namespace std;
 
int main(){
   struct sysinfo info;                           // A structure that contains system stats
   sysinfo(&info);                                // retrieve the data
   int mins = info.uptime  / 60;                  // the uptime comes from the sysinfo struct
   int ram  = info.freeram / 1024 / 1024;         // the available memory in Mb
   cout << "Uptime : " << mins << " minutes" << endl;
   cout << "RAM    : " << ram << "Mb of memory available" << endl;
   return 0;
}
