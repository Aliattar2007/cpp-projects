  #include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  
    ofstream f("d.txt");

    f << "Alireza " << 18 << endl;
    f << "Fathad " << 19 << endl;
    f << "Reza " << 9.4 << endl;

    f.close();

    
    string name[3];
    double grade[3];

    ifstream g("d.txt");

    for (int i = 0; i < 3; i++)
    {
        g >> name[i] >> grade[i];

        if(grade[i]<=18){
        grade[i] += 2;}
    }

    g.close();

    
    ofstream s("d.txt");

    for (int i = 0; i < 3; i++)
    {
         s<< name[i] << " " << grade[i] << endl;
    }

    s.close();

    return 0;
    system("pause");
}

       



      