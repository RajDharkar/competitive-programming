#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main() {
    ll t;
    cin >> t;
    while(t--){
       ll n;
       string s;
       cin >> n;
       cin >> s;
       vector<int> st;
       set<int> seen;
        for(int i = 0; i< n; i++){
            if(s[i] == '1'){
                st.pb(i + 1);
            } else if (s[i] == '2') {
                if (!st.empty()) {
                    int k = st.back();
                    st.pop_back();
                    seen.insert(k);
                }else{
                seen.insert(i + 1);
                }
            } else{
                seen.insert(i + 1);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!seen.contains(i + 1)){
                ans.pb(i + 1);
            }
        }
        cout << sz(ans) << '\n';
        if(sz(ans) == 0){
            cout << "\n";
        }
        for(int i = 0; i < sz(ans); i++){
            cout << ans[i] << " \n"[i == sz(ans) - 1];
        }
        st.clear();
    }
}
