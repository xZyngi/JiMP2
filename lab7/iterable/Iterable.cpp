//
// Created by kamila on 19.04.18.
//

#include "Iterable.h"
#include <memory>


utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) {
    left_begin_=left_begin;
    right_begin_ = right_begin;
    left_end_=left_end;
    right_end_=right_end;

}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {

    return {*left_begin_,*right_begin_};
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    ++left_begin_;
    ++right_begin_;
    if(right_begin_!=right_end_ &&left_begin_==left_end_ ){
        --left_begin_;
    }
    if(left_begin_!=left_end_ && right_begin_==right_end_){
        --right_begin_;
    }
    return *this;
}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other)const {
    //niekoniecznie ale test ok
    if (Dereference()==other->Dereference()){
        if (left_begin_==other->left() && right_begin_==other->right()){
            return false;
        }


    }
    else{
        return true;
    }




}


utility::IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    iterator_=move(iterator);

}

bool utility::IterableIteratorWrapper::operator!=(const utility::IterableIteratorWrapper &other) const {
    return iterator_->NotEquals(other.iterator_);
}

std::pair<int, std::string> utility::IterableIteratorWrapper::operator*() const {
    return iterator_->Dereference();
}

utility::IterableIteratorWrapper &utility::IterableIteratorWrapper::operator++() {
    iterator_->Next();
    return *this;
}

utility::IterableIteratorWrapper utility::Iterable::cbegin() const {
    return IterableIteratorWrapper(ConstBegin());
}

utility::IterableIteratorWrapper utility::Iterable::cend() const {
    return IterableIteratorWrapper(ConstEnd());
}

utility::IterableIteratorWrapper utility::Iterable::begin() const {
    return cbegin();
}

utility::IterableIteratorWrapper utility::Iterable::end() const {
    return cend();
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstBegin() const {
    ZipperIterator x(vi_.begin(),vs_.begin(),vi_.end(),vs_.end());
    std::unique_ptr<IterableIterator> begin = std::make_unique<ZipperIterator>(x);
    return begin;

}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstEnd() const {
    ZipperIterator x(vi_.end(),vs_.end(),vi_.end(),vs_.end());
    std::unique_ptr<IterableIterator> end = std::make_unique<ZipperIterator>(x);
    return end;
}