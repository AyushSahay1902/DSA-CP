#include <bits/stdc++.h>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

    public:
    TwoStack(int size){
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int ele){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = ele;
        }else{
            cout << "Stack Underflow" << endl;
        }
    }

    void push2(int ele){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = ele;
        }else{
            cout << "Stack Underflow" << endl;
        }
    }

    void pop1(){
        if(top1 >= 0){
            top1--;
        }else{
            return -1;
        }
    }

    void pop2(){
        if(top2 < size){
            top2++;
        }else{
            return -1;
        }
    }

}

int main() {

    TwoStack st(4);

    st.push1(1);
    st.push1(2);
    st.push2(3);
    st.push2(4);

    st.pop1();
    st.pop2();

    
    return 0;
}
