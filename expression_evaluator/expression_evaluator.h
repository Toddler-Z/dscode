#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>

class ExpressionEvaluator {
private:
    // 判断字符是否为除负号外的数字字符
    bool isnumber(const char &c){
        return (c >= '0' && c <= '9') || c == '.' || c == 'e'  ;
    }  
    // 判断字符是否为运算符
    bool isoperator(const char &c){
        return (c == '+' || c == '-' || c == '*' || c == '/' ) ;
    } 
    // 计算优先级
    int precedence(const char &c){
        if(c == '+' || c == '-'){
            return 1;
        }
        if(c == '*' || c == '/'){
            return 2;
        }
     throw std::invalid_argument("Unknown operator for precedence");   
    }   

    // 后缀运算
    double applyoperator(double a, double b, const char &op){
        if(op == '+'){
            return a + b;
        }
        if(op == '-'){
            return a - b;
        }
        if(op == '*'){
            return a * b;
        }
        if(op == '/'){
            if(b == 0) throw std::invalid_argument(": Division by zero");
            else return a / b;
        }else{
            throw std::invalid_argument(": Invalid operator");
        }
    }
    // 判断括号是否匹配
    bool isparenthesesbalanced(const std::string &expression){
    std::stack<char> stack;
        for(char c : expression){
            if(c == '('){
            stack.push(c);
            }
            if(c == ')'){
                if(stack.empty()){
                    return false;
                }
                stack.pop();
            }
        }
    return stack.empty();
}
public:
    // 计算表达式的值
    double evaluate(const std::string &expression){
        if(!isparenthesesbalanced(expression)){
            throw std::invalid_argument(": Parentheses are not balanced");
        }
        std::stack<char> operators; // 运算符栈
        std::stack<double> operands; // 运算数栈
        // 遍历表达式
        for(int i = 0; i < expression.size(); i++){
            char c = expression[i];
            // 处理空格：直接跳过
            if(c == ' '){
                continue;
            }
            // 处理数字
            if((c >= '0' && c <= '9')||(c=='-'&&(i==0||isoperator(expression[i-1])||expression[i-1]=='('))){
                double operand = 0;
                bool isnegative = false; // 标记是否为负数
                int dotflag = 0; // 标记小数点出现个数
                int eflag = 0; // 标记e出现个数
               // 负数处理  是负号，则跳过，并打标记。
               if(c == '-'){
                   isnegative = true;
                   i++;
               }
                if(dotflag == 0 && eflag == 0 && isnumber(expression[i])){
                    // 处理整数部分
                     while(i<expression.size()&&expression[i]>='0'&&expression[i]<='9'){
                        operand = operand*10 + (expression[i]-'0');
                        i++;
                     }
                    // 处理小数部分
                    if(i<expression.size()&&expression[i]=='.'){
                        i++; // 跳过小数点
                        dotflag ++; // 标记出现小数点
                        int j=1; // 记录小数点后面的位数
                        while(i<expression.size()&&expression[i]>='0'&&expression[i]<='9'){
                             operand = operand + (expression[i]-'0')*pow(10,-j);
                            j++;
                            i++;
                        }
                    }
                    // 处理指数部分
                    if(i<expression.size()&&expression[i]=='e'){
                        i++; // 跳过e
                        eflag ++; // 标记出现e
                        int exponentsdotflag = 0; // 标记e后面的数字是否为小数
                        bool isnegativeexponent = false; // 标记指数是否为负数
                        if(i<expression.size()&&expression[i]=='-'){
                            isnegativeexponent = true;
                            i++; // 跳过负号
                        }
                        double exponents = 0;
                        // 处理指数整数部分
                        while(i<expression.size()&&expression[i]>='0'&&expression[i]<='9'){
                                exponents = exponents*10 + (expression[i]-'0');
                                i++;
                        }
                        // 处理指数小数部分
                        if(i<expression.size()&&expression[i]=='.'){
                            exponentsdotflag ++; // 标记指数出现小数点
                            i++;
                            int k=1; // 记录指数小数点后面的位数
                            while(i<expression.size()&&expression[i]>='0'&&expression[i]<='9'){
                                exponents = exponents + (expression[i]-'0')*pow(10,-k);
                                k++;
                                i++;
                            }
                        }
                        // 处理指数负号
                        if(isnegativeexponent){
                            exponents = -exponents;
                        }
                        operand = operand*pow(10,exponents);
                   }
                }
                // 处理数字负号
                if(isnegative){
                    operand = -operand;
                } 
                operands.push(operand); // 压入运算数栈
                i--;
                continue; // 直接进行下一次循环
            }
            // 处理运算符
            if(isoperator(c)){
                // 处理表达式以运算符开头、结尾或运算符连续出现
                if((i==0&&c!='-')||i==expression.size()-1||(isoperator(expression[i+1])&&expression[i+1]!='-')){
                    throw std::invalid_argument(": Invalid operator");
                }
                // 处理连续的运算符
                while(!operators.empty()&&operators.top()!='('&&precedence(c)<=precedence(operators.top())){
                    double b = operands.top();
                    operands.pop();
                    char op = operators.top();
                    operators.pop();
                    double a = operands.top();
                    operands.pop();
                    double result = applyoperator(a,b,op);
                    operands.push(result);
                }
                operators.push(c); // 压入运算符栈
                continue; // 直接进行下一次循环
            }
            // 处理左括号
            if(c == '('){
                operators.push(c); // 压入运算符栈
                continue; // 直接进行下一次循环
            }
            // 处理右括号
            if(c == ')'){
                while(!operators.empty()&&operators.top()!='('){
                    double b = operands.top();
                    operands.pop();
                    char op = operators.top();
                    operators.pop();
                    double a = operands.top();
                    operands.pop();
                    double result = applyoperator(a,b,op);
                    operands.push(result);
                }
                if(operators.empty()){
                    throw std::invalid_argument(": Parentheses are not balanced");
                }
                operators.pop(); // 弹出左括号
                continue; // 直接进行下一次循环
            }

        }
    // 处理剩余的运算符和运算数
    while(!operators.empty()){
        double b = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        double a = operands.top();
        operands.pop();
        double result = applyoperator(a,b,op);
        operands.push(result);
    }
    return operands.top(); // 返回结果
    }
};

#endif



