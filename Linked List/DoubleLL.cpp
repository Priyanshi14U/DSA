#include<iostream>

using namespace std;

struct DLLnode{
    int data;
    struct DLLnode *next;
    struct DLLnode *prev;
};
struct DLLnode *head = NULL;

struct DLLnode *insertAtBeginning(int data);
struct DLLnode *insertAtLast(int data);
struct DLLnode *insertAtPosition(int data,int pos);
void deleteAtBegin();
void deleteAtEnd();
void deleteAtPos(int pos);
void search(int ele);
void display();

struct DLLnode *insertAtBeginning(int data){
  struct DLLnode *prev, *next, *newnode;
  newnode = (struct DLLnode *)malloc(sizeof(struct DLLnode));
  newnode->data = data;
  if(head==NULL){
    newnode->next = NULL;
    newnode->prev = NULL;
    head=newnode;
  }
  else{
    head->prev=newnode;
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
  }
  return head;
}

struct DLLnode *insertAtLast(int data){
    struct DLLnode *newnode,*temp;
    newnode = (struct DLLnode *)malloc(sizeof(struct DLLnode));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    temp=head;
    
    if(head==NULL){
        
        head=newnode;
        cout<<"Insert at 1st ";
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        if(temp->next==NULL){
            newnode->prev=temp;
            temp->next=newnode;
        }else{
            cout<<"Not able to insert at last";
        }
    }
    return head;
}

struct DLLnode *insertAtPosition(int data,int pos){
    struct DLLnode *newnode,*temp;
    int curpos=1;
    newnode = (struct DLLnode *)malloc(sizeof(struct DLLnode));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    temp=head;
    if(pos<=1){
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        return head;
    }
    else{
        while(curpos!=pos && temp->next!=NULL){
            curpos++;
            temp=temp->next;
        }
        if(curpos==pos){
           newnode->prev=temp->prev;
           temp->prev->next=newnode;
           temp->prev=newnode;
           newnode->next=temp;
           return head;
        }
        else{                               
            cout<<"Position not found!!";
            //free(newnode);
            return temp;
        }
    }
    
}

void deleteAtBegin(){
    struct DLLnode *temp;
    if(head==NULL){
        cout<<"already empty";
    }
    else{
        temp=head;
        head->next->prev=NULL;
        head=head->next;
        free(temp);
    }
}

void deleteAtEnd(){
    struct DLLnode *temp;
    if(head==NULL){
        cout<<"already empty";
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        if(temp->next==NULL){
            temp->prev->next=NULL;
            free(temp);
        }
    }
}

void deleteAtPos(int pos){
    struct DLLnode *temp;
    int curpos=1;
    temp=head;
    if(pos<=1){
        head=head->next;
        head->prev=NULL;
        return;
    }
    while(curpos!=pos && temp->next!=NULL){
        curpos++;
        temp=temp->next;
    }
    if(curpos==pos){
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
        return;
    }
    else{
        cout<<"Position not found";
        return;
    }
}

void search(int ele){
    struct DLLnode *temp;
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

void display(){
    struct DLLnode *temp;
    temp=head;
    if(head==NULL){
        cout<<"Empty";
    }
    else{
        cout<<"Head->";
    while(temp!=NULL){
        cout<<"("<<temp<<")[ prev-"<<temp->prev<<" "<<temp->data<<" next-"<<temp->next<<"]"<<"->";
        temp=temp->next;
    } 
    cout<<endl;
    }
}

int main(){
    int choice=0,fuck=2; 
    struct DLLnode *v; 
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
                search(4);         
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
}
