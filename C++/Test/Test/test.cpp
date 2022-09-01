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
eax����ָ�롣b����ָ�롣eBP+b ��bֵ��ƫ������Ȼ��ӡ��� ȡ��bֵ
�����B��ֵ��eax
����˵eax��ֵָ�����
mov edx,[eax]
���ָ��ӽṹ���ж�ȡ������������EDX�Ĵ����С����ڲ���bָ��һ��SubClass��������Ҳ����SubClass�����ĵ�ַ
bָ�������������ֵ��edx
mov ecx,[ebp+b]
mov eax,[edx+8]
��������ĵ�ַ+8��Ȼ����ȡָ���func3 ��ֵ
call eax 