#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class LabelGenerator{
protected:
    string lab;
    int length;
public:
    LabelGenerator(string s, int i){
        lab = s;
        length = i;
    }
    virtual string nextLabel(){
        length++;
        return lab+to_string(length-1);
    }
};

class FileLabelGenerator:public LabelGenerator{
private:
    string filename;
    fstream f;
public:
    FileLabelGenerator(string s, int k, string file):LabelGenerator(s, k){
        filename = file;
        f.open(filename, ios::in);
    }
    string nextLabel(){
        string s;
        getline(f, s);
        length++;
        return lab+to_string(length-1) + ": " + s;
    }
};

int main() {
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
            cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
            cout << pointNumbers.nextLabel() << ", ";
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
            cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl;
    FileLabelGenerator figureLabels("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for(int i = 0; i < 3; i++){
        cout << figureLabels.nextLabel() << endl;
    }
    return 0; 
}