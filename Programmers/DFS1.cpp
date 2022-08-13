//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//void dfs(vector<int>& numbers, int& answer, int target, int count = 0, int sum = 0) {
//    if (count == numbers.size() - 1) {
//        if (target == sum + numbers[count])        answer++;
//        if (target == sum - numbers[count])        answer++;
//        return;
//    }
//    dfs(numbers, answer, target, count + 1, sum + numbers[count]);
//    dfs(numbers, answer, target, count + 1, sum - numbers[count]);
//}
//
//int solution(vector<int> numbers, int target) {
//    int answer = 0;
//    dfs(numbers, answer, target);
//    return answer;
//}
//
//int main()
//{
//    cout << "1 << 0 : " << (3 &(1 << 0)) << endl;
//    cout << "1 << 1 : " << (3 &(1 << 1)) << endl;
//    cout << "1 << 2 : " << (3 &(1 << 2)) << endl;
//    cout << "1 << 3 : " << (3 &(1 << 3)) << endl;
//
//
//    return 0;
//}