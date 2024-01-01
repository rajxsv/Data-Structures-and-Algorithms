#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct fun {
        int stock;
        int stock_orders;
        int profit;
        int worth_stock;
        int worth_order;
    }  f ;


void input(){
    printf("Current stock : %d worth %d Rupees\nEnter the initial Stock and price of each stock :\n ",f.stock,f.worth_stock);
    scanf("%d %d",&f.stock,&f.worth_stock);
    printf("Enter your order for stock and the price of each :\n");
    scanf("%d %d",&f.stock_orders,f.worth_order);
    printf("\n");
}   
void check(){
    if(f.stock_orders>f.stock){
        f.stock += (f.stock_orders - f.stock);
        printf("Quantity Restocked to the value required");
    }
    else{
        f.stock -= f.stock_orders;
        printf("Transaction successful\nThe Stock Has been updated");
        
    }
    printf("\n");
    
}
void profit(){
    if(f.stock*f.worth_stock > f.worth_stock*f.stock_orders){
        f.profit = f.stock*f.worth_stock - f.worth_stock*f.stock_orders;
        printf("We had a profit of %d",profit);
    }
    else if (f.stock*f.worth_stock == f.worth_stock*f.stock_orders){
        printf("There was neither profit nor loss , net transaction = 0");
    }
    else{
        printf("We had a loss of %d",(f.stock*f.worth_stock - f.worth_stock*f.stock_orders));
    }
    printf("\n");
}
int main(){
    struct fun f = {0,0,0,0,0};
    printf("<--------------------Welcome to this mini store management system!!-------------------->");
    input();
    check();
    profit();
    return 0;

}