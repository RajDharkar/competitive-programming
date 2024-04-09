#include <string>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
string danceCommand(string word, vector<int> shifts) {
    ll sum = 0;
    string ret = "";
    int n = int(shifts.size());
    for(int i = 0; i < shifts.size(); i++){
        sum+=shifts[i];
    }
    int k = int(word.size());
    sum%=int(word.size());
    char ans[k];
    for(int i = 0; i < k; i++){
        ans[i] = word[(i-sum + k)%k];
        // cout << ans[i];
    }
    for(int i = 0; i < k; i++){
        string b = string(1, ans[i]);
        ret.append(b);
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        string word;
        cin >> word;
        int length;
        cin >> length;
        string line;
        vector<int> shifts;
        shifts.resize(length);
        for (int i = 0; i < length; i++) {
            std::cin >> shifts[i];
        }
        std::cout << danceCommand(word, shifts) << std::endl;

    }
}