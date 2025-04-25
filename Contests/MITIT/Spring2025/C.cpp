#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;

        priority_queue<int> notused;
        ll p = 1;
        vector<pair<ll, ll>> ans;
        for(ll i = 0; i < n; i++){
            if(s[i] == 'O'){
                if(!notused.empty() && (p + notused.top()) % 2 == 1){
                    ans.pb({p, notused.top()});
                    notused.pop();
                    p++;
                    continue;
                }
                if(p + 1 <= 2*n){
                    if(!notused.empty() && (p+1 + notused.top()) % 2 == 1){
                        ans.pb({p+1, notused.top()});
                        notused.pop();
                        notused.push(p);
                        p+=2;
                        continue;
                    }
                    ans.pb({p, p+1});
                    p+=2;
                    continue;
                }
                if(notused.empty() || (p + notused.top()) % 2 == 0){
                    goto end;
                } 
                ans.pb({p, notused.top()});
                notused.pop();
                p++;
            } else{
                if(!notused.empty() && (p + notused.top()) % 2 == 0){
                    ans.pb({p, notused.top()});
                    notused.pop();
                    p++;
                    continue;
                }
                if(p + 2 <= 2*n){
                    ans.pb({p, p+2});
                    notused.push(p+1);
                    p+=3;
                    continue;
                }
                if(notused.empty() || (p + notused.top()) % 2 != 0){
                    goto end;
                } 
                ans.pb({p, notused.top()});
                notused.pop();
                p++;
            }
        }

        cout<<"YES"<<endl;
        for(auto &[a, b] : ans){
            cout << a << " " << b << endl;
        }
        continue;
        end:;
        cout <<"NO"<<endl;
    }
}

