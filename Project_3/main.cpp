//Name: Rio Simpson
//Main file for testing

//Libraries
#include <chrono>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>

//Header Files
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

int main(){
    //extracting data from text flile
    std::ifstream input_data("inputs/test_input.txt");
    // std::ifstream input_data("inputs/test_input2.txt");
    // std::ifstream input_data("inputs/test_input3.txt");

    // std::ifstream input_data("inputs/test_input_1k_1-100.txt");
    // std::ifstream input_data("inputs/test_input_100k_1-100.txt");
    // std::ifstream input_data("inputs/test_input_10M_1-100.txt");

    // std::ifstream input_data("inputs/test_input_1k_2-500.txt");
    // std::ifstream input_data("inputs/test_input_100k_2-500.txt");
    // std::ifstream input_data("inputs/test_input_10M_2-500.txt");

    // std::ifstream input_data("inputs/test_input_1k_3-1000.txt");
    // std::ifstream input_data("inputs/test_input_100k_3-1000.txt");
    // std::ifstream input_data("inputs/test_input_10M_3-1000.txt");

    std::vector<int> read_data;

    //throw away introductory line
    std::string header;
    std::getline(input_data, header);

    if (input_data.is_open()) {
        int value;
        while (input_data >> value){
            read_data.push_back(value);
        }

        input_data.close();
    }

    // StdSort myData1;
    // //calling function
    // myData1.stdSort(header, read_data);

    // // starting timer
    // auto start1 = std::chrono::high_resolution_clock::now();
    stdSort(header, read_data);
    //ending timer
    // auto end1 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration1 = end1 - start1;
    // std::cout << "StdSort Completed in: " << duration1.count() * 1000 << " milliseconds\n";


    // QuickSelect1 myData2;
    // //calling function
    // myData2.quickSelect1(header, read_data);

    //starting timer
    // auto start2 = std::chrono::high_resolution_clock::now();
    quickSelect1(header, read_data);
    // auto end2 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration2 = end2 - start2;
    // std::cout << "QuickSelect1 Completed in: " << duration2.count() * 1000 << " milliseconds\n";

    // QuickSelect2 myData3;
    // //calling function
    // myData3.quickSelect2(header, read_data);

    // //starting timer
    // auto start3 = std::chrono::high_resolution_clock::now();
    quickSelect2(header, read_data);
    // auto end3 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration3 = end3 - start3;
    // std::cout << "QuickSelect2 Completed in: " << duration3.count() * 1000 << " milliseconds\n";

    // CountingSort myData4;
    // //calling function
    // myData4.countingSort(header, read_data);

    // //starting timer
    // auto start4 = std::chrono::high_resolution_clock::now();
    countingSort(header, read_data);
    // auto end4 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration4 = end4 - start4;
    // std::cout << "CountingSort Completed in: " << duration4.count() * 1000 << " milliseconds\n";
}