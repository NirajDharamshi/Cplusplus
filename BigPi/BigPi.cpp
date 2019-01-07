//--------------------------------------------------------------------------------------------------//
//Created by: Niraj Dharamshi
//Assignment No. 4 of 180-C,Big Pi in Spring 2018
//Instructor Ron Mak
//-------------------------------------------------------------------------------------------------//

#include <iostream>
#include <iomanip>
#include <mpir.h>                           //MPIR library
#include <stdlib.h> 
#include <string.h>
#include <math.h>               
#include <chrono>                           //For time computation

using namespace std::chrono;
using namespace std;
const int MAX_ITERATIONS = 10;             
const int PLACES         = 1000000;           // Number of digits to be generated after decimal
const int PRECISION      = PLACES + 1;     // One digit before decimal i.e. 3
const int BASE       = 10;                 // base 10 numbers
const int BIT_COUNT  = 8;                  // bits per machine word
const int BLOCK_SIZE = 10;                 // print digits in blocks
const int LINE_SIZE  = 100;                // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;   // lines to print
const int GROUP_SIZE = 5;                  // line grouping size


void print(const mpf_t& big_pi)
{

    int count=0;
    char *str=NULL;
    char *newPtr=(char *)malloc(sizeof(char)*1000000);     //Allocating huge memory for storing pi digits
    mp_exp_t exp;
    newPtr = mpf_get_str(str,&exp,BASE,PRECISION,big_pi);    // converts pi into c_string
    cout<<newPtr[0]<<".";                                    // printing digit before decimal i.e. 3 
    int i=1; 
    while(i<=PRECISION)
    {  
        cout<<newPtr[i];                                      //printing digit
        if(i%BLOCK_SIZE==0)                                   //checking if 10 digits(block) are printed
        {
            cout<<" ";
            if(i%LINE_SIZE==0)                                //checking if the 100 digits are printed 
            {
                cout<<endl;                                   //new line
                cout<<" ";
                count++;                                      
                if(count%GROUP_SIZE==0)                       //checking if vertical group of lines i.e 5 is reached
                {
                    cout<<endl;
                    cout<<" ";
                }
            }
        }
        i++;
    }   
    
     
}


auto time()
{
    return std::chrono::system_clock::now(); 
}


int main(){

  mpf_set_default_prec(BIT_COUNT*PRECISION);
    //Variable declaration
    mpf_t a0;
    mpf_t two;
    mpf_t root_two;
    mpf_t a;
    mpf_t a0t2;
    mpf_t y0;
    mpf_t y04;
    mpf_t one_y04;
    mpf_t root_four;
    mpf_t num;
    mpf_t den;
    mpf_t Yi;
    mpf_t a1t1;
    mpf_t temp;
    mpf_t a1t2;
    mpf_t temp2;
    mpf_t y0_square;
    mpf_t temp3;
    mpf_t big_pi;
    mpf_t temp4;
    //Variable Initialisation
    mpf_init(temp4);
    mpf_init(big_pi);
    mpf_init(a0);
    mpf_init (Yi);
    mpf_init (den);
    mpf_init (num);
    mpf_init (root_four);
    mpf_init (one_y04);
    mpf_init(y04);
    mpf_init(root_two);
    mpf_init(a0);
    mpf_init(two);
    mpf_init (a);
    mpf_init (a1t1);
    mpf_init (temp);
    mpf_init(y0);
    mpf_init (temp3);
    mpf_init (temp2);
    mpf_init (a1t2);
    mpf_init (y0_square);
    mpf_init(a0t2);
    
   //Recording start time of the computation
    
    auto start=time();
    // Calculating a0
   
    mpf_ui_sub(two,2u,two);           
    mpf_sqrt(root_two,two);          //square root of 2
    mpf_mul_ui(a0t2,root_two,4);     // 4 * sqrt(2)
    mpf_ui_sub(a0,6u,a0t2);          // a0=6-4*sqrt(2)

    //Calculating y0
    
    mpf_sub_ui(y0, root_two, 1u);    //y0=sqrt(2)-1

    //Computing ai in multiple iterations towards convergence

    for (int i = 1; i <=MAX_ITERATIONS; i++)
    {
    
    //Calculating yi
    mpf_pow_ui(y04, y0, 4u);         //y^4
    mpf_ui_sub(one_y04, 1u, y04);    //1-y^4
    mpf_sqrt(root_four, one_y04);    
    mpf_sqrt(root_four, root_four);  //quadroot(1-y^4)
    mpf_ui_sub(num, 1u, root_four);  //1-quadroot(1-y^4)
    mpf_add_ui(den,root_four,1u);    //1+quadroot(1-y^4)
    mpf_div(Yi, num, den);           // yi={1-quadroot(1-y^4)}/{1+quadroot(1-y^4)}

    // Calculate ai

    //Calculate First Term


    mpf_add_ui(temp,Yi,1u);          //1+yi
    mpf_pow_ui(temp, temp, 4u);      //(1+yi)^4
    mpf_mul(a1t1, a0, temp);         //a0*(1+y)^4

    //Calculate Second Term
   
    double power_term= (2*i)+1;           // 2i+1
    double two_power=pow(2,power_term);   // 2^(2i+1)
    mpf_mul_ui(temp2, Yi,two_power);      //yi*2^(2i+1)
    mpf_mul(y0_square, Yi, Yi);           //yi^2
    mpf_add(temp3, Yi, y0_square);        //yi^2 + yi
    mpf_add_ui(temp4,temp3,1u);           //yi^2 +  yi  + 1
    mpf_mul(a1t2, temp2, temp4);          //(yi^2 +  yi  + 1)*(yi)*(2^2i+1)

  
    mpf_sub(a, a1t1, a1t2);               //a0*(1+y)^4-(yi^2 + yi + 1)*(yi)*(2^2i+1)
    mpf_set(a0,a);                        
    mpf_set(y0,Yi);

    }

   
    mpf_ui_div(big_pi,1u,a0);             //pi=1/ai

 //recording time to mark end of computation
  
      auto end = time();

   
   std::chrono::duration<double> elapsed_seconds = end-start;     //Calculating time taken to execute
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);  
   

    
    print(big_pi);         //printing pi

    cout<<endl;

    
  

     std::cout << "Finished computing enormous digits of Pi on " << std::ctime(&end_time)
              << "in " << elapsed_seconds.count() <<"s\n"<<" It's just Awesome! ";
    

    return 0;
}




