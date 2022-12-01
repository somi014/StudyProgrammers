#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int>  x;
    istringstream ss(s);
    string stringBuffer;

    while (getline(ss, stringBuffer, ' '))
    {
        x.push_back(stoi(stringBuffer));
    }
    sort(x.begin(), x.end());
 
    answer += to_string(x.front());
    answer += " ";
    answer += to_string(x.back());

    return answer;
}

int main()
{
    //string s = "1 2 3 4";
    string s = "-1 -2 -3 -4";

    cout << solution(s) << endl;
    return 0;
}