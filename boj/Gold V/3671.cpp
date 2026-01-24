#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define    MAX 10000000

bool not_prime[10000000];
bool visited[10000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int c, i, j, v, ans;
    not_prime[0] = not_prime[1] = 1;
    for (i=2;i<sqrt(MAX);i++) {
        if (not_prime[i]) continue;
        for (j=i+i;j<MAX;j+=i)
            not_prime[j] = 1;
    }

    string s;
    cin >> c;
    for (i=0;i<c;i++) {
        cin >> s;
        memset(visited, 0, sizeof(visited));
        sort(s.begin(), s.end());
        ans = 0;
        do {
            for (j=1;j<=s.size();j++) {
                int x = stoi(s.substr(0, j));
                if (!visited[x] && !not_prime[x]) {
                    ans++;
                    visited[x] = 1;
                }
            }
        } while (next_permutation(s.begin(), s.end()));
        cout << ans << endl;
    }
    return 0;
}
