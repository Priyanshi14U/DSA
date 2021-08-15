#include<iostream> 
 
using namespace std; 
 
struct Stack{ 
    int top; 
    int capacity; 
    int *array; 
}; 
 
 
struct Stack *createStack(int capacity){ 
    struct Stack *S=(struct Stack*)malloc(sizeof(struct Stack)); 
    if(!S){ 
        return NULL; 
    } 
    S->capacity=capacity; 
    S->top=-1; 
    S->array=(int *)malloc(S->capacity*sizeof(int)); 
    if(!S->array){ 
        return NULL; 
    } 
    return S; 
} 
 
int isFull(struct Stack *S){ 
    return (S->top==S->capacity-1); 
} 

int isEmpty(struct Stack *S){
    return (S->top==-1);
}
 
void push(struct Stack *S,int data){
    if(!S){
        cout<<"Stack already deleted";
        return;
    }
    else{
        if(isFull(S)){ 
        cout<<"Overflow"<<endl; 
        return; 
        } 
        S->top++; 
        S->array[S->top]=data; 
        cout<<data<<" pushed!"<<endl; 
        return;
    }
     
} 
 
int pop(struct Stack *S){
    if(!S){
        cout<<"Stack already deleted";
        return -1;
    }
    else{
        if(isEmpty(S)){
        cout<<"Underflow"<<endl;
        return -1;
        }
        cout<<"Element deleted : "<<S->array[S->top]<<endl;
        S->top--;
        return S->array[S->top];
    }
    
}

int peek(struct Stack *S)
{
    if(!S){
        cout<<"Stack already deleted";
        return -1;
    }
    else{
        if(isEmpty(S)){
            return -1;
        }
        return S->array[S->top];
    }
    
}

void deleteStack(struct Stack *S){
    if(S){
        if(S->array){
            free(S->array);
        }
        free(S);
        cout<<"Stack Deleted "<<endl;
    }
    return;
}
 
int main(){ 
    int choice=1,capacity=15,capacity2=20,n,pet; 
    struct Stack *stk=createStack(capacity); 
    
    
    while(choice!=0){
        cout<<"Enter your choice: "; 
        cin>>choice;
        switch(choice){ 
        case 0:
            exit(1);
            break;
        case 1: 
            cout<<"Enter your number : ";
            cin>>pet;
            push(stk,pet);
            break; 
        case 2: 
            pop(stk);
            break;
        case 3:
            n=peek(stk);
            cout<<"Element at top : "<<n<<endl;
            break; 
        case 4:
            deleteStack(stk);
            break;
        default: 
        cout<<"Enter valid choice"<<endl; 
        break; 
        } 
    }
    
    return 0; 
}