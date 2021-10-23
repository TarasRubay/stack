#pragma once
#include <iostream>
using namespace std;
template <typename t>
class stack {
	template <typename t>
	struct noda {
		noda* p_next;
		t data;
		noda<t>(t _data = t(),noda<t>* _p_next = nullptr) {
			data = _data;
			p_next = _p_next;
		}
	};
	int length = 0;
	noda<t>* head = nullptr;
public:
	stack();
	void push_front(t _data);
	int size();
	t front();
	t pop_front();
	~stack();
};
void fill_stack(string& str, stack <char>& obj_s, stack<int>& obj_n);
string to_string(int res);
int from_string(char _data);
int from_string(string& str);
int from_string_not_rev(string& str);
int counts(string& str, stack <char>& obj_s, stack<int>& obj_n);
string bracket(string& str, stack <char>& obj_s, stack<int>& obj_n);
string brac(string& str, stack<char>& obj_s, stack<int>& obj_n);
string multiple(string& str, stack <char>& obj_s, stack<int>& obj_n);
string simple(string& str, stack <char>& obj_s, stack<int>& obj_n);
int plas(int a, int b);
int minu(int a, int b);
int divide(int a, int b);
int multiple(int a, int b);

template<typename t>
inline stack<t>::stack()
{
}

template<typename t>
inline void stack<t>::push_front(t _data)
{
	head = new noda<t>(_data,head);
	length++;
}

template<typename t>
inline int stack<t>::size()
{
	return length;
}

template<typename t>
inline t stack<t>::front()
{
	return head->data;
}


template<typename t>
inline t stack<t>::pop_front()
{
	if (head != nullptr) {
		noda<t>* tmp = head;
		t res = head->data;
		head = head->p_next;
		length--;
		delete tmp;
		return res;
	}
	return 0;
}


template<typename t>
inline stack<t>::~stack()
{
	if (head != nullptr) {
		while (length)
			pop_front();
	}
}
