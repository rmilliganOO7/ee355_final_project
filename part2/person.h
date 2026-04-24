#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "contact.h"
#include "fstream"
#include <vector> //including vector
class Person{
    friend class Network;

private:
	string f_name;
	string l_name;
	Date *birthdate;
    Email *email;
    Phone *phone;
    
    vector<Person*> myfriends; // part 2 add friend vector (bryson)

    // the following to attributes are used in the linked list.
    Person* next;
    Person* prev;

public: 
    Person();
    ~Person();
    Person(string filename);
    Person(string f_name, string l_name, string b_date, string email, string phone);
	void print_person();
	void set_person();
	void set_person(string filename);

    void makeFriend(Person* newFriend); // part2 add makeFriend function (bryson)
	void print_friends(); // part 4 function (cesar)

    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
};


#endif
