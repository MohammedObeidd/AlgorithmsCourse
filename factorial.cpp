#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

unsigned long Itr(unsigned long n)
{
    unsigned long result = 1;
    for (unsigned long i = 1; i <= n; i++)
        result = result * i;
    return result;
}
unsigned long Rec(unsigned long n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return n * Rec(n - 1);
}
main()
{
    unsigned long n = 262000;

    auto st = high_resolution_clock::now();
    cout << "Iterative: " << Itr(n) << endl;
    auto ed = high_resolution_clock::now();
    double Itr_time = (duration_cast<nanoseconds>(ed - st)).count();
    cout << Itr_time << endl;

    st = high_resolution_clock::now();
    cout << "Recursion: " << Rec(n) << endl;
    ed = high_resolution_clock::now();
    double Rec_time = (duration_cast<nanoseconds>(ed - st)).count();
    cout << Rec_time << endl;
}
