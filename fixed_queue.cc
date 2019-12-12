#include "fixed_queue.h"

namespace dev {
    void FixedSizeQueue::push(const float& item){
        while (_size <= this->size()){
            this->pop();
        }
        std::queue<float>::push(item);
    }

    bool FixedSizeQueue::getFirst(float& item) {
        if (this->empty()){
            return false;
        }
        item = this->front();
        this->pop();
        return true;
    }
}
