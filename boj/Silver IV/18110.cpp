#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	double total = 0;
	cin >> n;
	double skip = round(n * 0.15);

	if (n == 0) {
		cout << "0\n";
		return 0;
	}
	for (i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);

	for (i=skip;i<n-skip;i++)
		total += a[i];

	double ans = round(total / (n-skip*2));

	cout << ans << endl;

	return 0;
}
