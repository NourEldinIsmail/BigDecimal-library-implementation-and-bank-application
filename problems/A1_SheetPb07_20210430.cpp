#include <iostream>

using namespace std;

bool bears(int n);

int main(){
    int n;
    cin >> n;
    if(bears(n)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}

bool bears(int n){
    int tdp = (n%10) * ((n % 100) / 10);
    if(n == 42){
        return true;
    }
    else if(n < 42){
        return false;
    }
    else if(n % 2 == 0 && bears(n/2)){
        cout << n << " gives " << n/2 << endl;
    }
    else if((n%3==0 || n%4==0) && bears(tdp)){
        cout << n << " gives " << tdp << endl;
    }
    else if(n%5 == 0 && bears(42)){
        cout << n << " gives " << 42 << endl;
    }
    else{
        return false;
    }
}