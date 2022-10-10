#include <iostream>

using namespace std;

static void binaryPrint(int n);
static void numbers(string prefix, int k);

int main(){
    binaryPrint(27);
    cout << endl;
    numbers("00101", 3);
    return 0;
}

static void binaryPrint(int n){
    if(n == 1){
        cout << 1;
        return;
    }
    binaryPrint(n/2);
    cout << n%2;
}

static void numbers(string prefix, int k){
    if(k == 0){
        cout << prefix << endl;
        return;
    }
    numbers(prefix + '0', k-1);
    numbers(prefix + '1', k-1);
}


