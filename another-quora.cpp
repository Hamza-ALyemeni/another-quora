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
    }
    
    
};

struct question_answer{
    int id;
    int sender_id; 
    int reciver_id;
    int parent_id;
    string question;
    string answer;
     
    question_answer(){
        id = 0;
        sender_id = 0;
        reciver_id = 0;
        parent_id = 0;
        question = "";
        answer = "Not Answerd Yet";
    }
};

struct quora{
    vector<user> users; 
    vector<question_answer> chat; 
    int users_id = 0;
    int question_added = 0;
    int session_id = -1;

   void print_users() {
        if (users.empty()) {
            cout << "No users found.\n";
        } else {
            for (int i = 0; i < users.size(); i++) {
                cout << "ID : "<<users[i].id << "         ";
                cout <<" Name : "<< users[i].name << "\n";
            }
        }
    }

    bool search_user_id(int id){
          for (int i = 0; i < users.size(); i++) {
               if (users[i].id == id)
                    return true;  
            }
        return false;
    }

     bool search_question_id(int id){
          for (int i = 0; i < users.size(); i++) {
               if (chat[i].id == id)
                    return true;  
            }
        return false;
    }

    void feed(){
        for (int i = 0; i < chat.size(); i++)
        {
            cout<<"\n Question ID : ("<<chat[i].id<<") "<<" from user id : ("<<chat[i].sender_id<<") to user id : ("<<chat[i].reciver_id<<")       "<<"Question :" << chat[i].question <<"\n";
            cout<<"         Answer : "<<chat[i].answer; 
        }
    }

    void ask(){
        question_answer qa; 
        chat.push_back(qa); 
        cout<<"Enter user id or -1 to cancel : ";
        int question_id;
        cin>>chat[question_added].reciver_id;
        if(search_user_id(chat[question_added].reciver_id) == true){
            if(users[chat[question_added].reciver_id].accept_anonymous == false)
                cout<<"this user deos not accept anonymous questions \n";
            
            cout<<"Enter Question id or -1 for new question : ";
            cin>>question_id;
            if (search_question_id(question_id))
            {
                 cout << "Enter Question: ";
                 cin.ignore(); // Clear the input buffer
                 getline(cin, chat[question_added].question);
                 chat[question_added].id = question_id;
            }
            else if(question_id == -1){
                cout << "Enter Question: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, chat[question_added].question);
                chat[question_added].id = question_added;
            }else{
                 cout<<"there is no such question to reply on !!";
                 return;
            }
            
           chat[question_added].sender_id = session_id;
           question_added++;
        }
        else if(chat[question_added].reciver_id == -1)
            return;
        else
            cout<<"this user does not exist .";
    }

        // void ask() {
        //     // Ensure there is an element in the vector for the current question_added index
        //     if (question_added >= chat.size()) {
        //         question_answer qa;  // Create a new question_answer object
        //         chat.push_back(qa);  // Add it to the vector
        //     }

        //     cout << "Enter user id or -1 to cancel: ";
        //     cin >> chat[question_added].reciver_id;

        //     if (chat[question_added].reciver_id == -1) {
        //         return; // Exit the function if the user chooses to cancel
        //     }

        //     if (search_user_id(chat[question_added].reciver_id)) {
        //         if (!users[chat[question_added].reciver_id].accept_anonymous) {
        //             cout << "This user does not accept anonymous questions.\n";
        //             return;
        //         }

        //         cout << "Enter Question id or -1 for a new question: ";
        //         cin >> chat[question_added].id;
        //         if (search_question_id(chat[question_added].id)) {
        //             cout << "Enter Question: ";
        //             cin.ignore(); // Clear the input buffer
        //             getline(cin, chat[question_added].question);
        //             chat[question_added].sender_id = session_id;
        //             question_added++;
        //         } else if (chat[question_added].id == -1) {
        //             cout << "Enter Question: ";
        //             cin.ignore(); // Clear the input buffer
        //             getline(cin, chat[question_added].question);
        //             chat[question_added].sender_id = session_id;
        //             question_added++;
        //         } else {
        //             cout << "Invalid Question id.\n";
        //         }
        //     } else {
        //         cout << "This user does not exist.\n";
        //     }
        // }

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
                u.id = users_id++;
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
			if (choice == 5)
				ask();
			else if (choice == 6)
                print_users();
            else if (choice == 7)
                feed();
			else if (choice == 8) {
                logout();
                break;
            }
			else
		    	break;
            
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
			cout << "8) Logout \n";

			cout << "\n Enter your menu choice [1 - 8]: ";
			cin >> choice;

			if (!(1 <= choice && choice <= 8)) {
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

    return 0;
}