#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
string Change(string _str);

string solution(string s) {
	string answer = "";

	bool blank = true;		//이전이 공백이었는지 체크

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			blank = true;			
		}
		else if(s[i] != ' ')
		{
			if (blank == true)	//시작 대문자로
			{
				if ('a' <= s[i] && s[i] <= 'z')
				{
					s[i] = s[i] - 32;
				}
			}
			else
			{
				if ('A' <= s[i] && s[i] <= 'Z')
				{
					s[i] = s[i] + 32;
				}
			}
			blank = false;
		}
	}
	cout << s;
	return s;
}

string Change(string _str)
{
	string result;

	if ('a' <= _str.front() && _str.front() <= 'z')
	{
		_str.front() = _str.front() - 32;
	}

	for (int i = 1; i < _str.size(); i++)
	{
		if ('A' <= _str[i] && _str[i] <= 'Z')
		{
			_str[i] = _str[i] + 32;
		}
	}
	return _str;
}

int main()
{
	string s = "3people   unFollowed me";
	//string s = "for the last week";
	//string s = "for tHE LAsT week  ";

	solution(s);
	return 0;
}

/*
for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' && blank == false)
		{
			blank = true;
			vec.push_back(stringBuffer);
			stringBuffer = "";
		}
		else if(s[i] != ' ')
		{
			stringBuffer += s[i];
			blank = false;
		}
	}
	if (blank == false)
	{
		vec.push_back(stringBuffer);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if ('a' <= vec[i].front() && vec[i].front() <= 'z')
		{
			vec[i].front() = vec[i].front() - 32;
		}

		answer += Change(vec[i]);
		if (i < vec.size() - 1)
		{
			answer += " ";
		}
	}*/