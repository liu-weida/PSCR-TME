#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;
    using namespace std::chrono;

    ifstream input("/home/weida/eclipse-workspace/TME2/WarAndPeace.txt");

    auto start = steady_clock::now();
    cout << "Parsing War and Peace" << endl;

    unordered_map<string, int> wordCounts;

    // une regex qui reconnait les caractères anormaux (négation des lettres)
    regex re(R"([^a-zA-Z])");
    string word;
    while (input >> word) {
        // élimine la ponctuation et les caractères spéciaux
        word = regex_replace(word, re, "");
        // passe en lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        wordCounts[word]++;  // Increment the word count
    }
    input.close();

    // Initialize vector using unordered_map's entries
    vector<pair<string, int>> vec(wordCounts.begin(), wordCounts.end());

    cout << "Finished Parsing War and Peace" << endl;

    auto end = steady_clock::now();
    cout << "Parsing took "
         << duration_cast<milliseconds>(end - start).count()
         << "ms.\n";

    // (Optional) Display some entries from the vector
    for (const auto& searchWord : {"war", "peace", "toto"}) {
        auto it = find_if(vec.begin(), vec.end(),
                          [&searchWord](const pair<string, int>& element) { return element.first == searchWord; });

        if (it != vec.end()) {
            cout << "The word \"" << searchWord << "\" appeared " << it->second << " times." << endl;
        } else {
            cout << "The word \"" << searchWord << "\" did not appear in the text." << endl;
        }
    }

    return 0;
}
