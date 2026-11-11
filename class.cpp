#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
int main()
{
    string name[4];
    double grade[4];

    ifstream f("class.txt");
    if(!f)
    {
        cout<<"eror...";
        exit(-1);
    }
      
        
         while(getline(f>>ws,name[i],grade[i],',')){
          if(grade[i]<=18)
           grade[i]+=2;
        }
        f.close();

        ofstream g("class.txt");
         if(!g)
    {
        cout<<"eror...";
        exit(-1);
    } 
         for(int i=0;i<4;i++)
        g<<name[i] <<" "<<grade[i]<<endl;
          g.close();

  system("pause");

}
