#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {

    long long n;
    cin >> n;
    long long number = 0;
    for(long long i = 1; i <= n; i = i + 1){
        number = number + 1;
    }
    cout << number;
}
