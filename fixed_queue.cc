#include "fixed_queue.h"
#include <iostream>

namespace dev {
    void FixedSizeQueue::push(const float item){
        if (_size >= this->size()) {
            this->pop();
        }

        std::queue<float>::push(item);
    }
}
