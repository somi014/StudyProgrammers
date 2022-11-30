#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string Convert(string text);
string Remove(string _text);
string Period(string text);

vector<char> special = { '~','!','@','#','$','%', '^','&','*','(',')', '=', '+',
				'[','{',']', '}', ':', '?' , ',', '<', '>', '/' };

string solution(string new_id) {
	string answer = "";
	answer = Convert(new_id);
	answer = Remove(answer);
	answer = Period(answer);

	if (answer == "")
	{
		answer += "a";
	}

	if (answer.size() >= 16)
	{
		answer.erase(answer.begin() + 15, answer.end());
	}
	if (answer[answer.size() - 1] == '.')
	{
		answer.erase(answer.end() - 1);
	}

	int addCount = 3 - answer.size();
	if (answer.size() <= 2)
	{
		for (int i = 0; i < addCount; i++)
		{
			answer += answer.back();
		}
	}

	return answer;
}

//소문자 치환
string Convert(string text)
{
	string result = text;

	for (int i = 0; i < result.size(); i++)
	{
		if ('A' <= result[i] && result[i] <= 'Z')
		{
			result[i] += 32;
		}
	}
	return result;
}

//특수 문자 제거 
string Remove(string _text)
{
	string result;
	for (int i = 0; i < _text.size(); i++)
	{
		bool remove = false;
		for (int j = 0; j < special.size(); j++)
		{
			if (_text[i] == special[j])
			{
				remove = true;
			}

		}if (remove == false)
		{
			result += _text[i];
		}
	}
	return result;
}

string Period(string text)
{
	string result;

	for (int i = 0; i < text.size() - 1; i++)
	{
		if (text[i] == '.')
		{
			if (text[i + 1] != '.')
			{
				result += text[i];
			}
		}
		else
		{
			result += text[i];
		}
	}
	result += text[text.size() - 1];

	if (result[0] == '.')
	{
		result.erase(result.begin());
	}
	if (result.size() > 0)
	{
		if (result[result.size() - 1] == '.')
		{
			result.erase(result.end() - 1);
		}
	}
	return result;
}

int main()
{
	//string new_id = "...!@BaT#*..y.abcdefghijklm";
	//string new_id = "z-+.^.";
	//string new_id = "=.=";
	//string new_id = "123_.def";
	string new_id = "abcdefghijklmn.p";
	cout << solution(new_id) << endl;

	return 0;
}