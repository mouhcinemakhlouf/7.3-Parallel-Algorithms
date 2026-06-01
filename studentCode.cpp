#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <algorithm>
#include <execution>

using namespace std;

using LargeInt = unsigned long long;
bool isPrime(LargeInt num){
    LargeInt result = sqrt(num);
    if (num <= 1)
        return false;
    if (num <=3)
        return true;
    
    if (num % 2 == 0)
        return false;
    
    for(LargeInt i=3; i<=result;i+=2){
        if(num % i == 0 )
            return false;
    }
    return true;
}
bool isSemiPrime(LargeInt num){
    LargeInt result = sqrt(num);
    if (num < 4)
        return false;
    for (LargeInt i = 2; i <= result; i++){
        if (num % i == 0){
            LargeInt secondFactor = num / i;
            if (isPrime(i) && isPrime(secondFactor)){
                return i * secondFactor == num;
            } else {
                return false;
            }
        }
    }

    return false;
}


// The date for you to use will be in g_numberData 
vector<LargeInt> g_numberData;

// Your job is to fill g_results with the proper result answering
// if each corresponding element is a semiprime 
// Note that g_results will be already configured to contain the 
// same number of elements as g_numberData you all you have to do
// is set each element to true or false.
vector<bool> g_results;


// Write this function that will fill g_results.
// Note: g_results has already been sized to hold the same number
//  of elements as g_NumberData 
void semiprimeVector() 
{
    transform(execution::par,g_numberData.begin()
    ,g_numberData.end(),
    g_results.begin(),
    [](LargeInt temp ){
        return isSemiPrime(temp);
    });

}

// main will call this just in case you want to add Your
// own test cases 

void runStudentTestCases() {

}