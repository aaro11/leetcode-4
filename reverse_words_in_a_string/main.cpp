
#include <string>
#include <vector>
using namespace std;

//http://baike.baidu.com/view/1005388.htm?fr=aladdin#4

//string &operator=(const string &s);//把字符串s赋给当前字符串
//string &assign(const char *s);//用c类型字符串s赋值
//string &assign(const char *s, int n);//用c字符串s开始的n个字符赋值
//string &assign(const string &s);//把字符串s赋给当前字符串
//string &assign(int n, char c);//用n个字符c赋值给当前字符串
//string &assign(const string &s, int start, int n);//把字符串s中从start开始的n个字符赋给当前字符
//string &assign(const_iterator first, const_itertor last); //把first和last迭代器之间的部分赋给字符串

//两次翻转 单词翻转 句子翻转
class Solution {

private:
	void reverseStr(string& s, string::size_type left, string::size_type right)
	{
		while (left < right)
		{
			swap(s[left++], s[right--]);
		}
	}
public:
	void reverseWords(string &s) {
		if (s.empty())
		{
			return ;
		}
		string ret = s;
		string::size_type left, right;
		left = s.find_first_not_of(' ', 0);
		right = s.find_first_of(' ', left);
		while (right != string::npos)
		{
			reverseStr(ret, left, right - 1);
			left = s.find_first_not_of(' ', right);
			right = s.find_first_of(' ', left);
		}
		if (left != string::npos)
		{
			reverseStr(ret, left, ret.size() - 1);
		}
		reverseStr(ret, 0, ret.size() - 1);

		s = ret;
		return ;
	}
};


int main()
{
	string str = "i am ddd";

	Solution s;

	s.reverseWords(str);

	return 0;
}
