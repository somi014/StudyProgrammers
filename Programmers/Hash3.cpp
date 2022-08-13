#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.second > b.second;
	return a.second > b.second;     //재생회수로 오름차순
}

bool compare(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	else
	{
		return a.first < b.first;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> music;					//각 장르별로 횟수저장
	map<string, map<int, int>> musiclist;	//각 장르별로 무슨노래가 몇번씩 저장됬는지

	for (int i = 0; i < genres.size(); i++)	//들어온 리스트만큼 반복
	{
		music[genres[i]] += plays[i];		//music map에 장르별로 횟수추가
		musiclist[genres[i]][i] = plays[i];	//musiclist map에 노래번호와 플레이횟수 추가
	}

	while (music.size() > 0)				//장르가 다없어질때까지 반복
	{
		string genre{};
		int max{ 0 };

		for (auto mu : music)				//장르중에서 제일높은것 찾기
		{
			if (max < mu.second)
			{
				max = mu.second;
				genre = mu.first;
			}
		}

		for (int i = 0; i < 2; i++)			//2곡을 넣어야하므로 2번반복
		{
			int val = 0, ind = -1;

			for (auto ml : musiclist[genre])	//노래중에서 제일높은것 찾기
			{
				if (val < ml.second)
				{
					val = ml.second;
					ind = ml.first;
				}
			}

			if (ind == -1)			//만약 노래가 0~1곡밖에없다면 반복문 탈출
				break;

			answer.push_back(ind);			//리턴할 리스트에 노래번호 추가
			musiclist[genre].erase(ind);
		}

		music.erase(genre);		//map 에서 사용한 장르삭제
	}

	return answer;
}

int main()
{
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };
	solution(genres, plays);

	return 0;
}