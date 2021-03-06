
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
      operator int() const;
      operator double() const;
      bool operator~()const;
      Account& operator=(const int New);
      Account& operator=(Account& RO);
      Account& operator+=(double value);
      Account& operator-=(double value);
      Account& operator<<(Account& RO);
      Account& operator>>(Account& RO);
   };

   double operator+(const Account& leftOper, const Account& rightOper);
   double operator+=(double& leftOper, const Account& rightOper);
   
   
}
#endif // SDDS_ACCOUNT_H_
