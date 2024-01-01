#include<iostream>
#include<queue>
using namespace std;

class fun{
public:
    void operator()(string s = "25"){
        cout<<"I am "<<s<<" year old.\n ";
    }

};

class Person{
public:
    string name;
    int age;

    Person(string n,int a){
        name=n;
        age=a;
    }
};

class PersonCompare{
public:
    bool operator()(Person A,Person B){
        cout<<" comparing " << A.age << " and "<<B.age<<endl;
        return A.age>B.age;
    }
};

int main(){

    fun f;
    f();

    int n;
    cin>>n;

    priority_queue<Person,vector<Person>,PersonCompare> pq; //the third parameter accepts a class comparator as a function so functional operator

    for(int i=0;i<n;i++){
        string name;
        int age;

        cin>>name>>age;
        Person p(name,age);
        pq.push(p);
    }

    int k = 3;
    for(int i=0;i<k;i++){
        cout<<pq.top().name<<" "<<pq.top().age<<endl;
        pq.pop();
    }

    return 0;
}