#include <iostream>

using namespace std;



//-------------DEFINE NODE-----------------//
struct Node{
  int data;
  struct Node *next;
};
struct Node *head = NULL;


//------------DECLARATION OF CODE-------------------------//

struct Node *insertAtBeginning(int data);
struct Node *insertAtLast(int data);
struct Node *insertAtPosition(int data, int pos);
void display();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtPos();
void search();


//---------------DIMAK PKAU FUNCTIONALITIES------------------//

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

void deleteAtBegin() {
    struct Node *temp;
    if(head==NULL)
    {
        cout<<"Linked List empty!";
    }
    else{
        temp = head;
        head = head->next;
        free(temp); 
    return;
    }
}

void deleteAtEnd() {
    struct Node *temp,*prev;
    prev=head;
    temp=head->next;
    if(head==NULL)
    {
        cout<<"Linked list empty";
    }
    while(temp->next!=NULL){
            temp=temp->next;
            prev=prev->next;
        }
        prev->next=NULL;
        free(temp);
    return;
}

void deleteAtPos(int pos){
    struct Node *temp,*prev;
    int curpos=1;
    if(pos<=1){
        if(head!=NULL){
          temp=head;
        head=head->next;
        free(temp);  
        }
        else{
            cout<<"Yha kuch nhi milega";
        }
    }
    else{
        temp=head;
        while(curpos!=pos && temp!=NULL){
            prev=temp;
            temp=temp->next;
            curpos++;
        }
        if(curpos==pos){
            prev->next=temp->next;
            free(temp);
        }
        else{
            cout<<"Node not found, Aee jaa ree";
        }
    }
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

void search(int ele){
    struct Node *temp;
    temp=head;
    while(temp!=NULL){
        if(temp->data==ele){
            cout<<"Element found";
        }
        temp=temp->next;
    }
    if(temp==NULL && temp->data!=ele){
        cout<<"Element nhi mila";
    }
}

int main() {
  int choice =0,fuck=2; 
  struct Node *v; 
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
            case 2:  
                 v=insertAtLast(6);
                 cout<<v->data<<" printed"<<endl;
                 break;  
            case 3:  
                v=insertAtPosition(5,2);
                cout<<v->data<<" printed"<<endl;
                break;  
            case 4:  
                deleteAtBegin();       
                break;  
            case 5:  
                deleteAtEnd();        
                break;  
            case 6:  
                deleteAtPos(2);          
                break;  
            case 7:
                cout<<"enter your dimak pkau number";
                 search(fuck);         
                break;  
            case 8:  
                display();        
                break; 
            case 9:
                exit(0); 
            default:  
            cout<<"Please enter valid choice.."<<endl;  
        }  
    }  
    return 0;
}
