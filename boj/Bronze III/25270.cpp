#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ll N, D1, D2;
	cin >> N;
	D1 = (N % 100) + 1;
	D2 = 99 - (N % 100);
	if (N < 100)
		cout << 99 << endl;
	else if (D1 < D2)
		cout << N - D1 << endl;
	else
		cout << N + D2 << endl;
	return 0;
}
