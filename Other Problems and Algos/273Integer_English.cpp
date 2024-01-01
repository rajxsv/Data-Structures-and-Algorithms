#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> one = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
vector <string> two = {"","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninty"};

string convert(int n){
	if(n>=1000000000){  //billion
		return convert(n/1000000000) + " Billion" + convert(n%1000000000);
	}
	if(n>=1000000){  //million
		return convert(n/1000000) + " Million" + convert(n%1000000);
	}
	if(n>=1000){   //thousand
		return convert(n/1000) + " Thousand" + convert(n%1000);
	} 
	if(n>=100){		//hundred
		return convert(n/100) + " Hundred" + convert(n%100);
	}

	if(n>19){
		return " "+two[n/10]  + convert(n%10);
	}
	if(n>=1){
		return " " + one[n];
	}
	return "";
}

int main(){	
	int n;
	cin>>n;

	cout<< convert(n).substr(1);
	return 0;
}
