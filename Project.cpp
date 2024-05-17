#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include "Signup.h"
#include "Signup.cpp"

using namespace std;

int main () {
	ofstream Project ("project.txt", ios::app);
	if (!Project) {
		cerr << "File is not opened";
		exit(EXIT_FAILURE);
	}
	Signup signup;
	Signup();
	string name, l_name, phone, id, pass, email;
	Project << "Welcome!";
	Project << "Please enter your informaion : ";
    Project << "Name : ";
    ifstream project ("project.txt", ios::in);
	project >> name;
	Project << "Last Name : ";
	project >> l_name;
	Project << "Passward : ";
	project >> pass;
	try {
	signup.CheckPassward(pass);
}
    catch (...) {
    	cout << "Enter information again : ";
	}
	Project << "Phone : ";
	project >> phone;;
	Project << "Email : ";
	project >> email;
	try {
	signup.CheckEmail(email);
}
    catch (...) {
    	cout << "Enter information again : ";
	}
	Project << "Email : ";
	project >> id;
	try {
	signup.CheckId(id);
}
    catch (...) {
    	cout << "Enter information again : ";
	}
	signup.setSignup(name, l_name, pass, email, id, phone); 
	return 0;
}