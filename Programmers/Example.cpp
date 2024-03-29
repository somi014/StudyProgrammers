#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    unordered_map<string, int> idx_map;
    for (int i = 0; i < id_list.size(); ++i) idx_map[id_list[i]] = i; // 멤버 index 저장

    unordered_map<string, set<string>> report_map;
    stringstream ss;
    for (auto rep : report) {
        ss.str(rep);
        string first, second; ss >> first >> second; // 문자열 parsing
              
        report_map[second].insert(first);

        ss.clear();
    }

    for (auto it : report_map) { // it.second = set<string>
        if (it.second.size() >= k) { // 어떤 멤버를 신고한 사람이 k명 이상이면
            for (auto set_it : it.second) { // 신고한 사람들의
                int idx = idx_map[set_it];
                answer[idx]++; // count 증가 (메일 전송)
            }
        }
    }

    return answer;
}
