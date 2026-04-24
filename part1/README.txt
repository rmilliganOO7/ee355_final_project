Trojan-Book Project - Part 1
Cesar Medellin, Riley Milligan, & Bryson Ngo
README

Overview
This project implements a small contact-management system called Trojan-Book in C++. 
The program is built around object-oriented design and a doubly linked list database. 
A Person stores a first name, last name, birth date, one phone number, and one email address. 
A Network stores multiple Person objects and supports loading, saving, insertion, removal, and simple search/print operations.

Files Included
1. contact.h / contact.cpp
- Defines the abstract base clas Contact.
- Defines the derived classes Email & Phone.
- Email stores an email type and email address.
- Phone stores a phone type and phone number, strips dashes on input, adn formats the number as XXX-XXX-XXXX when printed.

2. date.h / date.cpp
- Defines the Date class.
- Stores month, day, and year as integers
- Parses dates from strings in M/D/YYYY or MM/DD/YYYY style.
- Supports printing and equality comparison

3. person.h / person.cpp
- Defines the Person class.
- Stores first name, last name, birth date, email, and phone using dynamically allocated objects.
- Supports keyboard input, file input, printing, and equality comparison.
- Equality is based on first name, last name, and birthdate

4. network.h / network.cpp
- Defines the Network.cpp
- Uses a doubly linked list with head and tail pointers
- Supports:
* push_front()
* push_back()
* loadDB()
* saveDB()
* remove()
* search(Person*)
* search(string fname, string lname)
* showMenu()

5. misc.h / misc.cpp
- COntains the printMe() helper function used to print the Trojan-Book banner.

Design Summary
- Inheritance:
  contact is an abstract parent class. Email adn Phone inherit from contact and implement print(), get_contact(), and set_contact().

- Dynamic Memory:
  Person dynamically allocates Date, Email, and Phone objects. The Person destructor deletes these objects.
  Network dynamically manages Person nodes in the linked list and deletes all nodes in its destructor.

- Linked List Structure
  Network stores Person objects in a doubly linked list using next and prev pointers. This allows insertion at the fornt or back and safe removal of matching entries.

How Input/Output Works
- A Person can be created interactively from user input.
- A Person can also be created from a file
- Network databases can be loaded from .txt files
- The database can be saved back into a text file in the same printed format used by print_person()

Main Features Implemented
- Contact hierarchy with Phone and Email subclasses
- Date parsing and comparison
- Person construction from terminal input and file input
- Person equality and inequality operators
- Doubly linked list database
- Add a person to the front of the network
- Add a person to the back of the network
- Remove a person by first and last name
- Search for a person by object or by first/last name
- Save and load the full network database
- Print people with a requested last name
- Interactive text menu
Compilation
Compile command is:
g++ -std=c++11 contact.cpp date.cpp person.cpp network.cpp misc.cpp
test_network.cpp -o test_network
Assumptions
- Input files follow the expected course format.
- Each Person has exactly one birth date, one phone number, and one
email address
- Phone numbers may be entered with or without dashes.
- Duplicate checking in the menu uses first name and last name before
insertion.
- Person equality uses first name, last name, and birth date.
Testing Suggestions
We tested the code using the following kinds of cases:
- Creating a person manually from keyboard input
- Loading a database from a .txt file
- Saving the current network to a new file
- Adding a person who does not already exist
- Attempting to add a duplicate person
- Removing an existing person
- Attempting to remove a missing person
- Printing all people with the same last name
- Verifying that phone numbers print in XXX-XXX-XXXX format
