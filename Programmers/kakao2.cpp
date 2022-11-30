#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

string Change(string _text);
vector<string> english = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int solution(string s) {
	int answer = 0;

	string result;
	string temp;
	for (int i = 0; i < s.size(); i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
		{
			temp += s[i];
			if (Change(temp) != temp)
			{
				result += Change(temp);
				temp = "";
			}
		}
		else
		{
			result += s[i];
		}
	}

	return stoi(result);
}

string Change(string _text)
{
	for (int i = 0; i < english.size(); i++)
	{
		if (_text == english[i])
		{
			return to_string(i);
		}
	}
	return _text;
}

int main()
{
	//string s = "one4seveneight";
	//string s = "23four5six7";
	//string s = "2three45sixseven";	
	string s = "123";
	solution(s);

	return 0;
}