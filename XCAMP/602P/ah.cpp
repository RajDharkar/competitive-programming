#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

struct Edge{
    ll a, b, w;
};
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, m, w;
        vector<Edge> ed;
        cin >> n >> m >> w;
        for (ll i = 0; i < m; i++) {
            ll x, y, z;
            cin >> x >> y >> z;
            x--; 
            y--;
            ed.push_back((Edge){x, y, z});
            ed.push_back((Edge){y, x, z});
        }
        for (ll i = 0; i < w; i++) {
            ll x, y, z;
            cin >> x >> y >> z;
            x--; 
            y--;
            ed.push_back((Edge){x, y, -z});
        }
        vi dis(n, (ll)1e18);
        dis[0] = 0;
        for(ll i = 0; i < n-1; i++){
            for(int l = 0; l < sz(ed); l++){
                Edge e = ed[l];
                if(dis[e.a] != 1e18 && dis[e.b]> dis[e.a] + e.w){
                    dis[e.b] = dis[e.a] + e.w;
                }
            }
        }
        bool works = 1;
        for(int l = 0; l < sz(ed); l++){
            Edge e = ed[l];
            if(dis[e.a] != 1e18 && dis[e.b]> dis[e.a] + e.w){
                dis[e.b] = dis[e.a] + e.w;
                works=0;
            }
        }
        cout << (!works ? "YES" : "NO") << '\n';
    }
}