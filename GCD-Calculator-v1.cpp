#include <iostream>
#include <cmath>
#include <format>

class Iteration {
    public:
        int number, p, q, r, b;
};

void iterationMaker(int iterationNumber, int p, int q, int b, int r) {
    Iteration iteration;
    iteration.number = iterationNumber;
    iteration.p = p;
    iteration.q = q;
    iteration.b = b;
    iteration.r = r;
}

int main() {

    int tempInput_1, tempInput_2, p, q, r, b;
    int iterationNumber = 0, rearragneNumber = 0, a = 1;
    bool isOnGoing = true;

    std::cout << "GCD Calculator (Euclidian Algorithm)\n"
              << "Enter the first number: ";
    std::cin >> tempInput_1;
    
    std::cout << "Enter the second number: ";
    std::cin >> tempInput_2;

    if(tempInput_1 > tempInput_2) {p = tempInput_1; q = tempInput_2;}
    else if(tempInput_2 > tempInput_1) {p = tempInput_2; q = tempInput_1;}
    else if(tempInput_1 = tempInput_2) {std::cout << "GCD is " << tempInput_1 << std::endl;}
    else {std::cout << "Invalid input!";}

    std::cout << '\n' << p << " is greater than " << q << ". So, we will have:\n" << std::endl;

    while(isOnGoing){
        b = static_cast<int>(p/q);
        r = p % q;
        iterationNumber++;
        iterationMaker(iterationNumber, p, q, b, r);
        std::cout << "\nIteration Number " << iterationNumber << ": " << p << " = " << b << '(' << q << ") + " << r << std::endl;

        p = q;
        q = r;

        if(r != 1) {isOnGoing = true;}
        else {isOnGoing = false;}
    }

    std::cout << "\nNow, we will rearrange each iteration to solve for the remainder (r):" << std::endl;

    
    
    

    return 0;
}