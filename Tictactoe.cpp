#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
int grid[3][3];
bool end = false;
int check(){
    for(int i = 0; i < 3; i++){
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != 0){
            return grid[i][0];
        }
        if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != 0){
            return grid[0][i];
        }
    }
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] != 0){
        return grid[0][0];
    }
    if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[1][1] != 0){
        return grid[1][1];
    }
    bool draw = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == 0){
                draw = false;
            }
        }
    }
    if(draw){
        return 0;
    }
    return -1;
}
void display(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            string letter = "_";
            if(grid[i][j] == 1){
                letter = "X"; 
            }
            else{
                letter = "O";
            }
            cout << letter << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            grid[i][j] = 0;
        }
    }
    // cout << check();
    cout << "Enter your moves like \n 1 3"; 
    while(true){
        cout << "Enter your move";
        int x, y;
        cin >> x >> y;
        grid[x-1][y-1] = 1;
        cout << "After Your Turn\n";
        cout << "Ai is thinking";
        display();
        for(int i = 0; i < 3; i++){
            sleep(1);
            cout << ".";
        }
        cout << endl;
        playOptimalMove();
        display();
        if(check() != -1){
            cout << "Game Over\nWinner: Player" + check() << endl;
            break; 
        }
    }
}
