# include<bits/stdc++.h>


using namespace std;

typedef pair<int, int> pii;
int n, m;
struct Cell{
    int height, i, j;
    bool wtr;
};

bool cmp(Cell a, Cell b){
    if(a.height == b.height){
        return a.i*m+a.j < b.i*m+b.j;
    }
    return a.height < b.height;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<Cell>> grid(n, vector<Cell>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                string s;
                cin >> s;
                grid[i][j].wtr = s[int(s.size()-1)] == 'W';
                grid[i][j].height = stoi(s.substr(0, int(s.size()-1)));
                grid[i][j].i = i;
                grid[i][j].j = j;
            }
        }
        vector<pii> dir = {{-1, 0}, {-1, -1}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        vector<Cell> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bool works = 1;
                for(const auto& [a, b] : dir){
                    int newI = i+a;
                    int newJ = j+b;
                    if(newI >= n || newJ >= m || newI < 0 || newJ < 0)continue;
                    works &= grid[newI][newJ].height >= grid[i][j].height;
                }
                works &= !grid[i][j].wtr;
                if(works)ans.push_back(grid[i][j]);
                // cout << grid[i][j].height << " " << grid[i][j].wtr << " ";
            }
            //cout << endl;
        }
        //cout << ans.size() << endl;
        sort(ans.begin(), ans.end(), cmp);
        for(Cell a : ans){
            cout << a.height << " " << a.i << " " << a.j << endl;
        }
    }
}