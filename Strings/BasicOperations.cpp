#include<iostream>
#include<string>
using namespace std;

int main() {
    //indexOf - find()
    //lastindexOf - rfind()
    //indexOf(char c, int indexFrom) - find(char c, fromIndex)
    //lastIndexOf(char c, int fromIndex) - rfind()
    //charAt(int indexNumber) - str[20]
    string str = "(Ayush_Sahay is GeeksforGeeks is a computer science portal)";
    int firstIndex = str.find('G');
    cout << "First Index of 'G':"<< firstIndex << endl;
    int lastIndex = str.rfind('p');
    cout << "Last Index of 'P':" << lastIndex << endl;
    int indexOf = str.find('c', 10);
    cout << "Last Index of 'C':" << indexOf << endl;
    int lastIndexOf = str.rfind('G', 20);
    cout << "Last index of 'G' before index 20 is:"<< lastIndexOf <<endl;
    char charAt20 = str[20];
    cout << "Character at index 20 is: " << charAt20 <<endl;
    if (str.length() < 50) {
        cout << "String length is less than 50. Cannot access character at index 50." << endl;
    } else {
        char charAt50 = str[50];
        cout << "Character at index 50 (safe access): " << charAt50 << endl;
    }

    return 0;

}