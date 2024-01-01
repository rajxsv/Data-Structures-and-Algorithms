#include <iostream>
#include<map>
#include <unordered_map>
using namespace std;

int main(){


// I. ORDERED MAP


	//ordered map-all keys are ordered so if we are putting strings it is lexographically ordered 
	map<string,int> m; //we are storing ordered key value pairs
	

	//lets insert - pair 
// 1.
	m.insert(make_pair("Mango",100));

// 2.
	pair<string,int> p;
	p.first = "apple";
	p.second = 230;
	m.insert(p);

// 3.
	m["Banana"] = 250;
	// m["Banana"] = 200;
	m["Kiwi"] = 600;


//2 search
	string fruit;
	cin>>fruit;

	auto it = m.find(fruit); //returns iterator to the fruit node

	if(it!=m.end()){
		cout<<"Price of "<<fruit << " is "<<m[fruit]<<endl;
	}
	else{
		cout<<"Not present"<<endl;
	}

	//another way to find a particular map
	//it stores only unique

	m["Banana"] = 1230;
	cout<<endl<<m["Banana"]<<endl;


	if(m.count(fruit)){ //returns 1 if present else 0
		cout<<"Price is "<<m[fruit]<<endl;
	}
	else{
		cout<<"Not found";
	}


	m.erase("Banana");

	if(m.count(fruit)){ 
		cout<<"Price is "<<m[fruit]<<endl;
	}
	else{
		cout<<"Not found\n";
	}

	m[fruit]=20;
	m[fruit]+=20;
	cout<<m[fruit]<<endl;
	cout<<endl;


	for(auto it=m.begin();it!=m.end();it++){
		cout<<(*it).first<<" is "<<(*it).second<<endl;
	}
	cout<<endl;
	//or

	for(auto it=m.begin();it!=m.end();it++){
		cout<<it->first<<" is "<<it->second<<endl;
	}
	cout<<"\n\n";
	//or
	//for each loop
	for(auto p:m){
		cout<<p.first << " is "<<p.second<<endl;
	}

	

	// II Unordered map

	//best part of this -> you can do insertion and deletion search or even find works on average O(1) time

	unordered_map<string,int> um;
	cout<<"\n\nFollowing outputs are from unordered_map\n"<<endl;

	um.insert(make_pair("Mango",100));

// 2.
	pair<string,int> p1;
	p1.first = "Apple";
	p1.second = 230;
	um.insert(p1);

// 3.
	um["Banana"] = 250;
	um["banana"] = 200;
	um["Kiwi"] = 600;


//2 search
	string fruit1;
	cin>>fruit1;

	auto it1 = um.find(fruit1); //returns iterator to the fruit node

	if(it1!=um.end()){
		cout<<"Price of "<<fruit1 << " is "<<um[fruit1]<<endl;
	}
	else{
		cout<<"Not present"<<endl;
	}

	//another way to find a particular map
	//it stores only unique

	um["Banana"] = 1230;
	cout<<um["Banana"]<<endl;


	if(um.count(fruit1)){ //returns 1 if present else 0
		cout<<"Price is "<<um[fruit1]<<endl;
	}
	else{
		cout<<"Not found";
	}


	um.erase("Banana");

	if(um.count(fruit1)){ 
		cout<<"Price is "<<um[fruit1]<<endl;
	}
	else{
		cout<<"Not found\n";
	}

	um[fruit1]=20;
	um[fruit1]+=20;
	cout<<um[fruit1]<<endl;
	cout<<endl;


	for(auto it=um.begin();it!=um.end();it++){
		cout<<(*it).first<<" is "<<(*it).second<<endl;
	}
	cout<<endl;
	//or

	for(auto it=um.begin();it!=um.end();it++){
		cout<<it->first<<" is "<<it->second<<endl;
	}
	cout<<"\n\n";
	//or
	//for each loop
	for(auto pr:um){
		cout<<pr.first << " is "<<pr.second<<endl;
	}

	return 0;
}