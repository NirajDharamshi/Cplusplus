#include "Book.h"
#include <vector>
#include<iostream>
#include<iomanip>
#include<stdio>
#include<string>

using namespace std;

//Default constructor
Book::Book() {
    isbn="";
    last="";
    first="";
    title="";
	category = Category::NONE;
}
;
//Parameterized constructor
Book::Book(string isbn, string last, string first, string title,
		Category category) :
 {
					
   isbn=isbn;
   last=last;
   first=first;
   title=title;
   category=category;
}

//Destructor
Book::~Book() {
}


// getter functions
string Book::get_isbn() const {
	return isbn;
}

string Book::get_first() const {
	return first;
}

string Book::get_last() const {
	return last;
}

string Book::get_title() const {
	return title;
}

string Book::get_category() const {

	if (category == Book::Category::FICTION) {
		return "fiction";
	} else if (category == Book::Category::HISTORY) {
		return "history";
	} else if (category == Book::Category::TECHNICAL) {
		return "technical";
	} else (category == Book::Category::NONE) {
		return "none";
	} 
}

// Output operator overloading

ostream& operator <<(ostream& outs, const Book& B1) {

output<<"Book{ISBN="<<b.isbn<<", last="<<b.last
  <<", first="<<b.first<<", title="<<b.title
<<", category="<<b.category<<"}";

   return output;
}

//input operator overloading
istream& operator >>(istream& ins, Book& B1) {
string cat;
   input.get();
   getline(input,b.isbn,',');
   getline(input,b.last,',');
   getline(input,b.first,',');
   getline(input,b.title,',');
   getline(input,cat);
   
   switch(cat)
   {
      case "fiction":b.category=Book::Category::FICTION;break;
      case "history":b.category=Book::Category::HISTORY;break;
      case "technical":b.category=Book::Category::TECHNICAL;break;
      default:b.category=Book::Category::NONE;
   }
   

   return input;
}