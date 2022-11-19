#include "CMenu.h"
#include "..\MyError\MyError.h"
#include <iostream>

namespace ExpressionTree
{
    CMenu::CMenu(){}
    CMenu::CMenu(std::string title, CMenuItem *items, size_t count) : m_title(title), m_items(items), m_count(count) {}

    int CMenu::getSelect() const {
        return m_select;
    }

    bool CMenu::getRunning()  {
        return m_running;
    }
    void CMenu::setRunning(bool _running)
    {
        m_running = _running;
    }

    size_t CMenu::getCount() const {
        return m_count;
    }

    std::string CMenu::getTitle() {
        return m_title;
    }

    CMenuItem *CMenu::getItems() {
        return m_items;
    }

    void CMenu::print()
    {
        
        for (size_t i{}; i < m_count-1; ++i)
        {
            std::cout << i + 1 << ". ";
            m_items[i].print();
            std::cout << std::endl;
        }
        //std::cout << "0. �����" << std::endl;
        std::cout << "0. ";
        m_items[m_count - 1].print();
        std::cout << std::endl;
    }

    void CMenu::printTitle() {
        system("cls");
        std::cout << "\t" << m_title << std::endl;
    }

    int CMenu::runCommand()
    {
        printTitle();
        print();
        std::cout << "\n   Select >> ";
        std::string SelectInput;
        bool flag = true;
        std::cin >> SelectInput;
        for (int i{ 0 }; i < SelectInput.size(); i++)
        {
            if (!(SelectInput[i] >= '0' && SelectInput[i] <= '9'))
            {
                flag = false;
            }
        }
        if (flag)
        {
            m_select = std::stoi(SelectInput);
            
        }
        else
        {
            system("cls");
            //std::cout << "\n������� ������� �������!��������� �������.\n";
            throw MyError{ "Wrong input. Enter only number." };
            system("pause");
            return 1;

        }
        if (m_select == 0)
        {
            //std::cout << std::endl << "����� �� ���������" << std::endl;
           //return 0;
           return m_items[m_count - 1].run();
            //exit(0);
            
        }
        else
        {
            if ((m_select > m_count - 1) || (m_select < 0))
            {
              system("cls");
              //std::cout << "\n������� ������� �������!��������� �������.\n"; 
              throw MyError{ "Wrong input. Enter correct number of menu." };
              system("pause");
                //system("pause");
               //system("cls");
                return 1;
            }
            else
            {
                system("cls");
                return m_items[m_select - 1].run();

            }
            
        }
    }
}