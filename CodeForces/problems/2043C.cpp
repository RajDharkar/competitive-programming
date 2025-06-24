// #include<bits/stdc++.h>
// using namespace std;
// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);  

// typedef long long ll;
// typedef pair<ll, ll> pii;

// #define sz(x) ll((x).size())
// #define bg(x) begin(x)
// #define all(x) bg(x), end(x)
// #define pb push_back
// #define f first
// #define s second
// #define vi vector<ll>
// #define vvi vector<vi>
// #define res(x, n) (x).resize(n)

// int main(){
//     ll n;
//     cin >> n;
//     vi ar(n);
//     for(auto &x : ar)cin >> x;
//     // vi pref(n+1);

//     auto func = [](vi arr) -> vi {
//         ll a = 0, b = 0, pref = 0;
//         ll mi=0, mx=0;
//         for(ll z : arr){
//             pref+=z;
//             mi = min({z-b, mi,z-a});
//             mx = max({z-b, mx ,z-a});
//             a = min(a, z);
//             b = max(b, z);
//         }
//         vi ret;
//         for(ll i = mi; i <= mx; i++){
//             ret.pb(arr[i]);
//         }

//         return ret;
//     };
    
//     vi fi;

//     ll ind = 0;
//     for(ll i = 0; i < n; i++){
//         if(ar[i] == -1 || ar[i] == 1){
//             fi.pb(ar[i]);
//         }
//         else{
//             ind = i;
//             break;
//         }
//     }

//     vi sec;
//     for(ll i = ind + 1; i < n; i++){
//         sec.pb(ar[i]);
//     }

//     auto l = func(fi);
//     auto r = func(sec);
//     set<ll> ans;
//     for(auto x : l)ans.insert(x);
//     for(auto x : r)ans.insert(x);

//     // ll p = accumulate(all(ar), 0LL);
//     ll p = 0;
//     for(int i = ind - 1; i >= 0; i--){
//         p += ar[i];
//     }
//     ll mx = *max_element(all(ar));
//     ll mi = *min_element(all(ar));

//     ll c = *max_element(all(sec));
//     ll d = *min_element(all(sec));
//     p = 0;
//     for(auto x : sec){
//         p += x;
//         c = max(c, x);
//         d = max(d, x);
//     }

//     for(ll y= mi+d; y<= mx+c;y++){
//         ans.insert(y+ ar[ind]);
//     }
//         //     ll a=0,b=0,c=0,d=0,x=0;
//         //     for(int i=po-1;i>=0;i--){
//         //         x+=A[i];
//         //         chmax(a,x);
//         //         chmin(b,x);
//         //     }
//         //     x=0;
//         //     for(int i=po+1;i<N;i++){
//         //         x+=A[i];
//         //         chmax(c,x);
//         //         chmin(d,x);
//         //     }
//         //     for(ll y=b+d;y<=a+c;y++){
//         //         ans.pb(y+A[po]);
//         //     }
//         //     //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
//         // }        
// }

