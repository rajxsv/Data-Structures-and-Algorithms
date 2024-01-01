#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> one = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
vector <string> two = {"","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninty"};

string convert(int n){

	return two[n/10] + " " + one[n%10];
}

int main(){

	int n = 999999 ;
	string res="";

	if(n/100000){
		res+= convert(n/100000) + " Lakh ";
	}
	if((n/1000)%100 ){
		res+= convert((n/1000)%100) + " Thousand ";
	}
	if((n%100)/10 && n>99){
		res+= convert((n%100)/10) + " Hundred ";
	}
	
	res+= convert(n%100) + " ";


	cout << res <<endl;

	return 0;
}