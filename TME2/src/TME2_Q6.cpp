#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <unordered_map>
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

    cout << "Finished Parsing War and Peace" << endl;

    auto end = steady_clock::now();
    cout << "Parsing took "
         << duration_cast<milliseconds>(end - start).count()
         << "ms.\n";

    // Afficher le nombre d'occurrences pour "war", "peace" et "toto"
    for (const auto& searchWord : {"war", "peace", "toto"}) {
        if (wordCounts.find(searchWord) != wordCounts.end()) {
            cout << "The word \"" << searchWord << "\" appeared " << wordCounts[searchWord] << " times." << endl;
        } else {
            cout << "The word \"" << searchWord << "\" did not appear in the text." << endl;
        }
    }

    return 0;
}

