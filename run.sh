#!/bin/bash

if [ "$#" -ne 4 ]; then
    echo "Usage: $0 <sigma_start> <sigma_end> <sim_iterations | 0 for force simulation> <optimize mode = {1,2,3}>"
    exit 1
fi

SIGMA_START=$1
SIGMA_END=$2
SIM_ITERATIONS=$3
SIM_OPT_MODE=$4

mkdir -p build && cd build
cmake ..
make
if [ $? -ne 0 ]; then
    echo "Build failed"
    exit 1
fi

./pucch_f2 "$SIGMA_START" "$SIGMA_END" "$SIM_ITERATIONS" "$SIM_OPT_MODE"
if [ $? -ne 0 ]; then
    echo "Simulation failed"
    exit 1
fi
cd ..

if [ "$SIM_ITERATIONS" -gt 0 ]; then
    python3 -m venv .venv
    source .venv/bin/activate
    pip install --quiet pandas matplotlib
    python ./graphics.py
    deactivate
fi
