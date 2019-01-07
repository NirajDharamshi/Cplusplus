#include "Book.h"
#include <vector>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

/***** Complete this file. *****/

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, const vector<Book>& catalog);
void searchAuthor(const string author,const vector<Book>& catalog);
void searchCategory(const string category,const vector<Book>& catalog);

const string INPUT_FILE_NAME = "commands.in";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    vector<Book> catalog;  // book catalog
    
                     //Object to store attributes
    string temp;
    string delete_book;
    int index=0;
    char command;
     int i, j;
     string key;
    int count=0;
    while(!input.eof())
    { Book b1;
      input >> command;  // read the first command
    if(command=='+')
    {
     
      input>>b1;
      catalog.insert(catalog.begin() + count, b1) ;
      string isbn=b1.get_isbn();
         for (i = 1; i <= catalog.size(); i++)
         {
            key = catalog[i].get_isbn();
            j = i-1;
 
         
         while (j >= 0 && catalog[j].get_isbn() > key)
         {
            catalog[j+1].get_isbn() = catalog[j].get_isbn();
            j = j-1;
          }
          
          catalog[j+1].get_isbn() = key;
         }
    }
    else if(command=='-')
    {
       string isbn=b1.get_isbn();
      	if (catalog.size() == 0) {
	} 
	else {
		for (int position = 0; position < catalog.size(); position++) {
			if (catalog[position].get_isbn() == isbn) {
				cout << endl << "- Removed " << catalog[position];
				catalog.erase(catalog.begin() + position);
				return position;
			}
		}
	}
	cout << "" << endl;
    }
    else if(command=='?')
    {
       string check;
       getline(input,check);
    
       string isbn="";
       string author="";
       string category="";
       int index_isbn=0;
       int index_author=0;
       int index_category=0;
       
       if(check==" author"){
          
          getline(input,author,'\n');
          searchAuthor(author,catalog);
          
       }else if(check==" category"){
          
          getline(input,category,'\n');
          searchCategory(category,catalog);
          
       }else if(check==" isbn"){
          
          getline(input,isbn,'\n');
          index_isbn=find(isbn,catalog);
          cout<<catalog[index_isbn];
          
       }else{
          
          for(int i=0; i<catalog.size(); i++){
             
             cout<<catalog[i];
             
          }
          
       }
    }
    else
    {
      cout<<"Invalid Command"<<endl;   
    }
    }
    /**
     * Loop to read commands until the end of file.
     */
    while (!input.fail())
    {
        cout << endl << command << " ";

        /*** Complete this main. *****/
    }

    return 0;
}

int find( string isbn1,  vector<Book>& catalog)
{
   int high=catalog.size()-1;
   int low=0;
   int mid=0;
   
   while(high>low)
   {
      
      mid=(high+low)/2;
      if(isbn1>catalog[mid].get_isbn()){
         low=mid+1;
      }else if(isbn1<catalog[mid].get_isbn()){
         high=mid-1;
      }else if(isbn1==catalog[mid].get_isbn()){
         return mid;
      }
   
      return -1;
   }
}
void searchAuthor(const string author,const vector<Book>& catalog)
{
   int i=0;
   int count=0;
   while(i<catalog.size())
     {
        if(author==catalog[i].get_last())
        {
           cout<<catalog[i];
           count++;
        }
        i++;
     }
   if(count==0){
      cout<<"No book found with this author!";
   }
}
void searchCategory(const string category,const vector<Book>& catalog)
{
   int i=0;
   while(i<catalog.size())
     {
        if(category==catalog[i].get_category();
        {
           cout<<catalog[i];
           count++;
        }
        i++;
     }
   if(count==0){
      cout<<"No book found with this category!";
   }
}
   
