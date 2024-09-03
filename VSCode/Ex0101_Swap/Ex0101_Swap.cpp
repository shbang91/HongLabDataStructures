#include <iostream>

using namespace std;


// int MySwapValue(int i, int j)
// {
// 	// TODO:

// 	return ? ;
// }

void MySwapPtr(int* i, int* j)
{
	// TODO:
	int tmp = *i;
	*i = *j;
	*j = tmp;
}


void MySwapRef(int& i, int& j)
{
	if (i > j){
		// TODO:
		int tmp = i;
		i = j;
		j = tmp;
	}
}

bool CheckSorted(int a, int b)
{
	if (a <= b)
		return true;
	
	return false;
}

int main()
{
	// Swap
	{
		int a = 3;
		int b = 2;

		cout << a << " " << b << endl;

		// TODO:
		// MySwapPtr(&a,&b);
		MySwapRef(a, b);


		cout << a << " " << b << endl;
	}


	// 정렬(sorting)
	{
		int arr[] = { 9, 3 };

		cout << arr[0] << " " << arr[1] << endl;

		// TODO:
		if (arr[0] > arr[1]){
			cout << "swap values!" << endl;
			MySwapRef(arr[0], arr[1]);
		}
		cout << arr[0] << " " << arr[1] << endl;
	}

	// 값과 상관 없이 항상 작은 값이 먼저 출력되게 하려면?
	// 두 값이 같을 때는 순서가 상관 없음 -> 큰 값이 먼저 출력되지 않게 하려면?
	{
		int arr[] = {0,1,2,3,4};
		// TODO:

		// 1)
		// int length = sizeof(arr) / sizeof(int);
		// for (int i=0; i < length; i++)
		// 	for (int j=0; j < length; j++){
		// 		MySwapRef(arr[j], arr[i]);
		// 		cout << boolalpha;
		// 		cout << arr[j] << " " << arr[i] << " " << CheckSorted(arr[j], arr[i]) << endl;
		// 	}

		// 2)
		for (int i : arr)
			for (int j : arr)
			{
				MySwapRef(j, i);
				cout << boolalpha;
				cout << j << " " << i << " " << CheckSorted(j, i) << endl;
			}

		
	}

	return 0;
}
