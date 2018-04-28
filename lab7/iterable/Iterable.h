//
// Created by kamila on 19.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <vector>
#include <iostream>
#include <memory>

namespace utility{


    class IterableIterator {
    public:
        virtual std::pair<int, std::string> Dereference() const=0;
        //=*it

        virtual IterableIterator &Next()=0;
        //++it

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const=0;
        virtual std::vector<int>::const_iterator left()const = 0;
        virtual std::vector<std::string>::const_iterator right()const = 0;

        ~IterableIterator ()= default;

    private:

    };

    class ZipperIterator: public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);

        virtual std::pair<int, std::string> Dereference() const override ;

        virtual IterableIterator &Next() override ;

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other)const override ;
        virtual std::vector<int>::const_iterator left()const {
            return left_begin_;
        }

        virtual std::vector<std::string>::const_iterator right()const {
            return right_begin_;
        }

        ~ZipperIterator()= default;



        std::vector<int>::const_iterator left_begin_;
        std::vector<std::string>::const_iterator right_begin_;
        std::vector<int>::const_iterator left_end_;
        std::vector<std::string>::const_iterator right_end_;
    };


    class IterableIteratorWrapper{
    public:

        IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other)const;

        std::pair<int, std::string> operator*() const;
        IterableIteratorWrapper &operator++();

        std::unique_ptr<utility::IterableIterator> iterator_;
    };

    class Iterable{
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const =0;

        virtual std::unique_ptr<IterableIterator> ConstEnd() const =0;

        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;

    };







    class Zipper:public Iterable{
    public:
        Zipper(const std::vector<int> vi,const std::vector<std::string> vs){
            for (int i=0; i<vi.size(); i++){
                vi_.push_back(vi[i]);
            }


            for (int i=0; i<vs.size(); i++){
                vs_.push_back(vs[i]);
            }


        }
        virtual std::unique_ptr<IterableIterator> ConstBegin() const override ;

        virtual std::unique_ptr<IterableIterator> ConstEnd() const override ;


    private:
        std::vector<int> vi_;
        std::vector<std::string> vs_;




    };


    class Enumerate {
        Enumerate(){}

    };
}



#endif //JIMP_EXERCISES_ITERABLE_H
