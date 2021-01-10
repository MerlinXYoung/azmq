#pragma once

namespace azmq{
namespace util{
template<class T>
struct link_node{
    T* next_{nullptr};
    T* prev_{nullptr};
};

template<class T>
class link_list
{
    T* head_{nullptr};
    T* tail_{nullptr};
public:
    inline bool empty()const noexcept{
        return head_ == nullptr ;
    }
    inline void push_front(T& node){
        if(empty()){
            node.prev_ = node.next_ = nullptr;
            head_ = tail_ = &node;
        }
        else{
            node.prev_ = nullptr;
            node.next_ = head_;
            head_ = &node;
        }
    }
    inline void push_back(T& node){
        if(empty()){
            node.prev_ = node.next_ = nullptr;
            head_ = tail_ = &node;
        }
        else{
            node.prev_ = tail_;
            node.next_ = nullptr;
            tail_ = &node;
        }
    }
    inline T* front()noexcept{
        return head_;
    }
    inline T* back()noexcept{
        return tail_;
    }
    inline void pop_front(){
        if(empty())
            return;
        if(head_ == tail_){
            head_ = tail_ = nullptr;
        }
        else{
            auto node = head_;
            head_ = head_->next_;
            head_->prev_ = nullptr;
            node->prev_ = node->next_ =nullptr;
        }
    }
    inline void pop_back(){
        if(empty())
            return;
        if(head_ == tail_){
            head_ = tail_ = nullptr;
        }
        else{
            auto node = tail_;
            tail_ = tail_->prev;
            tail_->next_ = nullptr;
            node->prev_ = node->next_ =nullptr;
        }
    }

    template<class F>
    inline void pop_front_and_dispose(F&& f){
        if(empty())
            return;
        auto node = head_;
        head_ = head_->next_;
        node->prev_ = node->next_ =nullptr;
        
        if(head_)
            head_->prev_ = nullptr;
        else
            tail_ = nullptr;
            
        f(node);
    }
    template<class F>
    inline void pop_back_and_dispose(F&& f){
        if(empty())
            return;

        auto node = tail_;
        tail_ = tail_->prev;
        node->prev_ = node->next_ =nullptr;
        
        if(tail_)
            tail_->next_ = nullptr;
        else
            head_ = nullptr;
            
        f(node);
    }
};
}
}