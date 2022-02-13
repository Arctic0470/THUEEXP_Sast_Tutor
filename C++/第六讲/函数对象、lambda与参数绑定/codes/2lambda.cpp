//��2.1
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class ShorterString {
  public:
    bool operator() (const string& a, const string& b) const {
        return a.size() < b.size();
    }
};
int main() {
    vector<string>words{ "sdfz","msdj","qhdx","zwjzm" };
    vector<string>::iterator it;

    auto f = [](const string& a, const string& b)
    { return a.size() < b.size(); };

    sort(words.begin(), words.end(),
        [](const string& a, const string& b)
        { return a.size() < b.size(); });
    //���൱��
    sort(words.begin(), words.end(), f);
    //Ҳ�൱��
    sort(words.begin(), words.end(), ShorterString());
    for (it = words.begin(); it != words.end(); it++)
        cout << *it<<"  ";
    return 0;
}
*/


//��2.2
/*
#include<iostream>
using namespace std;
void func1()
{
    int t = 42; //�����ڵľֲ�����
    //��t��������Ϊf�Ŀɵ��ö���   ֵ����
    //��ʱ������ֵ��42����������֮��t�ĸı���ı�
    auto f = [t] { return t; };
    t = 0;
    auto j = f();     //j=42
    cout << j<<endl;
}
void func2()
{
    int t = 42; //�ֲ�����
    //��t��������Ϊf�Ŀɵ��ö���
    //���ò��񣬽��������֮��t�ĸı���ı�
    auto f = [&t] { return t; };
    t = 0;
    auto j = f();     //j=0
    cout << j << endl;
}
int main() {
    func1();
    func2();
    return 0;
}
*/


//��2.3
/*
#include <iostream>
int main() {
    int ammo{ 10 };
    //��lambda����һ���ɵ��ö���shoot
    auto shoot{
      [ammo]() mutable {    //����ammo
        --ammo;    //ʹ��mutable����Ը���lambda��ammo��ֵ
        std::cout << "Pew! " << ammo << " shot(s) left.\n";
      }
    };
    //��������
    shoot();
    shoot();
    //��ӡ�������е�ammo
    std::cout << ammo << " shot(s) left";

    return 0;
}
*/

//��2.4
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int sz) {    //�ȽϺ�����������������
    return a > sz;
}
int main() {
    int myints[] = { 32,71,12,45,26,80,53,33 };
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;

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

    //ʹ�õ������������50��Ԫ��
    for (it = wc; it != myvector.end(); ++it)
        cout << *it << " ";

    return 0;
}
*/

