#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
map<int, int> elem;

void Add(int n, int len, vector<int> elements) {
    int result = 0;
    int index = 0;
    for (int i = 0; i < len; i++) {
        index = 0;
        result = 0;
        for (int j = n; j < elements.size(); j++) {
            result += elements[j];
            index++;
            if(index > i) {
                break;
            }
        }
        elem[result]++;
    }
}

int solution(vector<int> elements) {
    int answer = 0;

    int len = elements.size();
    for (int i = 0; i < len; i++) {
        elements.push_back(elements[i]);
    }

    for (int i = 0; i < len; i++) {
       Add(i, len, elements);
    }
    answer = elem.size();
    for (auto it = elem.begin(); it != elem.end(); it++)
    {
        cout << (*it).first << " , " ;
    }

    cout << endl;
    return answer;
}

int main()
{
    vector<int> elements = {7,9,1,1,4};
    cout << solution(elements)<< endl;
    return 0;
}