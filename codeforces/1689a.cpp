#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, l, r, ans;
	cin >> T;
	while(T--) {
		cin >> n >> m >> k;
		ll la = 0, lb = 0;
		string a, b;
		cin >> a >> b;
		i = 0;
		j = 0;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		while (i < a.size() && j < b.size()) {
			if (lb >= k) {
				cout << a[i++];
				lb = 0;
				la++;
			} else if (la >= k) {
				cout << b[j++];
				la = 0;
				lb++;
			} else if (a[i] < b[j]) {
				cout << a[i++];
				lb = 0;
				la++;
			} else {
				cout << b[j++];
				la = 0;
				lb++;
			}
		}
		cout << endl;
	}
	return 0;
}
