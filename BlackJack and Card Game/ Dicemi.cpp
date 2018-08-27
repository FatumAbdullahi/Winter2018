#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void clear()
{
    for(int i=0; i < 7; i++)
        arr[i] =0;
}


void Q11()
{
    int N=10;
    int arr[N];
    int i=0;
    int num_occ;
    cout << "Q1" << endl;	
    for (int i = 0; i < N; i++)
      {
       arr[i]=(1 + rand() / (RAND_MAX /6 +1));      
       cout<<arr[i];
       }     

    cout << "For " << N << " rolls:" << endl; 
    
    #define MAX_VALUE 6

    int counts[N];
    for(int i = 0; i < N; i++)
	    counts[i] = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= MAX_VALUE) {
            counts[arr[i]]++; // increment the counter for the current value
        }
    }
    for (int j = 1; j <= MAX_VALUE; j++) {
        cout << j << " : " << float(counts[j])/float(10) << endl;
        }
  clear();    
  return 0;
  }
  

void Q12()
{
    int N=1000;
    int arr[N];
    int i=0;
    int num_occ;
    cout << "Q1" << endl;	
    for (int i = 0; i < N; i++)
      {
       arr[i]=(1 + rand() / (RAND_MAX /6 +1));      
       cout<<arr[i];
       }     

    cout << "For " << N << " rolls:" << endl; 
    
    #define MAX_VALUE 6

    int counts[N];
    for(int i = 0; i < N; i++)
	    counts[i] = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= MAX_VALUE) {
            counts[arr[i]]++; // increment the counter for the current value
        }
    }
    for (int j = 1; j <= MAX_VALUE; j++) {
        cout << j << " : " << float(counts[j])/float(10) << endl;
        }
  clear();    
  return 0;
  }

void Q13()
{
    int N=100000;
    int arr[N];
    int i=0;
    int num_occ;
    cout << "Q1" << endl;	
    for (int i = 0; i < N; i++)
      {
       arr[i]=(1 + rand() / (RAND_MAX /6 +1));      
       cout<<arr[i];
       }     

    cout << "For " << N << " rolls:" << endl; 
    
    #define MAX_VALUE 6

    int counts[N];
    for(int i = 0; i < N; i++)
	    counts[i] = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= MAX_VALUE) {
            counts[arr[i]]++; // increment the counter for the current value
        }
    }
    for (int j = 1; j <= MAX_VALUE; j++) {
        cout << j << " : " << float(counts[j])/float(10) << endl;
        }
  clear();    
  return 0;
  }

int main(void){
	Q11;
	Q12;
	Q13;
	return 0;

}







