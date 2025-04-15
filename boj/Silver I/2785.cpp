#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, ans = 0;
	cin >> n;
	if (n == 2) {
		cout << "1\n";
		return 0;
	}

	deque<int> a(n);
	for (i=0;i<n;i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	while (a.size() > 1) {
		int last = a.back();
		a.pop_back();
		a.back() += last;
		ans++;
		a[0]--;
		if (a[0] == 0)
			a.pop_front();
	}

	cout << ans << endl;
	return 0;
}
