#include <stdio.h> 
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

template <typename T> 
class Stack { 
    public: 
        Stack(unsigned int s) { 
            vals = new T[s];
            ptr = -1; 
        };

        int push(T item) {
            if (isFull()) {
                printf("Stack overflow");
                return 0; 
            }
            vals[++ptr] = item; 
            return 1; 
        };

        T peek() {
            if (isEmpty()) {
                printf("Stack empty");
                throw 2; 
            }
            return vals[ptr]; 
        };

        T pop() {
            try { 
                T val = peek();
            } catch (int e) {
                printf("Stack empty");
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
        T* vals; 
        unsigned int maxSize; 
        int ptr; 
};

std::vector<std::string> reverseSentence(std::string sentence) { 
    std::vector<std::string> splitSentence; 
    
};

std::string splitString(std::string text) {

};

int main() { 
    return 0;
};
