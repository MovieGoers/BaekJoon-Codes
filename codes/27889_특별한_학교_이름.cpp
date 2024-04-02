//NLCS: North London Collegiate School
//BHA : Branksome Hall Asia
//KIS : Korea International School
//SJA : St. Johnsbury Academy

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<string, string> map;
	map["BHA"] = "Branksome Hall Asia";
	map["NLCS"] = "North London Collegiate School";
	map["KIS"] = "Korea International School";
	map["SJA"] = "St. Johnsbury Academy";

	string str;
	cin >> str;
	cout << map[str];
	return 0;
}
