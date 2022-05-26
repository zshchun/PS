#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, R, B, s1, s2, m1, m2;
	cin >> T;
	while(T--) {
		cin >> R;
		m1 = 0; s1 = 0;
		for (i=0;i<R;i++) {
			cin >> j;
			s1 += j;
			if (s1 > m1) m1 = s1;
		}
		cin >> B;
		m2 = 0; s2 = 0;
		for (i=0;i<B;i++) {
			cin >> j;
			s2 += j;
			if (s2 > m2) m2 = s2;
		}
		cout << m1+m2 << '\n';
	}
	return 0;
}
