#include <iostream>
#include <cmath>
#include <map>


class EuclideanStep {
    public:
        int number, p, q, r, b;
};



std::map<int, EuclideanStep> euclideanSteps;



void stepRecorder(int stepNumber, int p, int q, int b, int r) {
    EuclideanStep step;
    step.number = stepNumber;
    step.p = p;
    step.q = q;
    step.b = b;
    step.r = r;

    euclideanSteps[stepNumber] = step;
}



int main() {

    int tempInput_1, tempInput_2, p, q, r, b;
    int stepNumber = 0, a = 1;
    bool isOnGoing = true;



    std::cout << "GCD Calculator (Euclidian Algorithm)\n"
              << "Enter the first number: ";
    std::cin >> tempInput_1;
    
    std::cout << "Enter the second number: ";
    std::cin >> tempInput_2;



    if(tempInput_1 > tempInput_2)       {p = tempInput_1; q = tempInput_2;}
    else if(tempInput_2 > tempInput_1)  {p = tempInput_2; q = tempInput_1;}
    else if(tempInput_1 = tempInput_2)  {std::cout << "GCD is " << tempInput_1 << std::endl;}
    else                                {std::cout << "Invalid input!";}

    std::cout << "\n\n" << p << " is greater than " << q << ". So, we will have:\n" << std::endl;



    while(isOnGoing){
        b = static_cast<int>(p/q);
        r = p % q;
        stepNumber++;
        stepRecorder(stepNumber, p, q, b, r);
        std::cout << "Step Number " << stepNumber << ": " << p << " = " << b << '(' << q << ") + " << r << std::endl;

        p = q;
        q = r;

        if(r != 1) {isOnGoing = true;}
        else {isOnGoing = false;}
    }



    std::cout << "\n\nNow, we will rearrange each step to solve for the remainder (r):\n" << std::endl;

    
    
    for(int i = 1; i <= euclideanSteps.size(); i++){
        std::cout << euclideanSteps[i].r << " = " << a << '(' << euclideanSteps[i].p << ") - "
                  << b << '(' << euclideanSteps[i].q << ')' << std::endl;
    }

    return 0;
}