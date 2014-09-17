
#include <string>
#include <vector>
using namespace std;

//http://baike.baidu.com/view/1005388.htm?fr=aladdin#4
//string &erase(int pos = 0, int n = npos);//删除pos开始的n个字符，返回修改后的字符串


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
			char *p = "";
			s = p;
			return ;
		}
		string ret = s;
		string::size_type left, right;

		left = ret.find_first_of(' ', 0);
		//先删除前面的空格
		while (left == 0)
		{
			ret = ret.erase(left, 1);//删除pos开始的n个字符，返回修改后的字符串
			left = ret.find_first_of(' ', 0);
		}

		if (ret.empty())
		{
			char *p = "";
			s = p;
			return;
		}

		right = ret.find_last_of(' ');
		//先删除后面的空格		
		while (right == (ret.length() - 1))
		{
			ret = ret.erase(right, 1);//删除pos开始的n个字符，返回修改后的字符串
			right = ret.find_last_of(' ');
		}

		

		// 查找第一个不为' '的位置
		left = ret.find_first_not_of(' ', 0);
		// 查找第一个为' '的位置
		right = ret.find_first_of(' ', left);
		//如果 不等与字符串结尾
		while (right != string::npos)
		{
			reverseStr(ret, left, right - 1);
			left = ret.find_first_not_of(' ', right);
			right = ret.find_first_of(' ', left);
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
	string str = "a   ";
	Solution s;
	s.reverseWords(str);
	return 0;
}
