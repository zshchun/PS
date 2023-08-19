#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define NR_INT_BITS (8 * sizeof(int))
int bitmap[(1<<25) / NR_INT_BITS];

inline bool getbit(int n) {
	return (bitmap[n / NR_INT_BITS] >> (n % NR_INT_BITS)) & 1;
}

inline void setbit(int n) {
	bitmap[n / NR_INT_BITS] |= 1 << (n % NR_INT_BITS);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x;
	unordered_set<int> s;
	while (cin >> x) {
		if (!getbit(x)) {
			setbit(x);
			cout << x << ' ';
		}
	}
	cout << endl;
	return 0;
}
