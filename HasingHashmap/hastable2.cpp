#include<iostream>
#include "hashtable.h"

using namespace std;

int main(){

    hashtable<int> price_menu;

    price_menu.insert("Burger",120);
    price_menu.insert("Pizza",100);
    price_menu.insert("Noodles",90);
    price_menu.insert("Spring Roll",45);
    price_menu.insert("Cake",70);
    price_menu.insert("Pastry",20);
    price_menu.insert("Chicken",150);
    price_menu.insert("Dosa",69);

    price_menu.print();

    int* price = price_menu.search("Burger"); // ! this is &burger

    if(price == NULL){
        cout<<"Not Found"<<endl;
    }else{
        cout<<"Price is "<<(*price)<<endl;
    }

    price_menu.erase("Burger");
    price_menu.print();

    cout<<price_menu["Dosa"]<<endl;
    
    price_menu["Dosa"] = 20;  // ! we need to return the reference to the box in the table
                            // 
    cout<<price_menu["Dosa"]<<endl;
    return 0;
}