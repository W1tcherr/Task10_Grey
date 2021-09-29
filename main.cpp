#include <iostream>
#include <bitset>

unsigned gray_encode(unsigned const num)
{
    return num ^ (num >> 1);
}

unsigned gray_decode(unsigned gray)
{
    for (unsigned bit = 1U << 31; bit > 1; bit >>= 1)
    {
        if (gray & bit)
            gray ^= bit >> 1;
    }
    return gray;
}

std::string to_binary(unsigned value, int const digits)
{
    return std::bitset<32>(value).to_string().substr(32-digits, digits);
}

int main()
{
    std::cout << "Number\tBinary\tGray\tDecoded\n";
    std::cout << "------\t------\t----\t-------\n";
    for (unsigned n = 0; n < 32; ++n)
    {
        auto encg = gray_encode(n);
        auto decg = gray_decode(encg);
        std::cout << '\t' << n << "\t" << to_binary(n, 5) << "\t" << to_binary(encg, 5) << "\t" << decg << "\n";
    }

    return 0;
}

