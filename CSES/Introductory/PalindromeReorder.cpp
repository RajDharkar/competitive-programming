#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    string s;
    cin >> s;

    map<char, ll> count;

    for(int i = 0; i < int(s.size()); i++){
        count[s[i]]++;
    }
    vector<pair<ll, ll>> a;
    vector<pair<ll, ll>> b;
    for(const auto& [x, y] : count){
        if(y%2){
            a.push_back({y, x});
        }
        else{
            b.push_back({y, x});
        }
    }

    for(const auto& [x, y] : b){
        a.push_back({x, y});
    }
    deque<char> ans;
    bool k=1;
    for(const auto& [y, x] : a){
        // cout << char(x) << " " << y << endl;
        if(y%2!=0 && !k){
            cout << "NO SOLUTION";
            return 0;
        }
        else if(y%2){
            for(int i = 0; i < y; i++)
                ans.push_back(x);
            k=0;
        }
        else{
            for(int i = 0; i < y/2; i++){
                ans.push_back(x);
                ans.push_front(x);
            }
        }
    }
    for(auto x : ans){
        cout << x;
    }
}