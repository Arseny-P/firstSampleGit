#include <iostream>

void pyr(int levels){
    for(int i = 1; i <= levels; ++i){
        for(int j=0; j < i; ++j){
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

void right_pyr(int levels){
    for(int i = 0; i <= levels; ++i){
        for(int j = 0; (levels-i)>j;++j){
            std::cout << " ";
        }
        for(int j=0; j < i; ++j){
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

void reverse_right_pyr(int levels){
     for(int i = levels; i >= 0; --i){
        for(int j = 0; j < (levels - i);++j){
            std::cout << " ";
        }
        for(int j=0; j < i; ++j){
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

int main(){
    int levels=0;
    do{
        std::cout << "Please input levels: ";
        std::cin >> levels;
    }while(levels < 0);

    reverse_right_pyr(levels);
    
    return 0;
}