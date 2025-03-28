#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    vector<int> freq(N+1, 0);
    set<int> s;
    
    // initialize frequencies and the set
    for (int i = 0; i < N; i++){
        freq[a[i]]++;
    }
    for (int v = 1; v <= N; v++){
        if (freq[v] > 0)
            s.insert(v);
    }
    
    auto answer = [&](){
        if(s.empty())
            return 0; // This case won't really happen since N>=1.
        int mn = *s.begin();
        int mx = *s.rbegin();
        return mx - mn;
    };
    cout << answer() << "\n";
    
    // Process queries.
    while(Q--){
        int idx, x;
        cin >> idx >> x;
        idx--;  
        
        int oldVal = a[idx];
        a[idx] = x;
        
        freq[oldVal]--;
        if(freq[oldVal] == 0){
            s.erase(oldVal);
        }
        if(freq[x] == 0){
            s.insert(x);
        }
        freq[x]++;
        
        cout << answer() << "\n";
    }
    
    return 0;
}
