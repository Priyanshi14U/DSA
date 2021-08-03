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

void exponent(int a,int b){
	if(b<=1){
		return;
	}
	exponent(a,b-1);
	a= a*a;
	cout<<a;
}
int main(){
    cout<<"Enter a number: ";
    int n,fact,fibos,s=6753,a=3,b;
    cin>>n;
    cin>>b;
    countinghead(n);
    countingtail(n);
    fact=factorial(n);
    fibos=fibo(n);
    cout<<fact<<endl;
    cout<<fibos;
    getdigit(s);
    exponent(a,b);
    return 0;
}
