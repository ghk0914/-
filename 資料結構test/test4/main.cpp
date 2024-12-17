#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
using namespace std;

// 檢查字元是否為運算子
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 根據運算子進行計算
int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) {
                cerr << "Error: Division by zero!" << endl;
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default: 
            cerr << "Error: Invalid operator" << endl;
            exit(EXIT_FAILURE);
    }
}

int evaluatePostfixExpression(const string& expression) {
    stack<int> s; // 用來存放運算元的堆疊
    stringstream ss(expression); // 使用 stringstream 分割輸入
    string token;

    while (ss >> token) { // 從輸入字串中逐個讀取 token
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            // 如果是數字 (考慮負數情況)
            s.push(stoi(token));
        } else if (token.size() == 1 && isOperator(token[0])) {
            // 如果是運算子
            if (s.size() < 2) {
                cerr << "Error: Insufficient operands for operator " << token << endl;
                exit(EXIT_FAILURE);
            }
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            int result = performOperation(operand1, operand2, token[0]);
            s.push(result);
        } else {
            cerr << "Error: Invalid token " << token << endl;
            exit(EXIT_FAILURE);
        }
    }

    if (s.size() != 1) {
        cerr << "Error: Invalid postfix expression" << endl;
        exit(EXIT_FAILURE);
    }

    return s.top();
}

int main() {
    string postfixExpression;
    cout << "please enter (ex: 3 4 + 2 *): ";
    getline(cin, postfixExpression);

    try {
        int result = evaluatePostfixExpression(postfixExpression);
        cout  << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
