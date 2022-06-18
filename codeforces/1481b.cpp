#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        ll T, i, j, k, x, ans;
        cin >> T;
        while(T--) {
                cin >> n >> m;
                vector<ll> a(n);
                ans = 0;
                for (i=0;i<n;i++) {
                        cin >> a[i];
                }
		bool ok = true;
		while (m && ok) {
			ok = false;
			for (i=1;i<n;i++) {
				if (a[i-1] < a[i]) {
					a[i-1]++;
					m--;
					ok = true;
					break;
				}
			}
		}
		if (m > 0)
			cout << "-1\n";
		else
			cout << i << endl;
        }
        return 0;
}
