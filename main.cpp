#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Sorting.h"

using namespace std;

#define MIN_value  0
#define MAX_value  1000000
#define Length 100000




void main()
{
	double run_time = -1;
	double Original_Array[Length];
	srand((unsigned)time(NULL));
	for (int i = 0; i < Length; i++)
	{
		Original_Array[i] = (rand() % (MAX_value - MIN_value)) + MIN_value;
	}
//	show_array(Original_Array,Length);

	double S_A[Length];
	copy(Original_Array, S_A, Length);
	run_time = Select_Sorting(S_A, Length, Decreased);
	cout << "Select sort time is " << run_time << "s" << endl;

	double S_B[Length];
	copy(Original_Array, S_B, Length);
	run_time = Bubble_Sorting(S_B, Length, Decreased);
	cout << "Bubble sort time is " << run_time << "s" << endl;


	double S_I[Length];
	copy(Original_Array, S_I, Length);
	run_time = Inser_Sorting(S_I, Length, Decreased);
	cout << "Inser  Sort time is " << run_time << "s" << endl;


	double S_S[Length];
	copy(Original_Array, S_S, Length);
	run_time = Shell_Sorting(S_S, Length, Decreased);
	cout << "Shell  Sort time is " << run_time << "s" << endl;


	double S_M[Length];
	copy(Original_Array, S_M, Length);
	run_time = Merage_sorting(S_M, Length, Decreased);
	cout << "Merage Sort time is " << run_time << "s" << endl;

	double S_Q[Length];
	copy(Original_Array, S_Q, Length);
	run_time = Quick_Sorting(S_Q, Length, Decreased);
	cout << "Quick  Sort time is " << run_time << "s" << endl;

	double S_H[Length];
	copy(Original_Array, S_H, Length);
	run_time = Heap_Sorting(S_H, Length, Decreased);
	cout << "Heap   Sort time is " << run_time << "s" << endl;

	system("pause");
}
