#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAX_SIZE = 1e5 + 5;

int vertices, edges;
int degree[MAX_SIZE];

int main() {
    scanf("%d %d", &vertices, &edges);

    while (edges--) {
         int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        ++degree[temp1];
        ++degree[temp2];
    }

   

    int f = 1;
    for (int i = 1; i <= vertices; ++i) {
        if (degree[i] % 2) {
            f = 0;
            break;
        }
    }

    if (f)
        puts("YES");
    else
        puts("NO");

    return 0;
}
