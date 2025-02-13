# pucch-f2

## Overview

This project simulates the performance of a block code using a generator matrix and visualizes error rates for various values of `k` (number of information bits) and `sigma` (standard deviation of noise). Although using classes might introduce some overhead and potentially slow down execution, the code is structured this way to align with personal preference and maintainability.

## Dependencies

### C++ Dependencies

1. **CMake**: Required for building the project.
2. **GCC**: C++ compiler.
3. **C++17 Support**: Ensure your compiler supports C++17.

### Python Dependencies

1. **Python 3**: Required for running the visualization script.
2. **Pandas**: For data manipulation.
3. **Matplotlib**: For generating plots.

## Installation

### C++ Dependencies

#### Installing CMake

- **Ubuntu/Debian**:
    ```bash
    sudo apt-get update
    sudo apt-get install cmake
    ```

#### Installing GCC

- **Ubuntu/Debian**:
    ```bash
    sudo apt-get update
    sudo apt-get install build-essential
    ```

### Python Dependencies

- **Installing Python 3**:
    - Download and install from [python.org](https://www.python.org/downloads/).
    - Alternatively, use a package manager like `apt`:
        ```bash
        sudo apt-get update
        sudo apt-get install python3 python3-pip
        ```

- **Installing Pandas and Matplotlib**:
    ```bash
    pip3 install pandas matplotlib
    ```

---

### Run

```sh
   ./run.sh <sigma_start> <sigma_end> <sim_iterations | 0 - if force simulation>
```

### !!!! 3.1 Additional tasks

Замерьте время работы блок-декодера. Попробуйте максимально уменьшить время
используя различные приемы.

```sh
./run.sh <sigma_start> <sigma_end> <sim_iterations | 0 - if force simulation> <optimize mode = {1,2,3}>
```
#### <optimize mode> 
    
1. Стандартный метод
2. Регуляризация Тихонова + градиенты
3. первый режим, но с кешированием

Попробуйте качественно объяснить ход отснятых вами кривых. Почему код (20, 2)
гораздо более помехоусточив чем (20, 11)

Код (n, k) означает, что каждое кодовое слово имеет длину n бит, из которых k информационных бит, а остальные (n - k) — избыточные биты для коррекции ошибок. В данном случае, у нас есть два кода: (20, 2) и (20, 11).
Помехоустойчивость кода тесно связана с минимальным расстоянием Хемминга между кодовыми словами. Минимальное расстояние d_min определяет, сколько ошибок код может обнаружить и исправить. Чем больше d_min, тем выше помехоустойчивость.

Для кода (20, 2) количество избыточных бит равно 20 - 2 = 18, а для (20, 11) — 20 - 11 = 9. Большее количество избыточных бит позволяет создать большее минимальное расстояние между кодовыми словами.
Для кода (20, 2) минимальное расстояние d_min больше, чем для (20, 11). Это связано с тем, что при меньшем k (меньше информационных бит) можно создать кодовые слова, которые значительно отличаются друг от друга, увеличивая d_min.

Также важно учесть объём пространства кодовых слов. Для кода (20, 2) существует 2^2 = 4 кодовых слова, тогда как для (20, 11) — 2^11 = 2048. В большем пространстве вероятность того, что кодовые слова будут ближе друг к другу в метрике Хемминга, выше, что снижает d_min.

Нужно также учесть параметры генераторной матрицы. Для кода (20, 2) матрица позволяет создавать кодовые слова с большим расстоянием благодаря меньшей размерности информационных векторов. Возможно, структура матрицы A для (20, 2) оптимизирована для максимизации d_min.

Кроме того, при декодировании методом максимального правдоподобия вероятность правильного декодирования зависит от расстояния между принятым вектором и кодовыми словами. Большее d_min снижает вероятность того, что шум приведёт к ошибочному декодированию.

Таким образом, комбинация большего количества избыточных бит, меньшего пространства кодовых слов и оптимизированной структуры генераторной матрицы делает код (20, 2) более помехоустойчивым по сравнению с (20, 11).
