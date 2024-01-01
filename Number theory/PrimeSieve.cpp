#include<bits/stdc++.h>
using namespace std;

void primeprint(long long prime[]){
	prime[2] = 1;
	prime[0] = prime[1] = 0;
		//marking along long odds as prime
	for(long long i = 3 ; i < 100000 ; i+=2){
		prime[i] = 1;	
	}
	for(long long i = 3 ; i <= 100000 ; i+=2){	
		if(prime[i]){ 
			for(long long j = i*i ; j <=100000 ; j += 2*i){
				prime[j] = 0;
			}
		}
	}
}

int main(){	
	long long n;
	cin >> n;
	
	long long prime[100000] = {0};

	primeprint(prime);

	for (long long i = 0; i <= n; ++i){
		if(prime[i] == 1){
			cout << i <<" ";
		}
		/* code */
	} 
	return 0;
}	
