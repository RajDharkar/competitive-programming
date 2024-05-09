#include <bits/stdc++.h>  
using namespace std;
 
typedef long long ll;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define vi vector<int>
#define vp32 vector<p32>
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD %1000000007
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int ll
//never guess
//never debug without reviewing code
//never try adding ones or substracting them
//only step by step debug when necessay

signed main()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    //     #ifdef _WIN32
    //         freopen("input.in", "r", stdin);
    //         freopen("input.out", "w", stdout);
    //     #endif
    // #endif
    string s; cin>>s;
    int n = int(s.size());
    ll res = 0;
    ll cur = 0;
    int last[6]; fill(last,last+6,-1);
    auto t= [&](int i){
        if(last[i-1]!=-1)
        last[i] = last[i-1];
        last[i-1] = -1;
    };
    for (ll i = 0; i < n; i++)
    {
        if(s[i]=='b')
            last[0] = i;
        else if(s[i]=='e'){
            t(5);
            if(last[5]!=-1){
                cur+=last[5]+1;
                last[5] = -1;
            }
            t(1);
        }
        else if(s[i]=='s'){
            t(3);
            t(2);
        }
        else if(s[i]=='i')
            t(4);
        res+=cur;
    }
    cout<<res<<'\n';
    return 0;
}