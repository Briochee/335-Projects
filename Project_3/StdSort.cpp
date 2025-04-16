//Name: Rio Simpson
//Description: Implementation file for StdSort class

//Libraries
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

//header file
#include "StdSort.hpp"

/* Project Specifications
For method 1, just use std::sort and print out the appropriate data points. 
This is to ensure that you have the correct answer and are printing correctly, 
and to give you a baseline to time your other algorithms against.
*/

//sorting function
void stdSort(const std::string& header, std::vector<int> data){
    // //starting timer
    // auto start1 = std::chrono::high_resolution_clock::now();

    //variables to hold min, p25, median, p75, and max
    int min = 0, p25 = 0, median = 0, p75 = 0, max = 0;

    //using std::sort
    std::sort(data.begin(), data.end());
    if (data.size() % 2 == 0){
        int median_index = (data.size() - 1)/2;
        //calculating median to be lower of middle value
        median = data[median_index];
        //calculating 25th percentile to be middle value of lower hald
        p25 = data[median_index/2];
        //calculating 75th percentile to be middle value of upper half
        p75 = data[median_index + ((data.size() - median_index)/2)];
    } else {
        int median_index = (data.size())/2;
        //calculating median to be lower of middle value
        median = data[median_index];
        //calculating 25th percentile to be middle value of lower hald
        p25 = data[median_index/2];
        //calculating 75th percentile to be middle value of upper half
        p75 = data[median_index + ((data.size() - median_index)/2)];
    }

    //storing min and max for now sorted vector
    min = data[0];
    max = data[data.size() - 1];

    // //ending timer
    // auto end1 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration1 = end1 - start1;
    // std::cout << "StdSort Completed in: " << duration1.count() * 1000 << " milliseconds\n";

    //printiing out data as specified by project specifications
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
}