#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <cstring>
using namespace std;
 
 struct student
 {
   int age;
   double grade;
   string name;

 };

void savetofile(student s[],int n)
 {
    ofstream f("s.txt");
  if(!f){
    cout<<"erore";
    exit(-1);
  }    
    for(int i=0;i<3;i++)
    {
        f<<s[i].age<<"-"<<s[i].grade<<"-"<<s[i].name<<endl;
    }
    f.close();
    
 }
   
 int main()
 {
     student s[3]= {
        {19,18.4,"Ali"},{19,16,"Sadra"},{19,17.75,"Reza"}

        };
           savetofile(s,3);
     
     


     
     system("pause");
 
 }
  