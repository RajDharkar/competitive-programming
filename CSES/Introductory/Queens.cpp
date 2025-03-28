#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool grid[8][8];
ll ans = 0;
ll ld[15] = {0};
ll rd[15] = {0};
ll r[8] = {0};
void recur(ll row){
    // cout << row << endl;
    if(row == 8){
        ans++;
        return;
    }

    for(ll i = 0; i < 8; i++){
        // cout << i << " " << row << endl;
        //if valid square(i - row + 7)
        if(grid[i][row] && !ld[i-row+7] && !rd[i+row] && !r[i]){
            ld[i-row+7]=1;
            rd[i+row]=1;
            r[i]=1;
            recur(row+1);
            ld[i-row+7]=0;
            rd[i+row]=0;
            r[i]=0;
        }

    }
}

int main(){
    for(ll i = 0; i < 8; i++){
        string s;
        cin >> s;
        for(ll j = 0; j < 8; j++){
            grid[i][j] = s[j]=='.';
        }
    }
    recur(0);
    cout << ans << endl;
}