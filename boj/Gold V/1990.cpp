#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a, b;
int q[12];

void palindrome(int x, int s, int n) {
	int i;
	if (s >= n) {
		if (x < a || x > b)
			return;
		for (i=2;i<=sqrt(x);i++) {
			if (x % i == 0)
				return;
		}
		cout << x << endl;
		return;
	}
	if (n % 2 == 1 && s == n / 2) {
		for (i=0;i<=9;i++) {
			q[s] = i;
			palindrome(x * 10 + i, s + 1, n);
		}
	} else if (s >= n / 2) {
		q[s] = q[n-1-s];
		palindrome(x * 10 + q[s], s + 1, n);
	} else {
		for (i=0;i<=9;i++) {
			if (x == 0 && i == 0) continue;
			q[s] = i;
			palindrome(x * 10 + i, s + 1, n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> a >> b;
	for (i=1;i<=8;i++) {
		palindrome(0, 0, i);
	}
	cout << "-1\n";

	return 0;
}
