#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF INT32_MAX
int N, ans = INF;
pa p;
vector<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, l, r;
	cin >> N;
	a.resize(N);
	for (i=0;i<N;i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	l = 0;
	r = N-1;
	while (l < r) {
		int diff = abs(a[l] + a[r]);
		if (diff < ans) {
			ans = diff;
			p = pa(a[l], a[r]);
		}
		if (abs(a[l+1] + a[r]) < abs(a[l] + a[r-1]))
			l++;
		else
			r--;
	}
	cout << p.first << ' ' << p.second << endl;
	return 0;
}
