
#include <string>
#include <vector>
using namespace std;

//http://baike.baidu.com/view/1005388.htm?fr=aladdin#4

//string &operator=(const string &s);//���ַ���s������ǰ�ַ���
//string &assign(const char *s);//��c�����ַ���s��ֵ
//string &assign(const char *s, int n);//��c�ַ���s��ʼ��n���ַ���ֵ
//string &assign(const string &s);//���ַ���s������ǰ�ַ���
//string &assign(int n, char c);//��n���ַ�c��ֵ����ǰ�ַ���
//string &assign(const string &s, int start, int n);//���ַ���s�д�start��ʼ��n���ַ�������ǰ�ַ�
//string &assign(const_iterator first, const_itertor last); //��first��last������֮��Ĳ��ָ����ַ���

//���η�ת ���ʷ�ת ���ӷ�ת
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
