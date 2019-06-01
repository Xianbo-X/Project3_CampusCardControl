#include <iostream>
#include "..\..\src\card\campus_card.h"
#include "..\..\src\card\card.h"
#include "..\..\src\card\deposit_card.h"

//#define TEST_CAMPUS_CARD
#define TEST_DEPOSIT_CARD

int main() {
  std::string name;
  std::string password;
  std::string stuId;
  std::string department;
  std::string cardCode;
  int num;

#ifdef TEST_CAMPUS_CARD
  std::cin >> name;
  std::cin >> password;
  std::cin >> stuId;
  std::cin >> department;
  card::MoneyType amount;
  std::cin >> amount;
  card::Campus_Card STU1(name, password, stuId, department, amount);
  std::cout << STU1.GetInfo() << std::endl;
  std::cout << STU1.GetBalance() << std::endl;
  std::cin >> num;
  STU1.Deposit(num);
  std::cout << STU1.GetBalance() << std::endl;
  std::cin >> num;
  STU1.Withdraw(num);
  std::cout << STU1.GetBalance() << std::endl;
  std::cin >> num;
  STU1.Pay(num);
  std::cout << STU1.GetBalance() << std::endl;

  std::cin >> name;
  std::cin >> password;
  std::cin >> stuId;
  std::cin >> department;

  STU1.SetName(name);
  STU1.SetPasswd(password);
  STU1.SetStudentId(stuId);
  STU1.SetDepartment(department);
  std::cout << STU1.GetInfo() << std::endl;
#endif
#ifdef TEST_DEPOSIT_CARD
  std::cin >> name;
  std::cin >> password;
  std::cin >> cardCode;
  card::MoneyType amount;
  std::cin >> amount;
  card::Deposit_Card dep1(name, password, cardCode, amount);
  std::cout << dep1.GetInfo() << std::endl;
  std::cout << dep1.GetBalance() << std::endl;
  std::cin >> num;
  if (!dep1.Deposit(num)) std::cout << "FAILUSE\n";
  std::cout << dep1.GetBalance() << std::endl;
  std::cin >> num;
  if (!dep1.Withdraw(num)) std::cout << "FAILURE\n";
  std::cout << dep1.GetBalance() << std::endl;
  std::cin >> num;
  if (!dep1.Pay(num)) std::cout << "FAILURE\n";
  std::cout << dep1.GetBalance() << std::endl;

  std::cin >> name;
  std::cin >> password;
  std::cin >> cardCode;
  std::cin >> num;
  dep1.SetName(name);
  dep1.SetPasswd(password);
  dep1.SetCardCode(cardCode);
  dep1.SetOverdraft(num);
  std::cout << dep1.GetInfo() << std::endl;
#endif
  return 0;
}