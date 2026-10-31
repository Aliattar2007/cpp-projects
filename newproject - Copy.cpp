#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>

// Shop Management Project

using namespace std;

struct Visitor{
    string fullname;
    string phone_number;
    string visitor_code;

  };
  struct Order
  {
     string order_code;
     string visitor_code;
     string date;
     string  Status;  /*وضعیت سفارش*/
     int product_count;
     int quantity;     /*تعداد کالا */
     string name;
     double price;
    };  
   void Register_visitor()
 {
    Visitor v;

    cout << "Enter visitor code: ";
    cin >> v.visitor_code;

    cout << "Enter full name: ";
    getline(cin >> ws, v.fullname);

    cout << "Enter phone number: ";
    cin >> v.phone_number;

     while(v.phone_number.length()!=11)
     {
     cout<<"invalid phone number:";
     cin>>v.phone_number;
     }
     

    ofstream file("visitor.txt", ios::app);
    if (!file)
    {
        cout << "Can not open visitor file";
        exit(-1);
    }

    file << v.visitor_code << endl;
    file << v.fullname << endl;
    file << v.phone_number << endl;
    file.close();

      cout << "Visitor registered ";
    }     
 
            
   void Show_All_visitor()
  {
       Visitor v;
       bool found = false;

      ifstream file("visitor.txt");
      if (!file)
     {
        cout << "Can not open visitor file";
          exit(-1);
      }

       while (getline(file, v.visitor_code))
     {
         if (!getline(file, v.fullname))
            break;
        if (!getline(file, v.phone_number))
            break;

        cout << "Visitor code: " << v.visitor_code << endl;
        cout << "Full name: " << v.fullname << endl;
        cout << "Phone number: " << v.phone_number << endl;
      
        found = true;
    }

      file.close();

       if (!found)
        cout << "No visitors registered";
    }
     
  void Edit_visitor()
 {
    Visitor v;
    string search_code;
    bool found = false;

    cout << "Enter visitor code to edit: ";
    cin >> search_code;

    ifstream file("visitor.txt");
    ofstream temp("temp.txt");

      if (!file || !temp)
    {
       cout << "Can not open file";
      return;
    }

      while (getline(file >> ws, v.visitor_code))
    {
        if (!getline(file, v.fullname))
            break;

        if (!getline(file, v.phone_number))
            break;

        if (v.visitor_code == search_code)
    {
        found = true;

        cout << "Enter new full name: ";
        getline(cin >> ws, v.fullname);

        cout << "Enter new phone number: ";
        cin >> v.phone_number;
      }

        temp << v.visitor_code << endl;
        temp << v.fullname << endl;
        temp << v.phone_number << endl;
    }

    file.close();
    temp.close();

    if (!found)
    {
        remove("temp.txt");
        cout << "Visitor not found";
        return;
    }
    remove("visitor.txt");

    if (rename("temp.txt", "visitor.txt") == 0)
        cout << "Visitor edited successfully";
    else
        cout << "Error replacing visitor file";
   }





       void Serch_visitor()
   {
     
     Visitor v;
     string search_code;
     bool found = false;
     int choice;

      cout << "Enter visitor code: ";
      cin >> search_code;

     ifstream file("visitor.txt");
     if (!file)
    {
       cout << "Cannot open visitor file";
      exit(-1);
    }

      while (getline(file, v.visitor_code))
    {
       if (!getline(file, v.fullname))
            break;
       if (!getline(file, v.phone_number))
            break;
       if (v.visitor_code == search_code)
          {
            cout << "Visitor code: " << v.visitor_code << endl;
            cout << "Full name: " << v.fullname << endl;
            cout << "Phone number: " << v.phone_number << endl;
            found = true;

            cout<<"1-edit visitor"<<endl;
            cout<<"0-exit";
            cin>>choice;

            if(choice==1)
            {
            Edit_visitor();
             return;
            }
      }         
    }
       file.close();

        
        if(found!=true)
        cout<<"visitor not found";
      }

  void Dlelete_visitor()
   {
       Visitor v;
      string delete_code;
      bool found =false;

      cout<<"enter visitor code for delete : ";
      cin>> delete_code;

      ifstream file("visitor.txt");
      if(!file)
      {
        cout << "Can not open visitor file";
          exit(-1);
      }
      
      ofstream temp("temp.txt");
      if(!temp)
      {
          cout << "Can not open temp file";
          exit(-1);
      }

         while (getline(file, v.visitor_code))
    {
        if (!getline(file, v.fullname))
            break;

        if (!getline(file, v.phone_number))
            break;

        if (v.visitor_code == delete_code)
        {
            found = true;
        }
        else
        {
            temp << v.visitor_code << endl;
            temp << v.fullname << endl;
            temp << v.phone_number << endl;
        }
          file.close();
          temp.close();
      }
           if (found)
    {
      if (rename("visitor.txt", "old.txt") == 0)
     {
       if (rename("temp.txt", "visitor.txt") == 0)
      {
        remove("old.txt");
         cout << "Visitor deleted successfully!" << endl;
       }
        else
       {
         rename("old.txt", "visitor.txt");
         cout << "Error rename file!" << endl;
       }
        }
         else
        {
            cout << "Error renaming original file!" << endl;
        }
      }
        else
      {
        remove("temp.txt");
        cout << "Visitor not found!" << endl;
     }
   }
    

        void Register_order()
  {
       Order o;
        
      cout << "Enter order code: ";
      cin >> o.order_code;

      cout << "Enter visitor code: ";
      cin >> o.visitor_code;

     struct tm newtime;
    __time64_t long_time;

    _time64(&long_time);
    _localtime64_s(&newtime, &long_time);

         o.date = to_string(1900 + newtime.tm_year) + "/" +
         to_string(1 + newtime.tm_mon) + "/" +
         to_string(newtime.tm_mday);

      cout << "Enter order status: ";
      cin >> o.Status;

      cout<<"product count: ";
      cin>>o.product_count;

      while(o.product_count<1)
      {
        cout<<"Enter product count:";
        cin>>o.product_count;  
      }

     ofstream file("order.txt", ios::app);

      if (!file)
      {
        cout << "Can not open order file";
          exit(-1);
      }

      file << o.order_code << endl;
      file << o.visitor_code << endl;
      file << o.date << endl;
      file << o.Status << endl;
      file << o.product_count;

      for (int i=0;i<o.product_count;i++)
      {
         cout << "Product name: ";
         cin >> o.name;

         cout << "Quantity: ";
         cin >> o.quantity;

         cout << "Price: ";
         cin >> o.price;

       file << o.name << endl;
       file << o.quantity << endl;
       file << o.price << endl;
     }
      file.close();

      cout << "Order registered  ";
  }

  
      void edit_order()  
  {
      Order o;
      string search_code;
      bool found = false;

     cout << "Enter order code to edit: ";
     cin >> search_code;

    ifstream file("order.txt");
    ofstream temp("temp.txt");

    if (!file || !temp)
    {
        cout << "Can not open file";
         exit(-1);
    }

      while (getline(file >> ws, o.order_code))
     {
        if (!getline(file, o.visitor_code))
            break;

        if (!getline(file, o.date))
            break;

        if (!getline(file, o.Status))
            break;

        if (!(file >> o.product_count))
            break;

        int old_product_count = o.product_count;

     if (o.order_code == search_code)
    {
           found = true;

         cout << "Enter new visitor code: ";
         cin >> o.visitor_code;

         cout << "Enter new date: ";
         cin >> o.date;

         cout << "Enter new status: ";
         cin >> o.Status;

         cout << "Enter new product count: ";
         cin >> o.product_count;

        while (o.product_count < 1)
      {
           cout << "Enter new product count: ";
           cin >> o.product_count;
        }

            temp << o.order_code << endl;
            temp << o.visitor_code << endl;
            temp << o.date << endl;
            temp << o.Status << endl;
            temp << o.product_count << endl;

         for (int i = 0; i < old_product_count; i++)
       {
            if (!getline(file >> ws, o.name))
                    break;

            if (!(file >> o.quantity))
                    break;

            if (!(file >> o.price))
                    break;
            }
 
      for (int i = 0; i < o.product_count; i++)
    {
          cout << "Product name: ";
          cin >> o.name;

          cout << "Quantity: ";
          cin >> o.quantity;

          cout << "Price: ";
          cin >> o.price;

          temp << o.name << endl;
          temp << o.quantity << endl;
          temp << o.price << endl;
         }
      }
        else
        {
            
            temp << o.order_code << endl;
            temp << o.visitor_code << endl;
            temp << o.date << endl;
            temp << o.Status << endl;
            temp << old_product_count << endl;

        for (int i = 0; i < old_product_count; i++)
     {
        if (!getline(file >> ws, o.name))
           break;

        if (!(file >> o.quantity))
           break;

        if (!(file >> o.price))
           break;
           temp << o.name << endl;
           temp << o.quantity << endl;
           temp << o.price << endl;
        }
      }
    }

      file.close();
      temp.close();

      if (!found)
     {
        remove("temp.txt");
        cout << "Order not found";
        exit(-1);
     }

        remove("order.txt");

    if (rename("temp.txt", "order.txt") == 0)
        cout << "Order edited successfully";
    else
        cout << "Error replacing order file";
  }

    void Delete_order()
    {
       Order o;
      string delete_code;
      bool found=false;

       cout<<"enter delete code :";
       cin>>delete_code;

      ifstream file("order.txt");
      if (!file)
    {
        cout << "Cannot open order file";
        exit(-1);
    }
      ofstream temp("temp.txt");
      if(!temp)
       {
        cout << "Cannot open order file";
        exit(-1);
       }
         while (getline(file, o.order_code))
     {
        if (!getline(file, o.visitor_code))
            break;

        if (!getline(file, o.date))
            break;

        if (!getline(file, o.Status))
            break;

        if (!(file >> o.product_count))
            break;
      }
        if(o.order_code==delete_code)
         found==true;
         else
         
            temp << o.order_code << endl;
            temp << o.visitor_code << endl;
            temp << o.date << endl;
            temp << o.Status << endl;
            temp << o.product_count;

            for(int i=0;i<=o.product_count;i++)
            {
              getline(file>>ws,o.name);
              file>>o.price;
              file>>o.quantity;
            }
           if(o.order_code!=delete_code)
            temp<<o.name;
            temp<<o.price;
            temp<<o.quantity;
                     
    }


  void Show_All_order()
 {
      Order o;
    bool found = false;

    ifstream file("order.txt");

      if (!file)
    {
        cout << "Cannot open order file";
        return;
    }

    while (getline(file, o.order_code))
    {
        if (!getline(file, o.visitor_code))
            break;

        if (!getline(file, o.date))
            break;

        if (!getline(file, o.Status))
            break;

        if (!(file >> o.product_count))
            break;

        cout << "Order code: " << o.order_code << endl;
        cout << "Visitor code: " << o.visitor_code << endl;
        cout << "Date: " << o.date << endl;
        cout << "Status: " << o.Status << endl;

        for (int i = 0; i < o.product_count; i++)
        {
            if (!getline(file >> ws, o.name))
                break;

            if (!(file >> o.quantity))
                break;

            if (!(file >> o.price))
                break;

            cout << "Product name: " << o.name << endl;
            cout << "Quantity: " << o.quantity << endl;
            cout << "Price: " << o.price << endl;
        }   
               found = true;
      }

       file.close();

        if (!found)
        cout << "No orders registered";
    }

      void Serch_order()
{
     Order o;
     string search_code;
     bool found = false;

     cout << "Enter order code: ";
     cin >> search_code;

    ifstream file("order.txt");

    if (!file)
    {
        cout << "Cannot open order file";
        exit(-1);
    }
      while (getline(file >> ws, o.order_code))
    {
        if (!getline(file, o.visitor_code))
            break;

        if (!getline(file, o.date))
            break;

        if (!getline(file, o.Status))
            break;

        if (!(file >> o.product_count))
            break;

        bool order_found= (o.order_code == search_code);

        if (order_found)
    {
          cout << "Order code: " << o.order_code << endl;
          cout <<  "Visitor code: " << o.visitor_code << endl;
          cout << "Date: " << o.date << endl;
          cout << "Status: " << o.Status << endl;
      }

        for (int i = 0; i < o.product_count; i++)
      {
        if (!getline(file >> ws, o.name))
           break;

        if (!(file >> o.quantity))
                break;

        if (!(file >> o.price))
                break;

        if (order_found)
            {
                cout << "Product name: " << o.name << endl;
                cout << "Quantity: " << o.quantity << endl;
                cout << "Price: " << o.price << endl;
            }
        }

        if (order_found)
        {
            found = true;
            int choice;
            cout<<"1-Edit order"<<endl;
            cout<<"0-exit";
            cin>>choice;
            if(choice==1)
         {
            file.close();
            edit_order();
            return;
         }
           else if(choice==0)
           return;

           else
           {
           cout<<"invalid choice"<<endl;
           return;
           }

        }
    }

    file.close();

    if (!found)
        cout << "Order not found";
}


    
     void showMenu()
  {
    cout << "\n*** Menu ***\n" << endl;
    cout << "1. Add visitor" << endl;
    cout << "2. Show All visitor" << endl;
    cout << "3. Search visitor" << endl;
    cout << "4. Delete visitor" << endl;
    cout << "5. Edit visitor" << endl;
    cout << "6. Debtor visitor" << endl;
    cout << "7. Register order" << endl;
    cout << "8. Search order" << endl;
    cout << "0. Exit" << endl;
  }

   int main()
  {
        int choice;
    do{
      
    showMenu();
    cin>>choice;
     switch (choice)
    {
        case 1:Register_visitor();break;
        case 2:Show_All_visitor();break;
        case 3:Serch_visitor();break;
        case 4:Dlelete_visitor();break;
        case 5:Edit_visitor();break;
        case 7:Register_order();break;
        case 8:Serch_order();break;
        
        case 0:cout<<" goodbye ";break;

           default:
           cout << "invalid choice!" << endl;
           break;
     }  
          system("pause") , system("cls");
   }
         while(choice!=0) ;
         
    

             system("pause");
            }

       