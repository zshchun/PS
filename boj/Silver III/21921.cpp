#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll x, n, i, j, k, ans, s;
	cin >> n >> x;
	j = 0;
	k =0;
	ans = 0;
	s = 0;
	vector<ll> arr(n);
	for (i=0;i<n;i++) {
		cin >> arr[i];
	}
	for (i=0;i<n;i++) {
		while (j < n && (j-i) < x) {
			s += arr[j];
			j++;
			if (ans < s) {
				ans = s;
				k = 1;
			} else if (ans == s) {
				k++;
			}
		}
		s -= arr[i];
	}

	if (ans == 0) {
		cout << "SAD\n";
	} else {
		cout << ans << endl;
		cout << k << endl;
	}
	return 0;
}
