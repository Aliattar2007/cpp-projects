#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name[4];
    string lastname[4];
    double grade[4];
    
    ifstream f("grade.txt");
    if(!f)
    {
        cout<<"eror";
        exit(-1);
    }
    
       
        int i=0;
       while(f>>name[i]>>lastname[i]>>grade[i])
       {
        i++;
       }
    
      f.close();
     
    ofstream g("grade.txt");
    if(!g)
    {
        cout<<"eror";
        exit(-1);
    }
      int n=i;
       for(int i=0;i<n;i++)
       {
        if(grade[i]<=18)
       {
        grade[i]+=2;  
       }
        g<<name[i]<<"  "<<lastname[i]<<"  "<<grade[i]<<endl;
       
       }

        g.close();


     system("pause");
    }
    