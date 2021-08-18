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

int isEmpty(struct Stack *S){
    return (S->top==NULL);
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
    cout<<temp->data<<" pushed!"<<endl;
    return;
}

void pop(struct Stack *S){
    if(isEmpty(S)){
        cout<<"Underflow";
        return;
    }
    cout<<S->top->data<<" popped!"<<endl;
    S->top=S->top->next;
    // free(S->top);
    return;
}

void peek(struct Stack *S){
    if(isEmpty(S)){
        cout<<" Empty Stack ";
        return;
    }
    cout<<S->top->data<<" on top of stack"<<endl;
}

void size(struct Stack *S){
    int count=0;
    if(isEmpty(S)){
        cout<<"Empty Stack! ";
        return;
    }
    while(S->top){
        count++;
        S->top=S->top->next;
    }
    cout<<count<<endl;
    cout<<"Size of the Stack is "<<count<<endl;
}

void deleteStack(struct Stack *S){
    if(isEmpty(S)){
        cout<<"Empty Stack! ";
        return;
    }
    // while(S->top!=NULL){
    //     S->top=S->top->next;
    //     free(S->top);
    //}
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
            case 2:
                pop(stk);
                break;
            case 3:
                peek(stk);
                break;
            case 4:
                size(stk);
                break;
            case 5:
                deleteStack(stk);
                break;
            default:
                cout<<"Enter valid choice!";
                break;
        }
    }
    return 0;
}
