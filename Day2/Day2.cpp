//
// Created by mohd on 2023-12-08.
//

#include "Day2.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Set;

struct Game {
    int id;
    vector<Set> sets;
};

struct Set {
    map<string, int> balls = {
            {"red", 0},
            {"blue", 0},
            {"green", 0}
    };
};

void Day2::run() {
    parseFile();
}

void Day2::parseFile() {
    ifstream fileStream;
    string fileLine;
    fileStream.open("../Day2/input-1.txt");

    vector<Game> allGames;
    vector<string> file;

    // Eliminate double reading at eof by using eof as a boolean check
    if (fileStream.is_open()) {
        while (getline(fileStream, fileLine)) {
            file.push_back(fileLine);
        }
    }

    for(auto line: file){
        string token = line.substr(0, line.find(":")); // Get Game ID
        string id = token.substr(token.find(" ") + 1, token.length());
        int gameID = stoi(id);


        string allSets = line.substr(line.find(":") + 2, line.length());

        string token2;
        vector<string> draw;
        size_t pos = 0;

        // Store all set strings into an array
        while((pos = allSets.find(";")) != string::npos){
            token2 = allSets.substr(0, pos);
            allSets.erase(0, pos + 2);
            draw.push_back(token2);
        }
        // Don't forget to add last set
        draw.push_back(allSets);
        vector<Set> listOfSets;

        for(auto set : draw){
            Set newSet;
            string token3;
            vector<string> ballCounts;
            size_t pos2 = 0;

            // Store all set strings into an array
            while((pos2 = set.find(" ")) != string::npos){
                token3 = set.substr(0, pos2);
                set.erase(0, pos2 + 1);
                ballCounts.push_back(token3);
            }
            // Don't forget to add last set
            ballCounts.push_back(set);

            // Create Set structs with data
            for(int i = 0; i < ballCounts.size(); i++){
                int count = 0;
                int type = 1;


                while(type < ballCounts.size()) {
                    if (ballCounts[type][0] == 'r') {
                        newSet.balls["red"] = stoi(ballCounts[count]);
                    } else if (ballCounts[type][0] == 'b') {
                        newSet.balls["blue"] = stoi(ballCounts[count]);
                    } else if (ballCounts[type][0] == 'g') {
                        newSet.balls["green"] = stoi(ballCounts[count]);
                    }
                    count++;
                    type++;
                }
            }
            // Add to list of Sets
            listOfSets.push_back(newSet);
        }

        // Create Game data container and set ID and ball drawn sets
        Game newGame;
        newGame.id = gameID;
        newGame.sets = listOfSets;
        allGames.push_back(newGame);
    }

    int answer = 0;

    // Iterate over data
    for(auto games : allGames){
        int valid = 1;
        for(auto set : games.sets){
            if (set.balls["red"] > 12 || set.balls["green"] > 13 || set.balls["blue"] > 14) {
                valid = 0;
                break;
            }
        }
        if(valid) answer += games.id;
    }

    cout << "Part 1 answer: " << answer << endl; // DONE

    int answer2 = 0;
    for(auto games : allGames){
        int maxRed = 0;
        int maxBlue = 0;
        int maxGreen = 0;
        for(auto set : games.sets){
            if (set.balls["red"] > maxRed) {
                maxRed = set.balls["red"];
            }
            if (set.balls["blue"] > maxBlue) {
                maxBlue = set.balls["blue"];
            }
            if (set.balls["green"] > maxGreen) {
                maxGreen = set.balls["green"];
            }
        }
        answer2 += maxRed * maxBlue * maxGreen;
    }
    cout << "Part 2 answer: " << answer2 << endl; // DONE


}
