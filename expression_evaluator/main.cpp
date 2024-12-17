#include <iostream>
#include "expression_evaluator.h"

int main() {
    ExpressionEvaluator evaluator;
    std::string expression = "";
    std::cout << "请输入表达式 (输入 'exit' 退出): " << std::endl;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin,expression );
        if (expression == "exit") break;
        try{
        double result = evaluator.evaluate(expression);
          std::cout << expression << " = " << result << std::endl;
        }catch(const std::exception& e){
            std::cout <<"ILLEGAL"<<e.what()<< std::endl;
        }
    }
    return 0;
}