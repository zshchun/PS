#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MAX 100000000

bool is_prime(int n) {
	for (int i=2;i<=sqrt(n);i++) {
		if ((n % i) == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j, k;
	vector<int> a[10];

	cin >> N;
	a[1].push_back(2);
	a[1].push_back(3);
	a[1].push_back(5);
	a[1].push_back(7);

	for (i=2;i<9;i++) {
		for (int &x : a[i-1]) {
			for (j=0;j<=9;j++) {
				k = x * 10 + j;
				if (is_prime(k)) {
					a[i].push_back(k);
				}
			}
		}
	}

	for (int &x : a[N]) {
		cout << x << endl;
	}

	return 0;
}
