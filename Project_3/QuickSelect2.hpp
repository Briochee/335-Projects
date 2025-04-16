#ifndef QUICKSELECT2_HPP
#define QUICKSELECT2_HPP

//Name: Rio Simpson
//Description: Header file for QuickSelect2 class

//Libraries
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <unordered_map>

/* Project Specifications
For method 3, replace the key k in your quickSelect's parameters with a set of keys you're looking for 
(use whatever container you want to hold them), which will include position 0, the 25% mark, the 50% mark, 
the 75% mark, the the last position of the data vector. Rewrite the recursive portion of quickSelect so that it 
checks whether it needs to recurse on both sides (if there are keys you need to find on both sides of the range being called), 
or if it only needs to recurse on one side. This may be tricky to work out, but once you figure out the algorithm, 
it's not really much coding to implement. Again, default to insertion sort once you reach a size of 20 or less.

For method 3, modify quickselect's recursive function to take a short list of keys rather than just one key. 
If you refer to p.322 in the textbook, you can replace the parameter int k with a small vector or list. 
Then rewrite the recursive portion so that quickselect calls itself on one or both sides, depending on whether 
there are positions you're searching for on both sides or only one.
*/

//helper functions -- made non member so gradescope could see
//sorts data using insertion sort of size <= 20
void insertionSort2(std::vector<int>& arr, int low, int high);
//function returns pivot index of value half way between left and right and partitions data to left and right of pivot
int partition2(std::vector<int>& data, int left, int right);
//returns vector of values belonging to the desired keys
std::unordered_map<int, int> quickSelect(std::vector<int>& data, int left, int right, std::vector<int> keys);

//QuickSelect2.cpp, containing the function void quickSelect2(const std::string & header, std::vector<int> data)
void quickSelect2(const std::string& header, std::vector<int> data);


#endif