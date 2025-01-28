#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int n = 234;
    set<string, greater<string>> emails;
    for(int i = 0; i < 234; i++){
        string email;
        cin >> email;
        emails.insert(email);
    }
    for(auto em : emails){
        if(!(em.substr(0, 2) == "24" && em.substr(em.find("@") + 1) == "wwprsd.org")){
            cout << em << endl;
        }
    }
}
