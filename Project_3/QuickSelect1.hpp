#ifndef QUICKSELECT1_HPP
#define QUICKSELECT1_HPP

//Name: Rio Simpson
//Description: Header file for QuickSelect1 class

//Libraries
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

/* Project Specifications
For method 2, using quickSelect 3 times, the idea is simple: call quickSelect on the entire input with the middle of the vector as the key, k. 
This will give you the median, around which your vector will be partitioned. Then, call quickSelect on the half of the vector before 
the median with the 25% mark of the vector as k. Then, call quickSelect on the half of the vector after the median with the 75% mark as k. 
Then, search for the minimum only before the 25% mark, and the maximum only after the 75% mark. Default to insertion sort when quickSelect is 
recursively called on a range of size 20 or less (this means you'll have to write a small in-place insertion sort).

For method 2, find the median first. Then, on the same vector that's already partitioned around the median, call quickselect on the left half to 
find P25 and on the right half to find P75. Then, search the part of the vector below P25 for the min and above P75 for the max.
*/


//helper functions
//sorts data using insertion sort of size <= 20
void insertionSort(std::vector<int>& data);
//partitions using halfway point between left and right input
int partition(std::vector<int>& data, int left, int right);
//recursive quickselect function that returns the index of the value belonging to the desired key
int quickSelect(std::vector<int>& data, int left, int right, int key);

//QuickSelect1.cpp, containing the function void quickSelect1(const std::string & header, std::vector<int> data)
void quickSelect1(const std::string& header, std::vector<int> data);

#endif