#include <iostream>
#include <iomanip>

int main(){
    unsigned a, res;
    std::cout << "Enter num: ";
    std::cin >> a;
    res = a & 0xF000000F;
    res |= ((a&0xF00000) << 4) | ((a&0xF000000) >> 4);
    res |= ((a&0xF000) << 4) | ((a&0xF0000) >> 4);
    res |= ((a&0xF0) << 4) | ((a&0xF00) >> 4);
    std::cout << "Yur new num = " << res << std::endl;
    //std::cout << std::hex << res << std::endl; //for tests 
}