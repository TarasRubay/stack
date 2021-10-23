#include "stack.h"
int main() {
	stack <int> num;
	stack <char> str;
	string form = "(1+2)*(3+4)";
	cout << form << " = ";
	cout << counts(form, str, num) << endl;
	form = "2+(15/3)*2";
	cout << form << " = ";
	cout << counts(form, str, num)<<endl;
	form = "2+(15/3)*2+(25+100/2)";
	cout << form << " = ";
	cout << counts(form, str, num)<<endl;
	form = "((4*(5+10))+2)+3+2+(21/3)";
	cout << form << " = ";
	cout << counts(form, str, num)<<endl;
	form = "(((4*(5+10))+2)+3+2+(21/3))*(((4*(5+10))+2)+3+2+(21/3))";
	cout << form << " = ";
	cout << counts(form, str, num)<<endl;
	form = "((4*(5+10))+2)+3+2+(21/3)*5+(45/5+21*45-(56*8))*((4*(5+10))+2)+3+2+(21/3)";
	cout << form << " = ";
	cout << counts(form, str, num)<<endl;
	form = "((4*(5+10))+2)+3+2+(21/3)*5+(45/5+21*45-(56*8))-((4*(5+10))+2)+3+2+(21/3)";
	cout << form << " = ";
	cout << counts(form, str, num)<<endl;
	
	return 0;
}