﻿// OOPLab8T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"Task1.h"
#include"Task2.h"
#include"Task3.h"
#include"Task4.h"
int main()
{
    int r;       
    std::cout << "Lab 8 \n";
    char ch = '5';
    do {
        std::cout << "Chose task 1-4 (5-exit):" << std::endl;
        std::cout << " >>> ";
        ch = std::cin.get();

        std::cin.get();

        switch (ch) {
        case '1': Task1();  break;
        case '2': Task2();  break;
        case '3': Task3();  break;
        case '4': Task4(); break;
        case '5': return 0;
        }
        std::cout << " Press any key and enter\n";
        ch = std::cin.get();
    } while (ch != '5');
    
}

