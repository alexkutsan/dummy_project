#ifndef TYPES_CUSTOMSTACK_H
#define TYPES_CUSTOMSTACK_H

#include <stack>
#include <vector>
#include <memory>
#include <initializer_list>

namespace types {

  template <class T>
  class CustomStack {
    public:
      explicit CustomStack<T>() = default;
      explicit CustomStack<T>(const CustomStack<T>& ) = default;
      explicit CustomStack<T>(CustomStack<T>&&) = default;
      explicit CustomStack<T>(const std::initializer_list<T>& list) {
        for (const auto& element : list) {
          stack_.push(element);
        }
      }

      void push(T value) {
        stack_.push(value);
      }

      T pop() {
        T top_element = stack_.top();
        stack_.pop();
        return top_element;
      }

      size_t size() const {
        return stack_.size();
      }

      std::stack<T> get_stack() const {
        return stack_;
      }

      T top() const {
        return stack_.top();
      }

      bool empty() const {
        return stack_.empty();
      }

      void clear() {
        while(!empty()) {
          stack_.pop();
        }
      }

    private:
      std::stack<T> stack_;
  };

  typedef std::unique_ptr<CustomStack<int>> NumbersStackPtr;
  typedef CustomStack<int> NumbersStack;
  typedef std::unique_ptr<std::vector<std::string>> OperatorsListPtr;
  typedef std::vector<std::string> OperatorsList;
}
#endif
