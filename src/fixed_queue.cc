#include "fixed_queue.h"

namespace dev {
    void FixedSizeQueue::push(const float& item){
        while (_size <= this->size()){
            this->pop();
        }
        std::queue<float>::push(item);
    }

    // Not obvious naming
    bool FixedSizeQueue::getFirst(float& result) {
        result = 0;                     // result will be changed it bad case (if stack is empty)
        if (this->empty()){
            return false;
        }
        result = this->front();
        this->pop();
        return true;
    }
}
