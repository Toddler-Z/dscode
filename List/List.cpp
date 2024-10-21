#include "List.h"
#include <iostream>

int main()
{   

    List<int> lst1;
    std::cout << "Testing default constructor:" << std::endl;
    lst1.printList();
    for (int i = 0; i < 10; ++i)
    {
        lst1.push_back(i);
    }
    lst1.push_front(5);
    std::cout << "Testing push_back and push_front: " << std::endl;
    lst1.printList();
    
    List<int> lst2 {1, 2, 3, 4, 5};
    std::cout << "Testing initializer_list constructor: " << std::endl;
    lst2.printList();

    List<int> lst3(lst2);
    std::cout << "Testing copy constructor: " << std::endl;
    lst3.printList();

    List<int> lst4 = std::move(lst3);
    std::cout << "Testing move constructor: " << std::endl;
    lst4.printList();

    List<int> lst5; 
    lst5= lst1;
    std::cout << "Testing assignment operator: " << std::endl;
    lst5.printList();

    auto begin = lst2.begin();
    ++begin; // 指向第二个元素
    lst2.insert(begin, 6);
    auto end = lst2.end();
    --end;
    --end; // 指向倒数第二个元素
    lst2.erase(end);
    std::cout << "Testing begin,end,insert and erase: " << std::endl;
    lst2.printList();
    

    lst5.pop_back();
    lst5.pop_front();
    std::cout << "Testing front, back, size, pop_back and pop_front: " << std::endl;
    std::cout << "Front afer pop: "<< lst5.front() << "\n" << "Back after pop: " << lst5.back() << std::endl;
    std::cout << "Size: " << lst5.size() << std::endl;
    lst5.printList();

    auto it1 = lst4.begin();
    ++it1;
    ++it1; //指向第三个元素，被删。
    auto it2 = lst4.end();
    --it2; //指向倒数第一个元素，不被删。
    lst4.erase(it1, it2);
    std::cout << "Testing erase(from,to),empty andclear: " << std::endl;
    lst4.printList();
    std::cout << "Is empty: " << lst4.empty() << std::endl;
    lst4.clear();
    std::cout << "Is empty after clear: " << lst4.empty() << std::endl;
    return 0;
}
