#include <iostream>
#include <stdlib.h> // to use system("CLS");
#include <string> // to use everything related to string variable type; stoi function;
#include <fstream> // to use file;
#include <cstdlib>
#include <stdio.h>// for using scanf
#include <string.h>//for using getline
#include <vector> // I want to use vector to store data read collected from files;
#include <iomanip>// I want to use setw function;

using namespace std;

class admin_class { //class number 1;
public:
	bool login_logout_admin();
	void add_professor();
	bool find_profess(string id);
	void delete_professor();

	void add_student();
	bool find_student(string id);
	void delete_student();
	void change_pass();

	void find_all_users();
	~admin_class() {};
private:
	string password_of_admin;
};

class professor_class { //class number 2;
public:
	void open_5_course(string id);
	void change_pass(string id);
	string login_logout_profess();
	void modify_student_score(string id);
	void summarize_student_score(string id);

	~professor_class() {};

	string id_of_professor;
	string password_of_professor;
	string name, birthday, phone, address;
};

struct professor_file_user {
	string id;
	string pass;
};

professor_file_user make_object_profess_file_user(string id, string pass) {
	professor_file_user my_object = { id, pass };
	return my_object;
}

struct professor_file_profile {
	string id, name, birthday, phone, address;
};

professor_file_profile make_object_profess_file_profile(string id, string name, string birthday, string phone, string address) {
	professor_file_profile my_object = { id, name, birthday, phone, address };
	return my_object;
}

struct course_semester {
	string code_subject, id_teacher, name_subject;
	int credit, max_students, current_students;
};

course_semester make_object_course_semester_file(string code_subject, string id_teacher, string name_subject, int credit, int maxstu, int curstu) {
	course_semester my_object = { code_subject, id_teacher, name_subject, credit, maxstu, curstu };
	return my_object;
}

class student_class { //class number 3;
public:
	
	void change_pass(string id);
	string login_logout_student();
	void register_course(string id);
	void  remove_course(string id);
	void view_gpa(string id);
	void view_registered_courses(string id);
	void view_courses_in_semester();

	void student_find_courses();

	~student_class() {};

	string id_of_student;
	string password_of_student;
	string id, name, birthday, address;
};

struct student_file_profile {
	string id, name, birthday, address;
};

student_file_profile make_object_stu_file_profile(string id, string name, string birthday, string address) {
	student_file_profile my_object = { id, name, birthday, address };
	return my_object;
}

struct grade_semester_file {
	string subject_code, stu_id, teacher_id;
	int score_final, sub_credit;
};

grade_semester_file make_object_grade_semester_file(string subject_code, string stu_id, string teacher_id, int score, int sub_credit) {
	grade_semester_file my_object = { subject_code, stu_id, teacher_id, score, sub_credit };
	return my_object;
}

void first_screen();//function number 1;

int main()
{
	first_screen();
	int n1 = 0;
	cin >> n1;
	cout << '\n';
	switch (n1) {
	case 1: {
		admin_class object01_admin_class;
		bool flag_case1 = object01_admin_class.login_logout_admin();
		if (flag_case1 == false) {
			break;
		}
		bool flag_case1_logout = false;
		while (flag_case1_logout == false) {
			cout << "\nAdministrator abilities: \n";
			cout << "1. Change Administrator's password\n"
				 << "2. Add professor\n"
				 << "3. Delete professor\n"
				 << "4. Add student\n"
				 << "5. Delete student\n"
				 << "6. Find User\n"
				 << "7. Logout\n\n";
			cout << "Administrator, choose what to do (from number 1 to number 7): ";
			int to_do_1 = 0;
			cin >> to_do_1;
			cout << '\n';
			switch (to_do_1) {
			case 1: {
				object01_admin_class.change_pass();
				break;
			}

			case 2: {
				object01_admin_class.add_professor();
				break;
			}

			case 3: {
				object01_admin_class.delete_professor();
				break;
			}

			case 4: {
				object01_admin_class.add_student();
				break;
			}

			case 5: {
				object01_admin_class.delete_student();
				break;
			}

			case 6: {
				object01_admin_class.find_all_users();
				break;
			}

			case 7: {
				flag_case1_logout = true;
				break;
			}

			default: {
				cout << "Invalid input!!!\n";
				break;
			}

			}
		}
		break;
	}

	case 2: {
		professor_class object01_pro_class;
		string flag_case2 = object01_pro_class.login_logout_profess();
		if (flag_case2.compare("negative") == 0) {
			break;
		}
		bool flag_case2_logout = false;
		while (flag_case2_logout == false) {
			cout << "\nProfessor abilities: \n";
			cout << "1. Change Professor's password\n"
				<< "2. Open course\n"
				<< "3. Modify student's scores\n"
				<< "4. Summarize students' scores in a course\n"
				<< "5. Logout\n\n";
			cout << "Professor, choose what to do (from number 1 to number 5): ";
			int to_do_2 = 0;
			cin >> to_do_2;
			cout << "\n";
			switch (to_do_2) {
			case 1: {
				object01_pro_class.change_pass(flag_case2);
				break;
			}

			case 2: {
				object01_pro_class.open_5_course(flag_case2);
				break;
			}

			case 3: {
				object01_pro_class.modify_student_score(flag_case2);
				break;
			}

			case 4: {
				object01_pro_class.summarize_student_score(flag_case2);
				break;
			}

			case 5: {
				flag_case2_logout = true;
				break;
			}

			default: {
				cout << "Invalid input!!!\n";
				break;
			}

			}
		}
		break;
	}

	case 3: {
		student_class object01_stu_class;
		string flag_case3 = object01_stu_class.login_logout_student();
		if (flag_case3.compare("negative") == 0) {
			break;
		}
		bool flag_case3_logout = false;
		while (flag_case3_logout == false) {
			cout << "\nStudent abilities: \n";
			cout << "1. Change Student's password\n"
				<< "2. Register Course\n"
				<< "3. Remove Course\n"
				<< "4. View GPA\n"
				<< "5. View Registered Courses\n"
				<< "6. View Courses in the Semester\n"
				<< "7. Find Course\n"
				<< "8. Logout\n\n";
			cout << "Student, choose what to do (from number 1 to number 8): ";
			int to_do_3 = 0;
			cin >> to_do_3;
			cout << "\n";
			switch (to_do_3) {
			case 1: {
				object01_stu_class.change_pass(flag_case3);
				break;
			}

			case 2: {
				object01_stu_class.register_course(flag_case3);
				break;
			}

			case 3: {
				object01_stu_class.remove_course(flag_case3);
				break;
			}

			case 4: {
				object01_stu_class.view_gpa(flag_case3);
				break;
			}

			case 5: {
				object01_stu_class.view_registered_courses(flag_case3);
				break;
			}

			case 6: {
				object01_stu_class.view_courses_in_semester();
				break;
			}

			case 7: {
				object01_stu_class.student_find_courses();
				break;
			}

			case 8: {
				flag_case3_logout = true;
				break;
			}

			default: {
				cout << "Invalid input!!!\n";
				break;
			}

			}
		}
		break;
	}

	case 4: {
		break;
	}

	default: {
		cout << "Invalid input!!!";
		break;
	}

	}
	cout << '\n';
	cout << "Please press any key to close the window :)";
	char cChar;
	cin.ignore();
	cin.get(cChar);
	return 0;
}

void first_screen() { // function number 1
	cout << "Name: Nguyen Huu Trung Nhan \t Student ID: 1752392 \t Assignment \n\n";
	cout << "There are 3 types of users: \n";
	cout << "Administrator -> 1 \t Professor -> 2 \t Student -> 3 \n\n";
	cout << "Enter your type of users (from 1 to 3 to login || number 4 to exit): ";
}

bool admin_class::login_logout_admin() {
	//Note: There will be only one administrator in my program;
	ifstream object_admin_password("admin_password.csv", ios::in);
	if (!object_admin_password) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string name_admin, pass;
	
	while (!object_admin_password.eof()) {
		getline(object_admin_password, name_admin, ',');
		getline(object_admin_password, pass, '\n');
	}
	object_admin_password.close();

	bool flag = false;
	string admin_pass;
	while (flag == false) {
		cout << "Administrator: \t(Enter the password to login || Enter exactly the word 'logout' to logout)\n";
		cout << "Password: ";
		cin >> admin_pass;
		if (admin_pass.compare("logout") == 0) {
			cout << "\n";
			return flag;		
		}
		if (admin_pass.compare(pass) == 0) {
			flag = true;
			password_of_admin.assign(pass);
			cout << "\nAccess Granted\n";
		}
		else {
			cout << "Wrong password !!! Please try again\n\n\n";
		}
	}
	return flag;
}

void admin_class::change_pass() {
	string new_pass_2;
	cout << "Please input new password: ";
	cin >> new_pass_2;
	ofstream object_admin_password("admin_password.csv", ios::out);
	if (!object_admin_password) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	object_admin_password << "admin" << "," << new_pass_2;
	this->password_of_admin.assign(new_pass_2);
	cout << "=> Change password Success !!\n";
	object_admin_password.close();
}

void admin_class::add_professor() {
	professor_class object01_profess_class;
	cout << "Adding a new professor:\n";
	cout << "ID: ";
	cin >> object01_profess_class.id_of_professor;

	if (find_profess(object01_profess_class.id_of_professor) == true) {
		cout << "This Professor has been in the system already.\n";
		return;
	}
	cout << "Password: ";
	cin >> object01_profess_class.password_of_professor;
	cout << "Name: ";
	cin.ignore();
	getline(cin, object01_profess_class.name);
	cout << "Date of Birth (day-month-year): ";
	cin >> object01_profess_class.birthday;
	cout << "Phone number: ";
	cin >> object01_profess_class.phone;
	cout << "Address: ";
	cin.ignore();
	getline(cin, object01_profess_class.address);
	ofstream object_profess_users("profess_users.csv", ios::app);
	if (!object_profess_users) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	object_profess_users << object01_profess_class.id_of_professor << "," << object01_profess_class.password_of_professor << endl;
	object_profess_users.close();

	ofstream object_profess_profiles("profess_profiles.csv", ios::app);
	if (!object_profess_profiles) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	object_profess_profiles << object01_profess_class.id_of_professor << ","
							<< object01_profess_class.name << ","
							<< object01_profess_class.birthday << ","
							<< object01_profess_class.phone << ","
							<< "\""<< object01_profess_class.address << "\"" << endl;
	object_profess_profiles.close();
	cout << "\n=> Add Success !!\n";
}

bool admin_class::find_profess(string id) {
	bool is_exist = false;
	vector <professor_file_user> list_id_1;
	ifstream object01_profess_users("profess_users.csv", ios::in);
	if (!object01_profess_users) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string username, pass;
	while (!object01_profess_users.eof()) {
		getline(object01_profess_users, username, ',');
		if (object01_profess_users.eof()) {
			break;
		}
		getline(object01_profess_users, pass, '\n');
		list_id_1.push_back(make_object_profess_file_user(username, pass));
	}
	for (int i = 0; i < list_id_1.size(); i++) {
		if ( id.compare( list_id_1[i].id ) == 0 ) {
			is_exist = true;
			break;
		}
	}	
	object01_profess_users.close();
	return is_exist;
}

void admin_class::delete_professor() {
	cout << "Please input the ID of the professor who you want to delete: ";
	string profess_id, pass, id_deleted;
	cin >> id_deleted;
	//doing with the profess_user.csv;
	vector<professor_file_user> list_id_1;
	fstream object_read_01("profess_users.csv", ios::in);
	if (!object_read_01) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	while (!object_read_01.eof()) {
		getline(object_read_01, profess_id, ',');
		if (object_read_01.eof()) {
			break;
		}
		getline(object_read_01, pass, '\n');
		list_id_1.push_back(make_object_profess_file_user(profess_id, pass));
	}
	object_read_01.close();
	bool is_existed = false;
	int count_index = 0;
	for (count_index = 0; count_index < list_id_1.size(); count_index++) {
		if (id_deleted.compare(list_id_1[count_index].id) == 0) {
			is_existed = true;
			break;
		}
	}
	if (is_existed == false) {
		cout << "This professor doesn't exist.\n";
		return;
	}

	list_id_1.erase(list_id_1.begin() + count_index);

	object_read_01.open("profess_users.csv", ios::out);
	if (!object_read_01) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_id_1.size(); i++) {
		object_read_01 << list_id_1[i].id << "," << list_id_1[i].pass << endl;
	}
	object_read_01.close();
	//doing with the professs_profiles.csv;
	vector<professor_file_profile> list_profile_2;
	fstream object_read_02("profess_profiles.csv", ios::in);
	if (!object_read_02) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string profile_id, profile_name, profile_birth, profile_phone, profile_address;
	while (!object_read_02.eof()) {
		getline(object_read_02, profile_id, ',');
		if (object_read_02.eof()) {
			break;
		}
		getline(object_read_02, profile_name, ',');
		getline(object_read_02, profile_birth, ',');
		getline(object_read_02, profile_phone, ',');
		getline(object_read_02, profile_address, '\n');
		list_profile_2.push_back(make_object_profess_file_profile(profile_id, profile_name, profile_birth, profile_phone, profile_address));
	}
	object_read_02.close();
	
	int count_index02 = 0;
	for (count_index02 = 0; count_index02 < list_profile_2.size(); count_index02++) {
		if (id_deleted.compare(list_profile_2[count_index02].id) == 0) {
			break;
		}
	}
	list_profile_2.erase(list_profile_2.begin() + count_index02);
	
	object_read_02.open("profess_profiles.csv", ios::out);
	if (!object_read_02) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_profile_2.size(); i++) {
		object_read_02 << list_profile_2[i].id << ","
			<< list_profile_2[i].name << ","
			<< list_profile_2[i].birthday << ","
			<< list_profile_2[i].phone << ","
			<< list_profile_2[i].address << endl;
	}
	object_read_02.close();
	cout << "\n=> Delete Success !!\n";
}

void admin_class::add_student() {
	student_class object01_student_class;
	cout << "Adding new student:\n";
	cout << "ID: ";
	cin >> object01_student_class.id_of_student;

	if (find_student(object01_student_class.id_of_student) == true) {
		cout << "This Student has been in the system already.\n";
		return;
	}

	cout << "Password: ";
	cin >> object01_student_class.password_of_student;
	cout << "Name: ";
	cin.ignore();
	getline(cin, object01_student_class.name);
	cout << "Date of Birth (day-month-year): ";
	cin >> object01_student_class.birthday;
	cout << "Address: ";
	cin.ignore();
	getline(cin, object01_student_class.address);
	ofstream object_student_users("student_users.csv", ios::app);
	if (!object_student_users) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	object_student_users << object01_student_class.id_of_student << "," << object01_student_class.password_of_student << endl;
	object_student_users.close();

	ofstream object_student_profiles("student_profiles.csv", ios::app);
	if (!object_student_profiles) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	object_student_profiles << object01_student_class.id_of_student << ","
		<< object01_student_class.name << ","
		<< object01_student_class.birthday << ","
		<< "\"" << object01_student_class.address << "\"" << endl;
	object_student_profiles.close();
	cout << "\n=> Add Success !!\n";
}

bool admin_class::find_student(string id) {
	bool is_exist = false;
	vector <professor_file_user> list_id_1;
	ifstream object01_student_users("student_users.csv", ios::in);
	if (!object01_student_users) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string username, pass;
	while (!object01_student_users.eof()) {
		getline(object01_student_users, username, ',');
		if (object01_student_users.eof()) {
			break;
		}
		getline(object01_student_users, pass, '\n');
		list_id_1.push_back(make_object_profess_file_user(username, pass));
	}
	for (int i = 0; i < list_id_1.size(); i++) {
		if (id.compare(list_id_1[i].id) == 0) {
			is_exist = true;
			break;
		}
	}
	object01_student_users.close();
	return is_exist;
}

void admin_class::delete_student() {
	cout << "Please input the ID of the student who you want to delete: ";
	string student_id, pass, id_deleted;
	cin >> id_deleted;
	//doing with the student_users.csv;
	vector<professor_file_user> list_id_1;
	fstream object_read_01("student_users.csv", ios::in);
	if (!object_read_01) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	while (!object_read_01.eof()) {
		getline(object_read_01, student_id, ',');
		if (object_read_01.eof()) {
			break;
		}
		getline(object_read_01, pass, '\n');
		list_id_1.push_back(make_object_profess_file_user(student_id, pass));
	}
	object_read_01.close();
	bool is_existed = false;
	int count_index = 0;
	for (count_index = 0; count_index < list_id_1.size(); count_index++) {
		if (id_deleted.compare(list_id_1[count_index].id) == 0) {
			is_existed = true;
			break;
		}
	}
	if (is_existed == false) {
		cout << "This student doesn't exist.\n";
		return;
	}

	list_id_1.erase(list_id_1.begin() + count_index);

	object_read_01.open("student_users.csv", ios::out);
	if (!object_read_01) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_id_1.size(); i++) {
		object_read_01 << list_id_1[i].id << "," << list_id_1[i].pass << endl;
	}
	object_read_01.close();
	//doing with the student_profiles.csv;
	vector<student_file_profile> list_profile_2;
	fstream object_read_02("student_profiles.csv", ios::in);
	if (!object_read_02) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string profile_id, profile_name, profile_birth, profile_address;
	while (!object_read_02.eof()) {
		getline(object_read_02, profile_id, ',');
		if (object_read_02.eof()) {
			break;
		}
		getline(object_read_02, profile_name, ',');
		getline(object_read_02, profile_birth, ',');
		getline(object_read_02, profile_address, '\n');
		list_profile_2.push_back(make_object_stu_file_profile(profile_id, profile_name, profile_birth, profile_address));
	}
	object_read_02.close();

	int count_index02 = 0;
	for (count_index02 = 0; count_index02 < list_profile_2.size(); count_index02++) {
		if (id_deleted.compare(list_profile_2[count_index02].id) == 0) {
			break;
		}
	}
	list_profile_2.erase(list_profile_2.begin() + count_index02);

	object_read_02.open("student_profiles.csv", ios::out);
	if (!object_read_02) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_profile_2.size(); i++) {
		object_read_02 << list_profile_2[i].id << ","
			<< list_profile_2[i].name << ","
			<< list_profile_2[i].birthday << ","
			<< list_profile_2[i].address << endl;
	}
	object_read_02.close();
	//
	//doing with the grade_semester_193.csv file
	vector <grade_semester_file> object_extra_01;
	ifstream object_read_file_01("grade_semester_193.csv", ios::in);
	if (!object_read_file_01) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string sub_code, student_id_extra_01, profess_id, score01, credit01;
	int score02, credit02;

	while (!object_read_file_01.eof()) {
		getline(object_read_file_01, sub_code, ',');
		if (object_read_file_01.eof()) {
			break;
		}
		getline(object_read_file_01, student_id_extra_01, ',');
		getline(object_read_file_01, profess_id, ',');
		getline(object_read_file_01, score01, ',');
		score02 = stoi(score01);
		getline(object_read_file_01, credit01, '\n');
		credit02 = stoi(credit01);

		object_extra_01.push_back(make_object_grade_semester_file(sub_code, student_id_extra_01, profess_id, score02, credit02));
	}
	object_read_file_01.close();

	vector<grade_semester_file> object_extra_01_store_delete;
	int count_index_i_01 = 0;
	for (count_index_i_01 = 0; count_index_i_01 < object_extra_01.size(); count_index_i_01++) {
		if (id_deleted.compare(object_extra_01[count_index_i_01].stu_id) == 0) {
			object_extra_01_store_delete.push_back(object_extra_01[count_index_i_01]);
			object_extra_01.erase(object_extra_01.begin() + count_index_i_01);
			count_index_i_01 = -1;
		}
	}

	ofstream object_write_file_01("grade_semester_193.csv", ios::out);
	if (!object_write_file_01) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < object_extra_01.size(); i++) {
		object_write_file_01 << object_extra_01[i].subject_code << "," << object_extra_01[i].stu_id << "," << object_extra_01[i].teacher_id << "," << object_extra_01[i].score_final << "," << object_extra_01[i].sub_credit << endl;
	}
	object_write_file_01.close();
	//
	//doing with the course_semester_193.csv file
	string course_semester_code_sub, course_semester_teacher_id, course_semester_name_sub, course_semester_credit_sub_1, course_semester_max_stu_1, course_semester_cur_stu_1;
	int course_semester_credit_sub_2, course_semester_max_stu_2, course_semester_cur_stu_2;
	vector <course_semester> object_course_semester_01;
	ifstream object_read_file_02("course_semester_193.csv", ios::in);
	if (!object_read_file_02) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	while (!object_read_file_02.eof()) {
		getline(object_read_file_02, course_semester_code_sub, ',');
		if (object_read_file_02.eof()) {
			break;
		}
		getline(object_read_file_02, course_semester_teacher_id, ',');
		getline(object_read_file_02, course_semester_name_sub, ',');
		
		getline(object_read_file_02, course_semester_credit_sub_1, ',');
		course_semester_credit_sub_2 = stoi(course_semester_credit_sub_1);

		getline(object_read_file_02, course_semester_max_stu_1, ',');
		course_semester_max_stu_2 = stoi(course_semester_max_stu_1);

		getline(object_read_file_02, course_semester_cur_stu_1, '\n');
		course_semester_cur_stu_2 = stoi(course_semester_cur_stu_1);

		object_course_semester_01.push_back(make_object_course_semester_file(course_semester_code_sub, course_semester_teacher_id, course_semester_name_sub, course_semester_credit_sub_2, course_semester_max_stu_2, course_semester_cur_stu_2));
	}
	object_read_file_02.close();

	for (int i = 0; i < object_course_semester_01.size(); i++) {
		for (int j = 0; j < object_extra_01_store_delete.size(); j++) {
			if ((object_course_semester_01[i].code_subject.compare(object_extra_01_store_delete[j].subject_code) == 0) && (object_course_semester_01[i].id_teacher.compare(object_extra_01_store_delete[j].teacher_id) == 0)) {
				object_course_semester_01[i].current_students--;
			}
		}
	}

	ofstream object_write_file_02("course_semester_193.csv", ios::out);
	if (!object_write_file_02) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < object_course_semester_01.size(); i++) {
		object_write_file_02 << object_course_semester_01[i].code_subject << ","
			<< object_course_semester_01[i].id_teacher << ","
			<< object_course_semester_01[i].name_subject << ","
			<< object_course_semester_01[i].credit << ","
			<< object_course_semester_01[i].max_students << ","
			<< object_course_semester_01[i].current_students << endl;
	}
	object_write_file_02.close();
	//
	cout << "\n=> Delete Success !!\n";
}

void admin_class::find_all_users() {
	//load all file student_profiles.csv
	vector<student_file_profile> table_student01;

	ifstream read_file_student01("student_profiles.csv", ios::in);
	if (!read_file_student01) {
		cerr << "File could not be opened\n";
		exit(1);
	}

	string stu_id_01, stu_name_01, stu_birthday_01, stu_address_01;
	while (!read_file_student01.eof()) {
		getline(read_file_student01, stu_id_01, ',');
		if (read_file_student01.eof()) {
			break;
		}
		getline(read_file_student01, stu_name_01, ',');
		getline(read_file_student01, stu_birthday_01, ',');
		getline(read_file_student01, stu_address_01, '\n');
		table_student01.push_back(make_object_stu_file_profile(stu_id_01, stu_name_01, stu_birthday_01, stu_address_01));
	}

	read_file_student01.close();
	//
	//load all file profess_profiles.csv
	vector<professor_file_profile> table_teacher01;

	ifstream read_file_teacher01("profess_profiles.csv", ios::in);
	if (!read_file_teacher01) {
		cerr << "File could not be opened\n";
		exit(1);
	}

	string profess_id_01, profess_name_01, profess_birthday_01, profess_phone_01, profess_address_01;
	while (!read_file_teacher01.eof()) {
		getline(read_file_teacher01, profess_id_01, ',');
		if (read_file_teacher01.eof()) {
			break;
		}
		getline(read_file_teacher01, profess_name_01, ',');
		getline(read_file_teacher01, profess_birthday_01, ',');
		getline(read_file_teacher01, profess_phone_01, ',');
		getline(read_file_teacher01, profess_address_01, '\n');
		table_teacher01.push_back(make_object_profess_file_profile(profess_id_01, profess_name_01, profess_birthday_01, profess_phone_01, profess_address_01));
	}

	read_file_teacher01.close();
	//

	cout << "Please input ID of Professor (or Student): ";
	string in_id;
	cin >> in_id;
	cout << '\n';

	bool is_student_exist = false;
	for (int i = 0; i < table_student01.size(); i++) {
		if (in_id.compare(table_student01[i].id) == 0) {
			is_student_exist = true;
			cout << "Student " << in_id << ":" << '\n';
			cout << setw(9) << "ID" << setw(27) << "Name" << setw(18) << "Birthday" << setw(36) << "Address" << '\n';
			cout << setw(9) << table_student01[i].id << setw(27) << table_student01[i].name << setw(18) << table_student01[i].birthday << setw(36) << table_student01[i].address.substr(1, table_student01[i].address.size() - 2) << '\n';
			break;
		}
	}

	bool is_teacher_exist = false;
	if (is_student_exist == false) {
		for (int i = 0; i < table_teacher01.size(); i++) {
			if (in_id.compare(table_teacher01[i].id) == 0) {
				is_teacher_exist = true;
				cout << "Professor " << in_id << ":" << '\n';
				cout << setw(9) << "ID" << setw(27) << "Name" << setw(18) << "Birthday" << setw(18) << "Phone Number" << setw(36) << "Address" << '\n';
				cout << setw(9) << table_teacher01[i].id << setw(27) << table_teacher01[i].name << setw(18) << table_teacher01[i].birthday << setw(18) << table_teacher01[i].phone << setw(36) << table_teacher01[i].address.substr(1, table_teacher01[i].address.size() - 2) << '\n';
				break;
			}
		}
	}

	if ((is_student_exist == false) && (is_teacher_exist == false)) {
		cout << "This ID doesn't exist\n";
	}

	cout << '\n';
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Part 2: Dealing with 2.3) Professor;
string professor_class::login_logout_profess() {
	vector <professor_file_user> list_id;
	ifstream object_profess_user("profess_users.csv", ios::in);
	if (!object_profess_user) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string username, pass;
	while (!object_profess_user.eof()) {
		getline(object_profess_user, username, ',');
		if (object_profess_user.eof()) {
			break;
		}
		getline(object_profess_user, pass, '\n');
		list_id.push_back(make_object_profess_file_user(username, pass));
	}
	object_profess_user.close();
	bool flag = false;
	bool is_exist = false;
	string user_profess_id, user_profess_pass;
	while (flag == false) {
		is_exist = false;
		cout << "Professor: \t(Enter ID and Password to login || Enter exactly the word 'logout' (in the ID part or in the Password part) to logout)\n";
		cout << "ID: ";
		cin >> user_profess_id;

		//checking ID;
		if (user_profess_id.compare("logout") == 0) {
			cout << "\n";
			return "negative";
		}
		for (int i = 0; i < list_id.size(); i++) {
			if (user_profess_id.compare(list_id[i].id) == 0) {
				is_exist = true;
				cout << "Password: ";
				cin >> user_profess_pass;

				if (user_profess_pass.compare("logout") == 0) {
					cout << "\n";
					return "negative";
				}

				if (list_id[i].pass.compare(user_profess_pass) == 0) {
					cout << "\nAccess Granted\n";
					flag = true;
					break;
				}
				else {
					cout << "Wrong password !!! Please try again\n\n\n";
					break;
				}
			}
		}
		if (is_exist == false) {
			cout << "Wrong ID !!! Please try again\n\n\n";
		}
	}
	return user_profess_id;
}

void professor_class::change_pass(string id) {
	string new_pass;
	cout << "Please input new password: ";
	cin >> new_pass;

	vector <professor_file_user> list_id;
	ifstream object_user("profess_users.csv", ios::in);//load the whole table to the vector
	if (!object_user) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string username, pass;
	while (!object_user.eof()) {
		getline(object_user, username, ',');
		if (object_user.eof()) {
			break;
		}
		getline(object_user, pass, '\n');
		list_id.push_back(make_object_profess_file_user(username, pass));
	}
	object_user.close();

	for (int i = 0; i < list_id.size(); i++) { //change pass;
		if (id.compare(list_id[i].id) == 0) {
			list_id[i].pass.assign(new_pass);
			break;
		}
	}

	ofstream object_user2("profess_users.csv", ios::out);//write back everything to the file
	if (!object_user2) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_id.size(); i++) {
		object_user2 << list_id[i].id << "," << list_id[i].pass << endl;
	}
	object_user2.close();
	cout << "=> Change password Success !!\n";
}

void professor_class::open_5_course(string id) {
	int count_this_profess = 0;
	vector <course_semester> list_course;
	ifstream object2("course_semester_193.csv", ios::in);
	if (!object2) {
		cerr << "File could not be open\n";
		exit(1);
	}
	string code_sub, id_profess, name_sub, credit2, maxstu2, curstu2;
	int credit_read, maxstu, curstu;
	while (!object2.eof()) {
		getline(object2, code_sub, ',');
		if (object2.eof()) {
			break;
		}
		getline(object2, id_profess, ',');
		getline(object2, name_sub, ',');

		getline(object2, credit2, ',');
		credit_read = stoi(credit2);

		getline(object2, maxstu2, ',');
		maxstu = stoi(maxstu2);

		getline(object2, curstu2, '\n');
		curstu = stoi(curstu2);
		
		list_course.push_back(make_object_course_semester_file(code_sub, id_profess, name_sub, credit_read, maxstu, curstu));

		if (id.compare(id_profess) == 0) {
			count_this_profess++;
		}
	}
	object2.close();
	if (count_this_profess == 5) {
		cout << "Dear Professor " << id << ", you have already opened 5 courses in this semester. Therefore you can't not open any new course in this semester.\n";
		return;
	}

	cout << "Subject Code: ";
	string subjectcode, subjectname;
	int credit, max_student;
	cin >> subjectcode;

	for (int i = 0; i < list_course.size(); i++) {
		if ( (subjectcode.compare(list_course[i].code_subject) == 0) && (id.compare(list_course[i].id_teacher) == 0) ) {
			cout << "You have opened this course already!!!\n";
			return;
		}
	}

	cout << "Subject Name: ";
	cin.ignore();
	getline(cin, subjectname);
	cout << "Number of Credits: ";
	cin >> credit;
	cout << "Maximum number of students in this Course: ";
	cin >> max_student;
	int number_of_student_already = 0;

	ofstream object01("course_semester_193.csv", ios::app);
	if (!object01) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	object01 << subjectcode << "," << id << "," << subjectname << "," << credit << "," << max_student << "," << number_of_student_already << endl;
	object01.close();

	cout << "\n=> Open Course Success!!\n";
}

void professor_class::modify_student_score (string id) {
	//load all the grade_semester_193.csv file
	vector <grade_semester_file> list_01;
	ifstream object_read_001("grade_semester_193.csv", ios::in);
	if (!object_read_001) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string list_01_sub_code, list_01_stu_id, list_01_teacher_id, list_01_score, list_01_credit;
	int list_01_score_2, list_01_credit_2;
	while (!object_read_001.eof()) {
		getline(object_read_001, list_01_sub_code, ',');
		if (object_read_001.eof()) {
			break;
		}
		getline(object_read_001, list_01_stu_id, ',');
		getline(object_read_001, list_01_teacher_id, ',');

		getline(object_read_001, list_01_score, ',');
		list_01_score_2 = stoi(list_01_score);

		getline(object_read_001, list_01_credit, '\n');
		list_01_credit_2 = stoi(list_01_credit);

		list_01.push_back(make_object_grade_semester_file(list_01_sub_code, list_01_stu_id, list_01_teacher_id, list_01_score_2, list_01_credit_2));
	}
	object_read_001.close();
	cout << "Professor, Please input the subject code: ";
	string input_sub_code_01;
	cin >> input_sub_code_01;

	bool is_subject_exist_01 = false;
	for (int i = 0; i < list_01.size(); i++) {
		if ((id.compare(list_01[i].teacher_id) == 0) && (input_sub_code_01.compare(list_01[i].subject_code) == 0)) {
			is_subject_exist_01 = true;
			break;
		}
	}
	if (is_subject_exist_01 == false) {
		cout << "You don't teach this Subject this semester.\n";
		return;
	}
	cout << "Professor, Please input the Student ID: ";
	string input_stu_id_01;
	cin >> input_stu_id_01;
	bool is_student_exist_01 = false;
	int gpa_final_score_01 = 0;
	for (int i = 0; i < list_01.size(); i++) {
		if ((id.compare(list_01[i].teacher_id) == 0) && (input_sub_code_01.compare(list_01[i].subject_code) == 0)) {
			if (input_stu_id_01.compare(list_01[i].stu_id) == 0) {
				is_student_exist_01 = true;
				cout << "Professor, Please input the Final Score of Subject " << input_sub_code_01 << " for Student " << input_stu_id_01 << " : ";
				cin >> gpa_final_score_01;
				list_01[i].score_final = gpa_final_score_01;
				break;
			}
		}
	}
	if (is_student_exist_01 == false) {
		cout << "There is no Student with ID " << input_stu_id_01 << " in your Course.\n";
		return;
	}

	ofstream object_write_file_001("grade_semester_193.csv", ios::out);
	if (!object_write_file_001) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_01.size(); i++) {
		object_write_file_001 << list_01[i].subject_code << ","
			<< list_01[i].stu_id << ","
			<< list_01[i].teacher_id << ","
			<< list_01[i].score_final << ","
			<< list_01[i].sub_credit << endl;
	}
	object_write_file_001.close();
	cout << "\n=> Modify Student's Score Success !!\n";
}

void professor_class::summarize_student_score(string id) {
	//load all file grade_semester_193.csv
	vector<grade_semester_file>list_01;
	ifstream object_read_01("grade_semester_193.csv", ios::in);
	if (!object_read_01) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string list_01_sub_code, list_01_id_stu, list_01_id_profess, list_01_final_sco, list_01_credit;
	int list_01_final_sco_2, list_01_credit_2;
	while (!object_read_01.eof()) {
		getline(object_read_01, list_01_sub_code, ',');
		getline(object_read_01, list_01_id_stu, ',');
		getline(object_read_01, list_01_id_profess, ',');

		getline(object_read_01, list_01_final_sco, ',');
		list_01_final_sco_2 = stoi(list_01_final_sco);

		getline(object_read_01, list_01_credit, '\n');
		list_01_credit_2 = stoi(list_01_credit);

		list_01.push_back(make_object_grade_semester_file(list_01_sub_code, list_01_id_stu, list_01_id_profess, list_01_final_sco_2, list_01_credit_2));
	}
	object_read_01.close();
	//
	cout << "Professor, Please input subject code: ";
	string input_sub_code;
	cin >> input_sub_code;
	vector<grade_semester_file>list_02_store_needed;
	bool is_subject_exist_01 = false;
	for (int i = 0; i < list_01.size(); i++) {
		if ((id.compare(list_01[i].teacher_id) == 0) && (input_sub_code.compare(list_01[i].subject_code) == 0)) {
			is_subject_exist_01 = true;
			list_02_store_needed.push_back(list_01[i]);
		}
	}
	if (is_subject_exist_01 == false) {
		cout << "You don't teach this Subject in this semester.\n";
		return;
	}
	cout << "Students' Scores in the Course " << input_sub_code << " - (Professor ID: " << id << ") :\n\n";
	cout << setw(18) << "Student ID" << setw(18) << "Final Score" << endl;
	for (int i = 0; i < list_02_store_needed.size(); i++) {
		cout << setw(18) << list_02_store_needed[i].stu_id << setw(18) << list_02_store_needed[i].score_final << endl;
	}
	cout << '\n';
}
//---------------------------------------------------------------------------------------------------------------------------
//Part 3: Dealing with 2.4) Student
string student_class::login_logout_student() {
	vector <professor_file_user> list_id;
	ifstream object_profess_user("student_users.csv", ios::in);
	if (!object_profess_user) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string username, pass;
	while (!object_profess_user.eof()) {
		getline(object_profess_user, username, ',');
		if (object_profess_user.eof()) {
			break;
		}
		getline(object_profess_user, pass, '\n');
		list_id.push_back(make_object_profess_file_user(username, pass));
	}
	object_profess_user.close();
	bool flag = false;
	bool is_exist = false;
	string user_profess_id, user_profess_pass;
	while (flag == false) {
		is_exist = false;
		cout << "Student: \t(Enter ID and Password to login || Enter exactly the word 'logout' (in the ID part or in the Password part) to logout)\n";
		cout << "ID: ";
		cin >> user_profess_id;

		//checking ID;
		if (user_profess_id.compare("logout") == 0) {
			cout << "\n";
			return "negative";
		}
		for (int i = 0; i < list_id.size(); i++) {
			if (user_profess_id.compare(list_id[i].id) == 0) {
				is_exist = true;
				cout << "Password: ";
				cin >> user_profess_pass;

				if (user_profess_pass.compare("logout") == 0) {
					cout << "\n";
					return "negative";
				}

				if (list_id[i].pass.compare(user_profess_pass) == 0) {
					cout << "\nAccess Granted\n";
					flag = true;
					break;
				}
				else {
					cout << "Wrong password !!! Please try again\n\n\n";
					break;
				}
			}
		}
		if (is_exist == false) {
			cout << "Wrong ID !!! Please try again\n\n\n";
		}
	}
	return user_profess_id;
}

void student_class::change_pass(string id) {
	string new_pass;
	cout << "Please input new password: ";
	cin >> new_pass;

	vector <professor_file_user> list_id;
	ifstream object_user("student_users.csv", ios::in);//load the whole table to the vector
	if (!object_user) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string username, pass;
	while (!object_user.eof()) {
		getline(object_user, username, ',');
		if (object_user.eof()) {
			break;
		}
		getline(object_user, pass, '\n');
		list_id.push_back(make_object_profess_file_user(username, pass));
	}
	object_user.close();

	for (int i = 0; i < list_id.size(); i++) { //change pass;
		if (id.compare(list_id[i].id) == 0) {
			list_id[i].pass.assign(new_pass);
			break;
		}
	}

	ofstream object_user2("student_users.csv", ios::out);//write back everything to the file
	if (!object_user2) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_id.size(); i++) {
		object_user2 << list_id[i].id << "," << list_id[i].pass << endl;
	}
	object_user2.close();
	cout << "=> Change password Success !!\n";
}

void student_class::register_course(string id) {
	//load all file grade_semester_193.csv
	vector <grade_semester_file> list_grade;
	string grade_id_subject, grade_id_stu, grade_id_teacher, grade_score, grade_credit;
	int grade_score_2, grade_credit_2;
	int student_total_credit = 0;

	ifstream object_005("grade_semester_193.csv", ios::in);
	if (!object_005) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	while (!object_005.eof()) {
		getline(object_005, grade_id_subject, ',');
		if (object_005.eof()) {
			break;
		}
		getline(object_005, grade_id_stu, ',');
		getline(object_005, grade_id_teacher, ',');

		getline(object_005, grade_score, ',');
		grade_score_2 = stoi(grade_score);

		getline(object_005, grade_credit, '\n');
		grade_credit_2 = stoi(grade_credit);

		list_grade.push_back(make_object_grade_semester_file(grade_id_subject, grade_id_stu, grade_id_teacher, grade_score_2, grade_credit_2));
	}
	object_005.close();

	for (int i = 0; i < list_grade.size(); i++) {
		if (id.compare(list_grade[i].stu_id) == 0) {
			student_total_credit = student_total_credit + list_grade[i].sub_credit;
		}
	}

	if (student_total_credit == 20) {
		cout << "Student " << id << ", you have already register 20 credits in this semester. Therefore, you can't register a new subject anymore.\n";
		return;
	}

	//
	string sub_code, teacher;
	//load all the file course_semester_193.csv;
	vector <course_semester> list_course;
	string code_subject, id_teacher, name_sub, credit01, maxstu01, curstu01;
	int credit02, maxstu02, curstu02;
	ifstream object01("course_semester_193.csv", ios::in);
	if (!object01) {
		cerr << "File could not be opened\n";
		exit(1);
	}

	while (!object01.eof()) {
		getline(object01, code_subject, ',');
		if (object01.eof()) {
			break;
		}
		getline(object01, id_teacher, ',');
		getline(object01, name_sub, ',');

		getline(object01, credit01, ',');
		credit02 = stoi(credit01);

		getline(object01, maxstu01, ',');
		maxstu02 = stoi(maxstu01);

		getline(object01, curstu01, '\n');
		curstu02 = stoi(curstu01);

		list_course.push_back(make_object_course_semester_file(code_subject, id_teacher, name_sub, credit02, maxstu02, curstu02));
	}
	object01.close();

	//register course;
	cout << "Register a course: \n";
	cout << "Enter code subject: ";
	cin >> sub_code;
	//checking if the subject has been registered before
	for (int i = 0; i < list_grade.size(); i++) {
		if ((sub_code.compare(list_grade[i].subject_code) == 0) && (id.compare(list_grade[i].stu_id) == 0)) {
			cout << "You have already registered this subject in this semester.\n";
			return;
		}
	}
	//
	int number_difference = 0;
	for (int i = 0; i < list_course.size(); i++) {
		if (sub_code.compare(list_course[i].code_subject) != 0) {
			number_difference++;
		}
	}
	if (number_difference == list_course.size()) {
		cout << "This Subject isn't open this semester.\n";
		return;
	}
	
	cout << "Enter the ID of the professor who you want to study with: (Because there are some professors who teach the same subject)\n";
	cin >> teacher;
	bool teacher_available = false;
	bool is_course_full = false;
	for (int i = 0; i < list_course.size(); i++) {
		if ((sub_code.compare(list_course[i].code_subject) == 0) && (teacher.compare(list_course[i].id_teacher) == 0)) {
			teacher_available = true;
			if (list_course[i].max_students == list_course[i].current_students) {
				is_course_full = true;
			}
			break;
		}
	}
	if (teacher_available == false) {
		cout << "The Professor does't teach this subject this semester.\n";
		return;
	}

	if (is_course_full == true) {
		cout << "This class is FULL!!!\n";
		return;
	}
	//checking number of credit of this student in this semester maximum 20 credits;
	int credit_before = student_total_credit;
	int credit_addition = 0;
	for (int i = 0; i < list_course.size(); i++) {
		if ((sub_code.compare(list_course[i].code_subject) == 0) && (teacher.compare(list_course[i].id_teacher) == 0)) {
			student_total_credit = student_total_credit + list_course[i].credit;
			credit_addition = list_course[i].credit;
			break;
		}
	}
	if (student_total_credit > 20) {
		cout << "Dear Student " << id << ",\n";
		cout << "Your total credits for this semester is " << credit_before << " credits\n";
		cout << "The subject you want to register has " << credit_addition << " credits\n";
		cout << "Because the rule is 'A student is allowed to register maximum 20 credits in one semester'.\n";
		cout << "Therefore, you can not register this subject!!!\n";
		return;
	}
	//
	for (int i = 0; i < list_course.size(); i++) {
		if ((sub_code.compare(list_course[i].code_subject) == 0) && (teacher.compare(list_course[i].id_teacher) == 0)) {
			list_course[i].current_students++;
			break;
		}
	}

	//update the file course_semester_193.csv
	ofstream object02("course_semester_193.csv", ios::out);
	if (!object02) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_course.size(); i++) {
		object02 << list_course[i].code_subject << "," << list_course[i].id_teacher << "," << list_course[i].name_subject << "," << list_course[i].credit << "," << list_course[i].max_students << "," << list_course[i].current_students << endl;
	}
	object02.close();

	//write the file grade_semester_193.csv
	int student_credit_regis = 0;
	for (int i = 0; i < list_course.size(); i++) {
		if ((sub_code.compare(list_course[i].code_subject) == 0) && (teacher.compare(list_course[i].id_teacher) == 0)) {
			student_credit_regis = list_course[i].credit;
			break;
		}
	}
	int gpa_final = 15;
	ofstream object03("grade_semester_193.csv", ios::app);
	if (!object03) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	object03 << sub_code << "," << id << "," << teacher << "," << gpa_final << "," << student_credit_regis << endl;
	object03.close();
	cout << "\n=> Register Course Success !!\n";
}

void student_class::remove_course(string id) {
	//load all file grade_semester_193.csv to this function
	vector <grade_semester_file> list_subject_regis;
	string sub_code, student_id, profess_id, score01, credit01;
	int score02, credit02;
	ifstream object01("grade_semester_193.csv", ios::in);
	if (!object01) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	while (!object01.eof()) {
		getline(object01, sub_code, ',');
		if (object01.eof()) {
			break;
		}
		getline(object01, student_id, ',');
		getline(object01, profess_id, ',');
		getline(object01, score01, ',');
		score02 = stoi(score01);
		getline(object01, credit01, '\n');
		credit02 = stoi(credit01);

		list_subject_regis.push_back(make_object_grade_semester_file(sub_code, student_id, profess_id, score02, credit02));
	}
	object01.close();
	//
	cout << "Enter the Code of the Subject which you want to remove: ";
	string sub_remove_id;
	cin >> sub_remove_id;
	bool is_sub_exist = false;
	int count_index_locate = 0;
	string store_teacher_id;
	for (count_index_locate = 0; count_index_locate < list_subject_regis.size(); count_index_locate++) {
		if ((sub_remove_id.compare(list_subject_regis[count_index_locate].subject_code) == 0) && (id.compare(list_subject_regis[count_index_locate].stu_id) == 0)) {
			is_sub_exist = true;
			store_teacher_id = list_subject_regis[count_index_locate].teacher_id;
			break;
		}
	}
	if (is_sub_exist == false) {
		cout << "You didn't register this subject!!!\n";
		return;
	}

	for (int i = 0; i < list_subject_regis.size(); i++) {
		if ((sub_remove_id.compare(list_subject_regis[i].subject_code) == 0) && (id.compare(list_subject_regis[i].stu_id) == 0)) {
			if (list_subject_regis[i].score_final != 15) {
				cout << "You can not remove this course because you have had the final score for this course and your final score for this course has been updated to the system.\n";
				return;
			}
			else {
				break;
			}
		}
	}

	list_subject_regis.erase(list_subject_regis.begin() + count_index_locate); //remove course

	//Decrease student in that class in file course_semester_193.csv
	vector <course_semester> list_course;
	string sub_code_course_file, profess_id_course_file, name_course_file, credit_course_file_1, maxstu_course_file_1, curstu_course_file_1;
	int credit_course_2, maxstu_course_file_2, curstu_course_file_2;
	ifstream object02("course_semester_193.csv", ios::in);
	if (!object02) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	while (!object02.eof()) {
		getline(object02, sub_code_course_file, ',');
		if (object02.eof()) {
			break;
		}
		getline(object02, profess_id_course_file, ',');
		getline(object02, name_course_file, ',');

		getline(object02, credit_course_file_1, ',');
		credit_course_2 = stoi(credit_course_file_1);

		getline(object02, maxstu_course_file_1, ',');
		maxstu_course_file_2 = stoi(maxstu_course_file_1);

		getline(object02, curstu_course_file_1, '\n');
		curstu_course_file_2 = stoi(curstu_course_file_1);

		list_course.push_back(make_object_course_semester_file(sub_code_course_file, profess_id_course_file, name_course_file, credit_course_2, maxstu_course_file_2, curstu_course_file_2));
	}
	object02.close();

	for (int i = 0; i < list_course.size(); i++) {
		if ((sub_remove_id.compare(list_course[i].code_subject) == 0) && (store_teacher_id.compare(list_course[i].id_teacher) == 0)) {
			list_course[i].current_students--;
			break;
		}
	}
	//

	//update the file course_semester_193.csv
	ofstream object_02b("course_semester_193.csv", ios::out);
	if (!object_02b) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_course.size(); i++) {
		object_02b << list_course[i].code_subject << "," << list_course[i].id_teacher << "," << list_course[i].name_subject << "," << list_course[i].credit << "," << list_course[i].max_students << "," << list_course[i].current_students << endl;
	}
	object_02b.close();
	//

	//update the file grade_semester_193.csv
	ofstream object_03("grade_semester_193.csv", ios::out);
	if (!object_03) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	for (int i = 0; i < list_subject_regis.size(); i++) {
		object_03 << list_subject_regis[i].subject_code << "," << list_subject_regis[i].stu_id << "," << list_subject_regis[i].teacher_id << "," << list_subject_regis[i].score_final << "," << list_subject_regis[i].sub_credit << endl;
	}
	object_03.close();
	//
	cout << "\n=> Remove Course Success !!\n";
}

void student_class::view_gpa(string id) {
	vector<grade_semester_file> table001;
	ifstream object_read_file_001("grade_semester_193.csv", ios::in);
	if (!object_read_file_001) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string read_sub_code_01, read_student_01, read_teacher_01, read_score_01, read_credit_01;
	int read_score_02, read_credit_02;
	while (!object_read_file_001.eof()) {
		getline(object_read_file_001, read_sub_code_01, ',');
		if (object_read_file_001.eof()) {
			break;
		}
		getline(object_read_file_001, read_student_01, ',');
		getline(object_read_file_001, read_teacher_01, ',');

		getline(object_read_file_001, read_score_01, ',');
		read_score_02 = stoi(read_score_01);

		getline(object_read_file_001, read_credit_01, '\n');
		read_credit_02 = stoi(read_credit_01);

		table001.push_back(make_object_grade_semester_file(read_sub_code_01, read_student_01, read_teacher_01, read_score_02, read_credit_02));
	}
	object_read_file_001.close();
	
	cout << "Vieu GPA of Student " << id << ":\n\n";
	cout << setw(18) << "Subject Code" << setw(18) << "Final Score" << setw(18) << "Credits" << '\n';
	for (int i = 0; i < table001.size(); i++) {
		if ((id.compare(table001[i].stu_id) == 0) && (table001[i].score_final != 15)) {
			cout << setw(18) << table001[i].subject_code << setw(18) << table001[i].score_final << setw(18) << table001[i].sub_credit << '\n';
		}
	}
}

void student_class::view_registered_courses(string id) {
	vector<grade_semester_file> table001;
	ifstream object_read_file_001("grade_semester_193.csv", ios::in);
	if (!object_read_file_001) {
		cerr << "File could not be opened\n";
		exit(1);
	}
	string read_sub_code_01, read_student_01, read_teacher_01, read_score_01, read_credit_01;
	int read_score_02, read_credit_02;
	while (!object_read_file_001.eof()) {
		getline(object_read_file_001, read_sub_code_01, ',');
		if (object_read_file_001.eof()) {
			break;
		}
		getline(object_read_file_001, read_student_01, ',');
		getline(object_read_file_001, read_teacher_01, ',');

		getline(object_read_file_001, read_score_01, ',');
		read_score_02 = stoi(read_score_01);

		getline(object_read_file_001, read_credit_01, '\n');
		read_credit_02 = stoi(read_credit_01);

		table001.push_back(make_object_grade_semester_file(read_sub_code_01, read_student_01, read_teacher_01, read_score_02, read_credit_02));
	}
	object_read_file_001.close();

	cout << "View Registered Course of Student " << id << ":\n\n";
	cout << setw(18) << "Subject Code" << setw(18) << "Professor" << setw(18) << "Final Score" << setw(18) << "Credits" << '\n';
	for (int i = 0; i < table001.size(); i++) {
		if (id.compare(table001[i].stu_id) == 0) {
			cout << setw(18) << table001[i].subject_code << setw(18) << table001[i].teacher_id << setw(18) << table001[i].score_final << setw(18) << table001[i].sub_credit << '\n';
		}
	}
}

void student_class::view_courses_in_semester() {
	ifstream object_read_01("course_semester_193.csv", ios::in);
	if (!object_read_01) {
		cerr << "File could not be opened\n";
		exit(1);
	}

	cout << "Courses in the semester:\n\n";
	cout << setw(18) << "Subject Code"
		<< setw(18) << "Professor ID"
		<< setw(27) << "Subject Name"
		<< setw(11) << "Credits"
		<< setw(29) << "Maximum Number of Students"
		<< setw(29) << "Current Number of Students" << '\n';

	string read_sub_code, read_teach, read_name, read_credit, read_max_stu, read_cur_stu;
	while (!object_read_01.eof()) {
		getline(object_read_01, read_sub_code, ',');
		if (object_read_01.eof()) {
			break;
		}
		getline(object_read_01, read_teach, ',');
		getline(object_read_01, read_name, ',');
		getline(object_read_01, read_credit, ',');
		getline(object_read_01, read_max_stu, ',');
		getline(object_read_01, read_cur_stu, '\n');

		cout << setw(18) << read_sub_code
			<< setw(18) << read_teach
			<< setw(27) << read_name
			<< setw(11) << read_credit
			<< setw(29) << read_max_stu
			<< setw(29) << read_cur_stu << '\n';
	}
	object_read_01.close();
}

void student_class::student_find_courses() {
	vector<course_semester> table01;

	ifstream read_file_01("course_semester_193.csv", ios::in);
	if (!read_file_01) {
		cerr << "File could not be opened\n";
		exit(1);
	}

	string code_sub_store, id_teach_store, name_sub_store, credit_store, max_stu_store, cur_stu_store;
	int credit_store_2, max_stu_store_2, cur_stu_store_2;

	while (!read_file_01.eof()) {
		getline(read_file_01, code_sub_store, ',');
		if (read_file_01.eof()) {
			break;
		}
		getline(read_file_01, id_teach_store, ',');
		getline(read_file_01, name_sub_store, ',');

		getline(read_file_01, credit_store, ',');
		credit_store_2 = stoi(credit_store);

		getline(read_file_01, max_stu_store, ',');
		max_stu_store_2 = stoi(max_stu_store);

		getline(read_file_01, cur_stu_store, '\n');
		cur_stu_store_2 = stoi(cur_stu_store);

		table01.push_back(make_object_course_semester_file(code_sub_store, id_teach_store, name_sub_store, credit_store_2, max_stu_store_2, cur_stu_store_2));
	}
	read_file_01.close();

	cout << "Please input the Subject Code: ";
	string sub_code_input;
	cin >> sub_code_input;

	bool is_exist_code = false;

	for (int i = 0; i < table01.size(); i++) {
		if (sub_code_input.compare(table01[i].code_subject) == 0) {
			if (is_exist_code == false) {
				is_exist_code = true;
				cout << setw(18) << "Subject Code" << setw(18) << "Professor ID" << setw(27) << "Subject Name" << setw(18) << "Credits" << setw(27) << "Maximum Students" << setw(27) << "Current Students" << '\n';
				cout << setw(18) << table01[i].code_subject << setw(18) << table01[i].id_teacher << setw(27) << table01[i].name_subject << setw(18) << table01[i].credit << setw(27) << table01[i].max_students << setw(27) << table01[i].current_students << '\n';
			}
			else {
				cout << setw(18) << table01[i].code_subject << setw(18) << table01[i].id_teacher << setw(27) << table01[i].name_subject << setw(18) << table01[i].credit << setw(27) << table01[i].max_students << setw(27) << table01[i].current_students << '\n';
			}
		}
	}

	if (is_exist_code == false) {
		cout << "This Subject Code doesn't exist !!!";
	}

	cout << '\n';
}