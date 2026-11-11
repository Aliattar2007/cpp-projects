#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

double broker(double sell,double rate)
{
  return (sell*rate/100);
}
void square(double price,double rate)
{
  double a,s,b;
  cout<<"a";
  cin>>a;
  s=a*a;
  double kol=s*price+ broker(s*price,rate);
  cout<<kol;
}
void Rectangle(double price,double rate)
{
   double a,s,b;
    cout<<"a"<<"b";
    cin>>a>>b;
    s=a*b;
    double kol=s*price+ broker(s*price,rate);
    cout<<kol;
}

void Triangle(double price,double rate)
{
    double s,p,a,b,c;
    cout<<"a"<<"b:"<<"c";
    cin>>a>>b>>c;
     p=(a+b+c)/2;
  s=sqrt(p*(p-a)*(p-b)*(p-c));
  double kol=s*price+ broker(s*price,rate);
   cout<<kol;
}
void circle(double price,double rate)
{
   double p=3.14,r,s;
   cout<<"r:";
   cin>>r;
    s=p*r*r;
   double kol=s*price+ broker(s*price,rate);
   cout<<kol;
}

   void showMenu()
   {
    cout << "\n=== Menu ===" << endl;
    cout<<"1.square"<<endl;
    cout<<"2.Rectangl"<<endl;
    cout<<"3.Trianglel"<<endl;
    cout<<"4.circle"<<endl;
    cout<<"0.exit menu"<<endl;
    cout << "Choice: " ;

   }

 int main()
 {

   
  double price,rate;
  cout<<"price: "<< price<<"    "<<"rate: "<<rate;
    int choice;
    do
   {
    showMenu();
    cin >> choice;
   switch (choice)
   {
     case 1:  square   (price, rate);break;
     case 2:  Rectangle(price, rate);break;
     case 3:  Triangle ( price, rate);break;
     case 4:  circle   (price,rate);break;
     case 0:cout<<"goodbye";break;
    }
   }
   while (choice!=0);
   
   
   
   

   system("pause");
 }