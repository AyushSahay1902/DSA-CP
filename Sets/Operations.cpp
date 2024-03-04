#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<set<int>> setOperations(set<int> A, set<int> B) {
  vector<set<int>> retVector;

  // Union
  set<int> unionSet;
  set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(unionSet, unionSet.begin()));
  retVector.push_back(unionSet);

  // Difference (A - B)
  set<int> difSet;
  set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(difSet, difSet.begin()));
  retVector.push_back(difSet);

  // Difference (B - A)
  set<int> anotherDifSet;
  set_difference(B.begin(), B.end(), A.begin(), A.end(), inserter(anotherDifSet, anotherDifSet.begin()));
  retVector.push_back(anotherDifSet);

  // Intersection
  set<int> interSecSet;
  set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(interSecSet, interSecSet.begin()));
  retVector.push_back(interSecSet);

  return retVector;
}

// ... rest of the main function remains the same ...

// User function Template for C++
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        set<int> A, B;
        int x;
        for(int i=0; i<N; i++){
            cin>>x;
            A.insert(x);
        }
        for(int i=0; i<M; i++){
            cin>>x;
            B.insert(x);
        }
        vector<set<int>> result = setOperations(A, B);
        for (int i = 0; i < result.size(); ++i) { // Use a regular for loop
            for (auto &it : result[i]) {
                cout<<it<<" ";
            }cout<<endl;
        }
    }

}
