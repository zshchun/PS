#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans, T;

int eor(int x) {
	if (x % 4 == 3)
		return 0;
	else if (x % 4 == 1)
		return 1;
	else if (x % 4 == 2)
		return x | 1;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, s, f, a, b;
	cin >> T;
	while (T--) {
		cin >> s >> f;
		if (s == f) {
			cout << s << endl;
			continue;
		}
		a = eor(s - 1);
		b = eor(f);
		cout << (a ^ b) << endl;
	}
	return 0;
}
