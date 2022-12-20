//this program is devloped by deepak kumar yadav
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

struct Name              // structure for naming in program
{
	char first[20];       //character arrays for the names used in program..
	char last[20];
	char date[20];
	int room;
	char cnic[20], mob[20];
};

struct Room
{
	int room_number;
	int room_type;
	Room* next;
	Room* prev;
	bool reserved = false;
};

//\\Functions prototyping//\/\\
            
void vacant_rooms();                //for vacant rooms
void customer_reserve(struct Room*);           //for reservation  |
void check();                    //for the guest history
void user_total(struct Room*);                                //for user total on the time checkout
void loading();                                   // for loading bar
void help();                                     //for helping the user to operate the application
void about();                                   //for about the program
void del_resdata();                            // in order delete
void insert_end(struct Room**, int, int, bool); //adding to the end of the linked list
void displayList(struct Room*); //print list
bool check_room_status(); //Check for existence of log
void add_rooms(); //Create log file for the first time (first time the application starts or log does not exist).
bool check_availability(struct Room*, int); //check if a room is available for the public.
void reserve_room(struct Room*, int); //changing the room reservation status.
void log_update(struct Room*); //updates the log when needed.
Room* get_room(struct Room*, int); //get a specific room(node) from list when needed.
int room_damages(); // calc room damages to user_total func
void extending(struct Room*);           //for extending
void Survey(); //runs a survey for the guest with 8 questions and print the average rate


//------------------------.>//


int main()
{
	int a;
	int choice;
	char again;
	char x[20];
	struct Room* head = NULL;
	cout << endl;
	cout << "         *                           *    " << endl;
	cout << "      **                               **   " << endl;
	cout << "   *** Welcome to the yadav Hotel & sons ***" << endl;
	cout << "      **                               **  " << endl;
	cout << "        *                             *   " << endl;
	cout << endl;


	cout << "______________________________" << endl;
	cout << endl;
	while (check_room_status() == false) {
		cout << "No rooms found, beginning hotel construction..." << endl;
		add_rooms();
	}
	ifstream inroomsfile("infoRooms.txt");
	int number, type;
	bool reserve;
	while (inroomsfile >> number >> type >> reserve)
	{
		insert_end(&head, number, type, reserve);
	}
	inroomsfile.close();

	do {
		cout << "Welcome to the Main Menu " << endl;
		cout << endl;
		cout << "Press 1 to Reserve a room. " << endl;
		cout << endl;
		cout << "Press 2 to see the vacant rooms. " << endl;
		cout << endl;
		cout << "Press 3 to check out a room. " << endl;
		cout << endl;
		cout << "Press 4 to see the history of reserved rooms. " << endl;
		cout << endl;
		cout << "Press 5 to Delete the Reservation data. " << endl;
		cout << endl;
		cout << "Press 6 to see about the Application. " << endl;
		cout << endl;
		cout << "Press 7 for help. " << endl;
		cout << endl;
		cout << "Press 0 to Exit application. " << endl;
		cout << endl;
		cout << endl;
		cout << "Enter Here_: ";
		cin >> a;
		cout << "_____________________________________" << endl;
		cout << endl;
		switch (a) {
			cout << "________________________________________" << endl;
		case 0:
			break;
		case 1:
			cout << "   *                                 *" << endl;
			cout << "  ** Welcome to the Reservation Menu **" << endl;
			cout << "   *                                 *" << endl;
			cout << "  **        Available Rooms:         **" << endl;
			displayList(head);
			cout << endl;
			cout << endl;
			customer_reserve(head);     // funtion calling
			break;
		case 2:
			cout << "   *                             *" << endl;
			cout << "  ** Welcome to the Vacant Rooms **" << endl;
			cout << "   *                             *" << endl;
			cout << endl;
			cout << endl;
			vacant_rooms();    ///funtion calling
			break;
		case 3:
			cout << " *                                 *" << endl;
			cout << "** Welcome to the User Total Menu  **" << endl;
			cout << " *                                 *" << endl;
			cout << endl;
			cout << endl;
			user_total(head);   //function calling
			break;
		case 4:
			cout << "               *                                 *" << endl;
			cout << "              ** Welcome to the History Menu     **" << endl;
			cout << "               *                                 *" << endl;
			cout << endl;
			cout << endl;
			check();    //function calling
			break;
		case 5:
			cout << "        *                                                           *" << endl;
			cout << "    ** Welcome to Delete Reservation data function **" << endl;
			cout << "        *                                             *" << endl;
			cout << endl;
			cout << endl;
			del_resdata();    //function calling
			break;
		case 6:
			cout << "      *                       *" << endl;
			cout << "   ** About the Application **" << endl;
			cout << "      *                       *" << endl;
			cout << endl;
			cout << endl;
			about();     //function calling
			break;
		case 7:
			cout << "     *                     *" << endl;
			cout << "   ** Welcome to the Help **" << endl;
			cout << "      *                     *" << endl;
			cout << endl;
			cout << endl;
			help();    //function calling
			break;
		case 8:
			cout << "     *                     *" << endl;
			cout << "   ** Welcome to the Extending stay time **" << endl;
			cout << "      *                     *" << endl;
			cout << endl;
			cout << "First, you have to do a quick check-out for the old room" << endl;
			cout << endl;
			user_total(head);    //function calling
			cout << "  **        Available rooms for extending:         **" << endl;
			displayList(head);
			cout << endl;
			extending(head);    //function calling
			break;
		default:
			cout << "you have enter an invalid Choice " << endl;
			cout << endl;
		}
		cout << "Press 1 to go back into MAIN Menu or 0 to terminate the program: ";
		cin >> again;
		cout << "___________________________________" << endl;
		cout << endl;
		if (again == '0')
			log_update(head);
	} while (again == '1');
	cout << "Thankyou! for using Hotel Reservation application." << endl;
	cout << "Have a nice day! " << endl;
	cout << endl;
	cout << "Copyright(C) 2017. \n this is developed by deepak yadav" << endl << endl;
	cout << "_________________________________________" << endl;

	system("pause");
}
//....................................................................//

//....................................................................//
void user_total(struct Room* head)   //funtion definition  of function user_total
{
	int choice, days, total1 = 0;
	Room* the_room;
	char AC, again, choose;
	int c = 1000;
	int single = 3000;
	int doubl = 4500;
	int suite = 6000;
	int time = 24;
	int service = 300;
	do
	{
		cout << "**        Available Rooms:         **" << endl;
		displayList(head);
		cout << "What was the room number you stayed in?  " << endl << endl;
		cin >> choice;
		the_room = get_room(head, choice);
		if (!the_room)
		{
			cout << "Invalid room : Either not existent or already vacant" << endl;
			break;
		}
		the_room->reserved = false;

		cout << "__________________________________" << endl;
		switch (the_room->room_type)
		{
		case 1:
			cout << "You have Selected single room. " << endl << endl;
			cout << " For How many days did the guest stayed: ";
			cin >> days;
			total1 += room_damages();
			cout << " Press Y for A/c and N for without A/c: ";
			cin >> AC;
			cout << endl;
			if (AC == 'Y' || AC == 'y')
			{
				total1 += (c + single + time + service) * days;
				cout << "Your Total Total bill + service tax = (" << total1 << " Rs.)" << endl;
				cout << endl;
				cout << "______________________________" << endl;
			}
			else if (AC == 'N' || AC == 'n')
			{
				total1 += (single + time + service) * days;
				cout << "Your Total Total bill + service tax = (" << total1 << " Rs.)" << endl;
				cout << endl;
				cout << "_______________________________" << endl;
			}
			break;
		case 2:
			cout << "You Have Selected Double room." << endl;
			cout << endl;
			cout << " For How many days did the guest stayed: ";
			cin >> days;
			cout << endl;
			total1 += room_damages();
			cout << " Press Y for A/c and N for without A/c: ";
			cin >> AC;
			cout << endl;

			if (AC == 'Y' || AC == 'y')
			{
				total1 += (c + doubl + time + service) * days;
				cout << "Your Total Total bill + service tax = (" << total1 << " Rs.)" << endl;
				cout << endl;
				cout << "__________________________________" << endl;
			}
			else if (AC == 'N' || AC == 'n')
			{
				total1 += (doubl + time + service) * days;
				cout << "Your Total Total bill + service tax = (" << total1 << " Rs.)" << endl;
				cout << endl;
				cout << "_______________________________________" << endl;
			}
			break;
		case 3:
			cout << "You Have Selected Suite. " << endl;
			cout << endl;
			cout << " For How many days did the guest stayed: ";
			cin >> days;
			cout << endl;
			total1 += room_damages();
			cout << " Press Y for A/c and N for without A/c: ";
			cin >> AC;
			cout << endl;
			if (AC == 'Y' || AC == 'y')
			{
				total1 += (c + suite + time + service) * days;
				cout << "Your Total Total bill + service tax = (" << total1 << " Rs.)" << endl;
				cout << endl;
				cout << "_______________________________________" << endl;
			}
			else if (AC == 'N' || AC == 'n')
			{
				total1 += (suite + time + service) * days;
				cout << "Your Total Total bill + service tax = (" << total1 << " Rs.)" << endl;

				cout << endl;
				cout << "__________________________________________" << endl;
			}
			break;
		default:
			cout << "you have enter an invalid Choice " << endl;
			cout << endl;
		}
		cout << endl << "Are you interested in participating in a survey about the hotel and its services? (Y/N)" << endl;
		cin >> choose;
		if (choose == 'Y' || choose == 'y') {
			Survey();
		}
		cout << "Do you want to checkout for another room? (Y/N): ";
		cin >> again;
		cout << "___________________________________" << endl;
		cout << endl;
	} while (again == 'y' || again == 'Y');

}
//....................................................................//

//....................................................................//

void customer_reserve(struct Room* head)    //function definition
{

	Name guest;             // guest is the name structure
	Name guest2;
	char choicedo;       //for enter more data
	bool check_res = false;

	do
	{
		ofstream file;
		file.open("User info input.txt", ios::out | ios::app);  //openning txt file 
		if (!file)
		{
			cout << "Error: Cannot open file.\n";
			system("pause");
		}

		cout << "Enter The Room number to be Reserved: ";
		do
		{
			cin >> guest.room;
			check_res = check_availability(head, guest.room);
			if (!check_res)
			{
				cout << "Please choose a different room since the one chosen is not available." << endl;
				cout << "Enter The Room number to be Reserved:";
			}

		} while (!check_res);
		cin.ignore();
		cout << endl;
		cout << "Enter Guest's First Name: ";
		cin.getline(guest.first, 20);
		cout << endl;
		cout << "Enter Guest's Last Name: ";
		cin.getline(guest.last, 20);
		cout << endl;
		cout << "Enter The Mobile no. of The Guest: +";
		cin.getline(guest.mob, 20);
		cout << endl;
		cout << "The Name of Manager in Charge: ";
		cin.getline(guest2.first, 20);
		cout << endl;
		cout << endl;
		cout << "Date: ";
		cin.getline(guest.date, 20);
		cout << endl;
		int a;                            ///for choice
		cout << "Press 1 to Save or 2 to cancel: ";
		cout << endl;
		cin >> a;
		if (a == 1)
		{
			cout << endl;
			file << " Guests Info" << endl;
			cout << endl;
			file << "------------------------------------------------------------" << endl;
			file << endl;
			file << "              Reservation Data of Room no.: " << guest.room << endl;
			file << endl;
			file << "The Name of the Guest is: " << guest.first << " " << guest.last << endl;
			file << endl;
			file << "Mobile No.: +" << guest.mob << endl;
			file << endl;
			file << "Name of Manager in Charge is: " << guest2.first << endl;
			file << endl;
			file << "Date: " << guest.date << endl;
			file << endl;

			file << endl;
			file << "------------------------------------------------------------" << endl;
			file.close();
			reserve_room(head, guest.room);
			cout << "Record Saved..." << endl;
			cout << "__________________________________" << endl;
			cout << endl;

		}
		else
		{
			cout << "Record Was Not Saved" << endl;
			cout << "____________________________________" << endl;
			cout << endl;
		}
		cout << "Enter Y To input an other data or Enter N to Exit: ";
		cin >> choicedo;
		cout << "_____________________________________" << endl;
		cout << endl;
	} while (choicedo == 'y' || choicedo == 'Y');  //to enter more data

}


//....................................................................//

//....................................................................//

void vacant_rooms()    //function definition
{
	ifstream infile, infile2, infile3;
	char name[89], name2[89], name3[89], name4[100];
	int see;
	char again;
	do
	{
		cout << "Press 1 to see the list of Single Rooms. " << endl;
		cout << endl;
		cout << "Press 2 to See the list of Double Rooms. " << endl;
		cout << endl;
		cout << "Press 3 to See the list of Suites. " << endl;
		cout << endl;
		cout << "Enter Your Choice Here_: ";
		cin >> see;
		cout << endl;
		switch (see)
		{
		case 1:
			infile.open("infoVS.txt", ios::in);
			if (!infile)
			{
				cout << "File not found." << endl;
				exit(1);
			}
			else
			{
				while (!infile.eof())
				{
					infile >> name >> name2 >> name3;
					cout << name << " " << name2 << " " << name3 << endl;


					cout << endl;
				}
				infile.close();
			}
			break;
		case 2:

			infile2.open("infoVD.txt", ios::in);
			if (!infile2)
			{
				cout << "File not found." << endl;
				exit(1);
			}
			else
			{
				while (!infile2.eof())
				{
					infile2 >> name >> name2 >> name3;
					cout << name << " " << name2 << " " << name3 << endl;
					cout << endl;
				}
				infile2.close();
			}
			break;

		case 3:

			infile3.open("infoVSu.txt", ios::in);
			if (!infile3)
			{
				cout << "File not found." << endl;
				exit(1);
			}
			else
			{

				while (!infile3.eof())
				{
					infile3 >> name >> name2 >> name3;
					cout << name << " " << name2 << " " << name3 << endl;
					cout << endl;
				}


				infile3.close();
			}
			break;

		default:
			cout << "You have entered an invalid choice" << endl;
			cout << endl;
		}
		cout << "Do you want to see the List of vacant Rooms again? (Y/N): ";
		cin >> again;
		cout << endl;
	} while (again == 'Y' || again == 'y');
	cout << endl;
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

		data.open("User info input.txt", ios::in);
		cout << endl;
		if (!data)
		{
			cout << "File not found." << endl;
			exit(1);
		}
		else
		{
			while (!data.eof())
			{

				data.getline(word, 100);
				cout << word << "\n";
				data.getline(word, 100);
				cout << word << "\n";
				data.getline(word, 100);
				cout << word << "\n";
				data.getline(word, 100);
				cout << word << "\n";
			}
			data.close();
			cout << "Press Y to see the history again or N to cancel.";
			cin >> doagain;
			cout << "___________________________________" << endl;
			cout << endl;
		}
	} while (doagain == 'y' || doagain == 'Y');
}

//....................................................................//

void del_resdata()    ///function definition
{
	char again;
	int x;
	fstream deletefile;
	do
	{
		cout << "Enter 1 to delete the reservation data or 2 to cancel: ";
		cin >> x;
		cout << endl;
		if (x == 1)
		{
			deletefile.open("User info input.txt", ios::out | ios::trunc); //trunc for delete data 
			if (!deletefile)
			{
				cout << "File not found." << endl;
				exit(1);
			}
			else
			{
				cout << "Data has been deleted from the file." << endl;
				cout << endl;
			}
		}
		else
		{
			cout << "Data not deleted.." << endl;
			cout << endl;
		}
		cout << "Enter Y to run this function again or N to cancel: ";
		cin >> again;
		cout << endl;
		cout << "_____________________________________________" << endl;
	} while (again == 'Y' || again == 'y');
	deletefile.close();
}
void insert_end(struct Room** head, int number, int type, bool reserve) ///function definition
{
	struct Room* newRoom = new Room;
	struct Room* last = *head;
	newRoom->room_number = number;
	newRoom->room_type = type;
	newRoom->reserved = reserve;
	newRoom->next = NULL;
	if (*head == NULL) {
		newRoom->prev = NULL;
		*head = newRoom;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newRoom;
	newRoom->prev = last;
	return;
}
void displayList(struct Room* room) ///function definition
{
	struct Room* last;
	while (room != NULL) {
		cout << "         [" << "Room:" << room->room_number << "," << "Type:" << room->room_type << "," << "Status:" << room->reserved << "]" << endl;
		last = room;
		room = room->next;
	}
}
bool check_room_status() ///function definition
{
	ifstream infile;
	infile.open("infoRooms.txt");
	if (infile) {
		infile.seekg(0, ios::end);
		if (infile.tellg() == 0)
			return false;
		else
			return true;
	}
	else
		return false;
}
void add_rooms()///function definition
{
	ofstream infile("infoRooms.txt");
	vector<int> rooms;
	int n, number, type;
	bool m = true;
	while (m)
	{
		cout << "1. Add room" << endl;
		cout << "2. End" << endl;
		cout << "Choose your option: ";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "Enter room number: ";
			cin >> number;
			if (rooms.empty() == false)
				while (find(rooms.begin(), rooms.end(), number) != rooms.end())
				{
					cout << "Room number already exists" << endl;
					cout << "Enter room number: ";
					cin >> number;
				}
			cout << endl;
			cout << "Enter room type (Single: 1, Double: 2, Suite: 3): ";
			cin >> type;
			cout << endl;
			while (type > 3 || type < 1)
			{
				cout << "Incorrect type!" << endl;
				cout << "Enter room type (Single: 1, Double: 2, Suite: 3): ";
				cin >> type;
			}
			rooms.push_back(number);
			infile << number << " " << type << " " << false << endl;
			break;
		case 2:
			m = false;
			break;
		default:
			cout << "Invalid option, try again!" << endl;
		}
	}
	infile.close();
	rooms.clear();
}
bool check_availability(struct Room* Room_list, int wanted_room) ///function definition
{
	struct Room* last;
	while (Room_list != NULL)
	{
		if (Room_list->room_number == wanted_room && !Room_list->reserved)
			return true;
		last = Room_list;
		Room_list = Room_list->next;
	}
	return false;
}
void reserve_room(struct Room* Room_list, int wanted_room) ///function definition
{
	struct Room* last;
	while (Room_list != NULL) {
		if (Room_list->room_number == wanted_room && !Room_list->reserved)
			Room_list->reserved = true;
		last = Room_list;
		Room_list = Room_list->next;
	}
}
void log_update(struct Room* Room_list) ///function definition
{
	ofstream infile("infoRooms.txt", ofstream::trunc);
	struct Room* last;
	while (Room_list != NULL)
	{
		infile << Room_list->room_number << " " << Room_list->room_type << " " << Room_list->reserved << endl;
		last = Room_list;
		Room_list = Room_list->next;
	}
}
Room* get_room(struct Room* head, int wanted_room) ///function definition
{
	struct Room* last;
	while (head != NULL) {
		if (head->room_number == wanted_room && head->reserved)
			return head;
		last = head;
		head = head->next;
	}
	return NULL;
}
int room_damages()
{
	int sum = 0, objects;
	char object, obj;
	cout << "Are there any broken objects? (Y/N):";
	cin >> object;
	if (object == 'Y' || object == 'y')
	{
		cout << endl << "Does the TV work? (Y/N):";
		cin >> obj;
		if (obj == 'N' || obj == 'n')
			sum += 1500;
		cout << endl << "Is the bed intact? (Y/N):";
		cin >> obj;
		if (obj == 'N' || obj == 'n')
			sum += 3000;
		cout << endl << "Are there any appliances broken? (Y/N):";
		cin >> obj;
		if (obj == 'Y' || obj == 'y') {
			cout << endl << "How many?:";
			cin >> objects;
			sum += 200 * objects;
		}
	}
	return sum;
}
void Survey() {
	int Answer;
	float average = 0;
	ofstream file;
	cout << "Please rate the following questions with 5 being the highest and 1 being the lowest." << endl << endl;
	file.open("SurveyInfo.txt", ios::out | ios::app);
	if (!file) {
		cout << "Error,can't open file." << endl;
	}
	cout << "Rate your satisfaction for the room you stayed in:" << endl;
	file << "Rate your satisfaction for the room you stayed in:" << endl;
	do {
		cin >> Answer;
		if (Answer > 5 || Answer < 1)
			cout << "You have entered an invalid choice, Try again:" << endl;
	} while (Answer > 5 || Answer < 1);
	average += Answer;
	file << "Your answer is :" << Answer << endl;;
	cout << "Rate your satisfaction with the cleanliness and maintenance of the hotel:" << endl;
	file << "Rate your satisfaction with the cleanliness and maintenance of the hotel:" << endl;
	do {
		cin >> Answer;
		if (Answer > 5 || Answer < 1)
			cout << "You have entered an invalid choice, Try again:" << endl;
	} while (Answer > 5 || Answer < 1);
	average += Answer;
	file << "Your answer is :" << Answer<<endl;
	cout << "To what extent were you satisfied with the attitude of the hotel staff towards you?" << endl;
	file << "To what extent were you satisfied with the attitude of the hotel staff towards you?" << endl;
	do {
		cin >> Answer;
		if (Answer > 5 || Answer < 1)
			cout << "You have entered an invalid choice, Try again:" << endl;
	} while (Answer > 5 || Answer < 1);
	average += Answer;
	file << "Your answer is :" << Answer<<endl;
	cout << "Rate your satisfaction with the food that served at the hotel:" << endl;
	file << "Rate your satisfaction with the food that served at the hotel:" << endl;
	do {
		cin >> Answer;
		if (Answer > 5 || Answer < 1)
			cout << "You have entered an invalid choice, Try again:" << endl;
	} while (Answer > 5 || Answer < 1);
	average += Answer;
	file << "Your answer is :" << Answer<<endl;
	cout << "Rate your satisfaction with the hotel room service:" << endl;
	file << "Rate your satisfaction with the hotel room service:" << endl;
	do {
		cin >> Answer;
		if (Answer > 5 || Answer < 1)
			cout << "You have entered an invalid choice, Try again:" << endl;
	} while (Answer > 5 || Answer < 1);
	average += Answer;
	file << "Your answer is :" << Answer<<endl;
	cout << "Rate your satisfaction for the various areas of entertainment that the hotel offers:" << endl;
	file << "Rate your satisfaction for the various areas of entertainment that the hotel offers:" << endl;
	do {
		cin >> Answer;
		if (Answer > 5 || Answer < 1)
			cout << "You have entered an invalid choice, Try again:" << endl;
	} while (Answer > 5 || Answer < 1);
	average += Answer;
	file << "Your answer is :" << Answer << endl;
	cout << "To what extent are you satisfied with the process of receiving and leaving the room?" << endl;
	file << "To what extent are you satisfied with the process of receiving and leaving the room?" << endl;
	do {
		cin >> Answer;
		if (Answer > 5 || Answer < 1)
			cout << "You have entered an invalid choice, Try again:" << endl;
	} while (Answer > 5 || Answer < 1);
	average += Answer;
	file << "Your answer is :" << Answer<<endl;
	cout << "Rate in general your level of satisfaction with your stay at the hotel:" << endl;
	file << "Rate in general your level of satisfaction with your stay at the hotel:" << endl;
	do {
		cin >> Answer;
		if (Answer > 5 || Answer < 1)
			cout << "You have entered an invalid choice, Try again:"<<endl;
	} while (Answer > 5 || Answer < 1);
	average += Answer;
	file << "Your answer is :" << Answer<<endl;
	cout << "Your average rating is " << average / 8 << "/5 stars." << endl << "Thank you for participating in the survey!" << endl << endl;
	file << "Your average rating is " << average / 8<<endl;
	file << "-----------------------------------------------------------------------------------------------------------------" << endl;
	file.close();
	return;
}
void about()
{
	cout << "About the Application" << endl;
	cout << "______________________________________" << endl;
	cout << endl;
	cout << "This application is specially made for Hotel Reservation to " << endl;
	cout << "Organize data and to perform tasks, which can be useful for " << endl;
	cout << "Reservation.It can recored and analyze data of guests.With " << endl;
	cout << "this application you can not only see the past history of " << endl;
	cout << "guests,stayed in the hotel but you can also reserve rooms " << endl;
	cout << "for the future as well.You can also calculate the bill of " << endl;
	cout << "guests on the basis of time they have spent in the hotel  " << endl;
	cout << endl;
	cout << "This application is user friendly and one can easily use " << endl;
	cout << "this application.Thank you!" << endl;
	cout << endl;
	cout << "Copyright(c) 2017. this is devloped by deepak kumar" << endl;
	cout << "______________________________________________" << endl;
	cout << "for more detais just contact on given email address\n\n";
	cout << "deepakyadav02121998@gmail.com\n\n";
	cout << "thanks for be here";
}
//For more info plss contact deepak yadav
void help()
{
	cout << endl;
	cout << "This application will work according to the desired entries by " << endl;
	cout << "the user.The reservation data will be stored in a text file present " << endl;
	cout << "where the application is located.If the text file is not present " << endl;
	cout << "the program will not work properly and will terminate.Follow the  " << endl;
	cout << "displayed on the screen.Select the proper option to operate " << endl;
	cout << "instructions the application.Goodluck! " << endl;
	cout << "for more detais just contact on given email address\n\n";
	cout << "deepakyadav02121998@gmail.com\n";
	cout << "thanks for be here\n";
	cout << endl;
}
void extending(struct Room* head)
{
	Name guest;             // guest is the name structure
	Name Manager;
	bool check_res = false;


	ofstream file;
	file.open("User info input.txt", ios::out | ios::app);  //openning txt file 
	if (!file)
	{
		cout << "Error: Cannot open file.\n";
		system("pause");
	}

	cout << "Enter The Room number you want to extending your stay time in it: ";
	do
	{
		cin >> guest.room;
		check_res = check_availability(head, guest.room);
		if (!check_res)
		{
			cout << "Please choose a different room since the one chosen is not available at the dates you wanted." << endl;
			cout << "The staff will help you to move your staff\nPlease Enter a new number of room for extending your stay time" << endl;
		}

	} while (!check_res);
	cin.ignore();
	cout << endl;
	cout << "Enter Guest's First Name: ";
	cin.getline(guest.first, 20);
	cout << endl;
	cout << "Enter Guest's Last Name: ";
	cin.getline(guest.last, 20);
	cout << endl;
	cout << "Enter The Mobile no. of The Guest: +";
	cin.getline(guest.mob, 20);
	cout << endl;
	cout << "The Name of Manager in Charge: ";
	cin.getline(Manager.first, 20);
	cout << endl;
	cout << endl;
	cout << "Date: ";
	cin.getline(guest.date, 20);
	cout << endl;
	int a;                            ///for choice
	cout << "Press 1 to Save or 2 to cancel: ";
	cout << endl;
	cin >> a;
	if (a == 1)
	{
		cout << endl;
		file << " Guests Info" << endl;
		cout << endl;
		file << "------------------------------------------------------------" << endl;
		file << endl;
		file << "              Reservation Data of Room no.: " << guest.room << endl;
		file << endl;
		file << "The Name of the Guest is: " << guest.first << " " << guest.last << endl;
		file << endl;
		file << "Mobile No.: +" << guest.mob << endl;
		file << endl;
		file << "Name of Manager in Charge is: " << Manager.first << endl;
		file << endl;
		file << "Date: " << guest.date << endl;
		file << endl;

		file << endl;
		file << "------------------------------------------------------------" << endl;
		file.close();
		reserve_room(head, guest.room);
		cout << "Record Saved..." << endl;
		cout << "__________________________________" << endl;
		cout << endl;

	}
	else
	{
		cout << "Record Was Not Saved" << endl;
		cout << "____________________________________" << endl;
		cout << endl;
	}
}