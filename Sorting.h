#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <iomanip>

#define OUTPUT_WIDTH 6
#define Time_init	LARGE_INTEGER lFrequency; QueryPerformanceFrequency(&lFrequency);  
#define Time_begin	LARGE_INTEGER lBeginCount; QueryPerformanceCounter(&lBeginCount);
#define Time_end	LARGE_INTEGER lEndCount; QueryPerformanceCounter(&lEndCount);

enum Order { Increased, Decreased };
// enum data type,using choose increased list or decreased list

void copy(int Array_1[], int Array_2[], int length);
void copy(double Array_1[], double Array_2[], int length);
// copy function, overload function to adopt for int and double data type

void show_array(const double Array[], int length, double run_time = -1);
//show array function, tun_time parameter default value is -1, do not show the run time if did not pass run_time paramater

void swap(double &A, double &B);
// swap two elements

double Bubble_Sorting(double Array[], int length, Order Type = Increased);
// bubble sort and default order is increased

double Select_Sorting(double Array[], int length, Order Type = Increased);
// select sort and default order is increased

double Inser_Sorting(double Array[], int length, Order Type = Increased);
// inser sort and default order is increased

double Shell_Sorting(double Array[], int length, Order Type = Increased);
// shell sort and default order is increased

/*Merage sort*/
void merage(double a[], int first, int mid, int last, Order Type = Increased);
void seprate(double a[], int first, int last, Order Type = Increased);
double Merage_sorting(double a[], int n, Order Type = Increased);
/*Merage sort*/

/*Quick sort*/
void quicksort(double Array[], int left, int right, Order Type = Increased);
double Quick_Sorting(double Array[], int length, Order Type = Increased);
/*Quick sort*/

/*Heap sort*/
void AdjustHeap(double Array[], int length, int fatherpoint, Order Type = Increased);
double Heap_Sorting(double Array[], int length, Order Type = Increased);
/*Heap sort*/