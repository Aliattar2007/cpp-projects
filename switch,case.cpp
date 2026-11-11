#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <cstring>
using namespace std;
 

  void showMenu() 
  {
    cout << "\n=== Menu ===" << endl;
    cout << "1. Add" << endl;
    cout << "2. Show All" << endl;
    cout << "3. Search" << endl;
    cout << "4. Delete" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: " ;
}
  int main()
  { 
    int choice;
    do{
        showMenu();
        cin>>choice;
        switch (choice)
        {
        case 1:"Add";break;
        case 2:"showa All";break;
        case 3:"search";break;
        case 4: "Delet" ;break;
        case 5:"Exit";break;   
        }  
         }
         while(choice!=0) ;
    
            

        
       system("pause");
       
  }
    


  