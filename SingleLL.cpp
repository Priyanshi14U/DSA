#include <iostream>

using namespace std;

struct Node{
  int data;
  struct Node *next;
};
struct Node *head = NULL;

struct Node *insertAtBeginning(int data);
struct Node *insertAtLast(int data);
struct Node *insertAtPosition(int data, int pos);
void display();
void deleteAtBegin();

struct Node *insertAtBeginning(int data){
  struct Node *temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data=data;
  temp->next=NULL;

  if(head==NULL)
  {
    head=temp;
    head->next=NULL;
  }
  else
  {
    temp->next=head;
    head=temp;
  }
  return head;
}

struct Node *insertAtLast(int data){
    struct Node *temp,*cur;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data=data;
  temp->next=NULL;
  cur=head;
  if(cur==NULL)
  {
    head=temp;
  }
  else 
  {
    while(cur->next!=NULL)
      {
        cur=cur->next;
        
      }
    cur->next=temp;
  }
  return head;
}

struct Node *insertAtPosition(int data, int pos){
  struct Node *newnode,*temp;
  int currpos=1;
  newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data=data;
  newnode->next=NULL;
  temp = head;
  if(pos<=1)
  {
      newnode->next = head;
      head = newnode;
      return newnode;
  }
  else{
      while(temp!=NULL && (currpos+1)!=pos){
          temp = temp->next;
          currpos++;
      }
      if((currpos+1)==pos){
          newnode->next=temp->next;
          temp->next=newnode;
          return newnode;
      }
      else{
          cout<<"Position not found!";
          return newnode;
      }
  }
}
void deleteAtBegin(){
    struct Node *temp,**head;
    if(head==NULL)
    {
        cout<<"Linked List empty!";
    }
    temp = *head;
    *head = *head->next;
    free(temp);
    return;
}

void display(){
    struct Node *temp;
    temp=head;
    if(head==NULL){
        cout<<"Empty";
    }
    else{
        cout<<"Head->";
    while(temp!=NULL){
        cout<<"("<<temp<<")["<<temp->data<<" next-"<<temp->next<<"]"<<"->";
        temp=temp->next;
    } 
    cout<<endl;
    }
    
}

int main() {
  int choice =0; 
  struct Node *v;
    // printf("\n\n*********Main Menu*********\n");  
    //     printf("\nChoose one option from the following list ...\n");  
    //     printf("\n===============================================\n");  
    //     printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n"); 
    while(choice != 9)   
    {  
         
        cout<<"Enter your choice?"<<endl;         
        cin>>choice;  
        switch(choice)  
        {  
            case 1:  
                v=insertAtBeginning(4);    
                cout<<v->data<<" printed"<<endl;
                break;  
            // case 2:  
            // lastinsert();         
            // break;  
            case 3:  
                v=insertAtPosition(5,2);
                cout<<v->data<<" printed"<<endl;
                break;  
            case 4:  
                deleteAtBegin();       
                break;  
            // case 5:  
            // last_delete();        
            // break;  
            // case 6:  
            // random_delete();          
            // break;  
            // case 7:  
            // search();         
            // break;  
            case 8:  
            display();        
            break; 
      case 9:
        exit(0); 
            default:  
            cout<<"Please enter valid choice..";  
        }  
    }  
    return 0;
}