#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define f first
#define s second
#define sz(x) (int)(x).size()
int grid[101][101];
ll ans = 0;
int n, k, r; //Cows, Locations of Cows, 
bool visited[101][101];
struct vector_hash {
    template <class T>
    size_t operator()(const std::vector<T>& vec) const {
        size_t seed = vec.size();
        for (const auto& elem : vec) {
            seed ^= std::hash<T>{}(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
unordered_set<vector<int>, vector_hash> blocks;
vector<pii> cows;
pii directions[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void floodfill(int i, int j){
    if(i > n || i <= 0 || j <= 0 || j > n || visited[i][j]){
        return;
    }
    if(grid[i][j] == 1){
        ans++;
    }
    visited[i][j] = true;
    for(int a = 0; a < 4; a++){
        int x = i + directions[a].f;
        int y = j + directions[a].s;
        bool works = true;
        if(blocks.count({{i, j, x, y}}) != 0){
            works = false;
        }
        if(blocks.count({{x, y, i, j}}) != 0){
            works = false;
        } 
        if(works){
            floodfill(x, y);
        }
    }
}
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
    setIO("countcross");
    cin >> n >> k >> r;
    cows.resize(k);
    for(int i = 0; i < r; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        blocks.insert({{a, b, c, d}});
    }
    for(int i = 0; i < k; i++){
        cin >> cows[i].f >> cows[i].s;
        grid[cows[i].f][cows[i].s] = 1; //COW HERE
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 101; j++){
            for(int k = 0; k < 101; k++){
                visited[j][k] = false;
            }
        }
        floodfill(cows[i].f, cows[i].s);
        ans--;
    }
    //cout << ans/2 << endl;
    cout << (k*(k-1)/2) - ans/2 << endl;

}
