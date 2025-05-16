#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second



class Solution {
public:
    int minDeletion(string s, int k) {
        map<char, int> mp;
        for(int i = 0; i < sz(s); i++){
            mp[s[i]]++;
        }

        auto cmp = [](pair<char, int> a, pair<char, int> b){
            return a.s < b.s;
        };

        vector<pair<char, int>> se(mp.begin(), mp.end());
        sort(all(se), cmp);
        if(sz(se) <= k)return 0;
        int ans = 0;
        int si = sz(se);
        for(const auto &[a, b] : se){
            if(si > k)si--;
            else{break;}
            ans += b;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.minDeletion("yyyzz", 1); //1
}