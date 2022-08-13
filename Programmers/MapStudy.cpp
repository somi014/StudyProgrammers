#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, string> m;
	m.insert(pair<int, string>(30, "세번째"));
	m.insert(pair<int, string>(50, "다섯번째"));
	m.insert(pair<int, string>(10, "첫번째"));
	m.insert(pair<int, string>(40, "네번째"));
	m.insert(pair<int, string>(20, "두번째"));

	map<int, string>::iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << "[ " << iter->first << ", " << iter->second << " ]" << endl;
	}

	cout << "=============" << endl;

	m[10] = "첫번째 원소입니다";

	string findValue = m.find(20)->second;
	cout << "key값 20의 value 찾기" << findValue << endl;

	cout << "30, 40 지우기" << endl;
	m.erase(30);
	m.erase(m.find(40));

	cout << "=============" << endl;

	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << "[ " << (*it).first << ", " << (*it).second << " ]" << endl;
	}

	cout << "=============" << endl;

	m[60] = "여섯번째";
	m[70] += "일곱번째";
	m[70] += " 추가하기";

	cout << m.find(60)->second << endl;
	cout << m.find(70)->second << endl;

	map<int, map<int, string>> m2;
	m2[0][0] = "첫번째";
	m2[0][1] = "추가";
	m2[1].insert(pair<int, string>(0, "두번째"));
	m2[2][0] = "마지막";
	m2[2][2] = "입니다";

	cout << m2.find(0)->second[0] << " + " << m2.find(0)->second[1] << endl;
	cout << m2.find(1)->second[0] << " + " << m2.find(1)->second[1] << endl;
	cout << m2.find(2)->second[0] << " + " << m2.find(2)->second[1] << " + "
		<< m2.find(2)->second[2] << endl;


	return 0;
}