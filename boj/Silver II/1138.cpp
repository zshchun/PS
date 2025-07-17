#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, k;
	cin >> n;
	vector<int> a(n);
	vector<int> ans(n);
	for (i=0;i<n;i++)
		cin >> a[i];

	for (i=0;i<n;i++) {
		for (j=0,k=0; j<n && k <= a[i];j++) {
			if (ans[j]) continue;
			if (k == a[i])
				ans[j] = i + 1;
			k++;
		}
	}

	for (int &x : ans)
		cout << x << ' ';
	return 0;
}
