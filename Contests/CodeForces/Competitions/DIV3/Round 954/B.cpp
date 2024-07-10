#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <climits>
using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string;     // yay python!

// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

int main()
{
    // read read read
    int t;
    cin >> t;
    vector<pi> ni = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        while (true)
        {
            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (found){
                    break;
                }
                for (int j = 0; j < m; j++)
                {
                    int num = arr[i][j];
                    bool works = true;
                    int cer = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int row = ni[k].f + i;
                        int col = ni[k].s + j;
                        if (row >= n || row < 0 || col >= m || col < 0){
                            continue;
                        }
                        if (arr[row][col] >= num){
                            works = false;
                            break;
                        }
                        else{
                            cer = max(cer, arr[row][col]);
                        }
                    }
                    if (works)
                    {
                        arr[i][j] = cer;
                        found = true;
                        break;
                    }
                }
            }
            if (!found){
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
