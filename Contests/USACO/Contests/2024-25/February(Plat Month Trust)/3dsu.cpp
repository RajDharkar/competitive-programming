#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
// vector<int> p;
// vector<int> s;

// int find(int node){
//     if(p[node] == node){
//         return node;
//     }
//     return p[node] = find(p[node]);
// }

// int size(int node){
//     return s[find(node)];
// }

// void unite(int l, int q){
//     //cout << l << " " << q << endl;
//     int pA = find(l); 
//     int pB = find(q);
//     //cout << pA << " " << pB << endl;
//     if(pA == pB)return;
//     if(s[pA] < s[pB]){
//         p[pA] = pB;
//         s[pB] += s[pA];
//     }
//     else{
//         p[pB] = pA;
//         s[pA] += s[pB];
//     }

// }
typedef long long ll;
int n, m;
vector<vector<int>> adjm;
int edge_count(pii edge){
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(i != edge.first && i != edge.second){
            ret += !adjm[edge.first][i];
        }
    }return ret;
}

int main(){
    cin >> n >> m;
    // cout << n << m << endl;
    // p.resize(n);
    // iota(p.begin(), p.end(), 0);
    // s.resize(n, 1);
    adjm.resize(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        int a, b;
     cin >> a >> b;
        adjm[a-1][b-1]=1;
        adjm[b-1][a-1]=1;

        //cout << a << b << endl;
        // unite(a-1, b-1);
        //cout << a << b << endl;
    }
    //for(auto y : p)cout << y << endl;
    // for(auto x : s)cout << x << endl;
    // vector<int> allsizes;
    // for(int i = 0; i < n; i++){
    //     if(i==find(i))allsizes.push_back(i);
    // }

    // for(const auto& x : allsizes)cout << x << endl;


    //OK SO HEAR ME OUT AM I THE GOAT FOR THIS
    int ans = m;
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int awef = edge_count({i, j}) + edge_count({j, i}); //do i also have to do edgecount(i, j? maybe)
            a=0;
            for(int k = 0; k < n; k++){
                for(int l = k+1; l < n; l++){
                    if(k!=i && k!=j && l!=i && l!=j){ //william lin ah editorial using "and"
                        if(adjm[k][l]){
                            a++;
                        }
                    }
                }
            }
            b = awef+ a+!adjm[i][j];
            c =  awef+ +a+adjm[i][j];
            //cout << a <<" " << b <<" "<< c << endl;
            ans = min(ans, min(b, c));
        }
    }
    cout << ans << endl;

}