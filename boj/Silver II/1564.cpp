#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define endl "\n"
#define INF 123456789
ull sum;
void remove_zero() {
	while (sum) {
		int x = sum % 10;
		if (x != 0)
			break;
		sum /= 10;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ull i, N;
	cin >> N;
	sum = 1;

	for (i=2;i<=N;i++) {
		sum = sum * i;
		remove_zero();
		sum %= 1000000000000;
	}
	remove_zero();

	cout << setfill('0') << setw(5) << (sum % 100000) << endl;

	return 0;
}
