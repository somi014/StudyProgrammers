#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
vector<char> open = {'(', '{', '['};
vector<char> close = {')', '}', ']'};

bool Check(string s) {
    stack<char> pool;
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == open[0] || s[i] == open[1] || s[i] == open[2]) {
            pool.push(s[i]);
            flag = true;
        }
        else{
            if(pool.empty() == true)
            {
                return false;
            }
            if(s[i] == close[0] && pool.top() == open[0])
            {
                pool.pop();
            }
            else if(s[i] == close[1] && pool.top() == open[1])
            {
                pool.pop();
            }
            else if(s[i] == close[2] && pool.top() == open[2])
            {
                pool.pop();
            }
            else
            {
                return false;
            }
            flag = false;
        }
    }
    return (flag == false && pool.empty() == true);
}

int solution(string s) {
    int answer = 0;

    string temp = s;
    for (int i = 0; i < s.size(); ++i) {
        if(Check(temp) == true)
        {
            answer++;
            cout << "true" << temp << endl;
        }
        char first = temp.front();
        temp.erase(temp.begin());
        temp.push_back(first);
        cout << "temp " << temp << endl;
    }

    return answer;
}

int main(){
    // string s = "[](){}";
    //string s = "{{";
    //string s = "{(})";
    string s= "{{{}";
    cout << solution(s) << endl;
    return 0;
}