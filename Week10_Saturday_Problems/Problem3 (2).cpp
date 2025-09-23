#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to read a whole line of input from the user
string readString() {
    string s;
    getline(cin, s); // Read input including spaces until Enter is pressed
    return s;
}

// Function to check if a string of parentheses/brackets/braces is valid
bool isValidParentheses(const string &s) {
    stack<char> st; // Stack to keep track of opening symbols

    // Traverse each character in the string
    for(char c : s){
        // If it's an opening bracket, push it into the stack
        if(c=='(' || c=='{' || c=='[') 
            st.push(c);
        else {
            // If we find a closing bracket but stack is empty → invalid
            if(st.empty()) 
                return false;

            // Get the top element (the last opening bracket we saw)
            char t = st.top();

            // Check if the closing bracket matches the opening one
            if((c==')' && t=='(') || 
               (c=='}' && t=='{') || 
               (c==']' && t=='['))
                st.pop(); // Matched pair → remove the opening from stack
            else 
                return false; // Mismatched bracket → invalid
        }
    }

    // At the end, if stack is empty → all brackets matched correctly
    return st.empty();
}

// Function to print the result in a user-friendly way
void printValidParenthesesResult(bool res){
    cout << (res ? "Valid" : "Invalid") << endl;
}

int main(){
    cout << "Enter a string of parentheses: ";

    // Read input from user
    string s = readString();

    // Check if the input string is valid or not
    bool res = isValidParentheses(s);

    // Print the result
    printValidParenthesesResult(res);
}
