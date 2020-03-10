#include "Sorting.h"

using namespace std;

void copy(int Array_1[], int Array_2[], int length)
{
	for (int i = 0; i < length; i++)
	{
		Array_2[i] = Array_1[i];
	}
}
void copy(double Array_1[], double Array_2[], int length)
{
	for (int i = 0; i < length; i++)
	{
		Array_2[i] = Array_1[i];
	}
}

void show_array(const double Array[], int length, double run_time)
{
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		cout << std::left << setw(OUTPUT_WIDTH) << Array[i];
	}
	if (run_time != -1)
		cout << endl << "The order time is " << run_time << "s" << endl;
	cout << endl;
}

void swap(double &A, double &B)
{
	double temp;
	temp = A;
	A = B;
	B = temp;
}


double Bubble_Sorting(double Array[], int length, Order Type)
{
	bool sentinel = true;
	Time_init;
	Time_begin;
	if (Type == Increased)
	{
		for (int i = 0; i < length; i++)
		{
			sentinel = true;
			for (int j = i + 1; j < length; j++)
			{
				if (Array[i] > Array[j])
				{
					swap(Array[i], Array[j]);
					sentinel = false;
				}
			}
			if (sentinel)
				break;
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			sentinel = true;
			for (int j = i + 1; j < length; j++)
			{
				if (Array[i] < Array[j])
				{
					swap(Array[i], Array[j]);
					sentinel = false;
				}
			}
			if (sentinel)
				break;
		}
	}
	Time_end;
	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
	return time;
}


double Select_Sorting(double Array[], int length, Order Type)
{
	Time_init;
	Time_begin;
	if (Type == Increased)
	{
		for (int i = 0; i < length; i++)
		{
			int min = i + 1;
			if (min >= length)
				break;
			for (int j = i + 2; j < length; j++)
			{
				if (Array[min] > Array[j])
				{
					min = j;
				}
			}
			if (Array[min] < Array[i])
			{
				swap(Array[min], Array[i]);
			}
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			int max = i + 1;
			if (max >= length)
				break;
			for (int j = i + 2; j < length; j++)
			{
				if (Array[max] < Array[j])
				{
					max = j;
				}
			}
			if (Array[max] > Array[i])
			{
				swap(Array[max], Array[i]);
			}
		}
	}
	Time_end;
	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
	return time;
}


double Inser_Sorting(double Array[], int length, Order Type)
{
	int inser_index = -1;
	int wait_inser_element;
	Time_init;
	Time_begin;
	if (Type == Increased)
	{
		for (int i = 1; i < length; i++)
		{
			inser_index = -1;
			wait_inser_element = Array[i];
			for (int k = 0; k < i; k++)
			{
				if (Array[k] > wait_inser_element)
				{
					inser_index = k;
					break;
				}
			}
			if (inser_index != -1)
			{
				for (int j = i - 1; j >= inser_index; j--)
				{
					Array[j + 1] = Array[j];
				}
				Array[inser_index] = wait_inser_element;
			}
		}
	}
	else
	{
		for (int i = 1; i < length; i++)
		{
			inser_index = -1;
			wait_inser_element = Array[i];
			for (int k = 0; k < i; k++)
			{
				if (Array[k] < wait_inser_element)
				{
					inser_index = k;
					break;
				}
			}
			if (inser_index != -1)
			{
				for (int j = i - 1; j >= inser_index; j--)
				{
					Array[j + 1] = Array[j];
				}
				Array[inser_index] = wait_inser_element;
			}
		}
	}
	Time_end;
	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
	return time;
}


double Shell_Sorting(double Array[], int length, Order Type)
{
	int inser_index = -1;
	int wait_inser_element;
	Time_init;
	Time_begin;
	for (int gap = length / 2; gap > 0; gap = gap / 2)
	{	
		if (Type == Increased)
		{
			for (int t = 0; t < gap; t++)
			{
				for (int i = t + gap; i < length; i += gap)
				{
					inser_index = -1;
					wait_inser_element = Array[i];
					for (int k = t; k < i; k += gap)
					{
						if (Array[k] > wait_inser_element)
						{
							inser_index = k;
							break;
						}
					}
					if (inser_index != -1)
					{
						for (int j = i - gap; j >= inser_index;j = j-gap)
						{
							Array[j + gap] = Array[j];
						}
						Array[inser_index] = wait_inser_element;
					}
				}
			}
		}
		else
			for (int t = 0; t < gap; t++)
			{
				for (int i = t + gap; i < length; i += gap)
				{
					inser_index = -1;
					wait_inser_element = Array[i];
					for (int k = t; k < i; k += gap)
					{
						if (Array[k] < wait_inser_element)
						{
							inser_index = k;
							break;
						}
					}
					if (inser_index != -1 && inser_index != i)
					{
						for (int j = i - gap; j >= inser_index; j = j - gap)
						{
							Array[j + gap] = Array[j];
						}
						Array[inser_index] = wait_inser_element;
					}
				}
			}
	}
	Time_end;
	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
	return time;
}

void merage(double Array[], int first, int mid, int last, Order Type)
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	double *temp = new double[last - first];
	if (Type == Increased)
	{
		while (i <= m && j <= n)
		{
			if (Array[i] <= Array[j])
				temp[k++] = Array[i++];
			else
				temp[k++] = Array[j++];
		}
	}
	else
	{
		while (i <= m && j <= n)
		{
			if (Array[i] >= Array[j])
				temp[k++] = Array[i++];
			else
				temp[k++] = Array[j++];
		}
	}
	while (i <= m)
		temp[k++] = Array[i++];

	while (j <= n)
		temp[k++] = Array[j++];

	for (i = 0; i < k; i++)
		Array[first + i] = temp[i];
}

void seprate(double Array[], int first, int last, Order Type)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		seprate(Array, first, mid, Type);
		seprate(Array, mid + 1, last, Type);
		merage(Array, first, mid, last, Type);
	}
}

double Merage_sorting(double Array[], int length, Order Type)
{
	Time_init;
	Time_begin;
	seprate(Array, 0, length - 1, Type);
	Time_end;
	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
	return time;
}

void quicksort(double Array[], int left, int right, Order Type)
{
	if (left < right)
	{
		double temp = Array[left];
		bool moveright = true;
		bool moveleft = false;
		bool findright = false;
		bool findleft = false;
		int leftpoint;
		int rightpoint;
		if (Type == Increased)
		{
			for (leftpoint = left, rightpoint = right; leftpoint < rightpoint;)
			{
				if (moveright)
				{
					if (Array[rightpoint] >= temp)
					{
						rightpoint--;
					}
					else
					{
						moveright = false;
						moveleft = true;
						findright = true;
					}
				}
				if (moveleft)
				{
					if (Array[leftpoint] <= temp)
					{
						leftpoint++;
					}
					else
					{
						moveleft = false;
						moveright = true;
						findleft = true;
					}
				}
				if (findleft && findright)
				{
					if (leftpoint < rightpoint)
					{
						swap(Array[leftpoint], Array[rightpoint]);
						findleft = false;
						findright = false;
					}
					else
						break;
				}
			}
			swap(Array[left], Array[leftpoint]);
			quicksort(Array, left, leftpoint - 1, Type);
			quicksort(Array, leftpoint + 1, right, Type);
		}
		else
		{
			for (leftpoint = left, rightpoint = right; leftpoint < rightpoint;)
			{
				if (moveright)
				{
					if (Array[rightpoint] <= temp)
					{
						rightpoint--;
					}
					else
					{
						moveright = false;
						moveleft = true;
						findright = true;
					}
				}
				if (moveleft)
				{
					if (Array[leftpoint] >= temp)
					{
						leftpoint++;
					}
					else
					{
						moveleft = false;
						moveright = true;
						findleft = true;
					}
				}
				if (findleft && findright)
				{
					if (leftpoint < rightpoint)
					{
						swap(Array[leftpoint], Array[rightpoint]);
						findleft = false;
						findright = false;
					}
					else
						break;
				}
			}
			swap(Array[left], Array[leftpoint]);
			quicksort(Array, left, leftpoint - 1, Type);
			quicksort(Array, leftpoint + 1, right, Type);
		}
	}
}

double Quick_Sorting(double Array[], int length, Order Type)
{
	Time_init;
	Time_begin;
	quicksort(Array, 0, length - 1, Type);
	Time_end;
	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
	return time;
}


void AdjustHeap(double Array[], int length, int fatherpoint, Order Type)
{
	int temppoint;
	int currentpoint;
	if (Type == Increased)
	{
		while (fatherpoint * 2 + 1 < length)
		{
			temppoint = fatherpoint;
			currentpoint = fatherpoint * 2 + 1;
			if (currentpoint + 1 < length)
			{
				if (Array[currentpoint] < Array[currentpoint + 1])
				{
					currentpoint++;
				}
			}
			if (Array[temppoint] < Array[currentpoint])
			{
				swap(Array[temppoint], Array[currentpoint]);
				fatherpoint = currentpoint;
			}
			else
				break;
		}
	}
	else
	{
		while (fatherpoint * 2 + 1 < length)
		{
			temppoint = fatherpoint;
			currentpoint = fatherpoint * 2 + 1;
			if (currentpoint + 1 < length)
			{
				if (Array[currentpoint] > Array[currentpoint + 1])
				{
					currentpoint++;
				}
			}
			if (Array[temppoint] > Array[currentpoint])
			{
				swap(Array[temppoint], Array[currentpoint]);
				fatherpoint = currentpoint;
			}
			else
				break;
		}
	}
}

double Heap_Sorting(double Array[], int length, Order Type)
{
	Time_init;
	Time_begin;
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		AdjustHeap(Array, length, i, Type);
	}
	for (int end = length - 1; end >= 0; end--)
	{
		swap(Array[end], Array[0]);
		AdjustHeap(Array, end, 0, Type);
	}
	Time_end;
	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
	return time;
}