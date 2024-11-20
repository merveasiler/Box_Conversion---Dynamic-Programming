#ifndef _THE_4_H_
#define _THE_4_H_

#include <iostream>
#include <climits>
#include <cmath>
#include <string>

//int recursive_sln(int i, int j, char**& arr1, char**& arr2, int nrow, int ncol1, int ncol2, int &number_of_calls);
//int memoization_sln(int i, int j, char**& arr1, char**& arr2, int nrow, int ncol1, int ncol2, int**& mem);
int dp_sln(char**& arr1, char**& arr2, int nrow, int ncol1, int ncol2, int**& mem);

#endif
