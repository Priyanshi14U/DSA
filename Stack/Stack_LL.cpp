#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Stack{
  struct Node *top;
};

struct Stack *createStack(){
    struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
    if(!S){
        return NULL;
    }
    S->top=NULL;
    return S;
}

void push(struct Stack *S,int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if(!temp){
        cout<<"Overflow"<<endl;
        return;
    }
    temp->data=data;
    temp->next=S->top;
    S->top=temp;
    cout<<temp->data<<"Pushed!"<<endl;
    return;
}

int main(){
    int choice=1,data;
    struct Stack *stk = createStack();
    while(choice!=0){
        cout<<"Enter the choice: ";
        cin>>choice;
        switch(choice){
            case 0:
                exit(1);
            case 1:
                cout<<"Enter number: ";
                cin>>data;
                push(stk,data);
                break;
            default:
                cout<<"Enter valid choice!";
                break;
        }
    }
    return 0;
}