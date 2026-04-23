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

