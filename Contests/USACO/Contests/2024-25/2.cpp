#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll modexp(ll b, ll e) {
    ll res = 1 % MOD;
    b %= MOD;
    while(e){
        if(e & 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return res;
}

ll modInv(ll x){ return modexp(x, MOD-2); }

struct Interval {
    ll l, r;
    int val;
};

struct IntervalComp {
    bool operator()(const Interval &a, const Interval &b) const {
        return a.l < b.l;
    }
};

int main(){
    ll N; int M, Q;
    cin >> N >> M >> Q;
    set<Interval, IntervalComp> S;
    S.insert({1, N, 0});
    for(int i=0;i<M;i++){
        ll L, R; cin >> L >> R;
        auto it = S.lower_bound({L+1,0,0});
        if(it != S.begin()) it--;
        vector<decltype(it)> rem;
        vector<Interval> add;
        while(it!=S.end()){
            if(it->l>R) break;
            if(it->r < L){ it++; continue; }
            rem.push_back(it);
            Interval cur = *it;
            if(cur.l < L) add.push_back({cur.l, L-1, cur.val});
            ll nl = max(cur.l, L), nr = min(cur.r,R);
            add.push_back({nl, nr, 1 - cur.val});
            if(cur.r > R) add.push_back({R+1,cur.r, cur.val});
            it++;
        }
        for(auto &it2: rem) S.erase(it2);
        for(auto &iv : add){
            auto it2 = S.lower_bound(iv);
            if(it2!=S.begin()){
                auto prev = it2; prev--;
                if(prev->r+1==iv.l && prev->val==iv.val) { iv.l = prev->l; S.erase(prev); }
            }
            it2 = S.lower_bound(iv);
            if(it2!=S.end()){
                if(iv.r+1==it2->l && it2->val==iv.val){ iv.r = it2->r; S.erase(it2); }
            }
            S.insert(iv);
        }
    }
    vector<pair<ll,ll>> ones;
    for(auto &iv:S) if(iv.val==1) ones.push_back({iv.l,iv.r});
    for(int qi=0;qi<Q;qi++){
        ll L, R, k; cin >> L >> R >> k;
        ll Tlen = R - L + 1;
        ll cnt = 0;
        vector<pair<ll,ll>> blocks;
        int nOnes = ones.size();
        int lo = 0, hi = nOnes-1, startIndex = nOnes;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(ones[mid].second>=L){ startIndex = mid; hi = mid-1; }
            else lo = mid+1;
        }
        for(int i=startIndex;i<nOnes;i++){
            if(ones[i].first > R) break;
            ll A = max(ones[i].first, L), B = min(ones[i].second, R);
            blocks.push_back({A,B});
            cnt += (B-A+1);
        }
        if(cnt >= k){
            ll ans = (modexp(2,k) - 1) % MOD;
            if(ans<0) ans += MOD;
            cout << ans % MOD << "\n";
            continue;
        }
        ll ans = 0, r0 = 0;
        for(auto &blk: blocks){
            ll A = blk.first, B = blk.second, seglen = B - A + 1;
            ll X = A - L + 1;
            ll crit = (A - L + k - Tlen);
            if(r0 >= crit){
                ll pterm = modexp(2, k - r0);
                ll dterm = (1 - modInv(modexp(2, seglen))) % MOD;
                if(dterm < 0) dterm += MOD;
                ll sumBlock = (pterm * dterm) % MOD;
                ans = (ans + sumBlock) % MOD;
            } else {
                ll fterm = modexp(2, Tlen - X + 1);
                ll dterm = (1 - modInv(modexp(2, seglen))) % MOD;
                if(dterm < 0) dterm += MOD;
                ll sumBlock = (fterm * dterm) % MOD;
                ans = (ans + sumBlock) % MOD;
            }
            r0 += seglen;
        }
        ans %= MOD;
    }
    return 0;
}