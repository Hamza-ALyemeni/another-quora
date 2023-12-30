#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

struct user{
    int id;
    string name;
    string username;
    string password;
    string email;
    bool accept_anonymous = true;
    user(){
        id = 0;
        name = "";
        username = "";
        password = "";
        email = "";
        accept_anonymous = true;
    }

    void signup(){
        cout<<"Enter your Name : ";
        cin>>name;
        cout<<"Enter your Username : ";
        cin>>username;
        cout<<"Enter your Password : ";
        cin>>password;
        cout<<"Enter your Email : ";
        cin>>email;
        cout<<"Do you want to accept anonymous questions write 1 for yes and 0 for no: ";
        cin>>accept_anonymous;
        id++;
    }
    
};

struct question_answer{
    int id;
    int sender_id; 
    int reciver_id;
    int parent_id;
    pair<string,string> conversation;
    
};

struct quora{
    vector<user> users; 
    vector<question_answer> chat; 
    int users_added = 0;
    int questions_added = 0;
    int session_id = -1;

   void print_users() {
        cout << "Printing users...\n";

        if (users.empty()) {
            cout << "No users found.\n";
        } else {
            for (int i = 0; i < users.size(); i++) {
                cout << users[i].id << "\n";
                cout << users[i].name << "\n";
                cout << users[i].username << "\n";
                cout << users[i].password << "\n";
                cout << users[i].email << "\n";
                cout << "**********" << "\n";
            }
            cout << "End of users.\n";
        }
    }


    void regster(){

    }

    bool signin() {
        string n;
        string pass;
        cout << "Enter your name : ";
        cin >> n;
        cout << "Enter your password : ";
        cin >> pass;

        for (int i = 0; i < (int)users.size(); i++) {
            if (n == users[i].name && pass == users[i].password) {
                session_id = users[i].id;
                return true;
            }
        }
        return false;
    }

   void logout() {
        session_id = -1;
        cout << "Logout successful.\n";
    }

    void run() {
		while (true) {
			int choice = signin_menu();

			if (choice == 1){
				if(signin() == true){
                    quora_menu();
                }else{
                    cout<<"your credentiels is uncorrect ";
                }
            }
			else if (choice == 2){
				user u;
                u.signup();
                users.push_back(u);
            }
			else{
				break;
            }
		}
	}
    
	int signin_menu() {
		int choice = -1;
		while (choice == -1) {
			cout << "\n if you have an account you can sign in here\n";
			cout << "1) sign in\n";
            cout << "if its your first time you can sign up here \n";
			cout << "2) sign up\n";

			cout << "\nEnter your menu choice [1 - 2]: ";
			cin >> choice;

			if (!(1 <= choice && choice <= 2)) {
				cout << "Invalid choice. Try again\n";
				choice = -1;	// loop keep working
			}
		}
		return choice;
	}

    void quora_menu() {
		while (true) {
			int choice = system_menu();

			// if (choice == 1)
			// 	add_book();
			// else if (choice == 2)
			// 	search_books_by_prefix();
			// else if (choice == 3)
			// 	print_who_borrowed_book_by_name();
			// else if (choice == 4)
			// 	print_library_by_id();
			// else if (choice == 5)
			// 	print_library_by_name();
			if (choice == 6) {
                print_users();
            }
			else if (choice == 9) {
                logout();
                break;
            }
			else{
			//	break;
            }
		}
	}

    int system_menu(){
        int choice = -1;
		while (choice == -1) {
			cout << "\n Quora Menu;\n";
			cout << "1) Print Questions To Me \n";
			cout << "2) Print Questions From Me \n";
			cout << "3) Answer Questions \n";
			cout << "4) Delete Questions \n";
			cout << "5) Ask Questions \n";
			cout << "6) List System Users \n";
			cout << "7) Feed \n";
			cout << "9) Logout \n";

			cout << "\n Enter your menu choice [1 - 9]: ";
			cin >> choice;

			if (!(1 <= choice && choice <= 9)) {
				cout << "Invalid choice. Try again\n";
				choice = -1;	// loop keep working
			}
		}
		return choice;
    }
};
int main(){
    quora sys;
    sys.run();
}