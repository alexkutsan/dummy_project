#include<string>
#include<stack>
namespace dev {

class Calculator {
public:
    Calculator() = default;
    ~Calculator() = default;

    /**
     * method to evaluate the expression
     * param expression string fetched from console input
     */
    double evaluate(const std::string& expression);

private:

    //Stack to hold the numbers
    std::stack<float> mOperandStack;
    bool isOperator(char op);
    void getVariables(float& var1, float& var2);
};

}  // namespace calculator