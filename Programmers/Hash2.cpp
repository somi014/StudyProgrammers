#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    unordered_map<string, int> m;
    for (int i = 0; i < clothes.size(); i++) {
        m[clothes[i][1]]++;
        cout << "clothes[" << i << "][1] : " << clothes[i][1] << endl;
    }
    cout << "m size : " << m.size() << endl;
   
    unordered_map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        answer *= it->second + 1;
    cout << it->first << ", " << it->second << endl;
    }
    return answer - 1;
}
//
//int solution(vector<vector<string>> clothes) {
//    
//    int answer = 0, num = 1;
//    vector<int> cases;
//    vector<string> buf;
//    vector<vector<string>> clothes2;
//
//    for (int i = 0; i < clothes.size(); i++) {
//        string tmp = clothes[i].back();
//        buf.push_back(tmp);
//        buf.push_back(clothes[i].front());
//        clothes2.push_back(buf);
//        buf.clear();
//    }
//
//    sort(clothes2.begin(), clothes2.end());     //같은 것끼리 순서대로 정렬해서
//
//    for (int i = 0; i < clothes2.size() - 1; i++) {
//
//        if (clothes2[i].front() == clothes2[i + 1].front()) //앞뒤 비교가 가능
//            num++;
//        else {
//            cases.push_back(num + 1);
//            num = 1;
//        }
//    }
//    cases.push_back(num + 1);
//
//    answer = cases[0];
//    for (int i = 1; i < cases.size(); i++)
//        answer = answer * cases[i];
//
//    return answer - 1;
//}

int main()
{
	vector<vector<string>> a = { {"yellowhat", "headgear"},
								{"bluesunglasses", "eyewear"},
							{"green_turban", "headgear"} };
	cout << solution(a);

	return 0;
}