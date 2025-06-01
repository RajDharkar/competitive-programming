#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);  

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vvi vector<vi>
#define res(x, n) (x).resize(n)
ll dx[] = {0, 1, 0, -1}; 
ll dy[] = {1, 0, -1, 0};

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        ll n=sz(classroom);
        ll m = sz(classroom[0]);
        pii start = {-1,-1};
        vector<pii> pos; ll k=0;
        map<pii, ll> cc;
        for(ll j = 0; j < sz(classroom); j++){
            string x = classroom[j];
            for(ll i = 0; i < sz(x); i++){
                if(x[i] == 'S'){
                    start = {j, i};
                    // break;
                } else if(x[i] == 'L'){
                    pos.pb({j, i}); k++;
                    cc[pos.back()] = sz(pos)-1;
                }
            }
        }
        assert(start.f != -1);
        auto func = [&]() -> ll {
            queue<tuple<ll, ll, ll, ll, ll>> q;
            set<tuple<ll, ll, ll, ll>> vis;

            q.push({start.f, start.s, energy, 0, 0});
            vis.insert({start.f, start.s, energy, 0});

            while (!q.empty()) {
                auto [x, y, e, mask, dep] = q.front(); 
                q.pop();
                if(mask==(1<<k)-1)return dep;
                if (e == 0&&classroom[x][y]!='R')continue;
                for (ll d=0; d<4; d++) {
                    ll nx = x + dx[d];
                    ll ny = y +dy[d];
                    if(nx < 0|| ny < 0 || nx >= n || ny >= m)continue;
                    
                    char ch = classroom[nx][ny];
                    if (ch == 'X') continue;
                    if (((ch == 'R') ? energy : e - 1)< 0) continue;
                    ll nmask = mask;
                    if (ch == 'L') {
                        auto it = cc.find({nx, ny});
                        if (it != cc.end()){
                            nmask |= (1<<it->s);
                        }
                    }
                    auto pq = make_tuple(nx, ny,(ch == 'R' ? energy : e-1), nmask);
                    if (vis.count(pq)) continue;
                    vis.insert(pq);
                    q.push({nx, ny, (ch == 'R' ? energy : e-1), nmask, dep+1});
                }
            }
            return -1;
        };
        return func();
    }
};

// int main(){
//     Solution s;
//     ll n, e;
//     cin >> n >> e;
//     vector<string> arr(n);
//     for(auto &x : arr)cin >> x;
//     cout << s.minMoves(arr, e); //ans
// }