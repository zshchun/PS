#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ll N, T, NA, NB, i, j, k, l;
	cin >> N;
	for (l=1;l<=N;l++) {
		vector<tuple<ll,ll,ll>> v;
		cin >> T >> NA >> NB;
		ll count[2] = { 0, 0 };
		ll ans[2] = { 0, 0 };
		string s;
		for (i=0;i<NA;i++) {
			cin >> s;
			j = stoi(s.substr(0, 2));
			k = stoi(s.substr(3, 2));
			v.push_back(make_tuple(j*60+k, 0, +1));
			cin >> s;
			j = stoi(s.substr(0, 2));
			k = stoi(s.substr(3, 2));
			v.push_back(make_tuple(j*60+k+T, 1, -1));
		}
		for (i=0;i<NB;i++) {
			cin >> s;
			j = stoi(s.substr(0, 2));
			k = stoi(s.substr(3, 2));
			v.push_back(make_tuple(j*60+k, 1, +1));
			cin >> s;
			j = stoi(s.substr(0, 2));
			k = stoi(s.substr(3, 2));
			v.push_back(make_tuple(j*60+k+T, 0, -1));
		}
		sort(v.begin(), v.end());
		for (i=0;i<v.size();i++) {
			j = get<1>(v[i]);
			k = get<2>(v[i]);
			count[j] = count[j] + k;
			ans[j] = max(ans[j], count[j]);
		}
		cout << "Case #" << l << ": "<< ans[0] << " " << ans[1] << endl;
	}
	return 0;
}
