#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Statistic
{
private:
    int frequency_arr[4][16] = { 0 }; // массив для вычисления вероятности появления комбинаций бит
    int code_tabl_arr[256] = { 0 }; // массив для вычисления вероятности появления символов кодовой таблицы
    uint8_t bits_for_frequency = 0; // переменная хранящая последовательность комбинаций бит
    vector<bool> bits_for_autocorrelation; // массив для вычисления автокорелляции
    uint64_t size_bits_sequence = 0;       // кол-во бит в последовательности
    uint64_t nums_bytes = 0;               // кол-во байт

public:
    Statistic();
    void clear_all();             //очистить все переменные
    void calc_corellation(int t); //вычисление автокорелляции
    void print_num_prob(int bits_num); // вывести вероятности появления комбинаций бит
    void update_data(uint8_t x);       // подсчёт статистики
    void update_code_table(uint8_t byte); // вычисление вероятности появления символов кодовой таблицы
    void print_code_table(); // вывод вероятности появления символов кодовой таблицы
    void update_bytes_size(); // вычисление кол-ва байт
};