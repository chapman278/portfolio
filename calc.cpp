#include <iostream>

int main()
{
    int x, y, sum;
    char op;
    //prompt user for number
    std::cout << "Enter a number: ";
    std::cin >> x;
    //prompt for another number
    std::cout << "Enter another number: ";
    std::cin >> y;
    //prompt for operator
    std::cout << "Operator (+|-|/|*): ";
    std::cin >> op;
    //check operator, execute accordingly
    if (op ==  '+')
    {
        sum = x + y;
    }
    else if (op == '-')
    {
        sum =  x - y;
    }
    else if (op ==  '/')
    {
        sum = x / y;
    }
    else if (op == '*')
    {
        sum = x * y;
    }
    //if operator doesnt match, print invalid message, exit
    else
    {
        std::cout << "Invalid Function!\n";
        return 0;
    }
    //print "x op y is sum"
    std::cout << x << ' ' << op << ' ' <<  y << " is " << sum << '\n';
    return 0;

}