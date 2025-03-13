#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int a[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n, s, k;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> a[i];
	cin >> s;

	for (i=0;i<n-1 && s;i++) {
		k = i;
		for (j=i;j < n && j <= i+s;j++) {
			if (a[j] > a[k])
				k = j;
		}
		for (j=k;j>i;j--) {
			swap(a[j-1], a[j]);
			s--;
		}
	}

	for (i=0;i<n;i++)
		cout << a[i] << ' ';

	return 0;
}
