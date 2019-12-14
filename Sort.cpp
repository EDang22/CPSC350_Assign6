/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 6
* Sort implementation class
*/
#include <iostream>
#include "Sort.h"
#include <stdlib.h>
#include <ctime>
#include <fstream>

using namespace std;

// default constructor, generates random array of 100000 doubles
Sort::Sort()
{
  srand(time(NULL));
  arr = new double[100000];
  numL = 100000;
  for (int i = 0; i < numL; ++i)
  {
    arr[i] = (double) (rand() % 100000 + 1);
  }
}

// overloaded constructor, reads from file to generate array
Sort::Sort(string f)
{
  ifstream file(f);
  if(file)
  {
    string line = "";
    try
    {
      getline(file, line); // first line, represents number of elements
      numL = stoi(line);
      for (int i = 0; i < numL; ++i)
      {
        getline(file, line);
        arr[i] = stod(line);
      }
    }
    catch(invalid_argument const &e)
    {
      cout << "Error: improper file format" << endl;
    }
    catch(out_of_range const &e)
    {
      cout << "Error: improper file format" << endl;
    }
  }
  else
  {
    cerr << "Error: File could not be opened" << endl;
    arr = NULL;
  }
}

// destructor
Sort::~Sort()
{
  delete arr;
}

// creates duplicates of array and runs each sorting method
void Sort::sortArray()
{
  if (arr == NULL)
    return;

  double bubbleArr[numL];
  double selectionArr[numL];
  double insertionArr[numL];
  double quickArr[numL];

  for (int i = 0; i < numL; ++i)
  {
    bubbleArr[i] = arr[i];
    selectionArr[i] = arr[i];
    insertionArr[i] = arr[i];
    quickArr[i] = arr[i];
  }

  time_t s; // start time
  time_t f; // finish time

  // Bubble Sort
  time(&s);
  bubbleSort(bubbleArr, numL);
  time(&f);
  cout << "Bubble Sort complete total time: " << difftime(f, s) << " seconds" << endl;

  // Selection Sort
  time(&s);
  selectionSort(selectionArr, numL);
  time(&f);
  cout << "Selection Sort complete total time: " << difftime(f, s) << " seconds" << endl;

  // Insertion Sort
  time(&s);
  insertionSort(insertionArr, numL);
  time(&f);
  cout << "Insertion Sort complete total time: " << difftime(f, s) << " seconds" << endl;

  // Quick Sort
  time(&s);
  quickSort(quickArr, 0, numL);
  time(&f);
  cout << "Quick Sort complete total time: " << difftime(f, s) << " seconds" << endl;
}

// bubble sort method
void Sort::bubbleSort(double myArray[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    int temp = 0;
    for (int j = 0; j < n - 1; ++j)
    {
      if(myArray[j] > myArray[j + 1])
      {
        temp = myArray[j + 1];
        myArray[j + 1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

// selection sort method
void Sort::selectionSort(double myArray[], int n)
{
  int minIndex = 0;
  int temp = 0;
  for (int i = 0; i < n - 1; ++i)
  {
    minIndex = i;
    for (int j = i + 1; j < n; ++j)
    {
      if (myArray[j] < myArray[minIndex])
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
    {
      temp = myArray[i];
      myArray[i] = myArray[minIndex];
      myArray[minIndex] = temp;
    }
  }
}

// insertion sort method
void Sort::insertionSort(double myArray[], int n)
{
  for (int j = 1; j < n; ++j)
  {
    double temp = myArray[j];
    int k = j;
    while (k > 0 && myArray[k - 1] >= temp)
    {
      myArray[j] = myArray[k - 1];
      --k;
    }
    myArray[k] = temp;
  }
}

// quick sort recursive method
void Sort::quickSort(double myArray[], int l, int h)
{
  if (l < h)
  {
    int p = partition(myArray, l, h);
    quickSort(myArray, l, p - 1);
    quickSort(myArray, p + 1, h);
  }
}

// quick sort partition method, finds correct index of pivot
double Sort::partition(double myArray[], int l, int h)
{
  double pivot = myArray[h];
  int i = l - 1;
  double temp = 0.0;
  for (int j = l; j < h; ++j)
  {
    if (myArray[j] <= pivot)
    {
      ++i;
      temp = myArray[i];
      myArray[i] = myArray[j];
      myArray[j] = temp;
    }
  }
  temp = myArray[i + 1];
  myArray[i + 1] = myArray[h];
  myArray[h] = temp;
  return i + 1; // correct index of pivot point
}
