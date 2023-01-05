#include <iostream>
#include <bitset>

void printBin(int number) {
    int bit = 0x8000;
    for (int i = 0; i < 16; i++) {
        if (bit & number)
            printf("1");
        else
            printf("0");
        bit = bit >> 1;
    }
}

int main(){
    //declaring the binary variables
    using bit  = bool;
    using byte = unsigned char;     // uint8_t
    using word = unsigned short;    // uint16_t
    bit  var_bit  = 1;
    byte var_byte = 0xFF;
    word var_word = 0x0000;

    //declaring the binary variables using 'bitset' library
    using _bit = std::bitset<1>;
    using _byte = std::bitset<8>;
    using _word = std::bitset<16>;
    _bit  bitset_bit  = 1;
    _byte bitset_byte = 0xFF;
    _word bitset_word = 0x0000;

    //binary operations
    std::cout << "word             ";   printBin(var_word);  std::cout << std::endl;
    std::cout << "byte             ";   printBin(var_byte);  std::cout << std::endl;
    var_word = var_byte;
    std::cout << "word <- byte     ";   printBin(var_word);  std::cout << std::endl;
    var_word = var_word << 5;
    std::cout << "word << 5        ";   printBin(var_word);  std::cout << std::endl;
    var_word = var_word >> 2;
    std::cout << "word >> 2        ";   printBin(var_word);  std::cout << std::endl;
    var_word = var_word & 0x00FF;
    std::cout << "AND with 0x00FF  ";   printBin(var_word);  std::cout << std::endl;
    var_word = var_word | 0xAAAA;
    std::cout << "0xAAAA           ";   printBin(0xAAAA);    std::cout << std::endl;
    std::cout << "OR with 0xAAAA   ";   printBin(var_word);  std::cout << std::endl;
    var_word = ~var_word;
    std::cout << "Inverter ~       ";   printBin(var_word);  std::cout << std::endl;
    var_word = var_word ^ 0x0FF0;
    std::cout << "XOR with 0x0FF0  ";   printBin(var_word);  std::cout << std::endl;
    std::cout << "flag 9th bit            ^        " << std::endl;
    var_bit = var_word & 0x0100;
    std::cout << "flag 9th bit     " << var_bit << std::endl;
    var_word = var_word ^ 0x0100;
    std::cout << "flip 9th bit     ";   printBin(var_word);  std::cout << std::endl;
    std::cout << "flag 9th bit            ^        " << std::endl;
    var_bit = var_word & 0x0100;
    std::cout << "flag 9th bit     " << var_bit << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;

    //binary operations using 'bitset' library
    std::cout << "word             " << bitset_word << std::endl;
    std::cout << "byte             " << std::bitset<8>(0x00) << bitset_byte << std::endl;
    bitset_word = bitset_byte.to_ullong();
    std::cout << "word <- byte     " << bitset_word << std::endl;
    bitset_word.operator<<=(5);
    std::cout << "word << 5        " << bitset_word << std::endl;
    bitset_word.operator>>=(2);
    std::cout << "word >> 2        " << bitset_word << std::endl;
    bitset_word.operator&=(0x00FF);
    std::cout << "AND with 0x00FF  " << bitset_word << std::endl;
    bitset_word.operator|=(0xAAAA);
    std::cout << "0xAAAA           " << std::bitset<16>(0xAAAA) << std::endl;
    std::cout << "OR with 0xAAAA   " << bitset_word << std::endl;
    bitset_word = bitset_word.operator~();
    std::cout << "Inverter ~       " << bitset_word << std::endl;
    bitset_word.operator^=(0x0FF0);
    std::cout << "XOR with 0x0FF0  " << bitset_word << std::endl;
    std::cout << "flag 9th bit            ^        " << std::endl;
    bitset_bit = bitset_word[8].operator bool();
    std::cout << "flag 9th bit     " << bitset_bit << std::endl;
    bitset_word.operator^=(0x0100);
    std::cout << "flip 9th bit     " << bitset_word << std::endl;
    std::cout << "flag 9th bit            ^        " << std::endl;
    bitset_bit = bitset_word[8].operator bool();
    std::cout << "flag 9th bit     " << bitset_bit << std::endl;
}