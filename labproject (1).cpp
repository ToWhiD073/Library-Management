#include<bits/stdc++.h>
#include<fstream>
using namespace std;


class Student_Info {
    string student_name;
    int ID;
    string department_name;
    string phone_number;
    string blood_group;
    string date_of_birth;

public:
    Student_Info(){};
    void get_info() {
        cin.ignore();
        cout << "Enter Student Name : ";
        getline(cin,student_name);
        cout << "Enter Student ID : ";
        cin >> ID;
        cin.ignore();
        cout << "Enter Department Name : ";
        getline(cin,department_name);
        cout << "Enter your Date of Birth : ";
        cin.ignore();
        getline(cin, date_of_birth);
        cout << "Enter Phone Number : ";
        cin >> phone_number;
        cout << "Enter Blood Group : ";
        cin >> blood_group;
    }
    string get_name() {
        return student_name;
    }
    int get_ID() {
        return ID;
    }
    string get_deptname() {
        return department_name;
    }
    string get_date_of_birth() {
        return date_of_birth;
    }
    string get_phonenum() {
        return phone_number;
    }
    string get_blood_group() {
        return blood_group;
    }
    void showinfo() {
        cout<< setw(40) << student_name;;
        cout << setw(25) << ID;
        cout << setw(50) << department_name;
        cout<< setw(25) << date_of_birth;
        cout << setw(25) << phone_number;
        cout << '\n';
        
    }

};

class Student_Info_print : public Student_Info {
public:
    
    void show_my_id() {
        cout << "\n\n";
        cout << "***********************************************************************************************************" << "\n";
        cout << "***********************************************************************************************************" << "\n\n\n\n";
        cout << "***********************************************************************************************************" << "\n\n";
        cout << "````````````````````````````````````````````````````CUET```````````````````````````````````````````" << "\n\n";
        cout << "````````````````````````````````````````````````LIBRARY CARD```````````````````````````````````````````" << "\n\n\n";
        cout << "                                            STUDENT INFORMATION " << "\n\n";
        cout << "Name = " << get_name() << '\n';
        cout << "Student ID = " << get_ID() << '\n';
        cout << "Department Name = " << get_deptname() << '\n';
        cout << "Phone Number = " << get_phonenum() << '\n';
        cout << "Birth = " << get_date_of_birth() << '\n';
        cout << "Blood Group = " << get_blood_group() << "\n\n";

        cout << "\n\n                                               Validity Till 2026" << "\n\n";
        cout << "***********************************************************************************************************" << "\n\n\n\n";
        cout << "***********************************************************************************************************" << "\n";
        cout << "***********************************************************************************************************" << "\n";
    }


    /// Storing the information to database file
    void give_data() {
        ofstream openfile("Database.txt",ios:: app);
        openfile << "\n\n";
        openfile << "*********************************" << "\n";
        openfile << "Name = " << get_name() << '\n';
        openfile << "Student ID = " << get_ID() << '\n';
        openfile << "Department Name = " << get_deptname() << '\n';
        openfile << "Phone Number = " << get_phonenum() << '\n';
        openfile << "Birth = " << get_date_of_birth() << '\n';
        openfile << "Blood Group = " << get_blood_group() << "\n\n";
        openfile << "*********************************" << "\n";
        openfile.close();
    }
    

};

// class to open a file;
class Open_file{
    string file_name;
public:
    void showinfo(){
        cout << "Enter the file Name : ";
        cin >> file_name;
        file_name += ".txt";
        ifstream fin;
        fin.open(file_name);
        while(fin.eof() == 0) {
            string str;
            getline(fin, str);
            cout << str << '\n';
        }
        fin.close();
    }
};



int main() {
    cout << "\n\n\n";

    vector< Student_Info_print> student_list;
    cout << "````````````````````````````````````````````WELCOME TO CUET CENTRAL LIBRARY`````````````````````````````````````````````" << "\n\n\n\n";

    cout << "Enter Your ID to Login : ";
    int nn; cin >> nn;
    ofstream ofile("Program_History.txt",ios:: app);
    ofile << "ID : ";
    ofile << nn;
    time_t tt;
    struct  tm*ti;
    time (&tt);
    ti = localtime(&tt);
    ofile << " --> ";
    ofile << asctime(ti);
    
    ofile.close();
    while(1) {
        cout << "\n\n\n";
        cout << "____________________Choose What You What To See____________________" << "\n\n";
        cout << "             ---> Press Any Number From Following <---" << "\n\n\n";
        cout << "\t0 -----> Exit The site" << '\n';
        cout << "\t1 -----> Make a Library Card" << '\n';
        cout << "\t2 -----> See The Student List" << '\n';
        cout << "\t3 -----> See The Library Committee" << '\n';
        cout << "\t4 -----> See The Available Book List" << '\n';
        cout << "\t5 -----> See The Whole Student Libaray Card Database" << '\n';
        cout << "\t6 -----> See Login History" << '\n';

        cout << '\n';
        int n;
        cout << "Enter Your Choice : ";
        cin >> n;
        cout << "\n\n";


        if(n == 0) {
            cout << "\n\n\n";
            cout << "_____Have A Good Day_____";
            cout << "\n\n\n";
            break;
        }



        //Make a Library Card
        if(n == 1){
            cout << "Enter Your Information" << "\n\n\n";
            Student_Info_print info;
            info.get_info();
            info.give_data();
            student_list.push_back(info);
            cout << "\n\n---------------Congratulations---------------" << "\n\n";
            cout << "*************Your Library Card is Done*************" << "\n\n\n";

            cout << "If You Want to print Your Card " << "\n\n";
            int aa;
            cout << "1. Enter 11 " << "\n";
            cout << "2. Otherwise press Any integer " << "\n\n";
            cout << "Enter A Integer : ";
            cin >> aa;
            if(aa == 11) {
                cout << "\n\n";
                info.show_my_id();
            }
            cout << '\n';
        }



        //See The Student List
        if(n == 2) {
            cout << "\n\n";
            cout << "Enter password to get access : ";
            string s; cin >> s;
            // Checking given password with the file password

            ifstream in("mainpass.txt");
            string check; getline(in, check);
            if(check != s) {
                cout << "Your Password is Wrong." << '\n';
                cout << "Try Again" << "\n\n\n";
            }
            else {
                cout << setw(40) << "Name";
                cout << setw(25) << "ID";
                cout << setw(50) << "Department";
                cout << setw(25) << "Date of Birth";
                cout << setw(25) << "Phone" << '\n';

                if(student_list.size() == 0) {
                    cout << '\n';
                    cout << "                ---> List is Empty <---   " << '\n';
                }
                else {
                    for(int i = 0; i < student_list.size(); i++) {
                        student_list[i].showinfo();
                        cout << '\n';
                    }
                }
            }
        }

        // Showing library Committe from the file

        if(n == 3) {
            cout << '\n';
            cout << "To see the Committe Type -> Librarycommitte <-" << '\n';
            cout << "\n\n";
            Open_file A;
            A.showinfo();
        }
        if(n == 4) {
            cout << '\n';
            cout << "To see the Book list -> booklist <-" << '\n';
            cout << "\n\n";
            Open_file A;
            A.showinfo();
        }
        if(n == 5){
            cout << "\n\n";
            cout << "Enter password to get access : ";
            string s; cin >> s;
            // Checking given password with the file password

            ifstream in("mainpass.txt");
            string check; getline(in, check);
            if(check != s) {
                cout << "Your Password is Wrong." << '\n';
                cout << "Try Again" << "\n\n\n";
            }
            else {
                cout << "To see the database --> Database <--" << '\n';
                cout << "\n\n";
                Open_file B;
                B.showinfo();

            }
        }

        if(n == 6) {
            cout << "\n\n";
            cout << "Enter password to get access : ";
            string s; cin >> s;
            // Checking given password with the file password

            ifstream in("mainpass.txt");
            string check; getline(in, check);
            if(check != s) {
                cout << "Your Password is Wrong." << '\n';
                cout << "Try Again" << "\n\n\n";
            }
            else {
                cout << "To see the database --> Program_History <--" << '\n';
                cout << "\n\n";
                Open_file B;
                B.showinfo();

            }
        }
    }
}
