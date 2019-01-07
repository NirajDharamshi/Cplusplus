#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Token {
    char type;
    double value;
    string name;  
    Token(char ch) :type(ch), value(0) { }
    Token(char ch, double val) :type(ch), value(val) { }
    Token(char ch, string n) :type(ch), name(n) { }
};
class Token_stream {
    bool full;
    Token buffer;
public:
    Token_stream() :full(0), buffer(0) { }
    Token get();
    void unget(Token t) {
        buffer=t;
        full=true;
    }
    void ignore(char);
};
const char let = 'L';
const char name = 'a';
int bracesCount=0;
//getter function 
Token Token_stream::get()
{
    if (full) {
        full=false;
        return buffer;
    }
    char ch;
    cin >> ch;
    //if any operators are found in string than enter here
    switch (ch) {
    case '(':    case ')':    case '+':    case '-':    case '*':    case '/':  case '=': case '%': case '^':{
		if(ch=='('){
			bracesCount=bracesCount+1;
		} else if(ch==')'){
			bracesCount=bracesCount-1;
		} else if(ch=='='){
			if(bracesCount>0){
				throw "*** Missing )";
			}
		} else if(ch=='%'){
			throw "*** Unexpected %";
		}
		if(bracesCount<0){
			throw "*** Unexpected )";
		}
        return Token(ch);
	}
	//if string has any number than enter here
    case '.':    case '0':    case '1':    case '2':    case '3':    case '4':    case '5':    case '6':    case '7':    case '8':    case '9':{
		if(!full && ch=='.'){
			throw "Done!";
		}
        cin.unget();
        double val;
        cin >> val;
        return Token('0',val);
    }
    //otherwise enter here
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
            cin.unget();
            if (s == "let") return Token(let);
            if (s == ".") {
				throw "Done!";
				return Token('.');
			}
            return Token(name,s);
        }
    }
}
void Token_stream::ignore(char c){
	if (full && c==buffer.type) {
		full = false;
		return;
	}
}
struct Variable {
    string name;
    double value;
    bool var;
    Variable(string n, double v, bool va=true) :name(n), value(v), var(va) { }
};
vector<Variable> names;
double get_value(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return names[i].value;
}
Token_stream ts;
double expression();

// factor function that calls expression again to achieve recusrion
double factor()
{
    Token t = ts.get();
    switch (t.type) {
    case '(':
    {   double d = expression();
        t = ts.get();
        return d;
    }
    case '-':
        return - factor();
    case '0':
        return t.value;
    case name:
        return get_value(t.name);
    }
}

// term fucntion that calls factor
double term()
{
    double left = factor();
    while(true) {
        Token t = ts.get();
        switch(t.type) {
        case '*':
            left *= factor();
            break;
        case '/':
        {   double d = factor();
			if (d==0){
				cout<<"*** Division by zero";
			}
            left /= d;
            break;
        }
        case '^':
        {
            left = pow (left, factor());
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

// expression fucntion that calls term
double expression()
{
    double left = term();
    while(true) {
        Token t = ts.get();
        switch(t.type) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        case '^':
            left = pow(left,term());
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

// declaration function to get names vector
double declaration()
{
    Token t = ts.get();
    string name = t.name;
    Token t2 = ts.get();
    double d = expression();
    names.push_back(Variable(name,d));
    return d;
}

// statement function to decide to call declaration or expression
double statement()
{
    Token t = ts.get();
    switch(t.type) {
    case let:
        return declaration();
    default:
        ts.unget(t);
        return expression();
    }
}

// main calculate class
class calculate {
	public:
		calculate() {
			while(true){
				try{
					Token t = ts.get();
					while (t.type == '=') {
						t=ts.get();
					}
					if (t.type == '.') {
						throw "Done!";
						return;
					}
					ts.unget(t);
					cout << statement() << endl;
					cout<<"Expression? ";
				}
				catch(const char* msg) {
					cout << msg << endl;
					if(msg=="Done!"){
						return;
					} else {
						cout<<"Expression? ";
						ts.ignore('=');
					}
				}
			}
		}
};
int main()
{
	try {
		cout<<"Expression? ";
		calculate();
		return 1;
	}
	catch(const char* msg) {
	  cerr << msg << endl;
	  return 1;
	}
}
