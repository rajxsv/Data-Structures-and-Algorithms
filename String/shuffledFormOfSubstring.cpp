#include <iostream>
#include <algorithm>
#include <string>
#include <Cstring>
using namespace std;

bool mycompare(int* arr1,int* arr2){
	for(int i=0;i<256;i++){
		if(arr1[i]!=arr2[i]){
			return false;
		}
	}
	return true;
}

bool check(string s1,string s2,int m,int n){
	if(m>n){
		return false;
	}

	sort(s1.begin(),s1.end());
	// cout<<s1<<endl;
	for(int i=0;i<=(n-m);i++){
		string temp = "";
		for(int j=i;j<(m+i);j++){
			temp+=s2[j];
		}
		sort(temp.begin(),temp.end());
		// cout<<temp<<endl;
		if(temp==s1){
			return true;
		}
	}
	return false;
}

bool fast_check(string pat,string txt){
	int m = pat.length(), n = txt.length();
	if(m>n){
		return false;
	}

	int freqPattern[26]={0};
	int freqWindow[26]={0};

	memset(freqPattern, 0 , sizeof(freqPattern));
	memset(freqWindow, 0 , sizeof(freqWindow));

	for(int i=0;i<m;i++){
		freqWindow[pat[i]-'a']++;
		freqPattern[txt[i]-'a']++;
	}

	for(int i=m;i<n;i++){
		if(mycompare(freqWindow,freqPattern)){
			return true;
		}
		freqWindow[txt[i]-'a']++;
		freqWindow[txt[i-m]-'a']--;
		
		for(int j=0;j<26;j++){
			if(freqWindow[j]!=0){

			cout<<char(j+'a')<<" ";
			}
		}

		cout<<endl;

	}
	if(mycompare(freqWindow,freqPattern))return true;

	return false;
}


int main(){

	/*
	
	Input: str1 = “onetwofour”, str2 = “hellofourtwooneworld” 
	Output: YES 
	Explanation: str1 is substring in shuffled form of str2 as 
	str2 = “hello” + “fourtwoone” + “world” 
	str2 = “hello” + str1 + “world”, where str1 = “fourtwoone” (shuffled form) 
	Hence, str1 is a substring of str2 in shuffled form.

	Input: str1 = “roseyellow”, str2 = “yellow” 
	Output: NO 

	*/


	string str1;
	string str2;

	cin>>str1>>str2;

	int m = str1.length();
	int n = str2.length();

	// if(check(str1,str2,m,n)){
	// 	cout<<"YES"<<endl;
	// }
	// else{
	// 	cout<<"NO"<<endl;
	// }

	// learn how to effictively convert string to char array 
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";

	if(fast_check(str1,str2)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}


	return 0;
}