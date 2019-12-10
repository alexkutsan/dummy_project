#include "queue"

namespace dev {
class FixedSizeQueue : public std::queue<float> {
public:
    void push(const float item);
private:
    const int _size = 2;
};
}
