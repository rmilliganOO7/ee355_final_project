
#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>
#include <dirent.h>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method! - finished(riley)
    head = NULL;
	tail = NULL;
	count = 0;
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName); 
}

Network::~Network(){ 
    Person* cur = head;
	while (cur != NULL){
		Person* nxt = cur->next;
		delete cur;
		cur = nxt;
	}
	head = NULL;
	tail = NULL;
	count = 0;
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method - finished(riley)
    if (searchEntry == NULL)
        return NULL;
    Person* cur = head;
    while (cur != NULL){
        if (*cur == *searchEntry)
            return cur;
        cur = cur->next;
    }
    return NULL;
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method - finished(riley)
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
    Person* cur = head;
	while (cur != NULL){
		if (cur->f_name == fname && cur->l_name == lname)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


static bool is_separator_line(const string& s){
	if (s.size() < 4)
		return false;
	for (int i = 0; i < (int)s.size(); i++){
		if (s[i] != '-')
			return false;
	}
	return true;
}

void Network::loadDB(string filename){
    // TODO: Complete this method - finished(riley)
    ifstream in(filename.c_str());
    if (!in)
        return;

    Person* cur = head;
    while (cur != NULL){
        Person* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = NULL;
    tail = NULL;
    count = 0;

    string fn, ln, bd, el, pl, sep;
    while (getline(in, fn)){
        if (fn.size() == 0)
            continue;
        if (is_separator_line(fn))
            continue;
        if (!getline(in, ln))
            break;
        if (!getline(in, bd))
            break;
        if (!getline(in, el))
            break;
        if (!getline(in, pl))
            break;
        Person* p = new Person(fn, ln, bd, el, pl);
        push_back(p);
        if (getline(in, sep)){
            if (!is_separator_line(sep)){
                // malformed vs. strict template; keep going without losing a line
            }
        }
    }
    
}

void Network::saveDB(string filename){
    // TODO: Complete this method - finished(riley)
    ofstream out(filename.c_str());
	if (!out)
		return;
	Person* ptr = head;
	streambuf* oldbuf = cout.rdbuf();
	while (ptr != NULL){
		cout.rdbuf(out.rdbuf());
		ptr->print_person();
		cout.rdbuf(oldbuf);
		out << "--------------------" << endl;
		ptr = ptr->next;
	}
	cout.rdbuf(oldbuf);
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}



void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL - finished(riley)
    // TODO: Complete this method
    newEntry->next = NULL; //same as push_front
	newEntry->prev = tail; //same
	if (tail != NULL)
		tail->next = newEntry;
	else
		head = newEntry;
	tail = newEntry;
	count++;
}


bool Network::remove(string fname, string lname){
    // TODO: Complete method - finished(riley)
    Person* p = search(fname, lname);
	if (p == NULL)
		return false;
	if (p->prev != NULL)
		p->prev->next = p->next;
	else
		head = p->next;
	if (p->next != NULL)
		p->next->prev = p->prev;
	else
		tail = p->prev;
	delete p;
	count--;
	return true;
 
}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
        cout << "6. Connect two people \n"; //add new connection option
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me! - completed(riley)
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            getline(cin, fileName);
            saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
            
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format - completed(riley)
            DIR* dir = opendir(".");
            if (dir != NULL){
                struct dirent* ent;
                while ((ent = readdir(dir)) != NULL){
                    string n = ent->d_name;
                    if (n.size() >= 4 && n.substr(n.size() - 4) == ".txt")
                        cout << n << endl;
                }
                closedir(dir);
            }
            // print format: one filename one line.
            // This step just shows all the available .txt file to load.
            cout << "Enter the name of the load file: "; 
            // If file with name FILENAME does not exist: 
            //cout << "File FILENAME does not exist!" << endl;
            // If file is loaded successfully, also print the count of people in it: 
            getline(cin, fileName);
            ifstream fin(fileName.c_str());
            if (!fin){
                cout << "File " << fileName << " does not exist!" << endl;
            }
            else{
                fin.close();
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
        }
        else if (opt == 3){
            // TODO: Complete me! - completed(riley)
            // TODO: use push_front, and not push_back 
            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";
            Person* p = new Person();
            if (search(p->f_name, p->l_name) != NULL){
                delete p;
                cout << "Person already exists! \n";
            }
            else{
                push_front(p);
            }
        }
        else if (opt == 4){
            // TODO: Complete me! - completed(riley)
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            getline(cin, fname);
            cout << "Last name: ";
            getline(cin, lname);
            if (remove(fname, lname))
                cout << "Remove Successful! \n";
            else
                cout << "Person not found! \n";
        }
        else if (opt==5){
            // TODO: Complete me! - completed(riley)
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            bool found = false;
            cout << "Print people with last name \n";
            cout << "Last name: ";
            getline(cin, lname);
            
            Person* cur = head;
            while (cur != NULL){
                if (cur->l_name == lname){
                    cur->print_person();
                    found = true;
                }
                cur = cur->next;
            }
            if (!found)
                cout << "Person not found! \n";
        }
            // add connect option for people to be friends
            // if not found print and go back to main menu
            // if they both exist print info in order
            // completed (bryson)
        else if (opt == 6){
            cout << "Make friends\n";

            string fname1, lname1, fname2, lname2;

            cout << "Person 1\n";
            cout << "First Name: ";
            getline(cin, fname1);
            cout << "Last Name: ";
            getline(cin, lname1);

            Person* p1 = search(fname1, lname1);
            if (p1 == NULL){
                cout << "Person not found\n";
            }
            else{
                cout << "Person 2\n";
                cout << "First Name: ";
                getline(cin, fname2);
                cout << "Last Name: ";
                getline(cin, lname2);

                Person* p2 = search(fname2, lname2);
                if (p2 == NULL){
                    cout << "Person not found\n";
                }
                else{
                    p1->makeFriend(p2);
                    p2->makeFriend(p1);

                    p1->print_person();
                    p2->print_person();
                }
            }
        }
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}