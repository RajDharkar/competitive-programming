#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool grid[9][9];
string s;
vector<int> ar;
vector<pii> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// ll cd = 0;
int dfs(int r, int c, int depth, int d){
    // cd++;
    if(depth==48 && r==7 && c==1){
        // cout << "Found path to (7, 1) with depth 48!" << endl;
        return 1;
    }
    if(r==7 && c==1){
        return 0;
    }

    if(depth==48){
        return 0;
    }

    if(r>=8 || c>=8 || r<1 || c<1 || grid[r][c]){
        return 0;
    }

    if(d==0 || d==1){
        if((grid[r-1][c] && grid[r+1][c]) && !(grid[r][c+1] || grid[r][c-1])){
            // cout << "HERE" << endl;
            return 0;
        }   
    }
    if(d==2 || d==3){
        if((grid[r][c-1] && grid[r][c+1]) && !(grid[r-1][c] || grid[r+1][c])){
            // cout << "HERE" << endl;
            return 0;
        }  
    } 
    /*
    If the path touches a wall and can turn either left or right, the grid splits
    into two parts that contain unvisited squares. In this case, we cannot visit all
    squares anymore, so we can terminate the search.

    The idea of this can be generalized: if the path cannot continue
    forward but can turn either left or right, the grid splits into two parts that
    both contain unvisited squares. It is clear that we cannot visit all squares
    anymore, so we can terminate the search.
    */

    grid[r][c] = 1;
    // cout << r << " " << c << " " << depth << " " << endl;

    int res = 0;
    if(ar[depth]==-1){
        int ind =0;
        for(const auto& [a, b] : dir){
            int nR = a + r;
            int nC = b + c;
            if(!grid[nR][nC])
            res += dfs(nR, nC, depth+1, ind);  
            ind++; 
        }
    } else {
        int a = dir[ar[depth]].first;
        int b = dir[ar[depth]].second;
        int nR = a + r;
        int nC = b + c;
        if(!grid[nR][nC])
        res += dfs(nR, nC, depth+1, ar[depth]);   
    }

    grid[r][c] = 0;
    return res;
}

int main(){
    // cd=0;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='R')ar.push_back(2);
        if(s[i]=='L')ar.push_back(3);
        if(s[i]=='D')ar.push_back(1);
        if(s[i]=='U')ar.push_back(0);
        if(s[i]=='?')ar.push_back(-1);
    }
    for(int i = 0; i < 9; i++)for(int j = 0; j < 9; j++)grid[i][j]=1;
    for(int i = 1; i < 8; i++)for(int j = 1; j < 8; j++)grid[i][j]=0;

    cout << dfs(1, 1, 0, -1) << endl;
    // cout << cd;
    // cout << "HAOSDHIASD" << endl;

}
