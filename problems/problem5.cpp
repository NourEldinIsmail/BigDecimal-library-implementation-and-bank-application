#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE1 10
#define SIZE2 20

class GameOfLife{
private:
    bool grid[SIZE1 +2][SIZE2+2] = {{false}};
public:
    GameOfLife(string filename){
        ifstream f(filename);
        for(int i = 1; i < SIZE1 + 1; i++){
            for(int j = 1; j < SIZE2 + 1; j++){
                f >> grid[i][j];
            }
        }
    }
    void display(){
        for(int i = 1; i < SIZE1 + 1; i++){
            for(int j = 1; j < SIZE2 + 1; j++){
                cout << (grid[i][j]? 'L':'D') << ' ';
            }
            cout << endl;
        }

        getchar();
    }
    void nextGen(int i, int t){
        bool tmp[SIZE1+2][SIZE2+2];
        for(int i = 1; i < SIZE1 + 1; i++){
            for(int j = 1; j < SIZE2 + 1; j++){
                tmp[i][j] = grid[i][j];
            }
        }
        for(int i = 1; i < SIZE1 + 1; i++){
            for(int j = 1; j < SIZE2 + 1; j++){
                int cnt = 0;
                if(grid[i-1][j]){
                    cnt++;
                }
                if(grid[i+1][j]){
                    cnt++;
                }
                if(grid[i][j-1]){
                    cnt++;
                }
                if(grid[i][j+1]){
                    cnt++;
                }
                if(grid[i-1][j-1]){
                    cnt++;
                }
                if(grid[i-1][j-1]){
                    cnt++;
                }
                if(grid[i+1][j-1]){
                    cnt++;
                }
                if(grid[i-1][j+1]){
                    cnt++;
                }
                if(grid[i][j] && (cnt < 2)){
                    tmp[i][j] = false;
                }
                else if(grid[i][j] && (cnt == 2 || cnt == 3)){
                    tmp[i][j] = true;
                }
                else if(grid[i][j] && (cnt > 3)){
                    tmp[i][j] = false;
                }
                else if(!grid[i][j] && (cnt == 3)){
                    tmp[i][j] = true;
                }
            }
        }
        for(int i = 1; i < SIZE1 + 1; i++){
            for(int j = 1; j < SIZE2 + 1; j++){
                grid[i][j] = tmp[i][j];
            }
        }
        system("clear");
        cout << "Generation: " << i << '/' << t << endl;
        display();
    }
    void run(int t){
        int i = 0;
        int o = t;
        while(t--){
            i++;
            nextGen(i, o);
            // cout << "Generation: " << i << '/' << o << endl; 

        }
    }
};

int main(){
    GameOfLife game("test.txt");
    game.run(20);
    return 0;
}