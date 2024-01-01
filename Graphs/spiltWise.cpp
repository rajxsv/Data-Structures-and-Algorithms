#include <iostream>
#include <set>

using namespace std;

/*
	So we have a group of people owing each other money , so how do we go one deciding 
	how many transactions do we need?

	well thats the question

		1. We first decide to make a total credit and debit list
		2. then we say that the highest debiter gives the highest crediter 
		3. our goal is to make net 0 for everyone we keep moving one while doing this
		4. maxHeap or multiset can be used 
			a. Insertion in multiset take logn time


	making of entire graph is not needed
*/




int main(){

	int noOffriends,friends;
	cin>>noOffriends>>friends;

	int x,y,amount;

	// one d array to store the net amount of each person will havee to take at the end

	int net[100000]={0};

	while(noOffriends--){
		cin>>x>>y>>amount;

		net[x]-=amount;  	//x giving this much money
		net[y]+=amount;		// y recieving that much amount
	
	}

	multiset<int> m;


	for(int i=0;i<friends;i++){
		if(net[i]!=0){
			m.insert(net[i]);
		}
	}

	// pop out 2 persons from left and right and try to settle them
	int transactions = 0;
	while(!m.empty()){
		auto low = m.begin();
		auto high = prev(m.end());
		// high--; this works idk that prateek guy said to use prev as it is not applicable


		int debit = *low;
		int credit = *high;  //these are the limits of credit and debit for this operation

		//we  have to remove them as we will add them after modifying if needed
	
		m.erase(low);
		m.erase(high);

		int settlement = min(-debit,credit); 

		debit += settlement;
		credit -= settlement;

		if(debit!=0){
			m.insert(debit);
		}
		//we did not put else because at last we will have both pair zero
		if(credit!=0){
			m.insert(credit);
		}

		transactions++; //each pair is a transactions
	}

	cout<<transactions<<endl;

	return 0;
}