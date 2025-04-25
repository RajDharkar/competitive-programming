#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    vector<ll> arr(7);
    for(auto &x : arr)cin >> x;

    sort(all(arr));
    ll biggest = arr[6];
    ll smallest = arr[0];
    ll secondsmallest = arr[1];

    ll c = biggest - smallest - secondsmallest;

    cout << smallest << " " << secondsmallest << " " << c;
}

