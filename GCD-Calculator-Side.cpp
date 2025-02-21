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



void extendedEuclidean(int initialInput_1, int initialInput_2) {
    int a_0 = 1, a_1 = 0, b_0 = 0, b_1 = 1;
    bool isSubstituting = true;

    std::cout << "\n\nNow, we will compute the coefficients using the Extended Euclidean Algorithm:\n" << std::endl;
    for (const auto& [stepNumber, step] : euclideanSteps) {
        if (step.r == 0) break;

        int a = a_0 - step.b * a_1;
        int b = b_0 - step.b * b_1;

        a_0 = a_1;
        a_1 = a;
        b_0 = b_1;
        b_1 = b;

        std::cout << "Step " << stepNumber << ": " << step.r << " = (" << a << ")(" << initialInput_1 << ") + (" << b << ")(" << initialInput_2 << ")\n";
    }
    
    std::cout << "\nGCD(" << initialInput_1 << ", " << initialInput_2 << ") = " << a_0 << "(" << initialInput_1 << ") + " << b_0 << "(" << initialInput_2 << ")";
}



int main() {
    int input_1, input_2, p, q, r, previousR, b, stepNumber = 0;
    char choice;



    std::cout << "GCD Calculator (Euclidean Algorithm)\n"
              << "Enter the first number: ";
    std::cin >> input_1;
    
    std::cout << "Enter the second number: ";
    std::cin >> input_2;



    if(input_1 > input_2)       {p = input_1; q = input_2;}
    else if(input_2 > input_1)  {p = input_2; q = input_1;}
    else if(input_1 == input_2) {std::cout << "GCD is " << input_1 << std::endl; return 0;}
    else                                {std::cout << "Invalid input!"; return 0;}

    std::cout << "\n\n" << p << " is greater than " << q << ". So, we will have:\n" << std::endl;



    while(true){
        b = static_cast<int>(p/q);
        r = p % q;
        stepNumber++;
        stepRecorder(stepNumber, p, q, b, r);
        std::cout << "Step " << stepNumber << ": " << p << " = " << b << "(" << q << ") + " << r << std::endl;

        p = q;
        q = r;
        

        if(r > 1) {continue;}
        else if(r == 1) {std::cout << "\nThe numbers are prime relative to eachother!"  << std::endl; break;}
        else if(r == 0) {std::cout << "\nHere is the GCD: " << p << std::endl; return 0;}
    }

    while(true){
        std::cout << "\nWould you like to get the inverse of these two numbers?(Y/N) ";
        std::cin >> choice;
    
        if(choice == 'y' || choice == 'Y') {extendedEuclidean(input_1, input_2);}
        else if(choice == 'n' || choice == 'N') {std::cout << "Exiting..." << std::endl; break;}
        else {std::cout << "Invalid Input!" << std::endl;}
    }
    


    return 0;
}
