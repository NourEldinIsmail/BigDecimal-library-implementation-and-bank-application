#include <iostream>

using namespace std;

template<class t>

class Array
{
    private:
        t *ptr;
        int sz;
    public:
        Array(int n);
        Array(Array<t>& rhs){
            sz = rhs.size();
            ptr = new t[sz];
            for(int i = 0; i < sz; i++){
                ptr[i] = rhs[i];
            }
        }
        ~Array();
        int size();
        t& operator[] (int k);
        Array& operator= (Array& rhs);
        void tamam(){
            if(sizeof(ptr)/sizeof(ptr[0]) == sz){
                cout << "tamam" << endl;
            }
            else{
                cout << "msh tamam" << endl;
            }
        };

};


int main(){
    Array<int> arr1(2);
    arr1[0] = 1;
    cout << arr1[1] << endl;
    Array<int> arr2(arr1);
    arr1 = arr2;
    cout << arr2[1] << endl;
    arr1.tamam();
    return 0;
}

template<class t>

Array<t>::Array(int n){
    sz = n;
    ptr = new t[n];
}


template<class t>

Array<t>::~Array(){
    delete[] ptr;
}

template<class t>

int Array<t>::size(){
    return sz;
}

template<class t>

t& Array<t>::operator[] (int k){
    if(k < sz){
        return ptr[k];
    }
}

template<class t>

Array<t>& Array<t>::operator= (Array& rhs){
    if(this != &rhs){
        delete[] ptr;
        ptr = new t[rhs.size()];
        for(int i = 0; i < rhs.size(); i++){
            ptr[i] = rhs[i];
        }
        sz = rhs.size();
    }
    return *this;
}