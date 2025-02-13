// #include <iostream>
// #include <cstdint>

// #include "orchest.hpp"

// #if defined(__GNUC__) || defined(__clang__)
// uint64_t rdtsc() {
//     unsigned int lo, hi;
//     __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
//     return ((uint64_t)hi << 32) | lo;
// }
// #endif

// int main(int argc, char* argv[]) {
//     std::cout << "Ready pj" << std::endl; 

//     ProccessOrchest orch_ini; 
//     // задаём начальное значение sigma 
//     orch_ini.start = 0.01; 
//     // конечное значение sigma 
//     orch_ini.end   = 1.5; 
//     // шаг sigma для каждого этапа симуляции
//     orch_ini.step  = 0.01; 
//     // количество шагов симуляции
//     orch_ini.sim_iterations = 1000; 

//     // pass 
//     orch_ini.force_test = false      ; 
//     orch_ini.block_size = 2          ;

//     // Инициализация оркестратора 
//     orchest_init(orch_ini);


//     return EXIT_SUCCESS;
// }

#include <iostream>
#include <cstdlib>
#include <sstream>
#include "orchest.hpp"

void print_usage(const char* prog_name) {
    std::cerr << "Usage: " << prog_name << " <sigma_start> <sigma_end> <sim_iterations | 0 for force test>\n";
    std::cerr << "Example: " << prog_name << " 0.01 1.5 1000 1\n";
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    ProccessOrchest orch_ini;
    
    // Читаем аргументы
    std::istringstream ss1(argv[1]), ss2(argv[2]), ss3(argv[3]), ss4(argv[4]);

    if (!(ss1 >> orch_ini.start) || !(ss2 >> orch_ini.end) || !(ss3 >> orch_ini.sim_iterations) || (!ss4 >> orch_ini.opt_mode) || 
        orch_ini.start < 0 || orch_ini.end <= orch_ini.start || orch_ini.sim_iterations < 0 || orch_ini.opt_mode < 1 || orch_ini.opt_mode > 3) {
        std::cerr << "Invalid arguments provided!\n";
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Устанавливаем шаг sigma
    orch_ini.step = 0.01;

    // Определяем, включать ли форсированный тест
    orch_ini.force_test = (orch_ini.sim_iterations == 0);
    orch_ini.block_size = 2;

    std::cout << "Starting simulation with parameters:\n";
    std::cout << "  Sigma Start: " << orch_ini.start << "\n";
    std::cout << "  Sigma End: " << orch_ini.end << "\n";
    std::cout << "  Sim Iterations: " << (orch_ini.force_test ? "Force Test Enabled" : std::to_string(orch_ini.sim_iterations)) << "\n";

    // Запуск оркестратора
    orchest_init(orch_ini);

    return EXIT_SUCCESS;
}