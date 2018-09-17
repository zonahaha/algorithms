#include <iostream>
#include <vector>
//for istringstream
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;
int versionCmp(const string& v1, const string& v2) {
	istringstream iss1(v1);
	istringstream iss2(v2);
	while (1) {
		long long version1, version2;
		char c;
		iss1 >> version1;
		iss2 >> version2;
		if (version1 > version2) {
			return 1;
		}
		if (version1 < version2) {
			return -1;
		}
		if (iss1.eof() && iss2.eof()) {
			break;
		}
		if (iss1.eof()) {
			return -1;
		}
		if (iss2.eof()) {
			return 1;
		}
		iss1 >> c;
		iss2 >> c;
	}
	return 0;
}
int main() {
	string v1, v2;
	while (cin >> v1 >> v2) {
		cout << versionCmp(v1, v2) << endl;
	}
	return 0;
}
