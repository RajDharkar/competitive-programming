#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    // 1 7 3 5 2 6 4 4
    //
    if(n<=2){
        cout << "NO" << endl;
        return 0;
    }
    vector<ll> a, b;
    ll pnter=0;
    for(int i = n; i; i--){
        if(pnter)b.push_back(i);
        else{a.push_back(i);}
        if((n-i+1)%4==1)pnter++;
        if((n-i+1)%4==3)pnter--;
    }
    ll sum=0, tsum=0;
    for(auto &x : a)sum+=x;
    for(auto &x : b)tsum+=x;

    if(sum!=tsum || (sum+tsum != (n*(n+1))/2)){
        cout <<"NO"<<endl;
        return 0;
    }
    cout << "YES" << endl;
    // sort(a.begin(), a.end());
    // sort(b.begin(), b.end());
    cout << ll(a.size()) << endl;
    for(ll i = 0; i < ll(a.size()); i++){
        if(i>0){
            cout << " " << a[i];
        } else{
            cout << a[i];
        }
    }
    cout << endl;
    cout << ll(b.size()) << endl;
    for(ll i = 0; i < ll(b.size()); i++){
        if(i>0){
            cout << " " << b[i];
        } else{
            cout << b[i];
        }
    }
}