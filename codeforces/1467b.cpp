#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"

ll a[300001], n;
int ishill(int i) {
	if (i <= 0 || i >= n-1)
		return 0;
	if ((a[i-1] < a[i] && a[i] > a[i+1]) || (a[i-1] > a[i] && a[i] < a[i+1]))
		return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, ans=0;
	cin >> T;
	while(T--) {
		cin >> n;
		int ans, s=0;
		for (i=0;i<n;i++)
			cin >> a[i];
		for (i=1;i<n-1;i++)
			s += ishill(i);
		ans = s;
		for (i=1;i<n-1;i++) {
			int v = ishill(i-1) + ishill(i) + ishill(i+1);
			int t = a[i];

			a[i] = a[i-1];
			int v1 = ishill(i-1) + ishill(i) + ishill(i+1);
			ans = min(ans, s - v + v1);

			a[i] = a[i+1];
			int v2 = ishill(i-1) + ishill(i) + ishill(i+1);
			ans = min(ans, s - v + v2);
			a[i] = t;
		}
		cout << ans << endl;
	}
	return 0;
}
