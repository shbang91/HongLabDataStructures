#include <iostream>
#include <cassert>
#include <algorithm> // swap
#include <iomanip> // setw

using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0; // F0 = 0 
	else if (n == 1)
		return 1; // F1 = 1
	else
	{
		int fn = 0;

		// TODO:
		int prev_1 = 0;
		int prev_2 = 1;
		for (int i(2); i < n+1; i++)
		{
			fn = prev_1 + prev_2;

			// update
			prev_1 = prev_2;
			prev_2 = fn; 
		}
		
		return fn;
	}
}

int RecurFibonacci(int n)
{
	// termination conditions
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else{
		// change
		return RecurFibonacci(n-1) + RecurFibonacci(n-2);
	}
}

int main()
{
	// Input      : 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
	// Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377
	// Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377

	cout << "Input     : ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << i << " ";
	cout << endl;

	// Fibonnacci
	cout << "Fibonnacci: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << Fibonacci(i) << " ";
	cout << endl;

	cout << "Fibonnacci: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << RecurFibonacci(i) << " ";
	cout << endl;

	return 0;
}
