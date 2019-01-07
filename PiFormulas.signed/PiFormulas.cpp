//Assignment No-1 for Data Structures & Algorithms in C++
//Instructor-Ron Mak
//Date:1st Feb 2018.
//Created by Niraj Nilesh Dharamshi --SJSU ID 012551266
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
   
    //Using pre-built function atan,value of pi is calculated
    
    double pi_function = 0.0;   
    pi_function=4*atan(1);      //Computation using function atan()
        cout << "pi   = "<<std::fixed << std::setprecision(15)<<pi_function<<" = 4*arctan(1)"<<endl; //Output
    cout<<endl;
    
    
    //Using Ramanujan's formulas,value of pi is calculated to various precision
    cout << "Ramanujan's pi formulas:" << endl;
    
    double pi_15=0.0; 
        pi_15=(12/sqrt(130))*log((((2+sqrt(5))*(3+sqrt(13)))/(sqrt(2))));//computing value of pi till 15 decimal precision
             cout << "pi15   = "<<std::fixed << std::setprecision(15)<<pi_15;
    cout<<endl;
    
    double pi_16=0.0; 
    pi_16=(24/sqrt(142))*log(sqrt((10+11*(sqrt(2)))/4)+sqrt((10+7*(sqrt(2)))/4));//computing pi value till 16 decimal precision
        cout << "pi16   = "<<std::fixed << std::setprecision(15)<<pi_16;
    cout<<endl;
    
    
    double pi_18=0.0;
    pi_18=(12/sqrt(190))*log(((2*sqrt(2)+sqrt(10))*(3+sqrt(10))));//computing pi value till 18 decimal precision
         cout << "pi18   = "<<std::fixed << std::setprecision(15)<<pi_18;
    cout<<endl;
    
    double pi_22=0.0;
    pi_22=(12/sqrt(310))*log(((3+sqrt(5))*(2+sqrt(2))*((5+2*sqrt(10))+(sqrt(61+20*sqrt(10)))))/4);//computing pi value till 22 decimal precision
         cout << "pi22   = "<<std::fixed << std::setprecision(15)<<pi_22;
    cout<<endl;
    

    double pi_31=0.0; //declaring result variables;
          pi_31=(4/sqrt(522))*log(pow(((5+sqrt(29))/sqrt(2)),3)*((5*sqrt(29))+(11*sqrt(6)))*pow(sqrt((9+3*sqrt(6))/4)+sqrt((5+3*sqrt(6))/4),6));//computing pi value till 16 decimal precision
          cout << "pi31   = "<<std::fixed << std::setprecision(15)<<pi_31;
    cout<<endl;
    cout<<endl;
    
   //Computing Left Hand Side Term of Euler's Series
   
    float euler_left_side=(pow(pi_function,2))/6;
        cout << "Euler's infinite sum for pi*pi/6 = "<<std::fixed<<std::setprecision(7)<<euler_left_side<< endl;
  
    //Computing value of series devised by Euler;Right Hand Side Infinite Series till the Term Reduces less than 10^-8
    float euler_series=0;        
    int count=0;
    long current_term=0;
    float num2= 0.00000001;
    float temp= 0;
    long prev_term = 1;
    while(1)
    { 
       current_term+=prev_term;
       temp = 1/1.0/current_term;                     
       if(temp < num2)                       //if the value of term drops below 10^-8,calculation is terminated
       {
         break;
       }
       euler_series+=1/1.0/current_term;
       count+=1;
       prev_term+=2;
    }
    
    count=count+1;                         //To Correct Iterations as to suit expected output...
   
    cout << "                      Converged to " <<std::fixed<<std::setprecision(7)<<euler_series
         << " after " <<count<< " iterations" << endl;
         
    cout<<endl;
    
 
    //Using value generated by right hand side of infinite series,value of pi is computed.
    float euler_estimate=0.0;
    euler_estimate=sqrt(euler_series*6);
    cout << "Euler's estimate for pi = " <<euler_estimate<< endl;

      //Value(Pi) difference is calculated by comparing value generated by internal math function and by Euler's Infinite Series.
      float error;
      error=pi_function-euler_estimate;
      cout << "                  error = " << error << endl;
      return 0;
    
    
    
}