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

template <MultiFunctionPrinter T>
class User
{
public:
    User(std::shared_ptr<T> all_in_one_printer)
    : all_in_one_printer(all_in_one_printer)
    {
    }

    void print()
    {
        all_in_one_printer->print();
    }

    void scan()
    {
        all_in_one_printer->scan();
    }

private:
    std::shared_ptr<T> all_in_one_printer;
};

int main()
{
    User user(std::make_shared<AllInOnePrinter>());
    user.print();
    user.scan();
}