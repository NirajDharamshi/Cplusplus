#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

// The Book class.

class Book {
public:

	//Book categories.
	enum class Category {
		FICTION, HISTORY, TECHNICAL, NONE
	};

// Default constructor.
	Book();

	//Constructor
	Book(string isbn, string last, string first, string title,
			Category category);


	//Destructor
	~Book();

	//member functions
	Book& operator=(const Book& other);
    string get_isbn();
    string get_last();
    string get_first();
    string get_title();
    Category get_category();

	// Operaor Overloading functions
//	friend Category get_category(string cat_str);
    friend istream& operator>>(istream& inp, Book& b);
    friend ostream& operator<<(ostream& out, Book& b);

	//Private members
private:

	string isbn;
	string last;
	string first;
	string title;
	Category category;

};

#endif /* EMPLOYEE_H_ */