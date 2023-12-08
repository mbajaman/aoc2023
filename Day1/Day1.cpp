//
// Created by mohd on 2023-12-02.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Day1.h"

using namespace std; // because typing "std::" was getting annoying

void Day1::run() {
    cout << "Day 1 - Part 1:" << endl;
    parseFile();

    cout << "Day1 - Part 2:" << endl;
    parseAnotherFile();
}

/*
 * Parses input file
 */
void Day1::parseFile() {
    fstream fileStream;
    fileStream.open("../Day1/input-1.txt");

    string firstLine;

    int sum = 0;

    if(fileStream.is_open()){
        while(fileStream >> firstLine) // Eliminate double reading at eof by using eof as a boolean check
        {
            int firstPtr = -1;
            int lastPtr = -1;

            string twoDigit;

            if(firstLine.length() != 1){
                // Parse through every character
                for(int i = 0; i < firstLine.length(); i++){
                    if(isdigit(firstLine[i]) && firstPtr == -1){
                        firstPtr = i;
                    }
                    if(isdigit(firstLine[i])){
                        lastPtr = i;
                    }
                }
            }
            else {
                firstPtr = 0;
                lastPtr = 0;
            }

            // Set the chars
            twoDigit += firstLine[firstPtr];
            twoDigit += firstLine[lastPtr];

            // Debug
            //std::cout << twoDigit << std::endl;

            int lineNumbers = stoi(twoDigit); // Convert string to int
            sum += lineNumbers; // Add to sum

        }
        cout << sum << endl;


    } else {
        cout << "File not open";
    }

}

void Day1::parseAnotherFile() {

    fstream fileStream;
    fileStream.open("../Day1/input-2.txt");

    string firstLine;
    map<string, int> stringToInt = {
            {"zero", 0},
            {"one", 1},
            {"two", 2},
            {"three", 3},
            {"four", 4},
            {"five", 5},
            {"six", 6},
            {"seven", 7},
            {"eight", 8},
            {"nine", 9},
    };

    if(fileStream.is_open()) {
        while(fileStream >> firstLine) {
            vector<int> numArr;
            // Manage an array and size, grab first thing in array and size-1 in array

        }
    }
}
