
#include <string>
#include <vector>
using namespace std;

//string &operator=(const string &s);//把字符串s赋给当前字符串
//string &assign(const char *s);//用c类型字符串s赋值
//string &assign(const char *s, int n);//用c字符串s开始的n个字符赋值
//string &assign(const string &s);//把字符串s赋给当前字符串
//string &assign(int n, char c);//用n个字符c赋值给当前字符串
//string &assign(const string &s, int start, int n);//把字符串s中从start开始的n个字符赋给当前字符
//string &assign(const_iterator first, const_itertor last); //把first和last迭代器之间的部分赋给字符串


class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty())
			return;
		// 妈的我不想用string 
		char *p = s.c_str();

		vector<string> words;

		string tmp = s;

		// 查找" "的第一个位置
		int pos = s.find_first_of(" ");

		words.push_back( s.assign(s.c_str(), pos));
		
	}
};


int main()
{
	string str = "i am ddd";

	Solution s;

	s.reverseWords(str);

	return 0;
}