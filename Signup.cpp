# include <iostream>
# include <string>
# include <stdexcept>
# include "Signup.h"

using namespace std;


bool Signup::CheckId(string Id) {
	int sum, r, t;
	bool flag = 0;
	if (Id.length() < 10 && Id.length() > 7) {
		for (int i = Id.length() - 1; i >= 0; i--) {
			t = 10 - Id.length();
			Id[i + t] = Id[i];
			for (int i = 0; i < 10 - Id.length(); i++)
				Id[i] = '0';
		}
	}
	for (int i = 9; i > 0; i--) 
		sum += Id[i] * (i + 1);
	r = sum % 11;
	if ((r < 2 && r == Id[0]) || (r >= 2 && 11 - r == Id[0])) {
		flag = 1;
		return flag;
	}
	else {
	    throw invalid_argument ("Here are the conditions : ");
	}
}

bool Signup::CheckEmail(string Email) {
	bool flag1 = 0, flag2 = 0;
	for (int i = 0; i < Email.length(); i++) {
		Email[i] = tolower(Email[i]);
		if (Email[i] == '@') 
			if (Email[i - 1] != ' ')
				flag1 = 1;
	}
	for (int i = 0; i < Email.length(); i++) {
		if (Email[i] == '.')
			if (Email[i - 1] != ' ' && Email[i + 1] != ' ')
				flag2 = 1;
    }
	if(flag1 & flag2 == 0)
	    throw invalid_argument ("Here are the conditions : ");
	else
	    return flag1;
}

bool Signup::CheckPassward(string Passward) {
	bool flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
	for (int i = 0; i < 12; i++) {
		if ('a' <= Passward[i] && Passward[i] <= 'z' && 'A' <= Passward[i] && Passward[i] <= 'Z')
			flag1 = 1;
		if (0 <= (int)Passward[i] && (int)Passward[i] <= 9)
			flag2 = 1;
		if (5 < Passward.length() && Passward.length() < 13)
			flag3 = 1;
		if (Passward[i] == '@' || '#' || '%' || '&' || '*')
			flag4 = 1;
	}
	if(flag1 & flag2 & flag3 & flag4 == 0)
	    throw invalid_argument ("Here are the conditions : ");
	else
	    return flag1;
}

void Signup :: setSignup (string id, string phone, string pass, string name, string l_name, string email) 
{
	Signup signup;
	CheckPassward(pass);
	CheckId(id);
	CheckEmail(email);
    signup.Name = name;
    signup.L_Name = l_name;
    signup.Passward = pass;
    signup.Id = id;
    signup.Email = email;
    signup.Phone = phone;
    User.push_back(signup);
}
