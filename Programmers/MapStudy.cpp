#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, string> m;
	m.insert(pair<int, string>(30, "����°"));
	m.insert(pair<int, string>(50, "�ټ���°"));
	m.insert(pair<int, string>(10, "ù��°"));
	m.insert(pair<int, string>(40, "�׹�°"));
	m.insert(pair<int, string>(20, "�ι�°"));

	map<int, string>::iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << "[ " << iter->first << ", " << iter->second << " ]" << endl;
	}

	cout << "=============" << endl;

	m[10] = "ù��° �����Դϴ�";

	string findValue = m.find(20)->second;
	cout << "key�� 20�� value ã��" << findValue << endl;

	cout << "30, 40 �����" << endl;
	m.erase(30);
	m.erase(m.find(40));

	cout << "=============" << endl;

	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << "[ " << (*it).first << ", " << (*it).second << " ]" << endl;
	}

	cout << "=============" << endl;

	m[60] = "������°";
	m[70] += "�ϰ���°";
	m[70] += " �߰��ϱ�";

	cout << m.find(60)->second << endl;
	cout << m.find(70)->second << endl;

	map<int, map<int, string>> m2;
	m2[0][0] = "ù��°";
	m2[0][1] = "�߰�";
	m2[1].insert(pair<int, string>(0, "�ι�°"));
	m2[2][0] = "������";
	m2[2][2] = "�Դϴ�";

	cout << m2.find(0)->second[0] << " + " << m2.find(0)->second[1] << endl;
	cout << m2.find(1)->second[0] << " + " << m2.find(1)->second[1] << endl;
	cout << m2.find(2)->second[0] << " + " << m2.find(2)->second[1] << " + "
		<< m2.find(2)->second[2] << endl;


	return 0;
}