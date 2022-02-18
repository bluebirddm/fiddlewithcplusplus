//
// Created by dingmao on 2022/2/11.
//

#ifndef DEMO_HELLO_TEST_H
#define DEMO_HELLO_TEST_H

#include <iostream>
using namespace std;

void loop_test() {

    std::cout << "----------------------------- " << endl;

    for (int i = 0; i < 4; i++)
    {

        std::cout << "first loop idx begin: " << i << endl;

        for (int j = 0; j < 4 ; j++)
        {

            std::cout << "second loop idx begin: " << j << endl;

//            break;
//            continue;
//            return;
        }

        std::cout << "first loop idx end  : " << i << endl;

        std::cout << "----------------------------- " << endl;
    }
}

#endif //DEMO_HELLO_TEST_H
