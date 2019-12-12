#include "queue"

namespace dev {
class FixedSizeQueue : public std::queue<float> {
public:
    void push(const float& item);
    bool getFirst(float& item);
private:
    static constexpr int _size = 2;
};
}
