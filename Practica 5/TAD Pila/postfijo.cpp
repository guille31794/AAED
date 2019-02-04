//
//  postfijo.cpp
//  test
//
//  Created by Guillermo Girón García on 04/02/2019.
//  Copyright © 2019 Guillermo Girón García. All rights reserved.
//

#include <iostream>
#include "pilaEnla.hpp"
#include <cstring>

using namespace std;

int compute(char* postfijo)
{
    Pila<int> P;
    int A = 3, B = 5, C = 6;
    
    for (int i = 0; i < strlen(postfijo); ++i)
    {
        switch (postfijo[i])
        {
            case 'A': P.push(A);
                break;
            case 'B': P.push(B);
                break;
            case 'C': P.push(C);
                break;
            default: int term2 = P.tope();
                P.pop();
                int term1 = P.tope();
                P.pop();
                switch (postfijo[i])
            {
                case '+': P.push(term1 + term2);
                        break;
                case '-': P.push(term1 - term2);
                    break;
                case '*': P.push(term1 * term2);
                    break;
                case '/': P.push(term1 / term2);
                    break;
                }
                break;
        }
    }
    
    return P.tope();
}

int main()
{
    cout << "ABC+* -> The result is: " << compute((char*)"ABC+*") << endl;
}
