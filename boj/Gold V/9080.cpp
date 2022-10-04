#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, hh, mm, duration, start, end, ans;
	cin >> T;
	char c;
	while (T--) {
		cin >> hh >> c >> mm;
		cin >> duration;
		ans = 0;
		start = hh * 60 + mm + 120;
		end = start + duration;
		while (start < end) {
			j = start % 1440;
			if (j >= 0 && j <= 300 && end-start >= 300) {
				ans += 5000;
				start = start - (start%1440) + 600;
			} else {
				start += 60;
				ans += 1000;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
