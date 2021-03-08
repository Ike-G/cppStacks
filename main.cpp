#include <iostream> // Library for input/output 
#include <string> // Library for working with strings - Strings are normally defined as const char* types, however by using a string this provides manipulation methods
#include <vector> // Library for a form of linked lists

// I could write "using namespace std;" here, however it's generally better practice not to in order to avoid conflicting with namespace methods

template <typename T> // Generic 
class Stack { 
    public: 
        Stack(unsigned int s) { 
            vals = new T[s]; // Allocates s addresses while calling the T* constructor
            ptr = -1;  
        };

        int push(T item) {
            if (isFull()) {
                std::cout << "Stack overflow" << std::endl; // This is not something I would output if implementing for practical use, I would instead just return 0 to indicate failure.
                return 0; 
            }
            vals[++ptr] = item; // ++i returns the incremented value, while i++ returns the value pre-increment 
            return 1; 
        };

        T peek() {
            if (isEmpty()) {
                std::cout << "Stack empty" << std::endl;
                throw 2; // This appears as 'std::logic_error' 
            }
            return vals[ptr]; // This is identical to *(vals+ptr) 
        };

        T pop() {
            T val; 
            try { 
                val = peek();
            } catch (int e) {
                std::cout << "Stack empty" << std::endl;
                return 0; 
            }
            ptr--; 
            return val;
        };

        bool isEmpty() {
            return (ptr < 0);
        };

        bool isFull() {
            return (ptr >= maxSize-1);
        };

    private: 
        T* vals; // vals is a pointer to an address containing data of type T  
        int maxSize; 
        int ptr; 
};

std::vector<std::string> splitString(std::string text) {
    std::vector<std::string> results { "" }; // '=' is unnecessary here
    // Range-based for loop - char& is a reference to a character variable, meaning it holds an address and returns the value associated with the address
    for (char& c : text) { 
        if (isspace(c)) 
            results.push_back("");
        else
            results.back().push_back(c);
    }
    if (results.back().empty()) // This removes any potential whitespace
        results.pop_back();
    return results;
};

std::vector<std::string> reverseSentence(std::string sentence) { 
    std::vector<std::string> splitSentence = splitString(sentence); 
    Stack<std::string> wordStack(splitSentence.size()); // Calls the constructor of Stack
    for (std::string& w : splitSentence) {
        wordStack.push(w);
    }
    std::vector<std::string> results; 
    for (int i = 0; i < splitSentence.size(); ++i) {
        results.push_back(wordStack.pop());
    }
    return results;
};

void extA() {
    std::string inp; 
    std::cout << "Enter sentence: ";
    getline(std::cin, inp); // Gets the full line, whereas std::cin >> inp would cease to input after whitespace
    std::vector<std::string> reversedSentence(reverseSentence(inp)); // assignment with constructor
    for (std::string& w : reversedSentence) {
        std::cout << w << " ";
    }
};

inline int min(int a, int b) {
    return (a > b) ? b : a;
};

// If it is possible to pop a value (index < k), then it is possible to use that value provided there is at least one operation that can be made (index < k-1). 
// Alternatively, it is possible to use a value if it is at index k because no pop is required
// Thus, the output is the maximum over the first k+1 values excluding the value at index k-1
void extB() {
    std::string l1, l2; 
    getline(std::cin, l1);
    getline(std::cin, l2);
    std::vector<std::string> parsed1(splitString(l1));
    std::vector<std::string> parsed2(splitString(l2));
    int n (stoi(parsed1[0]));
    int k (stoi(parsed1[1]));
    std::vector<int> stackContents; 
    for (std::string& s : parsed2) {
        stackContents.push_back(stoi(s));
    }
    int max = stackContents[0];
    bool newMax = false; 
    for (int i = 0; i <= min(stackContents.size()-1, k); ++i) {
        std::cout << "Index: " << i << " Value: " << stackContents[i] << std::endl; 
        if (i != k-1 && stackContents[i] > max) { 
            max = stackContents[i];
            newMax = true; 
        }
    }
    if (!newMax) 
        max = -1; // Deals with the possibility that a new maximum is not introduced
    std::cout << max << std::endl; 
};

int main() {
    std::cout << "Extension A: " << std::endl; 
    extA();
    std::cout << std::endl << "Extension B: " << std::endl; 
    extB();
    return 0; 
}

