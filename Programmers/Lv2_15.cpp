#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    map<string, int> buy;
    map<string, int> m;
    int total =0;
    for (int i = 0; i < want.size(); ++i) {
        m[want[i]] = number[i];
        total += number[i];
        buy[want[i]] = 0;
    }

    int len = 0;
    int count = 10;
    while(len + 10 <= discount.size())
    {
        count = 10;
        buy.clear();
        for (int i = len; i < len + 10; i++) {
           if(m.find(discount[i]) == m.end()) {
               continue;
           }

            if(m[discount[i]] > buy[discount[i]]){
                count--;
                buy[discount[i]]++;
            }
        }

        if(count <= 0) {
            answer++;
        }
        len++;
    }

    return answer;
}

int main()
{
    //vector<string> want = {"banana", "apple", "rice", "pork", "pot"};
    //vector<int> number = {3, 2, 2, 2, 1};
    //vector<string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"
    //};

    vector<string> want = {"apple"};
    vector<int> number = {10};
    vector<string> discount = {"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"};
    cout << solution(want, number, discount) << endl;
    return 0;
}