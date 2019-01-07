#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include<string>
#include<iostream>

using namespace std;

class RomanNumeral
{
public:
  //Constructor declaration
  RomanNumeral (int decimal);
    RomanNumeral (string r);
    RomanNumeral ();
  //Getter function declaration
  int get_dec () const;
  string get_rom () const;
  //Operator overloading function declaration
  friend ostream & operator << (ostream & out, const RomanNumeral & r);
  friend istream & operator >> (istream & in, RomanNumeral & r);
  friend int operator + (const RomanNumeral & r, const RomanNumeral & r1);
  friend int operator - (const RomanNumeral & r, const RomanNumeral & r1);
  friend int operator / (const RomanNumeral & r, const RomanNumeral & r1);
  friend int operator * (const RomanNumeral & r, const RomanNumeral & r1);
  friend bool operator == (const RomanNumeral & r, const RomanNumeral & r1);
  friend bool operator != (const RomanNumeral & r, const RomanNumeral & r1);


  //private members 
private:
  int decimal;
  string roman;
  int to_dec (string p);
  string to_rom (int q);
};


#endif
