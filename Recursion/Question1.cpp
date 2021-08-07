#include<iostream>

using namespace std;

void countinghead(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    countinghead(n-1);
    
}
void countingtail(int n){
    if(n==0){
        return;
    }
    countingtail(n-1);
    cout<<n<<endl;
}
int factorial(int n){
    if(n==1){
        return 1;
    }
    return (n*factorial(n-1));
}
int fibo(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibo(n-1)+fibo(n-2); 
}

void getdigit(int n){
    if(n<=0){
        return;
    }
    getdigit(n/10);
    n=n%10;
    cout<<n<<endl;
}

int exp(int n,int a){
	int x;
	if(n==0){
		return 1;
	}
	
	x=exp(n/2,a);
	if(n%2==0){
		return x*x;
	}
	else{
		return a*x*x;
	}
}

bool sortarray(int arr[10],int i){
	if(arr[i]==arr[4]){
		return true;
	}
	if(arr[i]<arr[i-1]){
		return false;
	}
	sortarray(arr,i+1);
}

int main(){
    cout<<"Enter a number: ";
    int n,i=0,fact,fibos,s,a,expo,arr[10]={2,3,4,5};
    cin>>n;
    cout<<"Print counting : "<<endl;
    countinghead(n);
    cout<<"Print counting reverse : "<<endl;
    countingtail(n);
    cout<<"Factorial of "<<n<<endl;
    fact = factorial(n);
    cout<<fact<<endl;
    cout<<"Fibonaci series till "<<n<<endl;
    fibos = fibo(n);
    cout<<fibos<<endl;
    cout<<"Enter the number for digit split: ";
    cin>>s;
    getdigit(s);
	cout<<"Enter the base of exponent: ";
	cin>>a;
    expo = exp(n,a);
    cout<<expo<<endl;
    cout<<sortarray(arr,i)<<endl;
    return 0;
}
