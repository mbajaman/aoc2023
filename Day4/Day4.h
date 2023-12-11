//
// Created by mohd on 2023-12-11.
//

#ifndef AOC2023_DAY4_H
#define AOC2023_DAY4_H

#include <vector>
#include <string>

using namespace std;

class Day4 {
public:
    static void run();

private:
    static double answer;
    static vector<string> file_to_vector;
    static vector<int> winning_numbers;
    static vector<int> my_numbers;

    static void parse_file();
    static vector<string> string_to_array(string &v_str, char delimiter);
    static double generate_solution();
    static bool contains(const std::vector<int>& vecObj, int element);
};


#endif //AOC2023_DAY4_H
