#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
int n;
vector<int> readVector(int size)
{
    vector<int> t_vector(size);
    for (int i = 0; i < size; i++)
    {
        cin >> t_vector[i];
    }
    return t_vector;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr = readVector(n);
        unordered_set<int> nums;
        for (int a : arr)
        {
            nums.insert(a);
            for (int b : arr)
            {
                if(b > a){
                    nums.insert(b - a);
                }
            }
        }
        int ans = 0;
        for (int a : nums)
        {
            for (int b : nums)
            {
                for (int c : nums)
                {
                    if (a <= b && b <= c)
                    {
                        vector<int> works = {a, b, c, a + b, a + c, b + c, a + b + c};
                        bool possible = true;
                        for (int number : arr)
                        {
                            bool current = false;
                            for (int x : works)
                            {
                                if (x == number)
                                    current = true;
                            }
                            if (!current)
                            {
                                possible = false;
                            }
                        }
                        if (possible)
                        {
                            //cout << a << " " << b << " " << c << endl;
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
