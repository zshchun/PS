#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MAX_NUM 1100

int n;
int a[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, sum = 0;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> a[i];

	sort(a, a + n);

	for (i=0;i<n;i++) {
		if (a[i] > sum + 1)
			break;
		sum += a[i];
	}

	cout << sum + 1 << endl;
	return 0;
}
