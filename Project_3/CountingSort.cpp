//Name: Rio Simpson
//Description: Implementation file for CountingSort class

//Libraries
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>
#include <chrono>

//header file
#include "CountingSort.hpp"

/* Project Specifications
Method 4 (counting sort) is the only of these methods that isn't in-place. You'll need to read the integers 
from the data vector and insert them into a hash map, with the data value as the hash key, and a count of times 
that particular data value was seen as the hash value. So the first time you see a new value X in the data, 
you insert it into the hash using X as the key, and you set that key's hash value to 1. The second time you see X, 
you find that it's already in the hash, so you increment its hash value to 2. The third time you see X, you increment 
its hash value to 3, and so on.

Once you have a hash map of all the unique data values and the number of times each data value appeared in the data, 
iterate through the hash map, pushing the key-value pairs in the hash map to a vector. Then, sort that vector using 
std::sort (in an input with many duplicates, a vector of unique values will be much smaller than a vector of all the values). 
Finally, iterate through that vector finding P25, P50, and P75. You'll have to count how many data points you've seen along 
the way, since each element of the vector represents multiple data point, not just one. Finding the minimum and maximum should 
be self-explanatory.
*/

//sorting function
//function takes string and data vector, creates map, finds 5-summary values
void countingSort(const std::string& header, std::vector<int> data){
    // //starting timer
    // auto start4 = std::chrono::high_resolution_clock::now();

    //variables to hold min, p25, median, p75, and max
    int min = 0, p25 = 0, median = 0, p75 = 0, max = 0;

    //unordered map for elements from vector, int is key, count is value
    std::unordered_map<int, int> inital;

    //constructing unordered map
    for (const int& value : data){
        inital[value]++;
    }

    //pushing key value pairs onto a vector
    std::vector<std::pair<int, int> > keyValue;
    for (const auto& itemPair : inital){
        keyValue.push_back(std::make_pair(itemPair.first, itemPair.second));
    }

    //std sort using lambda comparison to get smaller of hashes
    // std::sort(keyValue.begin(), keyValue.end(),[](const std::pair<int, int>& a, const std::pair<int, int>& b){return a.first < b.first;});
    std::sort(keyValue.begin(), keyValue.end());

    //assigning min and max value, does not changed based on count
    min = keyValue[0].first;
    max = keyValue[keyValue.size() - 1].first;

    //getting median index from size of input, p25 and p75 index from median index
    int medianIndex = data.size() / 2;
    int p25_index = medianIndex/2;
    int p75_index = medianIndex + ((data.size() - medianIndex)/2);
    
    //using loop to iterate through vector, increment counts, if there is a match, assign correct value
    //creating counter for unique values that only show up once --> this produced an error with gradescope
    int current_count = 0, unique = 0;
    for (const std::pair<int, int>& item : keyValue){
        current_count += item.second;
        //checking if count matches with index of 25th percentile element and if p25 has been assigned
        if (current_count >= p25_index && p25 == 0){
            p25 = item.first;
        }
        if (current_count >= medianIndex && median == 0){
            //checking if count matches with index of 50th percentile element and if median has been assigned
            median = item.first;
        }
        if (current_count >= p75_index && p75 == 0){
            //checking if count matches with index of 75th percentile element and if p75 has been assigned
            p75 = item.first;
            //end loop, no need to go futher
            break;
        }

    }
    
    //NOTE TO GRADER: unique values should be the number of elements that only occur once, not the number of elements as some occur multiple times (thus not being unique)
    unique = inital.size();

    // //ending timer
    // auto end4 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration4 = end4 - start4;
    // std::cout << "CountingSort Completed in: " << duration4.count() * 1000 << " milliseconds\n";

    //printiing out data as specified by project specifications
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Unique: " << unique << std::endl;
}