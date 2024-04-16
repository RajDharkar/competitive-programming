#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <climits>
using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!
typedef pair<int, int> pii;
// vectors
// oops size(x), rbegin(x), rend(x) need C++17

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
int n;
int grid[10][10];
bool visited[10][10];
pii dir[] = {{0,-1}, {-1,0}, {1,0}, {0,1}};
bool dfs(int i, int j){
    if(i >= n || j >= n || i < 0 || j < 0){
        return false;
    }
    if(visited[i][j]){
        return false;
    }
    visited[i][j] = true;
    // cout << i << " " << j << endl;
    if(grid[i][j] == 2)
        return true;
    for(int pair = 0; pair < 4; pair++){
        int x = i + dir[pair].first;
        int y = j + dir[pair].second;
        //cout << x << " " << y << endl;
        if(x >= n || y >= n || x < 0 || y < 0){
            continue;
        }
        if(!visited[x][y] && grid[x][y] != 0){
          //  cout << "Here" << x << " " << y << endl;
            if(dfs(x, y)){
                return true;
                break;
            }
        }
    }
    return false;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    int startX, startY;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            char a = s[j];
            if(a == 'S'){
                grid[i][j] = 1;
                startX = i;
                startY = j;
            }
            else if(a == 'x'){
                grid[i][j] = 0;
            }
            else if(a == '.'){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 2; 
            }
        }
    }
    
    bool ans = dfs(startX, startY);
    ans ? cout << "YES" : cout << "NO";
	// read read read
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

