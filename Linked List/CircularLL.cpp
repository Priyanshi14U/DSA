#include<iostream>

using namespace std;

struct CLLnode {
    int data;
    struct CLLnode *next;
};
struct CLLnode *head=NULL;

struct CLLnode *insertAtBeginning(int data);
struct CLLnode *insertAtLast(int data);
void deleteAtBegin();
void deleteAtEnd();

struct CLLnode *insertAtBeginning(int data){
    struct CLLnode *newnode, *temp;
    newnode = (struct CLLnode *) malloc(sizeof(struct CLLnode));
    temp = head;
    newnode->next=newnode;
    newnode->data=data;
    if(head==NULL){
        head=newnode;
    }
    else{
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
        
    }
    return head;
}

struct CLLnode *insertAtLast(int data){
    struct CLLnode *newnode, *temp;
    newnode = (struct CLLnode *) malloc(sizeof(struct CLLnode));
    temp = head;
    newnode->next=newnode;
    newnode->data=data;
    if(head==NULL){
        head=newnode;
    }
    while(temp->next!=head){
        temp = temp->next;
    }
    newnode->next=head;
    temp->next=newnode;
    
    return newnode;
}

void deleteAtBegin(){
    struct CLLnode *temp;
    temp = head;
    if(head==NULL){
        cout<<"Empty list!"<<endl;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    free(head);
    head=temp->next;
    return;
}

void deleteAtEnd(){
    struct CLLnode *temp;
    temp = head;
    if(head==NULL){
        cout<<"Empty list!"<<endl;
        return;
    }
    while(temp->next->next!=head){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=head;
}

void display(){
    struct CLLnode *temp;
    temp=head;
    if(head==NULL){
        cout<<"Empty";
    }
    else{
        cout<<"Head->";
    while(temp->next!=head){
        cout<<"("<<temp<<")["<<temp->data<<" next-"<<temp->next<<"]"<<"->";
        temp=temp->next;
    } 
    cout<<"("<<temp<<")["<<temp->data<<" next-"<<temp->next<<"]"<<"->";
    cout<<endl;
    }
    
}

int main() {
  int choice =0,fuck=2; 
  struct CLLnode *v; 
    while(choice != 9)   
    {  
         
        cout<<"Enter your choice?"<<endl;         
        cin>>choice;  
        switch(choice)  
        {  
            case 1:  
                v=insertAtBeginning(6);    
                cout<<v->data<<" printed"<<endl;
                break;  
            case 2:  
                 v=insertAtLast(2);
                 cout<<v->data<<" printed"<<endl;
                 break;  
            case 3:  
                deleteAtBegin();
                cout<<"Node Deleted!"<<endl;
                break;  
            case 4:  
                deleteAtEnd(); 
                cout<<"Node Deleted!"<<endl;
                break;  
            case 5:  
                display();        
                break; 
            case 6:
                exit(0); 
            default:  
            cout<<"Please enter valid choice.."<<endl;  
        }  
    }  
    return 0;
}
