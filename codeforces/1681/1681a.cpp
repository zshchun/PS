#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, A, B, m1, m2, v;
	cin >> T;
	while(T--) {
		m1 = 0;
		m2 = 0;
		cin >> A;
		for (i=0;i<A;i++) {
			cin >> v;
			if (m1 < v) m1 = v;
		}
		cin >> B;
		for (i=0;i<B;i++) {
			cin >> v;
			if (m2 < v) m2 = v;
		}
		if (m1 == m2) {
			cout << "Alice\nBob\n";
		} else if (m1 < m2) {
			cout << "Bob\nBob\n";
		} else {
			cout << "Alice\nAlice\n";
		}
	}
	return 0;
}
