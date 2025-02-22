#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	int i, cnt, k;
	cin.tie(0);
	while (1) {
		cin >> k;
		if (k == 0)
			break;

		vector<int> a(k);
		for (i=0;i<k;i++)
			cin >> a[i];
		sort(a.begin(), a.end());

		vector<int> b(k, 0);
		fill_n(b.begin(), 6, 1);
		do {
			cnt = 0;
			for (i=0;i<b.size();i++) {
				if (b[i]) {
					cout << a[i] << ' ';
					cnt++;
				}
				if (cnt >= 6)
					break;
			}
			cout << "\n";
		} while (prev_permutation(b.begin(), b.end()));
		cout << "\n";
	}


	return 0;
}
