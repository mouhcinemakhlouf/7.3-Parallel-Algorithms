#include <iostream>
#include <vector>
#include <random>
#include <thread>

#include <cmath>
#include <algorithm>
#include "Timer.h"


using namespace std;

void semiprimeVector();
// main will call this just in case you want to add Your
// own test cases 
void runStudentTestCases();

using LargeInt = unsigned long long;

extern vector<LargeInt> g_numberData;
extern vector<bool> g_results;
void checkArray();

const int EASY_SIZE = 7;
LargeInt easy[] = { 7, 9, 12, 5, 13, 23, 25 };
const int MED_SIZE = 10;
LargeInt medium[] = { 7524535, 13, 10009, 10007*10009, 10007, 25*8, 15*3, 23*23, 100*100+1, 98463527};
const int HARD_SIZE = 16;
LargeInt hard1[] = { 99991*9907, 98303927,   224444333, 1743*80557, 863991439, 98303927, 10009*10009, 224444333,
                     224444333,  10009*10009, 98303927, 863991439,  1743*80557,224444333, 98303927,  99991*9907};
LargeInt hard2[] = { 199403,     98303927, 98303927,  224444333,  863991439, 98303927,  17191 ,     224444333,
                     199403,     98303927, 98303927,  224444333,  863991439, 98303927,  17191 ,     224444333};


LargeInt primes[] = { 7, 5, 13, 23, 10007, 10009, 224444333, 98303927, 863991439 };
LargeInt nonPrimes[] = { 4, 9, 12, 49, 25, 224444334, 25*25, 10009 * 10009 };


enum class Difficulty
{
    EASY,
    MEDIUM,
    HARD
};

// Stub function
void generateTestData(Difficulty difficulty)
{
    vector<LargeInt> data;

    void runStudentTestCases();

    switch (difficulty)
    {
        case Difficulty::EASY:
            for (int i = 0; i < EASY_SIZE; i++)
            {
                g_numberData.push_back(easy[i]);
            }
            break;

        case Difficulty::MEDIUM:
            for (int i = 0; i < MED_SIZE; i++)
            {
                g_numberData.push_back(medium[i]);
            }
            break;

        case Difficulty::HARD:
            for (int i = 0; i < HARD_SIZE; i++)
            {
                g_numberData.push_back(hard1[i]*hard2[i]);
            }
            break;
    }

    g_results.resize(g_numberData.size()); 
}

int main()
{
    Difficulty difficulty;
    bool printTiming = false;

    // ----------------------------------------
    // 1. Select difficulty
    // ----------------------------------------
    string choice;

    cout << "Select test case difficulty "
            << "(easy, medium, hard): ";

    cin >> choice;

    if (choice == "easy")
    {
        difficulty = Difficulty::EASY;
    }
    else if (choice == "medium")
    {
        difficulty = Difficulty::MEDIUM;
    }
    else if (choice == "hard")
    {
        difficulty = Difficulty::HARD;
    }
    else
    {
        cout << "Invalid choice. Please enter "
                << "easy, medium, or hard.\n";
        return 1;
    }


    // ----------------------------------------
    // 3. Print timing?
    // ----------------------------------------
    while (true)
    {
        cout << "Print timing? (yes/no): ";

        cin >> choice;

        if (choice == "yes")
        {
            printTiming = true;
            break;
        }
        else if (choice == "no")
        {
            printTiming = false;
            break;
        }
        else
        {
            cout << "Please enter yes or no.\n";
        }
    }

    // ----------------------------------------
    // Generate test data
    // ----------------------------------------
    generateTestData(difficulty);

    cout << "\nConfiguration:\n";
    cout << "Timing: "
         << (printTiming ? "Yes" : "No") << '\n';
    cout << "Test data size: "
         << g_numberData.size() << '\n';

    Timer timeThisCode(printTiming);

    semiprimeVector();

    for (size_t i = 0; i < g_numberData.size(); i++)
    {
        cout << g_numberData[i] << " -> " << g_results[i] << endl;
    }

    return 0;
}