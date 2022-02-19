#include<iostream>
using namespace std;

class Base
{
public:
    Base() {};
    virtual void Show() { cout << "This is Base calss"; }
};
class Derived :public Base
{
public:
    Derived() {};
    void Show() { cout << "This is Derived class"; }
};
int main()
{
    //��һ�����
    Base* base = new Derived;
    if (Derived* der = dynamic_cast<Derived*>(base))
    {
        cout << "��һ�����ת���ɹ�" << endl;
        der->Show();
        cout << endl;
    }
    //�ڶ������
    Base* base1 = new Base;
    if (Derived* der1 = dynamic_cast<Derived*>(base1))
    {
        cout << "�ڶ������ת���ɹ�" << endl;
        der1->Show();
    }
    else
    {
        cout << "�ڶ������ת��ʧ��" << endl;
    }

    delete(base);
    delete(base1);
    system("pause");
}