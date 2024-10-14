#include <iostream>

int main(){
    int height;
    std::cout << "Enter the height of the pyramid: ";
    std::cin >> height;
    std::cout << std::endl;
    while(height < 0){
        std::cout << "Enter the height of the pyramid: ";
        std::cin >> height;
        std::cout << std::endl;
    }
    for(int i = 1; i <= height; ++i){
        for(int j=0; j < i; ++j){
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    return 0;
}