//#include <vector>
//#include <queue>
//#include <iostream>
//
//using namespace std;
//
//int solution(vector<int> scoville, int K) {
//	int answer = 0;
//	
//	//============== 오답 ========================
//	priority_queue <int> pq;
//	priority_queue <int> tmp;
//	
//	for (int i = 0; i < scoville.size(); ++i)
//	{
//		pq.push(scoville[i]);
//		tmp.push(scoville[i]);
//	}
//	for (int i = 0; i < scoville.size(); i++)
//	{
//		cout << tmp.top() << endl;
//		tmp.pop();
//	}
//
//	while (pq.size() > 1 && pq.top() < K) {	//K보다 커서 안돌았음!
//		int first = pq.top();
//		pq.pop();
//		int second = pq.top();
//		pq.pop();
//		pq.push(first + (second * 2));
//		answer++;
//	}
//	
//	if (pq.top() < K) answer = -1;
//
//	//============== 정답으로 제출 ========================
//	//priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
//	//
//	//while (pq.size() > 1 && pq.top() < K) {
//	//	int first = pq.top();
//	//	pq.pop();
//	//	int second = pq.top();
//	//	pq.pop();
//	//	pq.push(first + (second * 2));
//	//	answer++;
//	//}
//	//
//	//if (pq.top() < K)
//	//	return -1;
//
//	//================ 테스트 ======================
//	/*priority_queue<int> sco;
//	priority_queue<int> temp;
//
//	for (int i = 0; i < scoville.size(); ++i)
//	{
//		sco.push(-scoville[i]);
//		temp.push(-scoville[i]);
//	}
//	for (int i = 0; i < scoville.size(); ++i)
//	{
//		cout << temp.top() << endl;
//		temp.pop();
//	}
//	
//	while (sco.size() >= 2 && -sco.top() < K)
//	{
//		int mix1 = sco.top();
//		sco.pop();
//		int mix2 = sco.top() * 2;
//		sco.pop();
//
//		sco.push(mix1 + mix2);
//		++answer;
//	}
//
//	if (-sco.top() < K)
//		answer = -1;
//*/
//	return answer;
//}
//
//void print(vector<int> scoville, int K, int answer) {
//	int t = solution(scoville, K);
//	//if (t == answer)
//	//	cout << "정답" << endl;
//	//else
//	//	cout << "틀림" << endl;
//	cout << t << endl;
//}
//
//int main() {
//
//	print({ 1,2,3,9,10,12 }, 7, 2);
//	return 0;
//}