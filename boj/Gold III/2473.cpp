#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567891234ULL

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, N, l, sum, r, mn = INF;
	ll ans[3];
	cin >> N;
	vector<ll> a(N);
	for (i=0;i<N;i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	for (i=0;i<N-2;i++) {
		l = i + 1;
		r = N - 1;
		while (l < r) {
			sum = a[i] + a[l] + a[r];
			if (mn > abs(sum)) {
				mn = abs(sum);
				ans[0] = i;
				ans[1] = l;
				ans[2] = r;
			}
			if (sum < 0)
				l++;
			else
				r--;
		}
	}
	cout << a[ans[0]] << ' ' << a[ans[1]] << ' ' << a[ans[2]] << endl;

	return 0;
}
