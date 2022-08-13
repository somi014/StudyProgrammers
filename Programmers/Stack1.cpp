//#include <vector>
//#include <queue>
//
//using namespace std;
//
//vector<int> last;
//vector<int> day;
//
//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//	vector<int> answer;
//
//	for (int i = 0; i < progresses.size(); i++)
//	{
//		last.push_back(100 - progresses[i]);
//	}
//
//	for (int i = 0; i < speeds.size(); i++)
//	{
//		if (last[0] % speeds[i] > 0)
//		{
//			day.push_back((last[0] / speeds[i]) + 1);
//		}
//		else
//		{
//
//			day.push_back(last[0] / speeds[i]);
//		}
//			last.pop_back();
//	}
//
//	int temp = 0;
//	int count = 1;
//	for (int i = 0; i < day.size(); i++)
//	{
//		temp = day[0];
//		day.pop_back();
//		if (temp >= day[0])
//		{
//			count++;
//		}
//		else
//		{
//			answer.push_back(count);
//			count = 1;
//		}
//	}
//	return answer;
//}
//
//int main(void)
//{
//	vector<int> p = { 93 , 30, 55 };
//	vector<int> s = { 1, 30, 5 };
//	vector<int> a;
//	a =  solution(p, s);
//	for (int i = 0; i < a.size(); i++)
//	{
//		printf(a.pop_back);
//	}
//}