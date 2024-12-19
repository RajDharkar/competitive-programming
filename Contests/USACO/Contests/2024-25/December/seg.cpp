#include <bits/stdc++.h>
using namespace std;

struct ST {
    int sz;
    vector<int> tr;

    ST(int s) {
        sz = s;
        tr.assign(4 * s, 0);
    }

    void b(int n, int s, int e) {
        if (s == e) {
            tr[n] = 1; 
        } else {
            int m = (s + e) / 2;
            b(2 * n, s, m);
            b(2 * n + 1, m + 1, e);
            tr[n] = tr[2 * n] + tr[2 * n + 1];
        }
    }

    void u(int n, int s, int e, int i, int v) {
        if (s == e) {
            tr[n] += v;
        } else {
            int m = (s + e) / 2;
            if (i <= m) {
                u(2 * n, s, m, i, v);
            } else {
                u(2 * n + 1, m + 1, e, i, v);
            }
            tr[n] = tr[2 * n] + tr[2 * n + 1];
        }
    }

    int q(int n, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tr[n];
        int m = (s + e) / 2;
        int left = q(2 * n, s, m, l, r);
        int right = q(2 * n + 1, m + 1, e, l, r);
        return left + right;
    }

    int q(int l, int r) {
        return q(1, 1, sz, l, r);
    }

    void u(int i, int v) {
        u(1, 1, sz, i, v);
    }
};

struct R {
    int a, b, n;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> x(N);
        for (auto &xx : x) cin >> xx;
        vector<pair<long long, int>> sx(N);
        for (int i = 0; i < N; i++) sx[i] = {x[i], i};
        sort(sx.begin(), sx.end());

        vector<long long> xs(N);
        for (int i = 0; i < N; i++) xs[i] = sx[i].first;

        vector<R> rs;

        for (int i = 0; i < K; i++) {
            long long l, r;
            int t;
            cin >> l >> r >> t;

            int ai = lower_bound(xs.begin(), xs.end(), l) - xs.begin() + 1;
            int bi = upper_bound(xs.begin(), xs.end(), r) - xs.begin();

            if (ai > bi) continue;
            int si = bi - ai + 1;
            int ni = max(0, si - t);

            rs.push_back({ai, bi, ni});
        }

        sort(rs.begin(), rs.end(), [](const R &r1, const R &r2) {
            return r1.b < r2.b;
        });

        ST st(N);
        st.b(1, 1, N);

        vector<int> p(N + 1);
        iota(p.begin(), p.end(), 0);

        function<int(int)> f = [&](int u) {
            return p[u] == u ? u : (p[u] = f(p[u]));
        };

        long long rc = 0;

        for (auto &r : rs) {
            int a = r.a;
            int b = r.b;
            int al = r.n;

            int cc = st.q(a, b);
            if (cc > al) {
                int tr = cc - al;
                while (tr > 0) {
                    int pos = f(b);
                    if (pos < a) break;

                    st.u(pos, -1);
                    rc++;
                    p[pos] = pos - 1;
                    tr--;
                }
            }
        }

        cout << (N - rc) << endl;
    }

    return 0;
}
