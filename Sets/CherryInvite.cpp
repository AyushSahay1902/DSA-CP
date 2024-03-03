#include<iostream>
#include<set>
using namespace std;

int main() {
    // Declare a set to store unique names
    set<string> inviteList;

    // Input the number of names
    int n;
    cin >> n;

    // Input 'n' names and insert them into the set
    while (n--) {
        string name;
        cin >> name;
        inviteList.insert(name);
    }

    // Print the invite list
    cout << "Printing invite list:" << endl;
    for (auto name : inviteList) {
        cout << name << endl;
    }

    return 0;
}
