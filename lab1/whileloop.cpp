#include <iostream>
using namespace std;
 
int main () {
   // Local variable declaration:
   int i;
   cin >> i;
   // while loop execution
   while (i != -1 ) {
       
      if(i % 2 == 0){
          cout << "EVEN" << endl;
      }
      else{
          cout << "ODD" <<endl;
      }
      cin >> i;
   }
 
   return 0;
}