
#include <string>
#include <vector>
using namespace std;

//string &operator=(const string &s);//���ַ���s������ǰ�ַ���
//string &assign(const char *s);//��c�����ַ���s��ֵ
//string &assign(const char *s, int n);//��c�ַ���s��ʼ��n���ַ���ֵ
//string &assign(const string &s);//���ַ���s������ǰ�ַ���
//string &assign(int n, char c);//��n���ַ�c��ֵ����ǰ�ַ���
//string &assign(const string &s, int start, int n);//���ַ���s�д�start��ʼ��n���ַ�������ǰ�ַ�
//string &assign(const_iterator first, const_itertor last); //��first��last������֮��Ĳ��ָ����ַ���


class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty())
			return;
		// ����Ҳ�����string 
		char *p = s.c_str();

		vector<string> words;

		string tmp = s;

		// ����" "�ĵ�һ��λ��
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