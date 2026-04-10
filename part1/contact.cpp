#include "contact.h"
// TODO: Add needed libraries! 
#include <sstream>
Email::Email(string type, string email_addr){
    // TODO: Complete me!
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
	
    cout << "Enter the type of email address: ";
    // some code here
    getline(cin,type);
    cout << "Enter email address: ";
    // some code here
    getline(cin, email_addr);
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    this->type = type;
    string digits = "";
    for (int i = 0; i < (int)num.size(); i++){
    	if (num[i] != '-'){
    		digits += num[i];
    	}
    }
    
    phone_num = 0;
    istringstream ss(digits);
    ss >> phone_num;

}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
    	string num_str;
	cout <<"Enter the type of phone number: ";
	getline(cin, type);
	cout << "Enter the phone number: ";
	getline(cin, num_str);
	
	//strip dashes and convert
	string digits = "";
	for (int i = 0; i < (int)num_str.size(); i++){
		if (num_str[i] != '-'){
			digits += num_str[i];
		}
	}
	phone_num = 0;
	istringstream ss(digits);
	ss >> phone_num;
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    // get the three parts
    long long num = phone_num;
    long long last4 = num%10000;
    num /= 10000;
    long long mid3 = num%1000;
    num /= 1000;
    long long first3 = num%1000;
    
    //build segment with leading zeros if needed
    ostringstream oss;
    
    // first 3
    if (first3 < 100) oss << "0";
    if (first3 < 10) oss << "0";
    oss << first3 << "-";
    
    // mid 3
    if (mid3 < 100) oss << "0";
    if (mid3 < 10) oss << "0";
    oss << mid3 << "-";
    
    // last 4
    if (last4 < 1000) oss << "0";
    if (last4 < 100) oss << "0";
    if (last4 < 10) oss << "0";
    oss << last4;
    
    string formatted = oss.str();
    
    if (style == "full")
    	return "(" + type + ") " + formatted;
    else
    	return formatted;
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

