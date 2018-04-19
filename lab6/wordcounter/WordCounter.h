//
// Created by kamila on 14.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <map>
#include <set>


namespace datastructures {



    class Counts{
    public:
        Counts(){
            counts_=0;
        }
        Counts(int x): counts_(x){}

        Counts &operator++(){
            counts_+=1;
            return *this;
        }
        operator int(){return counts_;}

        friend bool operator<(const Counts &x, const Counts &y) {
            return x.counts_ < y.counts_;
        }

        friend bool operator>(const Counts &x, const Counts &y) {
            return x.counts_ > y.counts_;
        }

        friend bool operator==(const Counts &x, const Counts &y) {
            return x.counts_ == y.counts_;
        }


    private:
        int counts_;

    };

    class Word{
    public:
        Word():word_() {}
        Word(std::string word): word_(word){}

        friend bool operator<(const Word &x, const Word &y) {
            return x.word_ < y.word_;
        }
        friend bool operator==(const Word &x, const Word &y) {

            return x.word_ == y.word_;
        }



    private:
        std::string word_;

    };

    class WordCounter {
    public:


        static Counts not_found; //for operator[] , because it need reference
        WordCounter():index_(){};
        WordCounter (const std::initializer_list<Word> &elements);

        static WordCounter FromInputStream (std::istream &text);
        int DistinctWords ()const;
        int TotalWords()const;
        std::set<Word> Words()const;

        // []
        Counts& operator[](std::string word);



        // <<

        friend std::ostream &operator<< (std::ostream &output, const WordCounter &counter);
        //posortowane malejąco


    private:
        //kontener z <Word,Counts>
        std::map <Word,Counts> index_;




    };
}




#endif //JIMP_EXERCISES_WORDCOUNTER_H
