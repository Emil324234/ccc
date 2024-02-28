#include <iostream>
#include <algorithm>
#include <string>
#include <random>

void reverse(std::string word) {
    std::reverse(word.begin(), word.end());
    std::cout << word << std::endl;
}

void removeVowels(std::string word) {
    std::string vowels = "a, o, e, i, u, y";
    word.erase(std::remove_if(word.begin(), word.end(), [&vowels](char a) {
        return vowels.find(a) != std::string::npos;
        }), word.end());
    std::cout << word << std::endl;
}

void removeConsonants(std::string word) {
    std::string consonants = "b, c, d, f, g, h, j, k, l, m, n, p, q, r, s, t, v, w, x, y, z";
    word.erase(std::remove_if(word.begin(), word.end(), [&consonants](char a) {
        return consonants.find(a) != std::string::npos;
        }), word.end());
    std::cout << word << std::endl;
}

void shuffle(std::string word) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(word.begin(), word.end(), g);
    std::cout << word << std::endl;
}

int main() {
    int choice;
    std::string word;

    std::cout << "Enter Word: ";
    std::cin >> word;

    std::cout << "Menu:" << std::endl;
    std::cout << "1. Reverse" << std::endl;
    std::cout << "2. Remove vowels" << std::endl;
    std::cout << "3. Remove consonants" << std::endl;
    std::cout << "4. Shuffle word" << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
        reverse(word);
        break;
    case 2:
        removeVowels(word);
        break;
    case 3:
        removeConsonants(word);
        break;
    case 4:
        shuffle(word);
        break;
    default:
        std::cout << "Error " << std::endl;
    }

    return 0;
}