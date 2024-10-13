#include <iostream>
#include <cstring>

class Chicken
{
    private:
        int age = 24;
        char *name = nullptr;
    public:
        Chicken(){};
        Chicken(int _age) : age(_age) {};
        Chicken(int _age, const char *_name) : age(_age) 
    {       if(_name != nullptr) {
                 int len = strlen(_name) + 1;
                 name = new char[len];
                 for (int i = 0; i < len; i++)
                  name[i] = _name[i];
        }
    };
         Chicken(const Chicken &_l)
    {
        age = _l.age;
         int len = strlen(_l.name) + 1;
        name = new char[len];
        for (int i = 0; i < len; i++)
           name[i] = _l.name[i];
    }
        Chicken &operator=(const Chicken &_l) {  
    if (this != &_l) {  
        delete[] name; 
        if (_l.name != nullptr) {  
            int len = strlen(_l.name) + 1;  
            name = new char[len];  
            strcpy(name, _l.name); 
        } else {  
            name = nullptr;  
        }  
    }  
    return *this;  
}  
     

        ~Chicken()
        {
            if (name != nullptr)
                delete[] name;
        }
        void setAge(int _age)
        {
            age = _age;
        }
        void setName(const char *_name)
        {
            if(name != nullptr)
                delete[] name;
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        }

        const char *getName() const
        {
            return name;
        }

        const int &getAge() const
        {
            return age;
        }
};
int main(){
auto print = [](const Chicken &c){
std::cout << "Hi, everyone! My name is " << c.getName()
<< ", I am " << c.getAge() << " years old." << std::endl;
};
Chicken c(24, "Kunkun");
print(c);
Chicken d;
d = c;
print(d); // 测试【赋值运算符】是否正确，能正确输出给 20 分
Chicken a = c;
print(a); // 测试【赋值构造函数】是否正确，能正确输出给 20 分
c.setName("Xukun Cai");
print(c);
print(a);
print(d); // 测试是否为【深度复制】，本行与上两行能正确输出给 20 分
Chicken b;
b = d = c;
print(b);
print(d); // 测试【连续赋值】功能，本行与上一行能正确输出给 20 分
return 0;
}
