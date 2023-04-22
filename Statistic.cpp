#include "Statistic.h"
Statistic::Statistic() {}

void Statistic::clear_all()
{
    frequency_arr[4][16] = { 0 };
    code_tabl_arr[256] = { 0 };
    bits_for_frequency = 0;
    bits_for_autocorrelation.clear();
    size_bits_sequence = 0;
    nums_bytes = 0;
}
void Statistic::update_data(uint8_t x)
{
    if(x)
        bits_for_autocorrelation.push_back(true);
    else
        bits_for_autocorrelation.push_back(false);
    frequency_arr[0][x] += 1;
    bits_for_frequency = (bits_for_frequency << 1) | x;
    if(size_bits_sequence > 0) {
        frequency_arr[1][bits_for_frequency & 0x03] += 1;
    }
    if(size_bits_sequence > 1) {
        frequency_arr[2][bits_for_frequency & 0x07] += 1;
    }
    if(size_bits_sequence > 2) {
        frequency_arr[3][bits_for_frequency & 0x0F] += 1;
    }
    size_bits_sequence += 1;
}
void Statistic::calc_corellation(int t)
{
    int At = 0, Bt = 0;
    switch(t) {
    case 0: {
        cout << "K(t) = 1";
        break;
    }
    default: {
        for(long unsigned int i = t; i < bits_for_autocorrelation.size(); i++) {
            if(bits_for_autocorrelation[i] == bits_for_autocorrelation[i - t])
                At++;
            else
                Bt++;
        }
        cout << "Автокорреляция ПСП:" << endl;
        cout << "A(t) = " << At << "\nB(t) = " << Bt << "\nK(t) = " << (double)(At - Bt) / (At + Bt) << endl;
    }
    }
}
void Statistic::print_num_prob(int comb_num)
{

    cout << "Количество комбинаций " << endl;
    double all_nums;
    switch(comb_num) {

    case 1:
        cout << "0:" << frequency_arr[0][0] << "; 1:" << frequency_arr[0][1] << endl;
        break;
    case 2:
        cout << "00:" << frequency_arr[1][0] << " 01:" << frequency_arr[1][1] << " 10:" << frequency_arr[1][2]
             << " 11:" << frequency_arr[1][3] << endl;
        break;
    case 3:
        cout << "000:" << frequency_arr[2][0] << "; 001:" << frequency_arr[2][1] << "; 010:" << frequency_arr[2][2]
             << "; 011:" << frequency_arr[2][3] << "; 100:" << frequency_arr[2][4] << "; 101:" << frequency_arr[2][5]
             << "; 110:" << frequency_arr[2][6] << "; 111:" << frequency_arr[2][7] << endl;
        break;
    case 4:
        cout << "0000:" << frequency_arr[3][0] << "; 0001:" << frequency_arr[3][1] << "; 0010:" << frequency_arr[3][2]
             << "; 0011:" << frequency_arr[3][3] << "; 0100:" << frequency_arr[3][4] << "; 0101:" << frequency_arr[3][5]
             << "; 0110:" << frequency_arr[3][6] << "; 0111:" << frequency_arr[3][7] << "; 1000:" << frequency_arr[3][8]
             << "; 1001:" << frequency_arr[3][9] << "; 1010:" << frequency_arr[3][10]
             << "; 1011:" << frequency_arr[3][11] << "; 1100:" << frequency_arr[3][12]
             << "; 1101:" << frequency_arr[3][13] << "; 1110:" << frequency_arr[3][14]
             << "; 1111:" << frequency_arr[3][15] << endl;
        break;
    }
    cout << "Вероятность появления комбинаций" << endl;
    switch(comb_num) {
    case 1:
        all_nums = (double)size_bits_sequence;
        cout << "0:" << (double)frequency_arr[0][0] / all_nums << "; 0:" << (double)frequency_arr[0][1] / all_nums
             << endl;
        break;
    case 2:
        all_nums = (double)size_bits_sequence - 1;
        cout << "00:" << (double)frequency_arr[1][0] / all_nums << "; 01:" << (double)frequency_arr[1][1] / all_nums
             << "; 10:" << (double)frequency_arr[1][2] / all_nums << "; 11:" << (double)frequency_arr[1][3] / all_nums
             << endl;
        break;
    case 3:
        all_nums = (double)size_bits_sequence - 2;
        cout << "000:" << (double)frequency_arr[2][0] / all_nums << "; 001:" << (double)frequency_arr[2][1] / all_nums
             << "; 010:" << (double)frequency_arr[2][2] / all_nums << "; 011:" << (double)frequency_arr[2][3] / all_nums
             << "; 100:" << (double)frequency_arr[2][4] / all_nums << "; 101:" << (double)frequency_arr[2][5] / all_nums
             << "; 110:" << (double)frequency_arr[2][6] / all_nums << "; 111:" << (double)frequency_arr[2][7] / all_nums
             << endl;
        break;
    case 4:
        all_nums = (double)size_bits_sequence - 3;
        cout << "0000:" << (double)frequency_arr[3][0] / all_nums << "; 0001:" << (double)frequency_arr[3][1] / all_nums
             << "; 0010:" << (double)frequency_arr[3][2] / all_nums
             << "; 0011:" << (double)frequency_arr[3][3] / all_nums
             << "; 0100:" << (double)frequency_arr[3][4] / all_nums
             << "; 0101:" << (double)frequency_arr[3][5] / all_nums
             << ": 0110:" << (double)frequency_arr[3][6] / all_nums
             << "; 0111:" << (double)frequency_arr[3][7] / all_nums
             << "; 1000:" << (double)frequency_arr[3][8] / all_nums
             << "; 1001:" << (double)frequency_arr[3][9] / all_nums
             << "; 1010:" << (double)frequency_arr[3][10] / all_nums
             << "; 1011:" << (double)frequency_arr[3][11] / all_nums
             << "; 1100:" << (double)frequency_arr[3][12] / all_nums
             << "; 1101:" << (double)frequency_arr[3][13] / all_nums
             << "; 1110:" << (double)frequency_arr[3][14] / all_nums
             << "; 1111:" << (double)frequency_arr[3][15] / all_nums << endl;
        break;
    }
    cout << "Вероятность появления комбинаций c одинаковым кол-вом единиц" << endl;
    switch(comb_num) {
    case 1:
        all_nums = (double)size_bits_sequence;
        cout << "0:" << (double)frequency_arr[0][0] / all_nums << "; 0:" << (double)frequency_arr[0][1] / all_nums
             << endl;
        break;
    case 2:
        all_nums = (double)size_bits_sequence - 1;
        cout << "Нет единиц: " << (double)frequency_arr[1][0] / all_nums
             << "; Одна единица: " << ((double)frequency_arr[1][1] + (double)frequency_arr[1][2]) / all_nums
             << "; Две единицы: " << (double)frequency_arr[1][3] / all_nums << endl;
        break;
    case 3:
        all_nums = (double)size_bits_sequence - 2;
        cout << "Нет единиц:" << (double)frequency_arr[2][0] / all_nums << "; Одна единица:"
             << ((double)frequency_arr[2][1] + (double)frequency_arr[2][2] + (double)frequency_arr[2][4]) / all_nums
             << "; Две единицы:"
             << ((double)frequency_arr[2][3] + (double)frequency_arr[2][5] + (double)frequency_arr[2][6]) / all_nums
             << "; Три единицы:" << (double)frequency_arr[2][7] / all_nums << endl;
        break;
    case 4:
        all_nums = (double)size_bits_sequence - 3;
        cout << "Нет единиц:" << (double)frequency_arr[3][0] / all_nums << "; Одна единица:"
             << ((double)frequency_arr[3][1] + (double)frequency_arr[3][2] + (double)frequency_arr[3][4] +
                 (double)frequency_arr[3][8]) /
                    all_nums
             << "; Две единицы:"
             << ((double)frequency_arr[3][3] + (double)frequency_arr[3][5] + (double)frequency_arr[3][6] +
                 (double)frequency_arr[3][8] + (double)frequency_arr[3][9] + (double)frequency_arr[3][10] +
                 (double)frequency_arr[3][12]) /
                    all_nums
             << "; Три единицы:"
             << ((double)frequency_arr[3][7] + (double)frequency_arr[3][11] + (double)frequency_arr[3][13] +
                 (double)frequency_arr[3][14]) /
                    all_nums
             << "; Четыре единицы:" << (double)frequency_arr[3][15] / all_nums << endl;
        break;
    }
}

void Statistic::update_code_table(uint8_t byte) { code_tabl_arr[byte] += 1; }
void Statistic::print_code_table()
{
    for(int i = 0; i <= 255; i++) {
        cout << (char)i << " : " << i << " : " << (double)code_tabl_arr[i] / (double)nums_bytes << endl;
    }
}
void Statistic::update_bytes_size() { nums_bytes += 1; }