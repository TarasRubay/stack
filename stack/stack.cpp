#include "stack.h"


void fill_stack(string& str, stack<char>& obj_s, stack<int>& obj_n)
{
	string num;
	for (int i = str.size() - 1; i >= 0; --i) {
		if ((int)str[i] >= 40 && (int)str[i] <= 47) {
			if ((int)str[i] == 42)   // *
				obj_s.push_front(str[i]);
			else if ((int)str[i] == 43)   // +
				obj_s.push_front(str[i]);
			else if ((int)str[i] == 45)   // -
				obj_s.push_front(str[i]);
			else if ((int)str[i] == 47)
				obj_s.push_front(str[i]);// (47) '/'
			
			if (num.size()) {
				obj_n.push_front(from_string(num));
				num = {};
			}
		}
		else if ((int)str[i] <= 57 && (int)str[i] >= 48) {
			num += str[i];
		}

	}
	if (num.size()) {
		obj_n.push_front(from_string(num));
		num = {};
	}
}


string to_string(int res)
{
	string str,str2;
	int a;
	while (res) {
		a = res % 10;
		str += a + 48;
		res /= 10;
	}
	for (int i = str.size()-1; i >= 0 ; --i)
	{
		str2 += str[i];
	}
	return str2;
}

int from_string(char _data)
{
	return (int)_data - 48;
}

int from_string(string& str)
{
	int res = 0;
	string rev;
	for (int i = str.size()-1; i >= 0; --i)
	{
		rev += str[i];
	}
	for (int i = 0; i < rev.size(); ++i)
	{
		if (i == 0) {
			res += from_string(rev[i]);
		}
		else {
			res *= 10;
			res += from_string(rev[i]);
		}
	}
	return res;
}

int from_string_not_rev(string& str)
{
	int res = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (i == 0) {
			res += from_string(str[i]);
		}
		else {
			res *= 10;
			res += from_string(str[i]);
		}
	}
	return res;

}

int counts(string& str, stack<char>& obj_s, stack<int>& obj_n)
{
	int result = 0;
	for (int i = str.size() - 1; i >= 0; --i) {
		if ((int)str[i] == 41 || (int)str[i] == 40) {
			str = bracket(str, obj_s, obj_n);
			break;
		}
	}

	for (int i = str.size() - 1; i >= 0; --i) {
		if ((int)str[i] == 42 || (int)str[i] == 47) {
			str = multiple(str, obj_s, obj_n);
			break;
		}
	}
	
	for (int i = str.size() - 1; i >= 0; --i) {
		if ((int)str[i] == 43 || (int)str[i] == 45) {
			str = simple(str, obj_s, obj_n);
			break;
		}
	}

	return from_string_not_rev(str);
}

string bracket(string& str, stack<char>& obj_s, stack<int>& obj_n)
{
	string tmp,brack,s;
	int count_bra = 0,ind;
	bool br = false;
	
		for (int i = 0; i < str.size(); ++i) {
			if ((int)str[i] == 40) {
				br = true;
				count_bra++;
				brack += str[i];
			}
			else if ((int)str[i] == 41) {
				brack += str[i];
				count_bra--;
				ind = brack.size() - 1;
				for (int j = ind; (int)brack[j] != 40 ; j--)
				{	
					if((int)brack[j] != 40 && (int)brack[j] != 41)
					s += brack[j];
					brack.pop_back();
				}
				if((int)brack[brack.size() - 1] == 40)
					brack.pop_back();
				string a;
				for (int j = s.size() - 1; j >= 0; --j)
				{
					a += s[j];
				}
				s = a;
				if (s.size()) {
					
					brack += brac(s, obj_s, obj_n);
					s = {};
				}
				if (!count_bra) {
					br = false;
					tmp += brac(brack, obj_s, obj_n);
					brack = {};
				}

			}
			else if (br) {
				brack += str[i];
			}
			else {
				tmp += str[i];
			}
		}
	
	str = tmp;
	return str;
}

string brac(string& str,stack<char>& obj_s, stack<int>& obj_n)
{
	
	for (int i = str.size() - 1; i >= 0; --i) {
		if ((int)str[i] == 42 || (int)str[i] == 47) {
			str = multiple(str, obj_s, obj_n);
			break;
		}
	}

	for (int i = str.size() - 1; i >= 0; --i) {
		if ((int)str[i] == 43 || (int)str[i] == 45) {
			str = simple(str, obj_s, obj_n);
			break;
		}
	}

	return str;
}

string multiple(string& str, stack<char>& obj_s, stack<int>& obj_n)
{
	fill_stack(str,obj_s,obj_n);
	string tmp;
	while (obj_s.size()) {
		if (obj_s.size() && (int)obj_s.front() == 42) {
			obj_n.push_front(multiple(obj_n.pop_front(), obj_n.pop_front()));
			obj_s.pop_front();
		}
		else if (obj_s.size() && (int)obj_s.front() == 47) {
			obj_n.push_front(divide(obj_n.pop_front(), obj_n.pop_front()));
			obj_s.pop_front();
		}
		else if (obj_s.size() && (int)obj_s.front() == 43 || (int)obj_s.front() == 45) {
			tmp += to_string(obj_n.pop_front());
			tmp += obj_s.pop_front();
		}
	}
	tmp += to_string(obj_n.pop_front());
	str = tmp;
	return str;
}

string simple(string& str, stack<char>& obj_s, stack<int>& obj_n)
{
	fill_stack(str,obj_s,obj_n);
	while (obj_s.size()) {
		if (obj_s.size() && (int)obj_s.front() == 43) {
			obj_n.push_front(plas(obj_n.pop_front(), obj_n.pop_front()));
			obj_s.pop_front();
		}
		else if (obj_s.size() && (int)obj_s.front() == 45) {
			obj_n.push_front(minu(obj_n.pop_front(), obj_n.pop_front()));
			obj_s.pop_front();
		}
	}
	string res = to_string(obj_n.pop_front());
	return res;
}

int plas(int a, int b)
{
	return b + a;
}

int minu(int a, int b)
{
	return b - a;
}

int divide(int a, int b)
{
	return b / a;
}

int multiple(int a, int b)
{
	return b * a;
}
