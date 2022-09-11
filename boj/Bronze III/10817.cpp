#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int a;
	cin >> a;
	v.push_back(a);
	cin >> a;
	v.push_back(a);
	cin >> a;
	v.push_back(a);
	sort(v.begin(), v.end());
	cout << v[v.size()-2] << '\n';
	return 0;
}

