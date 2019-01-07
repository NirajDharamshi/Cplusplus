#include"RomanNumeral.h"
#include<string>
#include<cmath>
#include<iostream>
using namespace std;

//Constructor with no arguments
RomanNumeral::RomanNumeral ()
{

}
//Constructor with string argument
RomanNumeral::RomanNumeral (string x):decimal (0), roman (x)
{
  decimal = to_dec (x);
}
//Constructor with integer argument 
RomanNumeral::RomanNumeral (int y):decimal (y),roman ("")
{

  roman = to_rom (y);
}

//Getter functions

int RomanNumeral::get_dec () const 
{
  return decimal;
}

string RomanNumeral::get_rom () const 
{
  return roman;
}

//Function to convert roman number to decimal number
int RomanNumeral::to_dec (string rom)
{
  int len;
  int sum = 0;
  int now = 0;
  int prev = 1000;

  len = rom.length ();
  for (int j = 0; j < len; j++)
    {
      switch (rom[j])
	{
	case 'M':
	  {
	    now = 1000;
	    break;
	  }
	case 'D':
	  {
	    now = 500;
	    break;
	  }
	case 'C':
	  {
	    now = 100;
	    break;
	  }
	case 'L':
	  {
	    now = 50;
	    break;
	  }
	case 'X':
	  {
	    now = 10;
	    break;
	  }
	case 'V':
	  {
	    now = 5;
	    break;
	  }
	case 'I':
	  {
	    now = 1;
	    break;
	  }

	}

      if (rom[j + 1] != '\0')
	{
	  if (rom[j + 1] == 'M')
	    {
	      prev = 1000;
	    }
	  if (rom[j + 1] == 'D')
	    {
	      prev = 500;
	    }
	  if (rom[j + 1] == 'C')
	    {
	      prev = 100;
	    }
	  if (rom[j + 1] == 'L')
	    {
	      prev = 50;
	    }
	  if (rom[j + 1] == 'X')
	    {
	      prev = 10;
	    }
	  if (rom[j + 1] == 'V')
	    {
	      prev = 5;
	    }
	  if (rom[j + 1] == 'I')
	    {
	      prev = 1;
	    }

	  if (prev > now)
	    {
	      sum = sum + prev - now;
	      j++;
	    }
	  else
	    {
	      sum = sum + now;
	    }
	}
      else
	{
	  sum = sum + now;
	}




    }




  return sum;

}

//Function to convert decimal number to roman number
string RomanNumeral::to_rom (int decimal)
{
  string rom;
  string M[] = { "", "M", "MM", "MMM" };
  string C[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
  string X[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
  string I[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

  rom =
    M[decimal / 1000] + C[(decimal % 1000) / 100] + X[(decimal % 100) / 10] +
    I[decimal % 10];

  return rom;
}
//Output(COUT) operator overloading
ostream & operator << (ostream & out, const RomanNumeral & r)
{



  out << "[" << r.decimal << ":" << r.roman << "]";

  return out;

}
//Input(CIN) operator overloading
istream & operator >> (istream & in, RomanNumeral & r)
{



  in >> r.roman;
  r.decimal=r.to_dec(r.roman);

  return in;

}
//Addition operator overloading
int operator + (const RomanNumeral & r, const RomanNumeral & r1)
{
  return r.decimal + r1.decimal;
}

//Subtraction operator overloading
int operator - (const RomanNumeral & r, const RomanNumeral & r1)
{
  return r.decimal - r1.decimal;
}
//Multiplication operator overloading
int operator * (const RomanNumeral & r, const RomanNumeral & r1)
{
  return (r.decimal) * (r1.decimal);
}
//Division operator overloading
int operator / (const RomanNumeral & r, const RomanNumeral & r1)
{
  return (r.decimal) / (r1.decimal);
}

//Equality comparison opeerator overloading
bool operator == (const RomanNumeral & r, const RomanNumeral & r1)
{
  return (r.decimal) == (r1.decimal);
}

//not equal operator overloading
bool operator != (const RomanNumeral & r, const RomanNumeral & r1)
{
  return (r.decimal) != (r1.decimal);
}
