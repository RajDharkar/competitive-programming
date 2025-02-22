#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct DSU{
    vector<ll> tree;
    void init(ll n){
        tree = vector<ll>(n, -1); //all nodes with a size of 1(if its -x its not a "father" and it has a size of x)
    }

    ll find(ll node){
        return tree[node] < 0 ? node : tree[node] = find(tree[node]); //flattening the tree(path compression)
    }

    bool unite(ll p, ll q){
        p = find(p);
        q = find(q);
        if(p == q){
            return false; //nodes are already united
        }

        if(tree[p] < tree[q]){
            swap(p, q); //weird way to do this but now we know that the size of p is greater than the size of q
        }
        tree[p] += tree[q]; //append to the bottom of the node p
        tree[q] = p; //p is now the father of q 
        return true;
    }

    ll size(ll x){
        return -tree[find(x)];
    }

    bool connected(ll p, ll q){
        return find(p) == find(q);
    }
};

bool cmp(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b){
    return a.first > b.first;
}

int main(){
   freopen("wormsort.in", "r", stdin);
   freopen("wormsort.out", "w", stdout);
   // cout << 1 << endl;
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n); //permutation of n
    //vector<bool> off(n, 1);
    ll count = n;
    for(ll i = 0; i < n; i++){
        cin >> p[i];
        //cout << p[i] << " " << i + 1 << endl;
        if(p[i] == i+1){
           // cout << "off";
            // off[i]=0;
            count--;
        }
        p[i]--;
    }
  //  cout << 1 << endl;

    if(count == 0){
        cout << -1;
        return 0;
    }
    //cout << m << endl;
    vector<pair<ll, pair<ll, ll>>> edges(m, {0, {0, 0}});
    for(int i = 0; i < m; i++){
        //int a, b, c;
        //cin >> a >> b >> c;
        //cout << a << " " << b << " " << c << endl;
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        edges[i].second.first--;
        edges[i].second.second--;
    }
 //       cout << 1 << endl;
    //cout << "Sorted";
    sort(edges.begin(), edges.end(), cmp);
    bool finished = false;
// for(ll i = 0; i < m; i++){
    //     cout << edges[i].first << " ";
    // }
    // cout << endl;
   // cout << count << endl;
   
    // vector<int> counttbf;
    // unordered_set<int> seensofar;
    // for(int i=0;i<m;i++){
    //     if(off[edges[i].second.first] || off[edges[i].second.second]){
    //         seensofar.insert(edges[i].second.first);
    //         seensofar.insert(edges[i].second.second);
    //         counttbf.push_back(int(seensofar.size()));
    //     }
    // }
    //int index = 0;
    // for(ll i = 0; i < m; i++){
    //     if(off[edges[i].second.first] || off[edges[i].second.second]){
    //        // cout << edges[i].second.first << " " << edges[i].second.second << endl;;
    //         dsu.unite(edges[i].second.first, edges[i].second.second);
    //         ans = min(ans, edges[i].first);
    //         int size = dsu.size(edges[i].second.first);
    //         cout << size << endl;
    //         cout << counttbf[index] << endl;
    //         if(size == counttbf[index] && size >= count){ //the size >= count is basically a cheese but hopefully i get a couple tc's like this
    //             finished = true;
    //             break;
    //         }
    //         index++;
    //     }
    // }

    // for(int i = 0; i < n; i++){

    // }
    // assert(finished); //cows must be able to have sorted themselves

    //binary search on answer x{uncomment this for working answer}
  //  cout << 1 << endl;
    // ll lo = 0;
    // ll hi = edges[0].first + 1;
    // ll ans = -1;
    // while(lo <= hi){
    //     ll mid = (lo + hi) / 2;
    //  //   cout << mid << endl;
    //     //mid=9;
    //     DSU dsu;
    //     dsu.init(n);
    //     for(int i = 0; i < m; i++){
    //         if(edges[i].first >= mid){
    //             dsu.unite(edges[i].second.first, edges[i].second.second);
    //         }
    //     }
    //    // cout << mid << endl;
    //     bool works = true;
    //     for(int i = 0; i < n; i++){
    //         if(!dsu.connected(i, p[i])){
    //             //cout << i << p[i] << endl;
    //             works = false;
    //             break;
    //         }
    //     }
    //     //cout << works << endl;

    //     if(works){
    //         ans = mid;
    //         lo = mid + 1;
    //     }
    //     else{
    //         hi = mid - 1;
    //     }
    //  //   cout << ans << endl;
    // }
    // cout << ans << endl;
    DSU dsu;
    dsu.init(n);
    ll ans = 0;
    int index = 0;
    for(int i = 0; i < n; i++){
       // cout << i << endl;
        while(!dsu.connected(p[i], i)){
            dsu.unite(edges[index].second.first, edges[index].second.second);
            index++;
        }
    }
    cout << edges[index-1].first;
}