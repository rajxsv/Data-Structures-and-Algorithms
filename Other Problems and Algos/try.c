#include<stdio.h>
#include<stdlib.h>

//structure creation
struct node
{
  int item;
  struct node* ptr;
};

//function to print linked list
struct node* printlinkedlist(struct node* n)
{
  struct node* temp = n;
  while(n!=NULL){
    printf("%d ",n->item);
    n=n->ptr;
  }
  return temp;
}

//create and delete function
void createlist_and_delete(int a){
  struct node* start=(struct node*)malloc(sizeof(struct node));
  struct node* temp;
  struct node* newnode;
  struct node* n;

      // printf("enter the data for node 1\n");
      int data;
      scanf("%d",&data);
      
      start->item=data;
      start->ptr=NULL;

      temp=start;
        for(int i=1;i<a;i++){
          newnode=(struct node*)malloc(sizeof(struct node));
          int data;
          scanf("%d",&data);
          newnode->item=data;
          newnode->ptr=NULL;
          temp->ptr=newnode;
          temp=temp->ptr;
        }
      // printf("Linked list successfully created.\n");
      start = printlinkedlist(start);
      //deletion at last
      n = start;
      while(n->ptr->ptr!=NULL)
      {
          n = n->ptr;
      }
      free(n->ptr);
      n->ptr = NULL;
      printf("\nDELETION SUCCESSFUL\nNEW LIST:\n");
      start = printlinkedlist(start);
}

//main program
int main()
{
  int n;
  printf("ENTER THE LENGTH OF LINKED LIST TO BE FORMED:\n");
  scanf("%d",&n);
  createlist_and_delete(n);
  return 0;
}