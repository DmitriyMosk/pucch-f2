#ifndef PUCCH_ORCHEST
#define PUCCH_ORCHEST
#include <chrono>
#include "awgn.hpp"

typedef struct {
    // сигма операций
    awgn::sigma_t start;
    awgn::sigma_t end;
    awgn::sigma_t step;

    int opt_mode;

    // если будет true, то симуляция прогонится 1 раз при sigma_t start
    bool force_test;

    // Размер блока кодирования (20 x k)
    int block_size;

    // Test Data length
    int data_size;

    // Simulation iterations count for one data set
    int sim_iterations;

    // todo
    int monte_carlo_accuracy;
} ProccessOrchest;

void orchest_init(ProccessOrchest &orchest_ini);

using timestamp_t = std::chrono::high_resolution_clock::time_point;

typedef struct {
    // какое-то S_{i} значение сигмы в момент тестирования
    awgn::sigma_t s;
    // длина исходного сообщения
    size_t src_msg_len;
    // длина блока данных
    size_t encoded_block;
    // исходное сообщение
    std::unique_ptr<char[]> di;
    // закодированное сообщение
    std::unique_ptr<char[]> di_encoded;
    // закодированное сообщение в канале с шумом
    std::unique_ptr<float[]> di_encoded_noised; // Изменение типа
    // декодированное сообщение
    std::unique_ptr<char[]> di_decoded;
    // счётчик ошибок декодирования
    size_t decode_errors;
    // среднее кол-во ошибок
    float avg_errors;

    // bench statictic
    long long encoding_diff;
    long long decoding_diff;

    // todo
    bool require_print;
    // хранилище данных оркестратора для метрики
    ProccessOrchest etc;
} metrics_t;

enum metrics_key {

};

#endif