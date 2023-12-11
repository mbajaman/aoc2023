//
// Created by mohd on 2023-12-11.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>

#include "Day4.h"

// Definition of static member variable
vector<string> Day4::file_to_vector;
vector<int> Day4::winning_numbers;
vector<int> Day4::my_numbers;
double Day4::answer = 0;

void Day4::run() {
    parse_file();
    cout << generate_solution();
}

void Day4::parse_file() {
    ifstream stream;
    stream.open("../Day4/input-1.txt");

    string line;

    // Read all lined into a vector
    if(stream.is_open()) {
        while (getline(stream, line)) {
            file_to_vector.push_back(line);
        }
    }
}

vector<string> Day4::string_to_array(string& v_str, char delimiter) {
    vector<string> array_to_return;
    string token;
    size_t pos;

    while((pos = v_str.find(delimiter)) != string::npos){
        token = v_str.substr(0, pos);
        v_str.erase(0, pos + 1);
        array_to_return.push_back(token);
    }

    array_to_return.push_back(v_str);
    return array_to_return;
}

double Day4::generate_solution() {
    for(const auto& line : file_to_vector){
        winning_numbers.clear();
        my_numbers.clear();

        vector<string> all_numbers_str;
        vector<string> winning_numbers_str;
        vector<string> my_numbers_str;

        string new_line;
        new_line = line.substr(line.find(':') + 2, line.size() - 1);
        all_numbers_str = string_to_array(new_line, '|');
        winning_numbers_str = string_to_array(all_numbers_str[0], ' ');
        my_numbers_str = string_to_array(all_numbers_str[1], ' ');

        for(const auto& numbers_str : winning_numbers_str) {
            if(!numbers_str.empty() && numbers_str != " "){
                int num = stoi(numbers_str);
                winning_numbers.push_back(num);
            }
        }

        for(const auto& numbers_str : my_numbers_str) {
            if(!numbers_str.empty() && numbers_str != " "){
                int num = stoi(numbers_str);
                my_numbers.push_back(num);
            }
        }

        int number_of_matches = 0;
        for(int num : my_numbers){
            if(contains(winning_numbers, num)){
                number_of_matches++;
            }
        }

        answer += std::pow(2, number_of_matches - 1);
    }

    return answer;
}

bool Day4::contains(const vector<int> &vecObj, const int element) {
    auto it = std::find(
            vecObj.begin(),
            vecObj.end(),
            element) ;
    return it != vecObj.end();
}





