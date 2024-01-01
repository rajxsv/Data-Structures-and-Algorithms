#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){

	unordered_map<string,vector<string>> phonebook;

	phonebook["Virdi"].push_back("684615672384");
	phonebook["Virdi"].push_back("684615672384");
	phonebook["Virdi"].push_back("684612383454");
	phonebook["Rajpreet"].push_back("68464345184");
	phonebook["Rajpreet"].push_back("6846435184");
	phonebook["Manmeet"].push_back("684684441232");
	phonebook["Manmeet"].push_back("68468442132");
	phonebook["Manmeet"].push_back("684684423");
	phonebook["Manmeet"].push_back("6846844212");
	phonebook["Surendra"].push_back("68468544");
	phonebook["Ranjeet"].push_back("684683454");


	for(auto p:phonebook){
		cout<<"Name "<<p.first<<" ->\n";
		for(auto i:p.second){
			cout<<i<<",";
		}
		cout<<endl;
	}
	cout<<"\n\n\n";
	string name;
	cin>>name;

	if(phonebook.count(name)==0){
		cout<<"nai haigi \n";
	}
	else{
		cout<<name<<" ->\n";
		for(string s:phonebook[name]){
			cout<<s<<endl;
		}
	}

	return 0;
}