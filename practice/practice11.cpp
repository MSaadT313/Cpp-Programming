#include <iostream>
#include <stdexcept> 

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    return a / b;
}

int main() {
    int x = 10;
    int y = 0;
    int result;

    try {
        result = divide(x, y);
        std::cout << "Result: " << result << std::endl; // This line won't be reached
    } catch (const std::runtime_error& error) {
        std::cerr << "Runtime error caught: " << error.what() << std::endl;
        // Handle the error, perhaps by logging it or asking the user for new input
    } catch (const std::exception& error) {
        std::cerr << "Something else went wrong: " << error.what() << std::endl;
        // Catch any other standard exceptions
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
    }

    std::cout << "Program continues after exception handling." << std::endl;

    return 0;
}