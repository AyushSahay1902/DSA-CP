// #include<iostream>
// #include<stack>
// using namespace std;

// // push, pop, getMin in O(1) time
// class MinimumStack {
//     stack<int> s;
//     stack<int> minStack;
// public:


// import java.util.*;

// class MinimumStack {
//     Stack<Integer> s;
//     int minEle;

//     public MinimumStack() {
//         s = new Stack<Integer>();
//     }
//     void getMin(){
//         if(s.empty()){
//             System.out.println("Stack is Empty!");
//         }else{
//             System.out.println("Minimum Element in the stack: " + minEle);
//         }
//     }
//     void getPeek(){
//         if(s.empty()){
//             System.out.println("Stack is empty!");
//             return;
//         }
//         Integer t = s.peek(); //Peek
//         System.out.println("Top Most Element is: ");
//         if(t < minEle){
//             System.out.println(minEle);
//         }else{
//             System.out.println(t);
//         }
//     }

//     void pop(){
//         if(!s.empty()){
//             System.out.println("Stack is empty!");
//             return;
//         }
//         System.out.println("Top most element is: ");
//         Integer t = s.pop();

//         if(t < minEle){
//             System.out.println(t);
//             minEle = minEle * 2 -  t;
//         }else{
//             System.out.println(t);
//         }
//     }

//     void push(int x){
//         if(s.empty()){
//             minEle = x;
//             s.push(x);
//             System.out.println("Number Inserted: " + x);
//             return;
//         }
//         if(x < minEle){
//             s.push(2 * x - minEle);
//             minEle = x;
//         }else{
//             s.push(x);
//             System.out.println("Number Inserted: " + x);
//         }
            
//     }
// };

// public class Main {
//     public static void main(String[] args)
//     {
//         MinimumStack s = new MinimumStack();
       
//           // Function calls
//         s.push(3);
//         s.push(5);
//         s.getMin();
//         s.push(2);
//         s.push(1);
//         s.getMin();
//         s.pop();
//         s.getMin();
//         s.pop();
//         s.getPeek();
//     }
// }

import java.util.Arrays;

public class OptimalBinarySearchTree {
    static class Node {
        int key;
        Node left, right;

        Node(int item) {
            key = item;
            left = right = null;
        }
    }

    static float[][] root;

    static float optimalBST(int keys[], float freq[]) {
        int n = keys.length;
        float[][] cost = new float[n + 1][n + 1];
        root = new float[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            cost[i][i] = freq[i - 1];
            root[i][i] = i;
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 1; i <= n - L + 1; i++) {
                int j = i + L - 1;
                cost[i][j] = Float.MAX_VALUE;
                for (int r = i; r <= j; r++) {
                    float c = ((r > i) ? cost[i][r - 1] : 0) +
                              ((r < j) ? cost[r + 1][j] : 0) +
                              sum(freq, i - 1, j - 1);
                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                        root[i][j] = r;
                    }
                }
            }
        }

        return cost[1][n];
    }

    static float sum(float freq[], int i, int j) {
        float s = 0;
        for (int k = i; k <= j; k++)
            s += freq[k];
        return s;
    }

    static Node constructOptimalBST(int keys[], float freq[], int i, int j) {
        if (i > j)
            return null;

        int idx = (int) root[i][j];
        Node root = new Node(keys[idx - 1]);

        root.left = constructOptimalBST(keys, freq, i, idx - 1);
        root.right = constructOptimalBST(keys, freq, idx + 1, j);

        return root;
    }

    public static void main(String[] args) {
        int keys[] = {1, 2, 3};
        float freq[] = {0.2f, 0.4f, 0.3f};
        float cost = optimalBST(keys, freq);
        System.out.println("Total cost: " + cost);

        Node root = constructOptimalBST(keys, freq, 1, keys.length);
        // You can now traverse the constructed binary search tree using 'root'.
    }
}
