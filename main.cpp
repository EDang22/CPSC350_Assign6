/*
* Ethan Dang
* 2326380
* edang@chapman.edu
* CPSC 350-02
* Assignment 6
* Main class, creates sort object and runs sim
*/
#include <iostream>
#include "Sort.h"

using namespace std;

int main(int argc, char** argv)
{
  if(argc == 2) // file given
  {
    Sort s(argv[1]);
    s.sortArray();
  }
  else // no file given, random array to be generated
  {
    Sort s;
    s.sortArray();
  }
  return 0;
}
