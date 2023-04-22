#pragma once
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Generators
{
private:
    uint32_t bits_1 = 0x0;   //переменная для полинома x^23+x^5+1
    uint64_t bits_2_1 = 0x0; //первая переменная для полинома x^124+x^37+1
    uint64_t bits_2_2 = 0x0; //вторая переменная для полинома x^124+x^37+1
    uint8_t bits_3 = 0x0;    //переменная для полинома x^6+x^1+1
    uint8_t bits_4 = 0x0;    //переменная для полинома x^5+x^4+x^2+x^1+1
    uint64_t for_zero_first_bit_64 = 0xFFFFFFFFFFFFFFFE;
    uint32_t for_zero_first_bit_32 = 0xFFFFFFFE;
    uint8_t for_zero_first_bit_8 = 0xFE;
    uint64_t size_bits_sequence = 0; //длина последовательности бит

public:
    Generators();
    void print_bits(uint8_t bits);  // вывод 8-ми битного числа
    void print_bits(uint32_t bits); // вывод 32-х битного числа
    void print_bits(uint64_t bits); // вывод 64-х битного числа
    void print_bit(uint8_t bits);   // вывод бита
    void gen_bit_generators(); // наполнение переменных начальными значениями
    uint8_t next_step_generator_1(); //получение бита обратной связи от 1 генератора
    uint8_t next_step_generator_2(); //получение бита обратной связи от 2 генератора
    uint8_t next_step_generator_3(); //получение бита обратной связи от 3 генератора
    uint8_t next_step_generator_4(); //получение бита обратной связи от 4 генератора
    uint8_t next_step_generators_1_2(); //получение бита обратной связи от 1 и 2 генератора
    uint8_t next_step_generators_3_4(); //получение бита обратной связи от 1 и 2 генератора
    uint64_t get_size_bits_sequence(); //получение кол-ва бит
};