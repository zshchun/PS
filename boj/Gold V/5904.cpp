#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll N, x, y;

void divide(int n, int k, int sz) {
	if (n <= 3) {
		if (n == 1)
			cout << "m\n";
		else
			cout << "o\n";
		exit(0);
	}
	ll new_sz = sz * 2 + (k + 3);
	if (new_sz < n) {
		divide(n, k+1, new_sz);
	} else if (n > sz && n <= sz + k + 3) {
		if (n - sz == 1)
			cout << "m\n";
		else
			cout << "o\n";
		exit(0);
	} else {
		divide(n - sz - k - 3, 1, 3);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	divide(N, 1, 3);

	return 0;
}
