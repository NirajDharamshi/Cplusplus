//Assignment No:2-Monty Hall Problem
//Instructor Ron mak
//Niraj Dharamshi-SJSU_ID 012551266
//Date Due 9th Feb 2018

#include <iostream>
#include <fstream>
#include<string>
#include<iomanip>

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;	//Number of simulation 

//Function to generate random door numbers behind which car is present
Door hideCar (int count_simulate)
{
  srand (count_simulate + 2);	// Initializing srand() function with the seed.
  int x = 0;
  x = rand () % 3 + 1;		//expression will generate random numbers in the range{1,3} i.e. 1,2,3.
  return x;			//return generated random number
};

//Function to generate First choice of the door number of the player in the game
Door makeFirstChoice (int count_simulate)
{
  srand (count_simulate + 222);
  int x = 0;
  x = rand () % 3 + 1;
  return x;
};

//Function to generate Monty's Choice of Door number which he opens
Door openDoor (int count_simulate)
{
  srand (count_simulate + 222);
  int x = 0;
  int car = 0;
  int i = 0;
  car = hideCar (count_simulate);	//door behind which car is present
  int firstChoice = 0;
  firstChoice = makeFirstChoice (count_simulate);	//door which is choosen by player

  //Checks that Monty does not opens door where car is present or player has chosen
  do
    {
      x = rand () % 3 + 1;
    }
  while (x == car || x == firstChoice);

  return x;
};

//Function to generate door number as second choice of the player in the game
Door makeSecondChoice (int count_simulate)
{
  srand (count_simulate + 117);

  int x = 0;
  int car = 0;
  int z = 0;
  car = hideCar (count_simulate);	//door behind which car is present    
  int firstChoice = 0;
  firstChoice = makeFirstChoice (count_simulate);	//First choice 
  int opened_door = 0;
  opened_door = openDoor (count_simulate);	//Opened Door
  do				//Checking if the second choice is not opened door or first chosen door
    {
      x = rand () % 3 + 1;

    }
  while ((x == firstChoice) || (x == opened_door));
  return x;
};

//Function to simulate all the possibilities(combinations) as capped by defined iterations i.e. 100 here
void simulate ()
{
  int car;
  float win1, win2 = 0.0;
  int first_choice;
  int opened_door;
  int second_choice;
  string win_1;
  string win_2;
  int i = 0;
  for (int i = 1; i <= SIMULATION_COUNT; i++)
    {
      car = hideCar (i);	//Door behind which car is present
      first_choice = makeFirstChoice (i);	//First Choice of the Player
      opened_door = openDoor (i);	//Opened Door
      second_choice = makeSecondChoice (i);	//Second choice of the player
      if (car == first_choice)	//if car is won by the player by his first choice,counter is incremented 
	{
	  win_1 = "Yes";
	  win1++;
	}
      else
	{
	  win_1 = "";
	}

      if (car == second_choice)	//if car is won by the player when he switches his choice,other counter is incremented
	{
	  win_2 = "Yes";
	  win2++;
	}
      else
	{
	  win_2 = "";
	}
      //Printing the one row of simulation
      if (i < 10)
	{
	  cout << i << "           " << car << "          " <<
	    first_choice << "            " << opened_door <<
	    "                " << second_choice << "            " << win_1 <<
	    "            " << win_2 << "    " << endl;
	}
      else
	{
	  if (i < 100)
	    {
	      cout << i << "          " << car << "          " <<
		first_choice << "            " << opened_door <<
		"                " << second_choice << "            " << win_1
		<< "            " << win_2 << "    " << endl;
	    }
	  else
	    {
	      cout << i << "         " << car << "          " <<
		first_choice << "            " << opened_door <<
		"                " << second_choice << "            " << win_1
		<< "            " << win_2 << "    " << endl;
	    }
	}

    }
  cout << endl;
  cout << endl;
  float ratio = 0.0;
  ratio = win2 / win1;		//ratio of wins by second choice to first choice

  cout << win1 << " wins if player stays with his first choice" << endl;
  cout << win2 << " wins if player switches his choice" << endl;
  cout << endl;
  cout <<setprecision(3);
  cout << "Ratio of wins by second choice to first choice i.e. is  " << ratio
    << endl;

};






int main ()
{
  //Header of the simulation columns
  cout << "Sr No   " << "Car here   " << "First Choice   " << "Monty_Opens   "
    << "Second Choice    " << "Win one    " << "Win Two    " << endl;
  // Run the simulations.

  simulate ();
  return 0;

}
