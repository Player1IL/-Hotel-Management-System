//this program is devloped by deepak kumar yadav
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

    struct Name              // structure for naming in program
    {
      char first[20];       //character arrays for the names used in program..
      char last[20];
      char date[20];
      int room;
      char cnic[20],mob[20];
    };
      
       //\\Functions prototyping//\/\\
            
       void vacant_rooms();                //for vacant rooms|
       void customer_reserve();           //for reservation  |
       void check();                    //for the guest history
       void user_total();                                //for user total on the time checkout
       void loading();                                   // for loading bar
       void help();                                     //for helping the user to operate the application
       void about();                                   //for about the program
       void del_resdata();                            // in order delete
       
//------------------------.>//


int main()
{
    int a;
    int choice;
    char again;
    char x[20];
    cout<<endl;
    cout<<"         *                           *    "<<endl;   
    cout<<"      **                               **   "<<endl;
    cout<<"   *** Welcome to the yadav Hotel & sons ***"<<endl;
    cout<<"      **                               **  "<<endl;
    cout<<"        *                             *   "<<endl;
    cout<<endl;                                                   
    
    cout<<"______________________________"<<endl;
    cout<<endl;
    do
    {
    cout<<"Welcome to the Main Menu "<<endl;
    cout<<endl;
    cout<<"Press 1 to Reserve a room. "<<endl; 
    cout<<endl;
    cout<<"Press 2 to see the vacant rooms. "<<endl;                        
    cout<<endl;
    cout<<"Press 3 to check out a room. "<<endl;
    cout<<endl;
    cout<<"Press 4 to see the history of reserved rooms. "<<endl;
    cout<<endl;
    cout<<"Press 5 to Delete the Reservation data. "<<endl;
    cout<<endl;
    cout<<"Press 6 to see about the Application. "<<endl;
    cout<<endl;
    cout<<"Press 7 for help. "<<endl;
    cout<<endl;
    cout<<"Press 0 to Exit application. "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Enter Here_: ";
    cin>>a;
    cout<<"_____________________________________"<<endl;
    cout<<endl;
    switch(a)
    {
    cout<<"________________________________________"<<endl;
    case 0:
    break;
    case 1:
         cout<<"   *                                 *"<<endl;
         cout<<"  ** Welcome to the Reservation Menu **"<<endl;
         cout<<"   *                                 *"<<endl;
         cout<<endl;
         cout<<endl;
         customer_reserve();     // funtion calling
         break;
         case 2:
         cout<<"   *                             *"<<endl;
         cout<<"  ** Welcome to the Vacant Rooms **"<<endl;
         cout<<"   *                             *"<<endl;
         cout<<endl;
         cout<<endl;
         vacant_rooms();    ///funtion calling
         break;
         case 3:
         cout<<" *                                 *"<<endl;
         cout<<"** Welcome to the User Total Menu  **"<<endl;
         cout<<" *                                 *"<<endl;
         cout<<endl;
         cout<<endl;
         user_total();    //function calling   
          break;          
         case 4:
         cout<<"               *                                 *"<<endl;
         cout<<"              ** Welcome to the History Menu     **"<<endl;
         cout<<"               *                                 *"<<endl;
         cout<<endl;
         cout<<endl;
                        
         check();    //function calling           
         break;           
         case 5:
         cout<<"        *                                                           *"<<endl;
         cout<<"    ** Welcome to Delete Reservation data function **"<<endl;
         cout<<"        *                                             *"<<endl;
         cout<<endl;
         cout<<endl;
         del_resdata();    //function calling
         break;         
         case 6:
         cout<<"      *                       *"<<endl;
         cout<<"   ** About the Application **"<<endl;
         cout<<"      *                       *"<<endl;
         cout<<endl;
         cout<<endl;
         about();     //function calling
         break;                     
         case 7:
         cout<<"     *                     *"<<endl;
         cout<<"   ** Welcome to the Help **"<<endl;
         cout<<"      *                     *"<<endl;
         cout<<endl;
         cout<<endl;
         help();    //function calling
         break;
  default:
                 cout<<"you have enter an invalid Choice "<<endl;
                 cout<<endl;
                 }
cout<<"Press 1 to go back into MAIN Menu or 0 to terminate the program: ";                    
cin>>again;
cout<<"___________________________________"<<endl;
cout<<endl;
}
while (again=='1');   
cout<<"Thankyou! for using Hotel Reservation application."<<endl;
cout<<"Have a nice day! "<<endl;
cout<<endl; 
cout<<"Copyright(C) 2017. \n this is developed by deepak yadav"<<endl<<endl;
cout<<"_________________________________________"<<endl;

     system ("pause");
     }
//....................................................................//
                        
//....................................................................//
void user_total()   //funtion definition  of function user_total
{
     int choice,days,total1;
    char AC,again;
    int c=1000;
    int single= 3000;
    int doubl=4500;
    int suit=6000;
    int time=24;
    int service=300;
    do
    {
    cout<<"Which kind of Room did the guest stayed in?  "<<endl<<endl;
               cout<<" 1.Single Rooms "<<endl<<endl;
               cout<<" 2.Double Rooms "<<endl<<endl;
               cout<<" 3.Suits "<<endl<<endl;
    
    cout<<"Select 1,2 or 3 . "<<endl<<endl;
    cout<<"Enter Your CHoice Here_: ";
    cin>>choice;
    cout<<"__________________________________"<<endl;
    switch(choice)
    {
    case 1:
         cout<<"You have Selected single room. "<<endl<<endl;
         cout<<" For How many days did the guest stayed: ";
         cin>>days;
         
          cout<<" Press Y for A/c and N for without A/c: ";
         cin>>AC;
         cout<<endl; 
        if (AC == 'Y' || AC == 'y')
{
         total1 =(c+single+time+service)*days;
          cout<<"Your Total Total bill + service tax = ("<<total1<<" Rs.)"<<endl;
          cout<<endl; 
          cout<<"______________________________"<<endl;
}       
         else if (AC == 'N' || AC == 'n')
 {        
         total1=(single+time+service) * days;
         cout<<"Your Total Total bill + service tax = ("<<total1<<" Rs.)"<<endl;
      cout<<endl; 
       cout<<"_______________________________"<<endl;
}      
         break;
         case 2:
         cout<<"You Have Selected Double room."<<endl;
          cout<<endl; 
         cout<<" For How many days did the guest stayed: ";
         cin>>days;
         cout<<endl;
        cout<<" Press Y for A/c and N for without A/c: ";
         cin>>AC;
         cout<<endl; 
         
        if (AC == 'Y' || AC == 'y')
{
         total1 =(c+doubl+time+service)*days;
          cout<<"Your Total Total bill + service tax = ("<<total1<<" Rs.)"<<endl;
cout<<endl; 
 cout<<"__________________________________"<<endl;
}       
         else if (AC == 'N' || AC == 'n')
 {        
         total1=(doubl+time+service) * days;
         cout<<"Your Total Total bill + service tax = ("<<total1<<" Rs.)"<<endl;
        cout<<endl; 
         cout<<"_______________________________________"<<endl;
}      
         break;
         case 3:
         cout<<"You Have Selected Suit. "<<endl;
         cout<<endl;
         cout<<" For How many days did the guest stayed: ";
         cin>>days;
         cout<<endl;      
         cout<<" Press Y for A/c and N for without A/c: ";
         cin>>AC;
         cout<<endl; 
        if (AC == 'Y' || AC == 'y')
{
         total1 =(c+suit+time+service)*days;
          cout<<"Your Total Total bill + service tax = ("<<total1<<" Rs.)"<<endl;
          cout<<endl;
           cout<<"_______________________________________"<<endl; 
}       
         else if (AC == 'N' || AC == 'n')
 {        
         total1=(suit+time+service) * days;
          cout<<"Your Total Total bill + service tax = ("<<total1<<" Rs.)"<<endl;
          
        cout<<endl; 
       cout<<"__________________________________________"<<endl;
}      
                  break;
                 default:
                 cout<<"you have enter an invalid Choice "<<endl;
                 cout<<endl; 
                 }
                 cout<<"Do you want to checkout for another room? (Y/N): ";
                 cin>>again;
                  cout<<"___________________________________"<<endl;
                 cout<<endl; 
    }
       while(again == 'y' || again == 'Y'); 

         }
        //....................................................................//
                        
      //....................................................................//
        
        void customer_reserve()    //function definition 
{

              Name guest;             // guest is the name structure
              Name guest2;
              char choicedo;       //for enter more data 

    do 
    { 
    ofstream file;                     
    file.open("User info input.txt",ios::out | ios::app);  //openning txt file 
if(!file)
{
         cout<<"Error: Cannot open file.\n";
         system("pause");
         }
         
    cout<<"Enter The Room number to be Reserved: ";
    cin>>guest.room;
    cin.ignore();                       
    cout<<endl;
    cout<<"Enter Guest's First Name: ";
    cin.getline(guest.first, 20);      
     cout<<endl;
    cout<<"Enter Guest's Last Name: ";
    cin.getline(guest.last, 20);
    cout<<endl;
    cout<<"Enter The Mobile no. of The Guest: +";
    cin.getline(guest.mob, 20);
    cout<<endl;
    cout<<"The Name of Manager in Charge: ";
    cin.getline(guest2.first, 20);
    cout<<endl;
    cout<<endl;
    cout<<"Date: ";
    cin.getline(guest.date, 20);
    cout<<endl;
    int a;                            ///for choice
    cout<<"Press 1 to Save or 2 to cancel: ";
    cout<<endl;
  cin>>a;
   if(a==1)
       {
    cout<<endl;
    file<<" Guests Info"<<endl;
    cout<<endl;
    file<<"------------------------------------------------------------"<<endl;
               file<<endl;
               file<<"              Reservation Data of Room no.: "<<guest.room<<endl;
               file<<endl;
               file<<"The Name of the Guest is: "<<guest.first<<" "<<guest.last<<endl;
               file<<endl;
               file<<"Mobile No.: +"<<guest.mob<<endl;
               file<<endl;
               file<<"Name of Manager in Charge is: "<<guest2.first<<endl;
               file<<endl;
               file<<"Date: "<<guest.date<<endl;
               file<<endl;
    file<<endl;  
    file<<"------------------------------------------------------------"<<endl;
    file.close(); 
    cout<<"Record Saved..."<<endl;
    cout<<"__________________________________"<<endl;
    cout<<endl;
}         
         else
 {        
         cout<<"Record Was Not Saved"<<endl;
          cout<<"____________________________________"<<endl;
         cout<<endl;
        }
         cout<<"Enter Y To input an other data or Enter N to Exit: ";
         cin>>choicedo;
         cout<<"_____________________________________"<<endl;
         cout<<endl;
         }
         while (choicedo=='y' || choicedo=='Y');  //to enter more data
 //}          
}
         
         
         //....................................................................//
                        
//....................................................................//

void vacant_rooms()    //function definition
{
     ifstream infile,infile2,infile3;           
    char name[89],name2[89],name3[89],name4[100];
    int see;
    char again;
    do
    {
    cout<<"Press 1 to see the list of Single Rooms. "<<endl;
    cout<<endl;
    cout<<"Press 2 to See the list of Double Rooms. "<<endl;
    cout<<endl;
    cout<<"Press 3 to See the list of Suits. "<<endl;
    cout<<endl;
    cout<<"Enter Your Choice Here_: ";
    cin>>see;
    cout<<endl;
    switch(see)
    {
    case 1:
    infile.open("infoVS.txt",ios::in);
if (!infile)
{
            cout<<"File not found."<<endl;
            exit(1);
            }
            else
            {
while(!infile.eof())
{
infile>>name>>name2>>name3;
    cout<<name<<" "<<name2<<" "<<name3<<endl;
   

    cout<<endl;
}
    infile.close();        
                           } 
break;
case 2:

           infile2.open("infoVD.txt",ios::in);
   if(!infile2)
   {
               cout<<"File not found."<<endl;
               exit(1);
               }
               else
               {
   while(!infile2.eof())
       {  
infile2>>name>>name2>>name3;
cout<<name<<" "<<name2<<" "<<name3<<endl;
cout<<endl;
}
     infile2.close();
}
break;

case 3:

           infile3.open("infoVSu.txt",ios::in);    
 if(!infile3)
 {
  cout<<"File not found."<<endl;
  exit(1);
}
else
{
      
     while(!infile3.eof())
     {
      infile3>>name>>name2>>name3;
    cout<<name<<" "<<name2<<" "<<name3<<endl;
    cout<<endl;
}


     infile3.close();
}
     break;
     
     default:
             cout<<"You have entered an invalid choice"<<endl;
             cout<<endl;
             }
     cout<<"Do you want to see the List of vacant Rooms again? (Y/N): ";
     cin>>again;
     cout<<endl;
}while (again=='Y' || again=='y');
     cout<<endl;  
}

//....................................................................//
                        
//....................................................................//


void check()    /// function definition
{
    
    char doagain;
    do
    {
     fstream data;
     char word[100];
     
     data.open("User info input.txt",ios::in);
     cout<<endl;
     if(!data)
     {
              cout<<"File not found."<<endl;
              exit(1);
              }
     else
     {
     while(!data.eof())
     {
   
         data.getline(word,100);
         cout<<word<<"\n";
         data.getline(word,100);
         cout<<word<<"\n";
         data.getline(word,100);   
         cout<<word<<"\n";
         data.getline(word,100);
         cout<<word<<"\n";
         }         
         data.close();
         cout<<"Press Y to see the history again or N to cancel.";
         cin>>doagain;
         cout<<"___________________________________"<<endl;
         cout<<endl;
         }
}
while (doagain=='y' || doagain=='Y');
}                 

//....................................................................//

void del_resdata()    ///function definition
{
   char again;
   int x;
   fstream deletefile;
  do
  {
    cout<<"Enter 1 to delete the reservation data or 2 to cancel: "; 
    cin>>x;
    cout<<endl;
    if (x==1)
    {
    deletefile.open("User info input.txt", ios::out | ios::trunc); //trunc for delete data 
    if(!deletefile)
    {
    cout<<"File not found."<<endl;
    exit(1);
    }
    else
    {
    cout<<"Data has been deleted from the file."<<endl;
    cout<<endl;
    }
}
else
{
cout<<"Data not deleted.."<<endl;
cout<<endl;
}
cout<<"Enter Y to run this function again or N to cancel: ";
cin>>again;
cout<<endl;
cout<<"_____________________________________________"<<endl;
}
while (again=='Y' || again=='y');
deletefile.close();
}
void about()
{
             cout<<"About the Application"<<endl;
             cout<<"______________________________________"<<endl;
             cout<<endl;
             cout<<"This application is specially made for Hotel Reservation to "<<endl;
             cout<<"Organize data and to perform tasks, which can be useful for "<<endl;
             cout<<"Reservation.It can recored and analyze data of guests.With "<<endl;
             cout<<"this application you can not only see the past history of "<<endl;
             cout<<"guests,stayed in the hotel but you can also reserve rooms "<<endl;
             cout<<"for the future as well.You can also calculate the bill of "<<endl;
             cout<<"guests on the basis of time they have spent in the hotel  "<<endl;
             cout<<endl;
             cout<<"This application is user friendly and one can easily use "<<endl;
             cout<<"this application.Thank you!"<<endl;
             cout<<endl;
             cout<<"Copyright(c) 2017. this is devloped by deepak kumar"<<endl;
             cout<<"______________________________________________"<<endl;
             cout<<"for more detais just contact on given email address\n\n";
             cout<<"deepakyadav02121998@gmail.com\n\n";
             cout<<"thanks for be here";
}
                   //For more info plss contact deepak yadav
void help()
{
             cout<<endl;
             cout<<"This application will work according to the desired entries by "<<endl;
             cout<<"the user.The reservation data will be stored in a text file present "<<endl;
             cout<<"where the application is located.If the text file is not present "<<endl;
             cout<<"the program will not work properly and will terminate.Follow the  "<<endl;
             cout<<"displayed on the screen.Select the proper option to operate "<<endl;
             cout<<"instructions the application.Goodluck! "<<endl;
              cout<<"for more detais just contact on given email address\n\n";
             cout<<"deepakyadav02121998@gmail.com\n";
             cout<<"thanks for be here\n";
             cout<<endl;
}


