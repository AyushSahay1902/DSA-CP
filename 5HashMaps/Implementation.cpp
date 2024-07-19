#include<iostream>
//BST - insertion - (log n)/deletion - (log n) all log n
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> map;
    pair<string, int> p = make_pair("babbar", 3);
    map.insert(p);
    
    pair<string, int> pair2("pair", 2);
    map.insert(pair2);


    map["meras"]  = 2;

    //searching
    cout << map["meras"] << endl;
    map.erase("meras");
    // map.count("love");
    // map.size();

    unordered_map<string, int> :: iterator it = map.begin();

    while(it != map.end()) {
        cout << it->first << " " << it->second <<endl;
        it++;
    }

    return 0;

}

/*
//maximaum frequency bumber
unordered_map<int, int> count;
for(int i=0; i<srr.size(); i++){
    count[arr[i]]++;
}

Write a function to add a key-value pair to a HashMap.
Write a function to retrieve a value from a HashMap given a key.
Write a function to remove a key-value pair from a HashMap.
Write a function to check if a key is present in a HashMap.
Write a function to check if a value is present in a HashMap.
Write a function to update the value associated with a key.
Write a function to get the size of a HashMap.
Write a function to check if a HashMap is empty.
Write a function to clear a HashMap.
Write a function to clone a HashMap.
Data Manipulation (15)
Write a function to merge two HashMaps.
Write a function to filter a HashMap based on a condition.
Write a function to transform a HashMap's values.
Write a function to find the intersection of two HashMaps.
Write a function to find the union of two HashMaps.
Write a function to find the difference between two HashMaps.
Write a function to sort a HashMap by keys.
Write a function to sort a HashMap by values.
Write a function to reverse a HashMap.
Write a function to rotate a HashMap.
Common Use Cases (10)
Write a function to cache frequently accessed data using a HashMap.
Write a function to count the frequency of words in a text using a HashMap.
Write a function to validate input data using a HashMap.
Write a function to store metadata using a HashMap.
Write a function to implement a simple cache layer using a HashMap.
Write a function to store configuration data using a HashMap.
Write a function to implement a data registry using a HashMap.
Write a function to store session data using a HashMap.
Write a function to implement a simple data store using a HashMap.
Write a function to store user preferences using a HashMap.
Challenging Questions (15)
Write a function to implement a HashMap with a custom hash function.
Write a function to implement a HashMap with a custom comparator.
Write a function to optimize HashMap performance for a specific use case.
Write a function to handle collisions in a HashMap.
Write a function to implement a concurrent HashMap.
Write a function to implement a persistent HashMap.
Write a function to serialize a HashMap.
Write a function to deserialize a HashMap.
Write a function to implement a HashMap with a limited capacity.
Write a function to implement a HashMap with a custom data structure.
Edge Cases (10)
Write a function to handle null keys and values in a HashMap.
Write a function to handle duplicate keys in a HashMap.
Write a function to handle large datasets in a HashMap.
Write a function to handle edge cases in HashMap operations.
Write a function to test HashMap implementation.
Write a function to benchmark HashMap performance.
Write a function to profile HashMap memory usage.
Write a function to handle HashMap serialization errors.
Write a function to handle HashMap deserialization errors.
Write a function to test HashMap concurrency.

*/