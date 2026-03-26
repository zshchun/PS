#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	if (s == "NLCS")
		cout << "North London Collegiate School\n";
	else if (s == "BHA")
		cout << "Branksome Hall Asia\n";
	else if (s == "KIS")
		cout << "Korea International School\n";
	else if (s == "SJA")
		cout << "St. Johnsbury Academy\n";
	return 0;
}
