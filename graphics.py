import pandas as pd
import matplotlib.pyplot as plt
import os

# Путь к директории, содержащей файлы
directory = 'build'

files = ['stats_v1_20x2.csv', 'stats_v1_20x4.csv', 'stats_v1_20x6.csv', 'stats_v1_20x8.csv']

# График 1: Зависимость ber от sigma
plt.figure(figsize=(10, 6))
for file in files:
    df = pd.read_csv(os.path.join(directory, file), sep=",")
    plt.plot(df['sigma'], df['ber'], label=file.split('.')[0])

plt.title('BER vs Sigma')
plt.xlabel('Sigma')
plt.ylabel('BER')
plt.legend()
plt.grid(True)
plt.show()

# График 2: Зависимость der от sigma
plt.figure(figsize=(10, 6))
for file in files:
    df = pd.read_csv(os.path.join(directory, file), sep=",")
    plt.plot(df['sigma'], df['der'], label=file.split('.')[0])

plt.title('DER (Decoding error rate) vs Sigma')
plt.xlabel('Sigma')
plt.ylabel('DER')
plt.legend()
plt.grid(True)
plt.show()

# График 3: Зависимость avgencodetime и avgdecodetime от b_size
plt.figure(figsize=(10, 6))
for file in files:
    df = pd.read_csv(os.path.join(directory, file), sep=",")
    plt.plot(df['b_size'], df['avgencodetime'], label=f'{file.split(".")[0]} - AVG encoding time', linewidth=3)
    plt.plot(df['b_size'], df['avgdecodetime'], label=f'{file.split(".")[0]} - AVG decoding time', linestyle='--', linewidth=3)

plt.title('Encoding and Decoding Time vs Block Size', fontsize=14)
plt.xlabel('Block Size', fontsize=12)
plt.ylabel('Time (seconds)', fontsize=12)
plt.legend(fontsize=10)
plt.grid(True, linestyle='--', alpha=0.6)
plt.show()
