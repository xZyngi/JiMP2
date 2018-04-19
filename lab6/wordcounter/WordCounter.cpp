//
// Created by kamila on 14.04.18.
//

#include "WordCounter.h"

datastructures::Counts datastructures::WordCounter::not_found =0;


datastructures::WordCounter::WordCounter(const std::initializer_list<datastructures::Word> &elements) {

    for (auto n: elements){
        if(not index_.empty()){
            auto search = index_.find(n);

            if (search != index_.end()) {
                ++search->second;
            }
            else{
                index_.insert ( std::pair<Word,Counts>(n,1));
            }
        }


        else{
            index_.insert ( std::pair<Word,Counts>(n,1));
        }
    }


}

int datastructures::WordCounter::DistinctWords() const {
    //rozmiar kontenera
    return index_.size();
}

int datastructures::WordCounter::TotalWords() const {
    //przejdz po kolei po kontenerze i zlicze Counts
    int total=0;
    for (auto n:index_){
        total = total + n.second;
    }
    return total;
}

std::set<datastructures::Word> datastructures::WordCounter::Words() const {
    std::set<Word> words;
    for (auto n:index_){
        words.insert(n.first);
    }
    return words;
}

datastructures::Counts &datastructures::WordCounter::operator[] (std::string word) {

    auto search = index_.find(word);
    // index_ to std::map <Word,Counter>


    if (search != index_.end()) {
        return search->second;
    }
    else{

        return not_found;
    }



}


std::ostream &datastructures::operator<<(std::ostream &output, const datastructures::WordCounter &counter) {
    std::map <Word,Counts> index = counter.index_;
    //sort

    //<<

    return output;
}



datastructures::WordCounter datastructures::WordCounter::FromInputStream(std::istream &text) {

    // WordCounter wc = WordCounter::FromInputStream(&is);



    // leave only ' ' and letters

    // save word until ' '
    // counts =counter [word] //reference is returned.. so i can change??"
    //  if (counts == 0 )
    //insert
    // else{
    //++counts //pointer??

    return datastructures::WordCounter();
}



