#include "dollars_and_cents.hpp"

int main()
{
    DollarandCents bank1(4, 175);
    DollarandCents bank2(6 , 75);
    DollarandCents bank3(5,0);

    bank1.increment_value(0,0);
    bank1.output_value();

    bank1.increment_value(bank2);
    bank1.output_value();
    bank1.decrement_value(bank3);
    bank1.output_value();
    return 0;
}