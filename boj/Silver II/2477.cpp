#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int k;
vector<pa> a;
int mx[2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, n, ans;
	cin >> n;
	for (i=0;i<6;i++) {
		cin >> j >> k;
		j--;
		if (j == 0) j = 3;
		else if (j == 3) j = 0;
		a.push_back(pa(j, k));
		mx[j%2] = max(mx[j%2], k);
	}

	ans = mx[0] * mx[1] * n;
	for (i=0;i<6;i++)
		if (a[(i+1)%6].first == (a[i].first + 3) % 4)
			ans -= a[i].second * a[(i+1)%6].second * n;

	cout << ans << endl;
	return 0;
}
