#include<iostream>
#include<fstream>

using namespace std;

struct user{
    int id;
    string name;
    string username;
    string password;
    string email;
    bool accept_anonymous = true;
    user(){
        id = -1;
        name = "";
        username = "";
        password = "";
        email = "";
        accept_anonymous = true;
    }

    void signup(){

    }
    

}

struct question{
    int id;
    string name;
}

int main(){
    
}