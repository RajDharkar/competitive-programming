#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll removeDigits(ll number, int i1, int i2, int i3, int i4, int totalDigits) {
    ll result = 0;
    ll factor = 1;
    for (int i = 0; i < totalDigits; ++i) {
        if (i != i1 && i != i2 && i != i3 && i != i4) {
            result += (number % 10) * factor;
            factor *= 10;
        }
        number /= 10;
    }
    return result;
}

int countValidNumbers(ll number, ll b) {
    int count = 0;
    string numStr = to_string(number);
    int len = numStr.size();

    // Iterate over all possible combinations of removing 4 digits
    for (int i1 = 0; i1 < len; ++i1) {
        for (int i2 = i1 + 1; i2 < len; ++i2) {
            for (int i3 = i2 + 1; i3 < len; ++i3) {
                for (int i4 = i3 + 1; i4 < len; ++i4) {
                    ll newNum = removeDigits(number, i1, i2, i3, i4, len);
                    if (newNum != 0 && newNum < b) {
                        ++count;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string a, b;
        cin >> a >> b;
        
        if (a.size() > 12) a = a.substr(0, 12);
        
        if (b.size() > 8) b = b.substr(0, 8);
        
        ll int_b = stoll(b);
        
        ll int_a = stoll(a);
        
      
        int result = countValidNumbers(int_a, int_b);

        if (a.size() > 8) a = a.substr(0, 8);
        ll x = stoll(a);
        if(x < int_b) {
            result++;
        }
        cout << result << endl;
    }

    return 0;
}
