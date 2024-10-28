#include <iostream>

int main(){
    unsigned int a, b;
    std::cout << "Please, write two numbers" << std::endl;
    std::cout << "First num = ";
    std::cin >> a;
    std::cout << '\n' << "Second num = "; 
    std::cin >> b;
    std::cout << std::endl;
    if((a > 0xFFFF) || (b > 0xFFFF)){
        std::cout << "Error, need numbers < 65535 ";
        return 1;
    }
    
    int shift = 0;
    unsigned int res = 0x00000000;
    for(int i = 0; i < 32; ++i){
        if(i % 2 == 0){
            res |= (((b>>shift) & 1) << i);
        }
        else{
            res |= (((a>>shift) & 1) << i);
            ++shift;
        }
    }
    std::cout  << "New number = " << res << std::endl;
    return 0;
}