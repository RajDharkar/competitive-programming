#include<bits/stdc++.h>

using namespace std;

int main(){
    int dp[9][9] = {0};
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            if((i == 4 || i == 5) && (j == 5 || j == 4)){
                dp[i][j] = 0;
                goto nxt;
            }
            if(i == 1 && j == 1){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            nxt:;
        }
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}