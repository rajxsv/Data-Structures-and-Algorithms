// ! lets make a hashmap for custom class Student

#include<iostream>
#include<unordered_map>

using namespace std;

class Student{
    public:

    string firstName;
    string lastName;
    string rollNo;

    Student(string f,string l,string no){
        firstName = f;
        lastName = l;
        rollNo = no;
    }

    bool operator==(const Student &s)const{
        return rollNo == s.rollNo?true:false;
    }
};

// ! we do 2 things no1 , overload the == operator and 2. write our own hashfn()

class HashFn{
public:
// unisgned int used to represent size of some memory in bytes
    size_t operator()(const Student &s)const{
       return s.firstName.length() + s.lastName.length(); 
    } 
};

int main(){

    unordered_map<Student,int,HashFn> student_map;

    Student s1("Rajpreet","Singh","1");
    Student s2("Anmoldeep","Singh","2");
    Student s3("Ranbir","Singh","3");
    Student s4("Anubhav","Singh","4");
    Student s5("Jabal","Singh","5");
    Student s6("Jabal","Singh","6");

    student_map[s1] = 100;
    student_map[s2] = 200;
    student_map[s3] = 300;
    student_map[s4] = 400;

    for(auto p:student_map){
        cout<<p.first.firstName<<" "<<p.second<<endl;
    }

    return 0;
}