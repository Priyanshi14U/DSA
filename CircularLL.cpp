#include<iostream>

using namespace std;

struct CLLnode {
    int data;
    struct CLLnode *next;
};
struct CLLnode *head=NULL;

struct CLLnode *insertAtBeginning(int data);
struct CLLnode *insertAtLast(int data);

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
        newnode->next=head;
        temp->next=newnode;
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
            // case 3:  
            //     v=insertAtPosition(5,2);
            //     cout<<v->data<<" printed"<<endl;
            //     break;  
            // case 4:  
            //     deleteAtBegin();       
            //     break;  
            // case 5:  
            //     deleteAtEnd();        
            //     break;  
            // case 6:  
            //     deleteAtPos(2);          
            //     break;  
            // case 7:
            //     cout<<"enter your dimak pkau number";
            //      search(fuck);         
            //     break;  
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
