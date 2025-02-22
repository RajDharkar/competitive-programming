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
/*
*      LOGIC:
*    Let's get the basic cleared first: We are creating a graph 
*    with element x having a connection with a-x in set A and with b-x in set B
*    now if we create a graph with connections like above we will end up having multiple connected components
*   Now comes the tricky part; we create and merge these using DSU 
*   initially all are separate nodes and then we merged x , a-x together if there was also b-x it also got merged
*   now how can there be contradiction in this?
*   if we have a component with only elements that are belonging to A or B we can get rid of these elements as 
*   they can be assigned clearly
*   what if there is an element x which can only be in set B but is in the same component as y which can only be in A
*   so we can loop over all the elements at last and match with their set representative if there is contradiction that will be found
*   NOTICE: we wereable to do this because all elements were unique , otherwise it will be complex and we can't directly say
*   there will be a contradiction as we can have multiple x which we can send some in A and some in B.
*/

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    DSU dsu;
    dsu.init(n);
    map<ll, ll> cc;
    for(ll i=0;i<n;i++){cc[p[i]]=i;}
    vector<bool> aworks;
    vector<bool> bworks;
    for(ll i=0;i<n;i++){
        bool one = cc.count(a-p[i]);
        bool two = cc.count(b-p[i]);
        if(one){
            dsu.unite(cc[p[i]], cc[a-p[i]]);
        }
        if(two){
            dsu.unite(cc[p[i]], cc[b-p[i]]);
        }
        aworks.push_back(one);
        bworks.push_back(two);
        //cout << aworks[i] << " " << bworks[i] << endl;
        //cout << cc[p[i]] << " " <<  cc[a-p[i]] << endl;
    }
    vector<ll> comb(n);
    bool works = true;
    for(ll i=0;i<n;i++){
        if(aworks[i] && bworks[i]){
            comb[dsu.find(i)] = 3;
        }
        else if((aworks[i] && !bworks[i])){
            comb[dsu.find(i)] = 1;
        }
        else if((!aworks[i] && bworks[i])){
            comb[dsu.find(i)] = 2;
        }
        else{
            works=false;
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    //for(ll i=0;i<n;i++)cout << dsu.find(i) << endl;
    cout << (comb[dsu.find(0)] != 1);
    for(ll i = 1; i < n; i++){
        cout << " " << (comb[dsu.find(i)] != 1);
    }
    
}