Trojan-Book Project - Part 2
Cesar Medellin, Riley Milligan, & Bryson Ngo
README

Overview
This phase extends the Trojan-Book contact-management system by introducing friendship connections between Person objects.
Each Person can now maintain a list of friends, allowing the Network to simulate a simple social network where users can connect with each other.

Files Included
1. person.h / person.cpp
- Defines the Person class.
- Stores first name, last name, birth date, email, and phone using dynamically allocated objects.
- Supports keyboard input, file input, printing, and equality comparison.
- Equality is based on first name, last name, and birthdate
- Added a vector<Person*> myfriends attribute to store friendships.
- Implemented makeFriend(Person* newFriend) method.
- This method adds a new friend to the person’s friend list while preventing invalid entries (such as self or null pointers).

2. network.cpp
Defines the Network.cpp
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
- Added a new menu option (Option 6: Connect).
Allows users to Input two people by first and last name
- Search for both individuals in the network
- If both exist, connect them as friends
- Print both persons' information after connecting
- Handles error cases when a person is not found.

3. misc.h / misc.cpp
Added helper function:
string codeName(string str1, string str2);
This function:
- Concatenates first and last names
- Removes all spaces
- Converts all characters to lowercase
- Used to generate a unique ID for each person (for future parts).

Design Summary
- Extension of OOP Design:
The Person class is extended to include relationships between objects using pointers.
Graph-like Structure:
The network now behaves like a simple graph:
Nodes → Person objects
Edges → Friend connections
- Encapsulation:
Friendship logic is handled inside the Person class using makeFriend().

Main Features Implemented
- Added a friendship system using a vector of Person*
- Each Person can store and manage a list of friends
- Implemented makeFriend(Person*) to create connections between users
- Ensured friendships are mutual (bidirectional connections)
- Added a new menu option (Connect) to link two people
- Search-based connection using first name and last name
- Error handling when attempting to connect non-existent users
- Prevented invalid friendships (self-connections and null pointers)
- Implemented codeName() helper function for generating unique IDs

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

New tests to include:
Connecting two existing people
Attempting to connect a person that doesn’t exist
Verifying both people become friends
Trying to connect the same two people multiple times
Ensuring no self-connections



