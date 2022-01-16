#include "login.h"

void LoginAdministrator::login() {
  std::cout << "\n------------------- Login Interface -------------------\n\n";
	cout << "Hello! \nWelcome to our application, a username is required. "
			"\nUsername:";  
	cin >> userNameAttempt;

	int usrID = ckeckFile(userNameAttempt, "users.txt");
	if (usrID != 0) {
		cout << "Password:";
		cin >> passwordAttempt;

		int pwdID = ckeckFile(passwordAttempt, "passwords.txt");
		if (usrID == pwdID) {
			cout << "Thank you! you have successfully logged in! \n" << endl;
      ;
			cout << "Now you have access to a range of useful Engineering calculators \n" << endl;
      ;
			//main_menu();

		} else {
			cout << "attempt failed." << endl;
			login();
		}
	} else {
		cout << "Useername corrects." << endl;
		login();
	}
}
void LoginAdministrator::addUser(const string username, const string password) {
	if (ckeckFile(username, "users.txt") != 0) {
		cout << "That username is not availble." << endl;
		return;
	}

	int id = 1 + getLastID();
	saveFile(username, "users.txt", id);
	saveFile(password, "passwords.txt", id);
}

int LoginAdministrator::getLastID() {
	fstream file;
	file.open("users.txt", ios::in);
	file.seekg(0, ios::end);

	if (file.tellg() == -1)
		return 0;

	string s;

	for (int i = -1; s.find("#") == string::npos; i--) {
		file.seekg(i, ios::end);
		file >> s;
	}

	file.close();
	s.erase(0, 4);

	int id;
	istringstream(s) >> id;

	return id;
}

void LoginAdministrator::saveFile(
	string p_line,
	const char *p_fileName,
	const int &id) {
	fstream file;
	file.open(p_fileName, ios::app);
	file.seekg(0, ios::end);

	if (file.tellg() != 0)
		file << "\n";

	file.seekg(0, ios::beg);

	for (int i = 0; i < p_line.length(); i++) {
		file << encrypt(p_line[i]);
		file << "\n";
	}

	file << "#ID:" << id;
	file.close();
}
bool LoginAdministrator ::ckeckFile(string attempt, const char *p_fileName) {
	string line;
	fstream file;

	string currentChar;
	long long eChar;

	file.open(p_fileName, ios::in);

	while (1) {
		file >> currentChar;
		if (currentChar.find("#ID:") != string::npos) {
			if (attempt == line) {
				file.close();
				currentChar.erase(0, 4);
				int id;
				istringstream(currentChar) >> id;
				return id;
			} else {
				line.erase(line.begin(), line.end());
			}
		} else {
			istringstream(currentChar) >> eChar;
			line += (char)decrypt(eChar);
			currentChar = "";
		}

		if (file.peek() == EOF) {
			file.close();
			return 0;
		}
	}
}

long long LoginAdministrator ::encrypt(int p_letter) {
	return powf(p_letter, 5) * 4 - 14;
}

int LoginAdministrator ::decrypt(long long p_letter) {
	return powf((p_letter + 14) / 4, 1 / 5.f); // return it as float
}
