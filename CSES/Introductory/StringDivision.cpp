#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = int(s.size());
    sort(s.begin(), s.end());
    vector<string> ans;
    do{
        // cout << s << endl;
        ans.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    sort(ans.begin(), ans.end());
    cout << int(ans.size()) << endl;
    for(auto x : ans){
        cout << x << endl;
    }

}