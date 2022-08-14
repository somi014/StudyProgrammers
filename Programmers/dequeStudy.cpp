#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> d(3, 5);

	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	cout << "size : " << d.size() << endl;

	deque<int> d1;
	d1.push_back(2);
	d1.push_back(1);
	d1.push_back(4);
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;
	d1.push_front(0);
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	cout << "pop" << endl;
	d1.pop_front();
	d1.pop_back();
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	cout << "size : " << d1.size() << endl;

	d1.insert(d1.begin() + 1, 6, 3);
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	d1.erase(d1.begin() + 2);
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	return 0;
}