#include <iostream>
#include <fstream>
#include <string> 
#include <stdlib.h>

using namespace std;

struct city {
  string name;
  string message;
  city *next;
  city *prev;
};

// int printMenu(int choice) { //returns number depending on choice.

// }

city *addCity(city *head, city *previous, string cityName)
{	
	city *cityAdder; //pointer to go through the linked list.
	city *temp; //will hold the 
	cityAdder = head;
	while(cityAdder->prev != previous)
	{
		cityAdder = cityAdder->next;
	}
	cityAdder = new city;
	temp = previous->next;
	previous->next = cityAdder;
	cityAdder->next = temp;
	cityAdder->prev = previous;
	cityAdder->name = cityName;
	head = head;
	return head;
}

// /*Add	a	new	city	to	the	linked	list	between	the	city	*previous	and	the	city	that	
// follows	it	in	the	network.	The	name	of	the	new	city	is	in	the	argument	cityName.	
// Return	the	head	of	the	linked	list.	
// */

city *deleteCity(city *head, string cityName)
{
	city *cityDeleter;
	city *deletePrev;
	city *deleteNext;
	cityDeleter = head;
	while(cityDeleter->name != cityName)
	{
		cityDeleter = cityDeleter->next;
	}
	deletePrev = cityDeleter->prev;
	deleteNext = cityDeleter->next;
	delete cityDeleter;
	deletePrev->next = deleteNext;
	deleteNext->prev = deletePrev;
	return head;
}

// /*Delete	the	city	in	the	linked	list	with	the	specified name.	Return	the	head	of	the	
// linked	list.	*/

/* Open	the	file	messageLn.txt	and	transmit	the	message	between	all	cities	in	the	
network	word	by	word.	A	word	needs	to	be	received	at	the	end	of	the	network	
before	sending	the	next word.	Only	one	city	can	hold	the	message	at	a	time;	as	soon	
as	it	is	passed	to	the	next	city,	it	needs	to	be	deleted	from	the	sender	city. */
void transmitMsg(city *head)
{
	city *messageTransmiter;
	messageTransmiter = head;
	string word;
	ifstream message;
	message.open("messageIn.txt");
	while(!message.eof())
	{
		while(message >> word)
		{
			while(messageTransmiter->next != NULL)
			{
				if(messageTransmiter == head)
				{
				messageTransmiter->message = word;
				cout << messageTransmiter->name << " received " << messageTransmiter->message << endl;
				messageTransmiter = messageTransmiter->next;
				}
				else
				{
				messageTransmiter->message = word;
				messageTransmiter->prev->message = "";
				cout << messageTransmiter->name << " received " << messageTransmiter->message << endl;
				// cout << messageTransmiter->prev->name << " received " << messageTransmiter->prev->message << endl; //Eraser checker.
				messageTransmiter = messageTransmiter->next;
				}
			}
			messageTransmiter = head;
		}
	}
}

// city *deleteEntireNetwork(city *head)
// /*This	function	deletes	all	cities	in	the	network	starting	at	the	head	city.	The	
// function	should	return	NULL	by	returning	the	next	pointer	of	the	last	city	deleted.

void printPath(city *head)
{
	city *listPrinter;
	listPrinter = head;
	cout << "===Current Network Path===" << endl;
			while(listPrinter != NULL)
			{
				if(listPrinter->name == "NULL")
				{
					cout << listPrinter->name << endl;
					listPrinter = listPrinter->next;
				}
				else
				{
					cout << listPrinter->name << " -> ";
					listPrinter = listPrinter->next;	
				}	
			}
			cout << "=================" << endl;
			listPrinter = head;
}
// /*Go	through	each	city	in	the	network	starting	at	the	head	and	print	the	name	of	the	
// city.*/







int main(int argc, char *argv[]) { //allows for command line arguments
	std::string input;
	while(input != "7")
	{
		cout << endl;
		string cities[11] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington D.C.", "New York", "Boston", "NULL"};
		int cityCounter;

		city *head;
		city *listPointer;

		cout << "======Main Menu======" << endl;
		cout << "1. Build Network" << endl;
		cout << "2. Print Network Path" << endl;
		cout << "3. Transmit Message Coast-To-Coast" << endl;
		cout << "4. Add City" << endl;
		cout << "5. Delete City" << endl;
		cout << "6.Clear Network" << endl;
		cout << "7. Quit" << endl;
		
		
		cin >> input;
		
		if(input == "1")
		{
			cout << "Build Network" << endl;
			city *LosAngeles, *Phoenix, *Denver, *Dallas, *StLouis, *Chicago, *Atlanta, *DC, *NY, *Boston, *lastCity;
			LosAngeles = new city; //Horrid coding practices but I was getting tired of getting seg faults so I did it by hand instead.
			head = LosAngeles;
			Phoenix = new city;
			Denver = new city;
			Dallas = new city;
			StLouis = new city;
			Chicago = new city;
			Atlanta = new city;
			DC = new city;
			NY = new city;
			Boston = new city;
			lastCity = new city;
			listPointer = head;
			
			LosAngeles->next = Phoenix;
			Phoenix->prev = LosAngeles;
			Phoenix->next = Denver;
			Denver->prev = Phoenix;  
			Denver->next = Dallas;
			Dallas->prev = Denver;
			Dallas->next = StLouis;
			StLouis->prev = Dallas;
			StLouis->next = Chicago;
			Chicago->prev = StLouis;
			Chicago->next = Atlanta;
			Atlanta->prev = Chicago;
			Atlanta->next = DC;
			DC->prev = Atlanta;
			DC->next = NY;
			NY->prev = DC;
			NY->next = Boston;
			Boston->prev = NY;
			Boston->next = lastCity;

			
			for(int i=0;i<11;i++)
			{
				listPointer->name = cities[i];
				listPointer = listPointer->next;
				
			}
			listPointer = head;
			cityCounter = 11;
		}
		
		else if(input == "2")
		{
			printPath(head);
		}
		
		else if(input == "3")

		{
			transmitMsg(head);
		}
		
		else if(input == "4")
		{
			cout << "Enter a city name:" << endl;
			string nameOfCity;
			cin >> nameOfCity;
			
			cout << "Enter a previous city name:" << endl;
			string previousCity;
			cin >> previousCity;

			while(listPointer != NULL)
			{
				if(listPointer->name == previousCity)
				{
					addCity(head, listPointer, nameOfCity);
				}
				listPointer = listPointer->next;
			}
			listPointer=head;
		}
		
		else if(input == "5")
		{
			cout << "Enter a city name to delete:" << endl;
			string cityToDelete;
			cin >> cityToDelete;

			while(listPointer != NULL)
			{
				if(listPointer->name == cityToDelete)
				{
					deleteCity(head, cityToDelete);
				}
				listPointer = listPointer->next;
			}
			listPointer=head;
		}
		
		else if(input == "6")
		{
			//
		}
		
		else if(input == "7")
		{
			//
		}
		
		else
		{
			cout << "Wrong choice detected, please choose again!" << endl;
		}
	}
}	