#include <iostream>
#include <chrono>
#include <thread>
#include <omp.h>
using namespace std;
using namespace chrono_literals;

int main()
{
	double start = omp_get_wtime();
	cout << "Going to sleep for 5 seconds"
		" and 300 milli seconds.\n";
	this_thread::sleep_for(5s + 300ms);
	cout << "Going to sleep for another 3 seconds.\n";
	this_thread::sleep_until(
		chrono::high_resolution_clock::now() + 3s);
	cout << "That's it.\n";
	double end = omp_get_wtime();
	cout << "Total time result: " << (end - start) << "\n";
}