#include <iostream>
#include <queue>

using namespace std;

struct Student
{
	int id;
	string name;

	Student(int _id, string _name)
	{
		id = _id;
		name = _name;
	}

	bool operator<(const Student p) const
	{
		return this->id > p.id;
	}
};

struct cmp
{
	bool operator()(Student a, Student b)
	{
		return a.id > b.id;
	}
};

int main()
{
	priority_queue<int, vector<int>, less<int>> pq1;
	pq1.push(1);
	pq1.push(3);
	pq1.push(2);
	pq1.push(4);

	while (pq1.size() > 0)
	{
		cout << pq1.top() << endl;
		pq1.pop();
	}

	priority_queue<Student, vector<Student>, cmp> pq2;
	pq2.push(Student(2, "A"));
	pq2.push(Student(5, "B"));
	pq2.push(Student(3, "C"));
	pq2.push(Student(1, "D"));
	pq2.push(Student(4, "E"));

	while (pq2.size()> 0)
	{
		cout << "id : " << pq2.top().id  << " name : " << pq2.top().name << endl;
		pq2.pop();
	}

	return 0;
}