#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ull A, B, i, j;
	cin >> A >> B;
	j = gcd(A, B);

	for (i=0;i<j;i++) {
		cout << '1';
	}
	cout << endl;
	return 0;
}
