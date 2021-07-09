#include <iostream>
#include <memory>

/**********************************************************************
 * Interfaces
 */

template <typename T>
concept IPrinter = requires(T t)
{
    {t.print()};
};

template <typename T>
concept IScanner = requires(T t)
{
    {t.scan()};
};

template <typename T>
concept MultiFunctionPrinter = IPrinter<T> && IScanner<T>;

template <typename T>
concept ScannerOrPrinter = IPrinter<T> || IScanner<T>;

/**********************************************************************
 * Implementation
 */

class Printer
{
public:
    void print()
    {
        printf("Print ......... . \n");
    }
};

class Scanner
{
public:
    void scan()
    {
        printf("Scan ....... .\n");
    }
};

class AllInOnePrinter
{
public:
    void print()
    {
        printf("AllInOnePrinter::Print: Print ......... . \n");
    }

    void scan()
    {
        printf("AllInOnePrinter::Scan: Scan ....... .\n");
    }
};


/**********************************************************************
 * Third party
 */

template <ScannerOrPrinter T>
class User
{
public:
    User(std::shared_ptr<T> all_in_one_printer)
    : all_in_one_printer(all_in_one_printer)
    {
    }

    void print() requires IPrinter<T>
    {
        all_in_one_printer->print();
    }

    void scan() requires IScanner<T>
    {
        all_in_one_printer->scan();
    }

private:
    std::shared_ptr<T> all_in_one_printer;
};

int main()
{
    User user1(std::make_shared<AllInOnePrinter>());
    user1.print();
    user1.scan();

    User user2(std::make_shared<Scanner>());
    // user2.print();
    user2.scan();

    User user3(std::make_shared<Printer>());
    user3.print();
    // user2.scan();
}