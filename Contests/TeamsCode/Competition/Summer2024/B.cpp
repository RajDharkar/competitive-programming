#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            grid[i][j] = s[j];
        }
    }
    pii direc[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'H'){
                bool counted = false;
                for(pii dir : direc){
                    int count = 0;
                    for(int k = 1; k <= 5; k++){
                        int x = i + dir.first * k;
                        int y = j + dir.second * k;
                        if(x >= 0 && x < n && y >= 0 && y < m){
                            if(grid[x][y] == 'L'){
                                count++;
                            }
                        }
                    }
                    if(count >= 2){
                        ans++;
                        counted = true;
                        //cout << i << " " << j << endl;
                        break; // Found a valid direction, no need to check further
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
