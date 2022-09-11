#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[225];
int n[50001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j;
	cin >> N;
	for (i=1;i<=223;i++) {
		a[i] = i*i;
		n[i*i] = 1;
	}

	for (i=2;i<=50000;i++) {
		int mn = 9999;
		for (j=1;j<=223;j++) {
			if (i-a[j] < 0) break;
			mn = min(mn, n[i-a[j]]+1);
		}
		n[i] = mn;
	}
	cout << n[N] << '\n';
	return 0;
}

