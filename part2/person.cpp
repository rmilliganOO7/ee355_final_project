#include "person.h"

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
    delete email;
    delete phone;
}


Person::Person(string f_name, string l_name, string b_date, string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version
    this -> f_name = f_name;
    this -> l_name = l_name;
    
    birthdate = new Date(b_date);
    
    //parse email string
    string email_type = email.substr(1, email.find(')')- 1);
    string email_addr = email.substr(email.find(')') + 2);
    this -> email = new Email(email_type, email_addr);
    
    string phone_type = phone.substr(1, phone.find(')') - 1);
    string phone_num = phone.substr(phone.find(')')+2);
    this->phone = new Phone(phone_type, phone_num);
    
    next = NULL;
    prev = NULL;
}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    // code here
    std::getline(std::cin, type);
    cout << "Email address: ";
    // code here
    std::getline(std::cin, temp);
    email = new Email(type, temp);

    cout << "Type of phone number: ";
    // code here
    std::getline(std::cin, type);
    cout << "Phone number: ";
    // code here
    std::getline(std::cin, temp);
    phone = new Phone(type, temp);
    // code here
    next = NULL;
    prev = NULL;
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    ifstream infile(filename.c_str());
    
    string temp, type;
    
    getline(infile, f_name);
    getline(infile, l_name);
    getline(infile, temp);
    birthdate = new Date(temp);
    
    getline(infile, temp);
    type = temp.substr(1, temp.find(')')-1);
    string num = temp.substr(temp.find(')')+2);
    phone = new Phone(type,num);
    
    getline(infile, temp);
    type = temp.substr(1, temp.find(')')-1);
    string addr = temp.substr(temp.find(')')+2);
    email = new Email(type, addr);
    
    next = NULL;
    prev = NULL;
}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    return (f_name == rhs.f_name && l_name == rhs.l_name && *birthdate == *rhs.birthdate);
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    return !(*this == rhs);
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    phone->print();
    email->print();

	for(int i = 0; i < (int)myfriends.size(); i++){
		cout << myfriends[i] -> email -> get_contact("short") 
			<< " (" << myfriends[i] -> f_name << " " 
			<< myfriends[i] -> l_name << ")" << endl;
	}
}

// part 2 (bryson)
void Person::makeFriend(Person* newFriend){
    if (newFriend == NULL || newFriend == this)
        return;

    // prevent duplicates
    for (int i = 0; i < (int)myfriends.size(); i++){
        if (myfriends[i] == newFriend)
            return;
    }

    myfriends.push_back(newFriend);
}
// make pretty list part 4 (cesar)
void Person::print_friends(){
	vector<Person*> sortedFriends = myfriends;

	for (int i = 0; i < (int)sortedFriends.size() - 1; i++){
		for (int j = 0; j < (int)sortedFriends.size() - i - 1; j++){
			string code1 = sortedFriends[j] -> f_name + sortedFriends[j] -> l_name;
			string code2 = sortedFriends[j + 1] -> f_name + sortedFriends[j + 1] -> l_name;

			if (code1[0] > code2[0] ||
				(code1[0] == code2[0] && code1[1] > code2[1])){
				
				Person* temp = sortedFriends[j];
				sortedFriends[j] = sortedFriends[j +1];
				sortedFriends[j + 1] = temp;
				
			}
		}
	}
	cout << f_name << ", " << l_name << endl;
	cout << "------------------------------" << endl;

	for (int i = 0; i < (int)sortedFriends.size(); i++){
		cout << sortedFriends[i] -> f_name << ", "
			<< sortedFriends[i] -> l_name << endl;
	}
}
