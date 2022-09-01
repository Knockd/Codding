#include<string.h>
#include<iostream>
using namespace std;
class Animal
{
public:
    Animal(const string& name) :
        m_name{ name }
    {}

    const string& getName() const
    {
        return m_name;
    }

    virtual string speak() const
    {
        return "???";
    }

private:
    string m_name;
};

class Cat : public Animal
{
public:
    Cat(const string& name) :
        Animal(name)
    {}

    virtual string speak() const
    {
        return "Meow";
    }
};

class Dog : public Animal
{
public:
    Dog(const string& name) :
        Animal(name)
    {}

    virtual string speak() const
    {
        return "Woof";
    }
};
void call_func(Animal* a)
{
    a->getName();
}

int main()
{
    Cat cat{ "Fred" };
    cout << "Cat is named " << cat.getName() << ", and it says " << cat.speak() << endl;

    Dog dog{ "Carbo" };
    cout << "Dog is named " << dog.getName() << ", and it says " << dog.speak() << endl;

    Animal* catAnimal = &cat;
    cout << "Cat is named " << catAnimal->getName() << ", and it says " << catAnimal->speak() << endl;

    Animal& dogAnimal = dog;
    cout << "Dog is named " << dogAnimal.getName() << ", and it says " << dogAnimal.speak() << endl;

    Animal* an = new Cat("cat");
    call_func(an);

    return 0;
}


mov ebp, esp
mov eax,[ebp+b]
eax就是指针。b就是指针。eBP+b 是b值的偏移量，然后加【】 取得b值
这里把B的值给eax
等于说eax的值指向虚表。
mov edx,[eax]
虚表指针从结构体中读取出来，保存在EDX寄存器中。由于参数b指向一个SubClass对象，这里也将是SubClass的虚表的地址
b指向类表，这里把类表值给edx
mov ecx,[ebp+b]
mov eax,[edx+8]
这里把类表的地址+8，然后提取指向的func3 的值
call eax 