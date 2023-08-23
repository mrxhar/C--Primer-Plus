#include <istream>
#include "brass.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Brass piggy("Porcelot Pigg", 381299, 4000.0);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.0);

    piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "Depositing $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "New Ballance: $" << Hoggy.Balance() << endl;

    cout << "Withdrawing $4200 form the piggy account:\n";
    piggy.Withdraw(4200.00);
    cout << "Piggy Account banlance: $" << piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the hogg Account:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();

    return 0;
}