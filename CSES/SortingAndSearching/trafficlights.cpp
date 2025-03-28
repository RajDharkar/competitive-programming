#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);      

    ll x, n;
    cin >> x >> n;
    ll ans = x;
    set<ll> llervals;
    llervals.insert(0);
    llervals.insert(x);
    multiset<ll> answers;
    answers.insert(x);
    while(n--){
        ll k;
        cin >> k;
        llervals.insert(k);
        auto it = llervals.lower_bound(k);
        ll mid = *it;
        it--;
        ll lo = *it;
        it++;it++;
        ll hi = *it;
        answers.erase(answers.find(hi-lo)); //only erase one occurance
        // cout << lo << " " << mid << " " << hi << endl;
        answers.insert(hi-mid);
        answers.insert(mid-lo);
        cout << *answers.rbegin() << endl;
    }
}

