#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

bool a[246913];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, i, j, ans;

    a[1] = 1;

    for (i=2;i*i<=2*123456;i++) {
        for (j=i*2;j<=2*123456;j+=i) {
            a[j] = 1;
        }
    }

    cin >> n;
    while (n != 0) {
        ans = 0;
        for (i=n+1;i<=2*n;i++) {
            if (!a[i])
                ans++;
        }
        cout << ans << endl;
        cin >> n;
    }

    return 0;
}
