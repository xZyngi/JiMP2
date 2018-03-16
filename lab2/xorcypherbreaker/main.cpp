//
// Created by zyngi on 08.03.18.
//

#include <iostream>
#include <string>
#include <vector>
#include "XorCypherBreaker.h"

using namespace std;

int main(){

    vector<string> dictionary
            {"the", "of", "and", "to", "a", "in", "is", "you", "are", "for", "that", "or", "it", "as", "be", "on",
             "your", "with", "can", "have", "this", "an", "by", "not", "but", "at", "from", "I", "they", "more",
             "will", "if", "some", "there", "what", "about", "which", "when", "one", "their", "all", "also",
             "how", "many", "do", "has", "most", "people", "other", "time", "so", "was", "we", "these", "may",
             "like", "use", "into", "than", "up", "out", "who", "them", "make", "because", "such", "through",
             "get", "work", "even", "different", "its", "no", "our", "new", "film", "just", "only", "see", "used",
             "good", "water", "been", "need", "should", "very", "any", "history", "often", "way", "well", "art",
             "know", "were", "then", "my", "first", "would", "money", "each", "over", "world", "information", "map",
             "find", "where", "much", "take", "two", "want", "important", "family", "those", "example", "while",
             "he", "look", "government", "before", "help", "between", "go", "own", "however", "business", "us",
             "great", "his", "being", "another", "health", "same", "study", "why", "few", "game", "might", "think",
             "free", "too", "had", "hi", "right", "still", "system", "after", "computer", "best", "must", "her",
             "life", "since", "could", "does", "now", "during", "learn", "around", "usually", "form", "meat", "air",
             "day", "place", "become", "number", "public", "read", "keep", "part", "start"};


    cout << dictionary[2] << endl;

    return 0;
}