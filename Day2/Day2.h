//
// Created by mohd on 2023-12-08.
//

#ifndef AOC2023_DAY2_H
#define AOC2023_DAY2_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Day2 {
public:
    static void run();

private:
//    vector<string> file;


    static void parseFile();
    static void runOperation();
    vector<string> stringToArrayString(string str, char delimiter);
};

#endif //AOC2023_DAY2_H
