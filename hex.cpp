#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

int to_int(const char* line){
    int num = 0;
    for(int i = 0; line[i] != '\0'; i++){
        if(line[i] <= '9' && line[i] >= '0'){
            num = (num * 10) + (line[i] - '0');
        }
    }
    return num;
}

char* strcopy(char* to_str, const char* from_str, int num) {
    int i = 0;
    for (; i < num && from_str[i] != '\0'; i++) {
        to_str[i] = from_str[i];
    }
    for (; i < num; i++) {
        to_str[i] = '\0';
    }
    return to_str;
}

char* mergestr(char* str_to_merge, const char* str_that_merge, int num) {
    int len = 0;
    while (str_to_merge[len] != '\0') {
        len++;
    }
    int i = 0;
    while (i < num && str_that_merge[i] != '\0') {
        str_to_merge[len + i] = str_that_merge[i];
        i++;
    }
    str_to_merge[len + i] = '\0';
    return str_to_merge;
}


int main(int argc, char *argv[]){
    if(argc != 2 && argc != 4 && argc != 6){
        std::cout << "error" << std::endl;
        return 1;
    }
    char *file_name = argv[argc - 1];
    std::fstream input;
    input.open(file_name, std::ios_base::in | std::ios_base::binary);
    if(!input.is_open()){
        std::cout << "error" << std::endl;
        std::cout << "cannot open input file" << std::endl;
        return 2;
    }

    char new_file_name[265]; //260 - максимальное название файлов + 5 символов на .hex\0
    strcopy(new_file_name, file_name, 260);
    new_file_name[265] = '\0';
    mergestr(new_file_name, ".hex", 5);

    std::ofstream output;
    output.open(new_file_name, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
    if (!output.is_open()){
        std::cout << "error" << std::endl;
        std::cout << "cannot create output file" << std::endl;
        return 3;
    }

    int shift = 0;
    int len_to_out = -1;
    for (int i = 1; i < argc - 1; i += 2){
        if (argv[i][1] == 's') {
            shift = to_int(argv[i + 1]);
        }else if(argv[i][1] == 'n'){
            len_to_out = to_int(argv[i + 1]); 
        }
    }
    input.seekg(shift); //производим сдвиг на shift
    
    int count_output_str = 0;
    char str_to_output[17];
    for (int k = 0; k < 17; k++){
        str_to_output[k] = '\0';
    }

    output << std::hex << std::setw(10) << std::setfill('0') << std::uppercase << count_output_str << ": ";
    char str[17];
    int count_out_symb = 0;
    while((len_to_out != 0) && (input.read(str, 16) || input.gcount() > 0)){
        int len_str = input.gcount();
        if (len_to_out > 0 && len_str > len_to_out) {
            len_str = len_to_out;
        }
        for(int j = 0; j < len_str; j++){
            count_out_symb++;
            unsigned char out = (unsigned char)str[j];
            output << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << (int)out << " ";
            if(out >= 32){
                str_to_output[j % 16] = str[j];
            }else{
                str_to_output[j % 16] = '.';
            }
            if((j + 1) % 16 == 0 && j != 0){
                output << " " << str_to_output << std::endl;
                count_output_str += 16;
                output << std::hex << std::setw(10) << std::setfill('0') << std::uppercase << count_output_str << ": ";
                for (int k = 0; k < 17; k++){
                    str_to_output[k] = '\0';
                }
                continue;
            }
            if((j + 1) % 8 == 0 && j != 0){
                output << "| ";
            }
        }

        if (len_to_out > 0){
            len_to_out -= len_str;
        }
    }

    if(count_out_symb > 0){
        while(count_out_symb % 16 != 0){
            if(count_out_symb % 8 == 0){
                output << "| ";
                output << "   ";
            }else{
                output << "   ";
            }
            count_out_symb++;
        }
        output << " " << str_to_output; 
    }

    input.close();
    output.close();
}