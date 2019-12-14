/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 6
* Sort header file
*/
#ifndef SORT_H
#define SORT_H
#include <iostream>

using namespace std;

class Sort
{
  private:
    double* arr;
    int numL;

  public:
    Sort(); // constructor to generate random array
    Sort(string f); // construtor that reads from file
    ~Sort(); // destructor

    // runs simulation
    void sortArray();

    // sorting algorithms
    void bubbleSort(double myArray[], int n);
    void selectionSort(double myArray[], int n);
    void insertionSort(double myArray[], int n);
    void quickSort(double myArray[], int l, int h);
    double partition(double myArray[], int l, int h);

};
#endif
