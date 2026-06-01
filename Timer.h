#include <chrono>
#include <iostream>

using namespace std;

class Timer 
{
public:
    Timer(bool verbose) : printResult(verbose) { 
        start_seq = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        auto end_seq = chrono::high_resolution_clock::now();
        chrono::duration<double> duration_seq = end_seq - start_seq;
        if (printResult) cout << "took: " << duration_seq.count() << " seconds." << endl;
    }

private: 
    bool printResult;
    chrono::time_point<chrono::high_resolution_clock> start_seq;
};