//��3.1
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include<functional>
using namespace std;
using namespace std::placeholders;
bool comp(int a, int sz){    //�ȽϺ�����������������
    return a > sz;
}
int main() {
    int myints[] = { 32,71,12,45,26,80,53,33 };
    // ���������8��Ԫ��װ������
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;    //����������������Ԫ��

    // ʹ��Ĭ�ϵıȽϺ���(operator <)��������Ԫ��:
    //12 26 32 33 45 53 71 80
    sort(myvector.begin(), myvector.end());
    //����Ƚϱ�׼sz
    int sz = 50;

    //��ȡһ��������wc,ָ���һ��>sz��Ԫ��
    //lambda���ʽֻ����һ����������ȷ
    auto wc = find_if(myvector.begin(), myvector.end(),
        [sz](int a) {return a > sz; });

    //comp������������������������find_if��Ҫ�󣬴���
    //auto wc2= find_if(myvector.begin(), myvector.end(),comp);

    auto wc3 = find_if(myvector.begin(), myvector.end(), bind(comp, _1, sz));
    //ʹ�õ������������50��Ԫ��
    for (it = wc3; it != myvector.end(); ++it)
        cout << *it << " ";

    return 0;
}
*/


//��3.2
/*
#include <functional>
#include <iostream>
struct Foo {
    void func(int x, int y)
    {
        std::cout << x - y << '\n';
    }
    int data = 10;
};
int main() {
    Foo foo;
    auto f = std::bind(&Foo::func, &foo, 25, std::placeholders::_1);
    f(5); // 20
    return 0;
}
*/


//��3.3
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include<functional>
using namespace std;
using namespace std::placeholders;

ostream& disp(ostream& os, const int a, char c) {
    return os << a << c;
}

int main() {
    int myints[] = { 32,71,12,45,26,80,53,33 };
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;
    sort(myvector.begin(), myvector.end());

    char cc = '*';
    ostream &os = cout;
    for_each(myvector.begin(), myvector.end(),
        bind(disp, ref(os), _1, cc));
    return 0;
}
*/


