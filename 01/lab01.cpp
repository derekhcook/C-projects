// Derek Cook
// CS 2336
// Lab 01

#include <iostream>
#include <string>

using namespace std;

const string ID = "Derek Cook - CS2336 - Lab 01\n\n";

uint productOfDigits(uint num);

int main()
{
    uint num;
    
    //output ID line
    cout << ID;
    
    //read an unknown number of units from standard input_iterator
    while (cin >> num)
    {
        uint persistence = 0;
        
        cout << num;
        
        //cycles through the numbers untilo there are no double digits
        while (num > 9)
        {
            //sets num equal to product
            num = productOfDigits(num);
            
            //prints the product
            cout << " -> " << num;
            
            //counts the number of cycles through productofdigits(uint num)
            ++persistence;
        }
        //outputs the number of cycles through
        cout << " persistence = " << persistence << endl;
        
    }
    
    return 0;
    
}

uint productOfDigits(uint num)
{
    uint digit, product;
    
    product = (num == 0) ? 0 : 1;
    
    while (num != 0)
    {
        // step 1: compute the rightmost digit of num
        digit = num % 10;
        
        //step 2: incorporate the rightost digit of num into product
        product = product * digit;
        
        //step 3:eliminate right most digit from num
        num = num / 10;
    }
    
    return product;
    
}
