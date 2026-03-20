#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
int ans = INF;
string name;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int temp;
	string s;
	while (cin >> s >> temp) {
		if (temp < ans) {
			ans = temp;
			name = s;
		}
	}
	cout << name << endl;
	return 0;
}
