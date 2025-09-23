#include <iostream>
#include <stack>
using namespace std;

// Function to read how many numbers the user wants to input
int readNumberOfElements() {
    cout << "Enter number of elements: ";
    int n;
    cin >> n; // store the number of elements
    return n;
}

// Function to read 'n' numbers from the user and push them into the stack
void readNumbers(stack<int>& st, int n){
    cout << "Enter " << n << " numbers: ";
    for(int i=0;i<n;i++){
        int x; 
        cin >> x;   // read a number
        st.push(x); // push the number onto the stack (top of stack changes)
    }
}

// Function to find the minimum element in the stack
// Notice: we pass the stack by value (copy) so that the original stack is not changed
int findMin(stack<int> st){
    int minVal = st.top(); // assume first element (top) is the minimum

    // Go through all elements until stack becomes empty
    while(!st.empty()){
        // If current element < current minimum, update minVal
        if(st.top() < minVal) 
            minVal = st.top();

        st.pop(); // remove the top element to move to the next
    }
    return minVal; // return the smallest element found
}

// Function to print the minimum value
void printMin(int minVal){
    cout << "Minimum element: " << minVal << endl;
}

int main(){
    // Step 1: Read how many numbers we’ll work with
    int n = readNumberOfElements();

    // Step 2: Declare a stack to hold numbers
    stack<int> st;

    // Step 3: Read numbers into the stack
    readNumbers(st, n);

    // Step 4: Find the minimum element
    int minVal = findMin(st);

    // Step 5: Print the result
    printMin(minVal);
}
