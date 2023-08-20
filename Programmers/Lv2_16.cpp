#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if(cacheSize == 0) {
        return cities.size() * 5;
    }

    deque<string> de;
    bool flag = false;
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].size(); j++) {
            cities[i][j] = toupper(cities[i][j]);
        }
        flag = false;
        for (int j = 0; j < de.size(); j++) {
            if(de[j] == cities[i]) {
                flag = true;
                answer++;
                string temp = de[j];
                de.erase(de.begin() + j);   //최근에 사용된 캐시는 뒤로
                de.push_back(temp);
                break;
            }
        }
        if(flag == false) {
            answer += 5;
            if(de.size() >= cacheSize )
            {
                de.pop_front();
            }
            de.push_back(cities[i]);
        }
    }

    return answer;
}

int main()
{
    int cacheSize = 0;
    //vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    //vector<string> cities = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    //vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
    //vector<string> cities ={"Jeju", "Pangyo", "NewYork", "newyork"};
    vector<string> cities ={"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    cout << solution(cacheSize, cities) << endl;
    return 0;
}