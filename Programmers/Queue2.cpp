#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

    int idx = 0;    //���� ����� idx
    int sum = 0;   //���� �ٸ��� �ö���ִ� ���� ���� ����
    queue<int> q;  //���� �ٸ��� �ǳʴ� Ʈ�� üũ�� ť

    while (1) {

        if (idx == truck_weights.size()) {  //������ Ʈ���� ��
            answer += bridge_length;  //������ Ʈ���� ������ �ð� �߰�
            break;
        }

        answer++; //�ð��� ����
        int tmp = truck_weights[idx];

        //���� �ٸ��� �� �ǳ��� ���
        if (q.size() == bridge_length) {
            sum -= q.front();  //�� �ǳ����� ���� �ٸ��� �ִ� ������ ���Կ��� ����
            q.pop();
        }

        if (sum + tmp <= weight) {  //�ٸ��� ���� ���� ������ �� �ִٸ�
            sum += tmp;  //���� ���� �߰�
            q.push(tmp);
            idx++;  //���� ������ ���ؼ�
        }
        else {
            q.push(0);  //������ �� ���ٸ� 0�� Ǫ���ؼ� �ð��� ���
        }
    }

	return answer;
}

int main()
{
	vector<int> truck_weights_arr = vector<int>({ 7, 4, 5, 6 });
	vector<int> truck_weights_arr2 = vector<int>({ 10, 10, 10, 10, 10, 10 ,10,10,10,10 });
	vector<int> truck_weights_arr3 = vector<int>({ 10 });

	//int result = solution(2, 10, truck_weights_arr);
	//cout << result << endl;

	cout << endl;
	int result2 = solution(100, 100, truck_weights_arr2);
	cout << result2 << endl;
	
	//cout << endl;
	//int result3 = solution(100, 100, truck_weights_arr3);
	//cout << result3 << endl;

	return 0;
}