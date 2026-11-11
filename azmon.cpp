#include <iostream>
using namespace std;
int main()
{
    double grade;int p=0;int o=0;
   for(int i=1;i<=10;i++)
   {
     cout<<"enter grade : "<<endl;
     cin>>grade;
     if(grade<0 || grade >20)
     {
     cout<<"invalid grade!"<<endl;
      cout<<"enter grade : "; 
      cin>>grade;
     }

      if(grade>=10)  
      {
        p++;
        cout<<"Accepted"<<endl;
      }
     
     else if (grade<10) 
     {
         o++;
         cout<<"Rejected"<<endl;
     }

    }  
     cout<<"o :"<<o<<endl;
     cout<<"p :"<<p<<endl;
     if(p>8)
     {
        cout<<"Increase the tuition fee.";
     }
    
  system("pause");
}