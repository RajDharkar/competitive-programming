#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    for(int j = 0; j < n; j++){
        string s;
        cin >> s;
        for(int i = 0; i < m; i++){
            if(s[i] != '.'){
                grid[j][i] = 1;
            }
            else{
                grid[j][i] = 0;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                bool done = false;
                ans++;
                if(j != m-1){
                    if(grid[i][j+1] == 1){
                        grid[i][j+1] = -1;
                        grid[i][j] = 9;
                        done = true;
                    }
                }
                if(!done && i != n - 1){
                    if(grid[i+1][j] == 1){
                        grid[i+1][j] = 9;
                        grid[i][j] = 9;
                        done = true;
                    }
                }
                grid[i][j] = 9;
                continue;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans;

}
