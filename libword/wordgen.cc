#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

/*remember to use this code carefully*/

#define DEBUG

int generate(const char* keyword) {
    std::string fixed_string = keyword;
    std::string character_sets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+=<>?/[]{}";
    int min_length = 6;
    int max_length = 20;
    std::string output_file = "wordlist.txt";

    std::ofstream file(output_file);
    for (int length = min_length; length <= max_length; length++) {
        std::vector<std::string> combinations;
        std::string temp;
        temp.reserve(length);
        std::fill_n(std::back_inserter(temp), length, character_sets.front());
        do {
            combinations.push_back(temp);
            for (int i = length - 1; i >= 0; i--) {
                if (temp[i] != character_sets.back()) {
                    temp[i] = *std::next(std::find(character_sets.begin(), character_sets.end(), temp[i]));
                    break;
                }
                else {
                    temp[i] = character_sets.front();
                }
            }
        } while (temp.front() != character_sets.back());

        for (const auto& combination : combinations) {
            std::string word = fixed_string + combination;
            file << word << "\n";
        }
    }
    file.close();

    std::cout << "Wordlist generated and saved to " << output_file << std::endl;
    return 0;
}