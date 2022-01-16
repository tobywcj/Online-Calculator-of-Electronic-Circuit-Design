#include <fstream>
#include <iostream>
#include <cmath>
#include "essential_func.h"
using namespace std;

///// login part 
class LoginAdministrator
{
public:
    LoginAdministrator()
    {
        allowIn = 0;
    }

void login();
    
bool ckeckFile (string attempt , const char* p_fileName);
    
void addUser(const string username, const string password);

int getLastID();

void saveFile(string p_line, const char* p_fileName, const int& id);
    

long long  encrypt(int  p_letter) ;
    
int  decrypt(long long  p_letter);
    
private:
    
  string userNameAttempt;
  string passwordAttempt;
  bool allowIn;

};

class SignupAdministrator{
  public:
  // only accessors and mutators are public in this example
  private :
  // member variables are private and set/get via accessor/mutator
  string gessNameEntered;
  string PasswordEntered;

};