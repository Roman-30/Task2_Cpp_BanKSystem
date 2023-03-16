#include <iostream>
#include "user.h"
#include "userType.h"
#include "account.h"
#include "bank.h"
#include <list>
#include <string>
#include <vector>

using namespace std;


User addNewUser()
{

    string name;
    string lastName;
    int passport;
    double cash;
    int num;
    Type type;

    cout << "Введите имя пользователя -> ";
    cin >> name;
    cout << "Введите фамилию пользователя -> ";
    cin >> lastName;
    cout << "Введите паспорт пользователя -> ";
    cin >> passport;
    cout << "Введите сумму пользователя -> ";
    cin >> cash;
    cout << "Введите тип пользователя пользователя (1 - физическое лицо, 2 - юридическое)-> ";
    cin >> num;

    if (num == 1) 
    {
        type = Type::Physical;
    }
    else
    {
        type = Type::Juridica;
    }
    return User(name, lastName, passport, cash, type);
}

void commands() 
{
    string s0 = "0 - Вывести список команд\n";
    string s1 = "1 - Создать пользователя\n";
    string s2 = "2 - Создать банк\n";
    string s3 = "3 - Вывести список пользователей\n";
    string s4 = "4 - Вывести список банков\n";
    string s5 = "5 - Добавть счет в банке\n";
    string s6 = "6 - Внести деньги на счет\n";
    string s7 = "7 - Вывести деньги со счет\n";
    string s8 = "8 - Сделать пееревод между счетами\n";
    string s9 = "9 - Удалить Пользователя\n";
    string s10 = "10 - Удалить Банк\n";
    string s11 = "-1 - Завершить процесс\n";

    cout << "Список команд:\n" + s0 + s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + s9 + s10 + s11 << endl;
}

Bank addNewBank()
{
    int id;
    string name;

    cout << "Введите имя банка -> ";
    cin >> name;
    cout << "Введите id банка -> ";
    cin >> id;
    
    return Bank(id, name);
}

int findBankIndex(vector<Bank> banks, int id)
{
    for (int i = 0; i < banks.size(); i++)
    {
        if (id == banks[i].getId()) 
        {
            return i;
            break;
        }
    }
    return -1;
}

int findUserIndex(vector<User> users, int passport)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (passport == users[i].getPassport())
        {
            return i;
            break;
        }
    }
    return -1;
}

bool isExists(vector<Bank> banks, int ind, int passport)
{
    for (int j = 0; j < banks[ind].getAccounts().size(); j++)
    {
        if (passport == banks[ind].getAccounts()[j].getId()) {
            return true;
            break;
        }
    }
    
    return false;
}

void removeUser(vector<User>& users, int index)
{
    users.erase(users.begin() + index);
}

void removeBank(vector<Bank>& banks, int index)
{
    banks.erase(banks.begin() + index);
}

int findAccIndex(vector<Bank> banks, int ix, int passport)
{
    for (int i = 0; i < banks[ix].getAccounts().size(); i++)
    {
        if (banks[ix].getAccounts()[i].getId() == passport)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    setlocale(LC_ALL, "rus");

    bool flag = true;
    int bId, passport, indexB, indexU, comand;
    double cash;

    vector <Bank> banks{};
    vector <User> users{};

    commands();

    while (flag)
    {
        try
        {
            cout << "Введите команду: ";
            cin >> comand;
        }
        catch (const std::exception&)
        {
            cout << "Ошибка";
        }

        switch (comand)
        {
        case -1:
            flag = false;
            cout << "Процесс завершен!";
            break;
        case 0:
            commands();
            break;
        case 1:
            users.push_back(addNewUser());
            cout << "Пользователь добавлен!" << endl;
            break;
        case 2:
            banks.push_back(addNewBank());
            cout << "Банк добавлен!" << endl;
            break;
        case 3:
            if (users.size() == 0)
            {
                cout << "Пользователей нет!" << endl;
            }
            else
            {
                cout << "Пользователи:" << endl;
                for (auto itU = users.begin(); itU != users.end(); itU++) {
                    cout << itU->toString() << endl;
                }
            }
            break;
        case 4:
            if (banks.size() == 0)
            {
                cout << "Банков нет!" << endl;
            }
            else
            {
                cout << "Банки:" << endl;
                for (auto itB = banks.begin(); itB != banks.end(); itB++) {
                    cout << itB->toString() << endl;
                }
            }
            break;
        case 5:
            cout << "Введете id банка: ";
            cin >> bId;

            indexB = findBankIndex(banks, bId);

            if (indexB == -1)
            {
                cout << "Операция прервана. Банк с данным id не существует!" << endl;
                break;
            }

            cout << "Введите паспортные данные пользователя: ";
            cin >> passport;

            indexU = findUserIndex(users, passport);

            if (indexU == -1)
            {
                cout << "Операция прервана. Пользователь с данным id не существует!" << endl;
                break;
            }

            if (!isExists(banks, indexB,passport))
            {
                banks[indexB].addAccount(users[indexU]);
                cout << "Счет создан!" << endl;
            } 
            else
            {
                cout << "Счет данного пользовалеля уже существует!" << endl;
                break;
            }
            break;
        case 6:
            
            double cash;
            cout << "Введете id банка: ";
            cin >> bId;

            indexB = findBankIndex(banks, bId);

            if (indexB == -1)
            {
                cout << "Операция прервана. Банк с данным id не существует!" << endl;
                break;
            }

            cout << "Введите паспортные данные пользователя: ";
            cin >> passport;

            indexU = findUserIndex(users, passport);

            if (indexU == -1)
            {
                cout << "Операция прервана. Пользователь с данным id не существует!" << endl;
                break;
            }

            if (isExists(banks, indexB ,passport))
            {
                cout << "Введите сумму для вклада: ";
                cin >> cash;
                
                if (users[indexU].getCash() - cash < 0) {
                    cout << "Не достаточно средств для совершения вклада" << endl;
                    break;
                }
                else
                {
                    double userCash = users[indexU].getCash();
                    users[indexU].setCash(userCash - cash);
                    banks[indexB].getAccounts()[findAccIndex(banks, indexB, users[indexU].getPassport())].updateSum(cash, true);
                    banks[indexB].upDateCash(cash, true);

                    cout << "Сумма внесена!" << endl;
                }
            }
            else
            {
                cout << "Счет не найден или не сущесвует!" << endl;
                break;
            }

            break;
        case 7:
           
            cout << "Введете id банка: ";
            cin >> bId;

            indexB = findBankIndex(banks, bId);

            if (indexB == -1)
            {
                cout << "Операция прервана. Банк с данным id не существует!" << endl;
                break;
            }

            cout << "Введите паспортные данные пользователя: ";
            cin >> passport;

            indexU = findUserIndex(users, passport);

            if (indexU == -1)
            {
                cout << "Операция прервана. Пользователь с данным id не существует!" << endl;
                break;
            }

            if (isExists(banks, indexB,passport))
            {
                cout << "Введите сумму для вывода: ";
                cin >> cash;

                
                if (banks[indexB].getAccounts()[findAccIndex(banks, indexB, users[indexU].getPassport())].updateSum(cash, true)) {
                    double userCash = users[indexU].getCash();
                    users[indexU].setCash(userCash + cash);
                    banks[indexB].upDateCash(cash, false);

                    cout << "Сумма успешно снята!" << endl;
                }
                
            }
            else
            {
                cout << "Счет не найден или не сущесвует!" << endl;
                break;
            }

            break;
        case 8:

            cout << "Введите паспортные данные пользователя: ";
            cin >> passport;

            indexU = findUserIndex(users, passport);

            if (indexU == -1)
            {
                cout << "Операция прервана. Пользователь с данным id не существует!" << endl;
                break;
            }
             
            cout << "Введете id банка отправителя: ";
            cin >> bId;

            indexB = findBankIndex(banks, bId);

            if (indexB == -1)
            {
                cout << "Операция прервана. Банк с данным id не существует!" << endl;
                break;
            }

            int bIdnew, indexBNew;

            cout << "Введете id банка получателя: ";
            cin >> bIdnew;

            indexBNew = findBankIndex(banks, bIdnew);

            if (indexBNew == -1)
            {
                cout << "Операция прервана. Банк с данным id не существует!" << endl;
                break;
            }

            if (isExists(banks, indexB,passport))
            {
                cout << "Введите сумму для перевода: ";
                cin >> cash;

                double perCash = cash - (cash * banks[indexB].getPercent());

                cout << perCash;
                 
                banks[indexB].upDateCash(perCash, false);
                banks[indexBNew].upDateCash(perCash, true);

                banks[indexB].getAccounts()[findAccIndex(banks, indexB, users[indexU].getPassport())].updateSum(perCash, false);
                banks[indexBNew].getAccounts()[findAccIndex(banks, indexBNew, users[indexU].getPassport())].updateSum(perCash, true);

                cout << "Сумма переведена!" << endl;
            }
            else
            {
                cout << "Счет не найден или не сущесвует!" << endl;
                break;
            }

            break;
        case 9:

            if (users.size() > 0)
            {
                cout << "Введите паспортные данные пользователя: ";
                cin >> passport;

                indexU = findUserIndex(users, passport);

                if (indexU == -1)
                {
                    cout << "Операция прервана. Пользователь с данным id не существует!" << endl;
                    break;
                }

                removeUser(users, indexU);
                cout << "Пользователь удален!" << endl;
            }
            else
            {
                cout << "Пользователей нет!" << endl;
            }
            break;
        case 10:

            if (banks.size() > 0)
            {
                cout << "Введете id банка: ";
                cin >> bId;

                indexB = findBankIndex(banks, bId);

                if (indexB == -1)
                {
                    cout << "Операция прервана. Банк с данным id не существует!" << endl;
                    break;
                }

                removeBank(banks, indexB);
                cout << "Банк удален!" << endl;
            }
            else
            {
                cout << "Банков нет!" << endl;
            }
            break;
        default:
            cout << "Команда отсутвует!" << endl;
            commands();
        }        
    }
    
    return 0;
}
