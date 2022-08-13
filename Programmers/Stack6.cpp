#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> left;
    stack<char> right;

    for (int i = 0; i < s.size(); i++)
    {
        if (right.size() > left.size())
        {
            if (s[i] == ')')
            {
                left.push(s[i]);
            }
            else if (s[i] == '(')
            {
                right.push(s[i]);
            }
        }
        else if (right.size() == left.size())
        {
            if (s[i] == ')')
            {
                answer = false;
                break;
            }
            else if(s[i] == '(')
            {
                right.push(s[i]);
            }
        }
        else
        {
            answer = false;
            break;
        }
    }

    if (right.size() != left.size())
    {
        answer = false;
    }

    if (answer == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return answer;
}

int main()
{
    bool answer = solution("()()");
    //bool answer = solution("(())()");

    return 0;
}