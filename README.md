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
./run.sh <sigma_start> <sigma_end> <sim_iterations | 0 - if force simulation> <optimized | (true | false)>
```

