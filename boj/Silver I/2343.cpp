#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int n, m;

int a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, r = 0, l = 0, mid, sum, num;
	cin >> n >> m;
	for (i=0;i<n;i++) {
		cin >> a[i];
		r += a[i];
		l = max(a[i], l);
	}
	while (l <= r) {
		mid = (l+r) / 2;
		sum = 0;
		num = 0;
		for (i=0;i<n;i++) {
			if (sum + a[i] > mid) {
				sum = 0;
				num++;
			}
			sum += a[i];
		}
		if (sum) num++;
		if (num > m) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	cout << l << endl;

	return 0;
}
