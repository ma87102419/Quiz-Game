#include<iostream>
#include<string>
#include<vector> 
#include<fstream> // for file input and output
#include<sstream> // istringstream
#include <cstdlib> /* about random */
#include <ctime> /* about time */
//#include <conio.h>/* kbhit */

using namespace std;

const int MAX_ACC_PASS_LEN = 11; // the maximum account and password length a person can set
int curr_active_user = 0; // record the number of active user 
const int MAX_USER_NUM = 100;
const int NUM_OPTION = 4;
const int LEVEL = 7;
const int RESPONSE_TIME = 10;
const int USER_BANNED_TIME = 300;

class User{
	friend void fileInput(string dir, User** allUser);
	friend int findUser(string user, User** allUser);
	friend void createUser(User** allUser);
	friend void Login(User** allUser);
	private:
		float time_used; // probably will convert to second
		int total_ques_answered; // the total questions answered
		int life; // five life at the start of the game. If it is deducted to zero, he/ she will wait for 10 mins(?
		int current_lv; 
		string username;
		string password;
		bool complete_status; // state whether the user completed the game 
		bool account_status; // check if the account is set up properly
		string wish; // the wish that user makes after clearing the game
		bool wish_status; // whether the wish is private
		bool banned_status; 
		int banned_time;
	public:
		User(string name, string pass);
		User(string username, string password, bool complete_status, int total_ques_answered, int time_used, int life, int current_lv, bool account_status, string wish, bool wish_status, bool banned_status, int banned_time);
		void add_time_used(int time_in_question);
		void add_total_ques_answered(); // increment by 1 by default
		void increment_lv(); // one question correct, then the user can increment one level 
		void decrement_lv(); // one question wrong, then the user will decrement one level
		void deduct_life(); // one question wrong, then then user will decrement one life
		void set_banned_time(int time_in_sec){this -> banned_time = time_in_sec; } // setter // record the time that the user start to be banned!
		void set_banned_status(bool status){this -> banned_status = status; } // setter // when recording the banned time, set the banned_status to be true;
		void set_complete_status(bool comp_status){this -> complete_status = comp_status;} // setter
		void set_wish(string add_wish){this -> wish = add_wish;} // set the wishes of the user if he/she complete the game
		void set_wish_status(bool wishStatus){this -> wish_status = wishStatus;}
		void refill_life(); // life refill to 5 after a game 
		
		int get_time_used(){return this -> time_used;} // getter
		int get_total_ques_answered(){return this -> total_ques_answered;} // getter 
		string get_username(){return this -> username;} // getter
		string get_password(){return this ->password;} // getter
		bool get_complete_status(){return this -> complete_status;} // getter
		int get_life(){return this -> life;} // getter
		int get_account_status(){return this -> account_status;} // getter
		int get_current_lv(){return this->current_lv;} // getter // not 
		string get_wish(){return this -> wish;}
		bool get_wish_status(){return this -> wish_status;}
		bool get_banned_status(){return this-> banned_status;}
		int get_banned_time(){return this -> banned_time;}
		void print(); // to check if the member information is constructed correctly
};

User::User(string username, string password){
	curr_active_user++;
	this -> time_used = 0;
	this -> total_ques_answered = 0;
	this -> life = 5;
	this -> username = username;
	this -> password = password; 
	this -> complete_status = 0;
	this -> account_status = 1; // status normal 
	this -> current_lv = 1;
	this -> wish = "?L";
	this -> wish_status = 0;
	this -> banned_status = 0;
	this -> banned_time = 0;
	//this -> login_status = 1; // the person can log into the account;
}
User::User(string username, string password, bool complete_status, int total_ques_answered, int time_used, int life, int current_lv, bool account_status, string wish, bool wish_status, bool banned_status, int banned_time){
	curr_active_user++;
	this -> username = username;
	this -> password = password; 
	this -> complete_status = complete_status; 
	this -> total_ques_answered = total_ques_answered;
	this -> time_used = time_used;
	this -> life = life;
	this -> current_lv = current_lv;
	this -> account_status = account_status;
	this -> wish = wish;
	this -> wish_status = wish_status; 
	this -> banned_status = banned_status;
	this -> banned_time = banned_time; 
	
}

void User::deduct_life(){
	this -> life -= 1;
	// check if the life is greater than 0
	// if(this -> life >= 0)
	// 	return true;
	// else
	// 	return false;
		
}
void User::refill_life(){
	this -> life = 5;
}

void User::add_time_used(int time_in_question){
	this -> time_used += time_in_question;
}

void User::increment_lv(){
	this -> current_lv += 1;
	// if(this -> current_lv == 8){
	// 	return true;
	// }
	// else
	// 	return false;
	
}

void User::decrement_lv(){
	if(this -> current_lv - 1 == 0)
		this -> current_lv = 1;
	else
		this -> current_lv -= 1;
}

void User::add_total_ques_answered(){
	this -> total_ques_answered += 1;
}

void User::print(){
	cout << "?b???W?? : " << this -> username << endl; 
	cout << "?b???K?X : " << this -> password << endl;
	cout << "?O?_?w?????}?? : ";
	if(this -> complete_status)
		cout << "?O" << endl;
	else
		cout << "?_" << endl;
	cout << "??O??? : " << this -> time_used << endl;
	cout << "???D???? : " << this -> total_ques_answered << endl;
	cout << "??R?? : " << this -> life << endl; 
	cout << "?{?b???d : " << this -> current_lv << endl; 
	cout << "?b?????A : " << this -> account_status << endl;
	//cout << "login status: " << this -> login_status << endl;
	cout << "?@?? : " << this -> wish << endl;
	cout << "?@?檬?A : " << this -> wish_status << endl; 
	cout << "?O?_?i?H?C?? : ";

	if(this -> banned_status && time(NULL) - this -> banned_time <= USER_BANNED_TIME)
		cout << "????" << endl;
	else
		cout << "?i?H" << endl; 

	cout << "??l?T????(??) : ";
	if((time(NULL) - this -> banned_time) <= USER_BANNED_TIME)
		cout << USER_BANNED_TIME - (time(NULL) - this -> banned_time) << endl;
	else{
		//this -> banned_time = 0; // reset to zero
		cout << 0 << endl;
	}
			
	cout << "................................" << endl;
	return;
}

class Question{
	friend class check_answer;
	private:
		int num_question;
		vector<string> ques_vec; // a single dimensional vector storing the questions
		vector<vector<string>> option_vec; // a two dimensional vector storing options (4 options)
		vector<string> answer_vec; // a single dimensional vector storing the answer of the answer to the question;
	public:
		Question(); // constructor, questions, options, and answers will also be written into it
		string get_ques(int ind_ques){return ques_vec[ind_ques];} // get the desired question
		string get_option(int row, int col){return option_vec[row][col];} // get the desired option
		// int get_ans(int ind_ans); // to obtain the answer to the question
		bool check_answer(int ind_ques, string userInput); // to check if the answer is correct
};

Question::Question(){

	// file input - question file(in ansi format)
	// note that in visual studio code, the default encoding is utf-8
	std::ifstream quesFile("../question_ansi.txt");
	std::string quesStr;
	if(quesFile){
		while(std::getline(quesFile, quesStr)){
			//cout << quesStr << endl;
			ques_vec.push_back(quesStr);
		}	
	}
	quesFile.close();
	
	// option
	
	fstream optFile("../options_ansi.txt");
	int index_vector = 0;
	if(optFile){
			// changing the line (type: string) to input stream	
		string option_line;
		while (getline(optFile, option_line,'\n')) {
		 	istringstream templine(option_line);
			option_vec.push_back(vector<string>()); // pushback an empty string vector
			index_vector += 1;
			string option;
			while(getline(templine, option, ',')){
				option_vec[index_vector - 1].push_back(option);
				//cout << index_vector << endl; 
				//cout << option << endl;
			}
		}	
	}	
	optFile.close();

	
	
	// answer

	fstream answerFile("../answer_ansi.txt");
	string answer_char;
	if(answerFile){
		while(answerFile >> answer_char)
			answer_vec.push_back(answer_char);
	}
	answerFile.close();


	//cout << option_vec.size() << endl;
	//cout << ques_vec.size() << endl;
	//cout << answer_vec.size() << endl;

}


// to check if the user inputs the correct answer
bool Question::check_answer(int i, string userInput){
	if(answer_vec[i] == userInput)
		return true;
	else
		return false;
}


void fileInput(string dir, User** allUser);
void fileOutput(string dir, User** allUser);
int findUser(string user, User** allUser);
void createUser(User** allUser); // put all User to global variable? 
void Login(User** allUser);
void welcome(User** allUser);
void internal_welcome(User** allUser, int user_ind);
void player_info(User** allUser, int user_ind);
void intro(User** allUser);
void story(User** allUser);
void ranking(User** allUser);
void sortSuccessUser(User** success_user, int success_num);
void gameState(User** allUser, int user_ind);
void setUserWish(User** allUser, int user_ind);


int main(){	
	string dir = "../user_info.txt";
	User** allUser = new User*[MAX_USER_NUM]; // the pointer array to store all users
	fileInput(dir, allUser);
	
	/*
	// test - if the class function can be correctly used
	for(int i = 0; i < curr_active_user; i++)
		//allUser[i] -> add_time_used(20);
	*/
		 

	/*
	// test - find if a user is in our system
	int index = findUser("testCoco", "NTUIM2021", allUser);
	cout << index;
	
	*/
	
	
	// test - print all current existing users
	for(int i = 0; i < curr_active_user; i++)
		 allUser[i] -> print();
	
	
	// login
	//int index = Login(allUser);
	intro(allUser); //return; 
	
//	if(index != -1)
//		allUser[index] -> print();
	
	// output to a file
	fileOutput(dir, allUser);

	return 0;
}

void fileInput(string dir, User** allUser){
	// string username, string password, int trial_used, int time_used, int life, bool account_status
	curr_active_user = 0; // reset
	ifstream userFile;
	userFile.open(dir);
	if(!userFile)
		cout << "?S?????????";
	else{
		string tmp_username;
		string tmp_password;
		bool tmp_complete_status;
		int tmp_total_ques_answered;
		int tmp_time_used;
		int tmp_life;
		int tmp_current_lv;
		bool tmp_account_status;
		string tmp_wish;
		bool tmp_wish_status;
		bool tmp_banned_status;
		int tmp_banned_time;
		
		while(userFile >> tmp_username >>  tmp_password >> tmp_complete_status >> tmp_total_ques_answered >> tmp_time_used >> 
		tmp_life >> tmp_current_lv >> tmp_account_status >> tmp_wish >> tmp_wish_status >> tmp_banned_status >> tmp_banned_time){
			//curr_active_user += 1;
			allUser[curr_active_user - 1] = new User(tmp_username, tmp_password, tmp_complete_status,
											 tmp_total_ques_answered, tmp_time_used, tmp_life, tmp_current_lv,  
											 tmp_account_status, tmp_wish, tmp_wish_status, tmp_banned_status,
											  tmp_banned_time);
		}
			
	}
	userFile.close();
}
void fileOutput(string dir, User** allUser){
	
	ofstream userFile;
	userFile.open(dir);
	
	if(!userFile)
		cout << "?S?????????";
	else{
		for(int i = 0; i < curr_active_user; i++)
			userFile << allUser[i] -> get_username() << " " << allUser[i] -> get_password() << " " 
			<< allUser[i] -> get_complete_status() << " "<< allUser[i] -> get_total_ques_answered() << " " 
			<< allUser[i] -> get_time_used() << " " <<allUser[i] -> get_life() <<" "
			<< allUser[i]  -> get_current_lv() << " "  << allUser[i] -> get_account_status() << " " << allUser[i] -> get_wish() << " " << 
			allUser[i] -> get_wish_status() <<  " " << allUser[i] -> get_banned_status() << " " << 
			allUser[i] -> get_banned_time() << "\n"; 
			
			//userFile << "\n"; 
	}
	
	userFile.close();
		
}
int findUser(string user, User** allUser){
	// string comparison
	for(int i = 0; i < curr_active_user; i++){
		if(allUser[i] -> username == user)
			return i;
	}
	// cout << "User not found!";
	return -1; // not found any user having the user and password 
		
}

void createUser(User** allUser){ // put all User to global variable? 
	string username_store;
	string password_store;
	cout << "?п?J?b???W???Ы?b??(?^??B??r?β???H???r???W???A????r??????W??) : ";
	cin >> username_store;
	cout << "?п?J?b???K?X??Ы?b??(?^??B??r?β???H???r???W???A????r??????W??) : ";
	cin >> password_store;
	cout << endl;
	
	//cout << username_store.size();
	//cout << password_store.size();
	
	int check_user = findUser(username_store, allUser);
	char continue_status = 0;
	if(check_user == -1){
		if(username_store.size() > MAX_ACC_PASS_LEN || password_store.size() > MAX_ACC_PASS_LEN){
			cout << "?b???W??αK?X????X?W?w(?^??B??r?β???H???r???W???A????r??????W??)" << endl;
			cout << "?z?n?A??@????H (Y/N)";
			cin >> continue_status;
			if(continue_status == 'Y')
				createUser(allUser); // will this line cause problem?
			else
				welcome(allUser);
		}
		else{
			cout << "?w??[?J???A?s???I" << "\n";	
			allUser[curr_active_user - 1] = new User(username_store, password_store);
//			for(int i = 0; i < curr_active_user; i++)
//		 		allUser[i] -> print();
			internal_welcome(allUser, (curr_active_user - 1));
			//gameState(allUser, (curr_active_user - 1));
			
		}
	}
	else{
		//while(true){
		cout << "?o??W?r?w?g?Q???U?L?F" << "\n" << "?Ы? 1 ?Ы?O???b??" <<"\n" <<"?Ы? 2 ?n?J?C??" << "\n";
		int answer = 0;
		cin >> answer;
		if(answer == 1)
			createUser(allUser);
		else
		 	Login(allUser);
	}
	//}
}

void Login(User** allUser){
	string account_store;
	string password_store;
	cout << "?п?J?z???b???W?? : ";
	cin >> account_store;
	//cout << "\n";
	
	cout << "?п?J?z???b???K?X : ";
	cin >> password_store;
	
	int user_ind = -1;
	for(int i = 0; i < curr_active_user; i++){
		if(allUser[i] -> username == account_store && allUser[i] -> password == password_store) 
			user_ind = i;
	} 
	
	if(user_ind != -1){

			cout << "?w??I" << endl;
			//allUser[user_ind] -> banned_status = false;
			internal_welcome(allUser, user_ind);
		// }	
	}
	else{
		// if the function doesn;t return, it means that the user might not registered or typed the wrong account/password
		char continue_status = 0;
		cout << "?b???W??αK?X?????T(?^??B??r?β???H???r???W???A????r??????W??)?C?z?n?A??@????H (Y/N)";
		cin >> continue_status;
		
		if(continue_status == 'Y')
			Login(allUser);
		else
			welcome(allUser);	
	}

}

void internal_welcome(User** allUser, int user_ind){
	cout << "?w??i?J?C???I?????_?I?? : " << allUser[user_ind] -> get_username() << "?I" << endl;
	cout << "?п?? : " << endl;
	cout << "[1] ?}?l?D??   [2] ?n?X  [3] ?d??b????T" << endl;
	int flag;
	cin >> flag;
	if(flag == 1){ //char flag != int 1 !!
		// write all the situation where a person can't play the game here
		if(allUser[user_ind] -> get_banned_status() == true && (time(nullptr) - allUser[user_ind] -> get_banned_time() <= USER_BANNED_TIME) ){
			cout << "?z?{?b????i?J?C???A?]????e?b???w?Q????..." << endl;
			cout << "?^??n?J????" << endl;
			internal_welcome(allUser, user_ind);
		}
		else if(allUser[user_ind] -> get_complete_status() == true){
			cout << "?@??H?u???@???\?@?????|?A???i?H?g??..." << endl;
			cout << "?^??n?J????";
			internal_welcome(allUser, user_ind);
		}
		else{
			allUser[user_ind] -> set_banned_status(false); 
			gameState(allUser, user_ind);
		}
	} 
	else if(flag == 2) 
		welcome(allUser);
	else if(flag == 3)
		player_info(allUser, user_ind);
	else
		internal_welcome(allUser, user_ind);
	
}

void player_info(User** allUser, int user_ind){
	allUser[user_ind] -> print();
	char flag;
	cout << "?^??n?J?????H (Y/N)";
	cin >> flag;
	if(flag == 'Y')
		internal_welcome(allUser, user_ind);
	else
		player_info(allUser, user_ind);
}

void welcome(User** allUser)
{
	cout << "???n?}?l?D??F??H" << "\n" << "?? 1 ?Ы?b??" << "\n" << "?? 2 ?n?J?b??"<< "\n" << "?? 3 ?^??D???" << "\n";
	int status = 0;
	cin >> status;
	if(status == 1)
	{
		createUser(allUser);
	}
	else if(status == 2)
	{
		Login(allUser);
	}
	else if(status == 3)
	{
		//welcome(allUser);
		intro(allUser);
	}
	else
		welcome(allUser);
		
}

void intro(User** allUser) // intro -> welcome
{
	cout << "?x?j?????"  << endl; 
	cout << "?? 1 ??G??" << "\n" << "?? 2 ???@??M??" << "\n" << "?? 3 ?}?l?C??" << "\n"<< "?? 4 ???}" << "\n";
	int status = 0;
	cin >> status;
	if(status == 1) // story
	{
		story(allUser);
	}
	else if(status == 2) // ranking
	{
		ranking(allUser);
	}
	else if(status == 3) //start
	{
		welcome(allUser);
	} 
	else // exit
		return;
}


void story(User** allUser)
{
	cout << "?Y??A?A??M?o?{?A?`???b????A?????L??A???A?u?O?@??V???~?????t???A?{?b?O?????{???????|?????L?~?C???C" << "\n" <<
	"?A?H???b???N???????Ц??????k??A???G?o?o?{?b????]??????????A?C??u??h?W??R?Y?????~...????@?p???`?M??}??A" << "\n" <<
	"??W??R?L?i???~?????W?A???u?S?????B??????o??A?A????F?{?????b????D???????????A???H?L?i?F???O???A???M?S??????A" << "\n" <<
	"???}??????x?????????@????????????A??k???N????x?????A?A?o?{?A???O?a?W????}?????A??A?????x????o??A?@??U?A" << "\n" <<
	"?ΤO?a??F?@?}?A?A?u????I?v?F?@?n?A?o?]???}?????u????I?v?F?@?n?A???Y?Q??L?N?]???A?A?o?{??F?M?}???z???M??`??A" << "\n" << 
	"???O???O??`???v????S???F?A??H????s?}????S???C????A?@?^?Y?A?N?Q?l?i?F???????@??A?o?????????A?u???@?x?C?????A" << "\n" <<
	"?W???g??G?Q?Q?A???j???????g???F????a?I?p?G????}???????????d?A??N??{??{?A?@???@??~~"<< "\n" <<\
	"?W?h:" << "\n" << "1.?C?@?????C?????A?A?N?n??7?D???????????D??C?C????@?D?N?|???W?@?????A??????C?C?????@?D?N?|????h?@?????C"<< "\n" <<
	"2.?C?@?????C????????W?L???D?A?W?L????|?Q???v10?????C"<< "\n" <<"3.??Q????: ???Q??????7???D??C?F??????Y?i?V???O???F???X?@???@??C" <<"\n" ;
	cout << "?^??D???H (Y/N)";
	char answer = 0;
	cin >> answer;
	if(answer == 'Y')
		intro(allUser);
	else
		story(allUser);
}

void ranking(User** allUser)
{
	//cout << "??W???" << "\n";
	cout << "????A??I???O???F?p??|???M????A??{??{?A????@?檺?I" << endl << endl;
	int success_num = 0;
	User** success_user = new User*[MAX_USER_NUM];
	// currently, I define the wish status to be the complete criteria
	for(int i = 0 ; i < curr_active_user; i++){
		if(allUser[i] -> get_complete_status() == true){
			success_user[success_num] = allUser[i]; // storing the pointer
			success_num++;
		}
	}

	// starting to sort the pointer
	if(success_num >= 2)
		sortSuccessUser(success_user, success_num); 

	cout << "\?\\?@??" << "     " << "?@??" << "      " << "??O???"<< "     " << "???D????" << endl;
	if(success_num == 0){
		cout << "????S???H???????...????|???H??\?\\???a?H" << endl;
	}
	else{
		for(int i = 0; i < success_num; i++)
			cout << success_user[i] -> get_username() << "     " << success_user[i] -> get_wish() << "     " << 
					success_user[i] -> get_time_used() << "     " << success_user[i] -> get_total_ques_answered() << endl;
		
		cout << "????A??I???O???F?p??|???M????A??{??{?A????@?檺?I";
	}
	cout << "?^??D???H (Y/N)";
	char answer = 0;
	cin >> answer;
	if(answer == 'Y')
		intro(allUser);
	else
		ranking(allUser);
}

void sortSuccessUser(User** success_user, int success_num){
	
	User* tmp;
	// implement bubble sort
	for(int i = success_num - 1; i > 0; i--){
    	for(int j = 0; j <= i-1; j++){
        	if( success_user[j]  -> get_total_ques_answered() > success_user[j+1] -> get_total_ques_answered()){
			// swap pointer
           		tmp = success_user[j];
            	success_user[j] = success_user[j+1];
            	success_user[j+1] = tmp;
        }
    }
}

}


void gameState(User** allUser, int user_ind)
{
	Question ques_obj;
	for(int i = 0 ; i < LEVEL ; i++)
	{	
		
		string player_answer = "E";
		srand( time(NULL) );
		
		int pick_question = rand() % 24;
		if(allUser[user_ind] -> get_current_lv() == 1)
		{	
			pick_question += 0; 
		}
		if(allUser[user_ind] -> get_current_lv() == 2)
		{
			pick_question += 24;
		}
		if(allUser[user_ind] -> get_current_lv() == 3)
		{
			pick_question += 48;
		}
		if(allUser[user_ind] -> get_current_lv() == 4)
		{
			pick_question += 72;
		}
		if(allUser[user_ind] -> get_current_lv() == 5)
		{
			pick_question += 96;
		}
		if(allUser[user_ind] -> get_current_lv() == 6)
		{
			pick_question += 120;
		} 
		if(allUser[user_ind] -> get_current_lv() == 7)
		{
			pick_question += 144;
		}
		
		cout << ques_obj.get_ques(pick_question) << endl;
		cout << "A. " << ques_obj.get_option(pick_question, 0) << endl; 
		cout << "B. " << ques_obj.get_option(pick_question, 1) << endl; 
		cout << "C. " << ques_obj.get_option(pick_question, 2) << endl; 
		cout << "D. " << ques_obj.get_option(pick_question, 3) << endl;
		cout << "???a???? : ";
		
		time_t question_start_time;
		time(&question_start_time);

		/*while(difftime(time(NULL), question_start_time) != RESPONSE_TIME)
		{	 
			//cout << difftime(time(NULL), question_start_time) << endl;
		
			if(kbhit())
			{	
				allUser[user_ind] -> add_time_used(difftime(time(NULL), question_start_time));
				int temp_answer = getch();
				if(temp_answer > 96)
				{
					temp_answer -= 32; 
				}
				player_answer = temp_answer;
				
				break;
			}	
		}*/
		
		cout << "?z??????G" << player_answer << endl;

		// add time used
		if(player_answer == "E")
		{
			allUser[user_ind] -> add_time_used(10);
		} 
		
		// check answer
		if(ques_obj.check_answer(pick_question, player_answer))
		{
			cout << "???????F!" << endl;
			allUser[user_ind] -> increment_lv();
		}
		else
		{
			cout << "??!?????F..." << endl; 
			allUser[user_ind] -> deduct_life();
			cout << "??R?? : " << allUser[user_ind] -> get_life() << endl;
			allUser[user_ind] -> decrement_lv();
			
		}
		
		allUser[user_ind] -> add_total_ques_answered();
		cout << endl;
		cout << endl;
		
		if((allUser[user_ind] -> get_current_lv() == 8) || (allUser[user_ind] -> get_life() == 0))
		{
			break;
		}
	}
	
	if(allUser[user_ind] -> get_current_lv() == 8)
	{
		allUser[user_ind] -> refill_life();	
		setUserWish(allUser, user_ind);
		internal_welcome(allUser, user_ind);

	}
	else if(allUser[user_ind] -> get_life() == 0)
	{
		int banned_time = time(nullptr);
		cout << "??R??w?g?Χ??A?е???10?????A?A???s?n?J?A?Y?i?~??C??..." << endl;	
		// operations to ban the users
		allUser[user_ind] ->set_banned_status(true);
		allUser[user_ind] -> set_banned_time(banned_time);
		allUser[user_ind] -> refill_life();	
		internal_welcome(allUser, user_ind);	
	}
	else{
		allUser[user_ind] -> refill_life();	
		internal_welcome(allUser, user_ind);
	}
	
}

void setUserWish(User** allUser, int user_ind){
	string wish;
	bool public_secret;
		
		cout << "\??\??A?????F????????d?A??o?F?@???V???O???F?p??\?@?????|" << endl;
		cout << "?@??i?H?????}?A??O???????F?p??o???A?Цb?????}???p???J?@???"<< endl;
		cout << "???e?X?A?@??N?b??????D???p?A?e?{??W?A?Y???F?p????@???{????"<< endl;
		 
		cout << "???} 0 / ???K 1 : ";
		cin >> public_secret;
		if(public_secret == 1)
		{
			cout << "?@??O?K" << endl;
		}
		else
		{
			cout << "???}?@??" << endl;
		} 


		allUser[user_ind] -> set_wish_status(public_secret);
		cout << "?A???@?? : "; 
		cin >> wish;
		cout << endl;
		allUser[user_ind] -> set_wish(wish);
		allUser[user_ind] -> set_complete_status(true);
}


