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
