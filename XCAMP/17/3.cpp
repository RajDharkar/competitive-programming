#include <bits/stdc++.h>

using namespace std;

struct Person {
    int a, b, c;
};

bool cmp(Person x, Person y) {
    if (x.b == y.b) {
        return x.a > y.a;
    }
    return x.b < y.b;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i];
    }
    vector<Person> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i].a >> p[i].b >> p[i].c;
    }

    sort(p.begin(), p.end(), cmp);

    vector<int> psum(n, 0);
    for (int i = 1; i < n; i++) {
        psum[i] = psum[i - 1] + edges[i - 1]; 
    }

    //1 2 3

    // for (int i = 0; i < n; i++) {
    //     cout << "psum[" << i << "] = " << psum[i] << endl;
    // }
    // for(Person x : p){
    //     cout << x.a << " " << x.b << " " << x.c << endl;
    // }
    vector<int> diff(n);
    for(int i = 0; i < m; i++){
        Person per = p[i];
        per.b--;
        per.c--;
        //diff[per.a];
        diff[per.b]++;
        diff[per.c]--;

    }
    // for(int i =0; i < n; i++){
    //     cout << diff[i] << " ";
    // }
   // cout << endl;
    vector<int> data(n-1);
    int val = 0;
    for(int i = 0; i < n; i++){
        val += diff[i];
        data[i] = val;
    }
    
    // for(int i = 0; i < n-1 ; i++){
    //     cout << data[i] << " ";
    // }
    // cout << endl;
    //[0, 0]
    //[0, 0, 0]
    //1 3

    // int sub = 0;
    // for(int i = 1; i < n; i++){
        // int one = data[i-1];
        // int two = one * edges[i-1] - one * k; 
        // if(one * k > two){
            // sub = max(sub, two);
        // }
        // else{
            // sub = max(one * k, two);
        // }
    // }

    // cout << sub << endl;
    int curspot = -1;
    int curtime = 0;
    int count = 0;
    for(int i = 0; i < m; i++){
        if(p[i].b != curspot){
           // cout << curtime << " " << p[i].a << endl;
            count += max(p[i].a-curtime, 0);
            curtime += p[i].a;
            curtime += edges[i];
            curspot = p[i].b;
        }
    }

    
    
    for(int i = 1; i < n; i++){
        int one = diff[i-1] - diff[i]; //2
        count += one * edges[i-1];
        //cout << one * edges[i-1] << endl;
    }



    // cout << count << endl;
    // cout << count << endl;
    cout << count << endl;
}  
