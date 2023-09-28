#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a, b;
bool composite[10000001];
int q[12];

bool is_palindrome(int x) {
	int i, n = 0;
	while(x) {
		q[n++] = x % 10;
		x /= 10;
	}
	for (i=0;i<n/2;i++) {
		if (q[i] != q[n-i-1]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> a >> b;
	int e = sqrt(b);
	for (i=2;i<=e;i++) {
		if (composite[i]) continue;
		for (j=i*i;j<=min(b, 10000000);j+=i) {
			if (composite[i]) continue;
			composite[j] = 1;
		}
	}

	for (i=a;i<=b;i++) {
		if (i >= 10000000) break;
		if (!composite[i] && is_palindrome(i))
			cout << i << endl;
	}

	cout << "-1\n";

	return 0;
}
