//��1.1
/*
#include <iostream>
using namespace std;

class Functor {
public:
    int operator() (int a, int b) {  //����()���������ǳ�Ա����
        return a < b;
    }
};

int main() {
    Functor f;      //����һ����������
    int a = 5;
    int b = 7;
    int ans = f(a, b);  //�˴�f����һ����������ʵ�����ڵ������ص�()������
    cout << ans;
}
*/

//��1.2
/*
#include <iostream>
using namespace std;
class F {
 public:
  F(int val) : data{val} {}
  bool operator() (int x) { return (x > data); }
 private:
  int data;
};

void Disp(int a[], int len, F op) {
  for (int i=0; i<len; i++)
    if (op(a[i])) cout << a[i] << endl;
}
int main() {
  int a[10] = {12, 1, 454, 45, 67, 162, 2, 90, 15, 49};
  int b[3] =  {30, 150, 300};

  for (int k=0; k<3; k++)
    Disp(a, 10, F(b[k]));
}
*/


//��1.3
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction(int i, int j) { return (i > j); } //�Զ���ȽϺ���

class myclass {  //����()����
public:
    bool operator() (int i, int j) { return (i > j); }
} myobject;     //�Զ���һ����������myobject

int main() {
    int myints[] = { 32,71,12,45,26,80,53,33 };
    // ���������8��Ԫ��װ������
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;    //����������������Ԫ��
    // ʹ��Ĭ�ϵıȽϺ���(operator <)����ǰ�ĸ�Ԫ��:
    //(12 32 45 71) 26 80 53 33
    sort(myvector.begin(), myvector.begin() + 4);

    // ʹ���Զ���ıȽϺ������к��ĸ�Ԫ��
    // 12 32 45 71 (80 53 33 26)
    sort(myvector.begin() + 4, myvector.end(), myfunction);

    // ʹ�����ֺ�����������(Ч��һ����ͬoperator >)
    //(80 71 53 45 33 32 26 12)
    sort(myvector.begin(), myvector.end(), myobject);
    sort(myvector.begin(), myvector.end(), myclass());     //myclass������������Ҫ��()
    sort(myvector.begin(), myvector.end(), greater<int>());  //greater<int>�Ǳ�׼���������

    cout << "myvector contains:";
    //ʹ�õ���������������Ԫ�����
    for (it = myvector.begin(); it != myvector.end(); ++it)
        cout << " " << *it;

    return 0;
}
//�����myvector contains: 80 71 53 45 33 32 26 12
*/
