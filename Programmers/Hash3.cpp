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
	return a.second > b.second;     //���ȸ���� ��������
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
	map<string, int> music;					//�� �帣���� Ƚ������
	map<string, map<int, int>> musiclist;	//�� �帣���� �����뷡�� ����� ��������

	for (int i = 0; i < genres.size(); i++)	//���� ����Ʈ��ŭ �ݺ�
	{
		music[genres[i]] += plays[i];		//music map�� �帣���� Ƚ���߰�
		musiclist[genres[i]][i] = plays[i];	//musiclist map�� �뷡��ȣ�� �÷���Ƚ�� �߰�
	}

	while (music.size() > 0)				//�帣�� �پ����������� �ݺ�
	{
		string genre{};
		int max{ 0 };

		for (auto mu : music)				//�帣�߿��� ���ϳ����� ã��
		{
			if (max < mu.second)
			{
				max = mu.second;
				genre = mu.first;
			}
		}

		for (int i = 0; i < 2; i++)			//2���� �־���ϹǷ� 2���ݺ�
		{
			int val = 0, ind = -1;

			for (auto ml : musiclist[genre])	//�뷡�߿��� ���ϳ����� ã��
			{
				if (val < ml.second)
				{
					val = ml.second;
					ind = ml.first;
				}
			}

			if (ind == -1)			//���� �뷡�� 0~1��ۿ����ٸ� �ݺ��� Ż��
				break;

			answer.push_back(ind);			//������ ����Ʈ�� �뷡��ȣ �߰�
			musiclist[genre].erase(ind);
		}

		music.erase(genre);		//map ���� ����� �帣����
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