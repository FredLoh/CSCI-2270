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
	head = new city;
	head->prev = previous;
	head->name = cityName;
	return head;
}

// /*Add	a	new	city	to	the	linked	list	between	the	city	*previous	and	the	city	that	
// follows	it	in	the	network.	The	name	of	the	new	city	is	in	the	argument	cityName.	
// Return	the	head	of	the	linked	list.	
// */

// city *deleteCity(city *head, string	cityName)

// /*Delete	the	city	in	the	linked	list	with	the	specified name.	Return	the	head	of	the	
// linked	list.	*/

// void transmitMsg(city *head)

// Open	the	file	messageLn.txt	and	transmit	the	message	between	all	cities	in	the	
// network	word	by	word.	A	word	needs	to	be	received	at	the	end	of	the	network	
// before	sending	the	next word.	Only	one	city	can	hold	the	message	at	a	time;	as	soon	
// as	it	is	passed	to	the	next	city,	it	needs	to	be	deleted	from	the	sender	city.	

// city *deleteEntireNetwork(city *head)
// /*This	function	deletes	all	cities	in	the	network	starting	at	the	head	city.	The	
// function	should	return	NULL	by	returning	the	next	pointer	of	the	last	city	deleted.
// void	printPath(city	*head)
// /*Go	through	each	city	in	the	network	starting	at	the	head	and	print	the	name	of	the	
// city.*/







int main(int argc, char *argv[]) { //allows for command line arguments
	


	city *head;

	cout << "======Main Menu======" << endl;
	cout << "1. Build Network" << endl;
	cout << "2. Print Network Path" << endl;
	cout << "3. Transmit Message Coast-To-Coast" << endl;
	cout << "4. Add City" << endl;
	cout << "5. Delete City" << endl;
	cout << "6.Clear Network" << endl;
	cout << "7. Quit" << endl;
	
	std::string input;
	// int intInput = stoi(input);
	cin >> input;
	if(input == "1")
	{
		cout << "Build Network" << endl;
	}
	else if(input == "2")
	{
		cout << "Print Network Path" << endl;
	}
	else if(input == "3")

	{
		//
	}
	else if(input == "4")
	{
		//
	}
	else if(input == "5")
	{
		//
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