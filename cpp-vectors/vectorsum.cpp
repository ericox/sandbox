// Program vectorsum.cpp sums the elements in an int vector and prints it to 
// stdout char stream.
//
// Coursera: C++ for C programmers
// Due Date: 8/7/2016 
// Author: Eric Cox
//
#include <iostream>
#include <vector>

const int N = 40; // N is the maximim size of the vector

using namespace std;

// sum is an inlined function that accumulates the sum of n item in a vector d
// into the value of an int* p.
inline int sum(int n, const vector<int>& d)
{
	int p = 0;
	for(int i = 0; i < n; ++i)
		p += d[i];
	return p;
}

int main()
{
	int accum = 0; 
	vector<int> data(N);
	for (int i = 0; i < N; ++i)
		data[i] = i;

	accum = sum(N, data);
	cout << "sum is " << accum << endl;
	return 0;
}
