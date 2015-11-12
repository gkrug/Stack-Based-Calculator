#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h> // for isatty
#include <stack>
#include "myStack.h"
#include <list>

using namespace std;

const bool interactive = isatty(0);
int linenum = 0;

void error (const char *s) {
  if (interactive) {
    cout << "error: " << s << endl;
  } else {
    cerr << "error: " << s << " on line " << linenum << endl;
  }
}

template <typename Number>
int string_to_number (const string &s, Number &x) {
  stringstream ss(s);
  ss >> x;
  if (ss.eof() && !ss.fail()) 
    return 0;
  else
    return -1;
}

int main (int argc, char *argv[]) {
	myStack <double> my_stack;
	list< myStack <double> > undo;
	stack <double> temp;
	int size;
	double top1;
	double top2;
	int counter = 1;
  while (!cin.eof()) {
    if (interactive) cout << "> ";

    string s;
    getline(cin, s);
    linenum++;

    double x;
	//cout << my_stack.size() << endl;
		//size = my_stack.size();
    if (string_to_number(s, x) == 0) {
			//cout << "here2\n";
			undo.push_front(my_stack); // copy undo stack to front of lst
			//cout << "here3\n;";
			my_stack.push(x);
			cout << x << endl;
			//cout << "new top is " << my_stack.Top << endl;
			//my_stack.print();
    } 
		else if (s == "+") {
			if (my_stack.size() < 2) {
				cout << "error: stack underflow on line " << counter << endl;
			}
			else {
				undo.push_front(my_stack); // copy undo stack to front of lst
				top1 = my_stack.top();
				my_stack.pop();
				top2 = my_stack.top();
				my_stack.pop();
				my_stack.push(top1 + top2);
				cout << top1 + top2 << endl;
				my_stack.link(undo.front().headPtr, undo.front().Top);
			}
		}
		else if (s == "-") {
			if (my_stack.size() < 2) {
				cout << "error: stack underflow on line " << counter << endl;
			}
			else {
				undo.push_front(my_stack); // copy undo stack to front of lst
				top1 = my_stack.top();
				my_stack.pop();
				top2 = my_stack.top();
				my_stack.pop();
				my_stack.push(top2 - top1);
				cout << top2 - top1 << endl;
				my_stack.link(undo.front().headPtr, undo.front().Top);
			}
		}
		else if (s == "/") {
			if (my_stack.size() < 2) {
				cout << "error: stack underflow on line " << counter << endl;
			}
			else {
				
				undo.push_front(my_stack); // copy undo stack to front of lst
				top1 = my_stack.top();
				my_stack.pop();
				top2 = my_stack.top();
				my_stack.pop();
				my_stack.push(top2 / top1);
				cout << top2 / top1 << endl;
				my_stack.link(undo.front().headPtr, undo.front().Top);
			}
		}
		else if (s == "*") {
			if (my_stack.size() < 2) {
				cout << "error: stack underflow on line " << counter << endl;
			}
			else {
				undo.push_front(my_stack); // copy undo stack to front of lst
				top1 = my_stack.top();
				my_stack.pop();
				top2 = my_stack.top();
				my_stack.pop();
				my_stack.push(top1 * top2);
				cout << top1 * top2 << endl;
				my_stack.link(undo.front().headPtr, undo.front().Top);
			}
		}
		else if (s == "swap" && my_stack.size() > 1) {
			undo.push_front(my_stack); // copy undo stack to front of lst
			top1 = my_stack.top();
			my_stack.pop();
			top2 = my_stack.top();
			my_stack.pop();
			my_stack.push(top1);
			my_stack.push(top2);
			cout << my_stack.top() << endl;
		}
		else if (s == "drop" && my_stack.size() > 0) {
			undo.push_front(my_stack); // copy undo stack to front of lst
			my_stack.pop();
			cout << my_stack.top() << endl;
		}
		else if (s == "undo") {
			
			if (my_stack.size() > 0) {
			//	cout << "-" << undo.front().top() << endl;
				my_stack = undo.front();
				//cout << " ^" << my_stack.size() << endl;
				if (my_stack.size() > 0) cout << my_stack.top() << endl;
			}
			else if (my_stack.size() == 1)
			{
				
			}
			else {
				cout << "error: cannot undo on line " << counter << endl;
			}
			//my_stack.print();
		}
		else if (s == "") {
      // do nothing
    } else {
      error("couldn't understand input");
    }
	counter++;
	}
}
