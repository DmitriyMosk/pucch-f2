import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import os
import argparse

# Настройка аргументов командной строки
parser = argparse.ArgumentParser(description="Генерация графиков.")
parser.add_argument('version', type=int, choices=[1, 2, 3], help="Число версии (1, 2 или 3), которое будет использовано в имени файлов")
args = parser.parse_args()

# Путь к директории, содержащей файлы
directory = 'build'

# Заменяем номер версии в именах файлов на аргумент
files = [f'stats_v{args.version}_20x2.csv', 
         f'stats_v{args.version}_20x4.csv', 
         f'stats_v{args.version}_20x6.csv', 
         f'stats_v{args.version}_20x8.csv', 
         f'stats_v{args.version}_20x11.csv']

# Загрузка данных в NumPy
data = {}
for file in files:
    df = pd.read_csv(os.path.join(directory, file), sep=",")
    sigma = df['sigma'].to_numpy()
    ber = df['ber'].to_numpy()
    der = df['der'].to_numpy()
    b_size = df['b_size'].to_numpy()
    avg_enc_time = df['avgencodetime'].to_numpy()
    avg_dec_time = df['avgdecodetime'].to_numpy()
    
    data[file] = {
        'sigma': sigma,
        'ber': ber,
        'der': der,
        'b_size': b_size,
        'avgencodetime': avg_enc_time,
        'avgdecodetime': avg_dec_time
    }

# Функция для полиномиальной аппроксимации
def polynomial_fit(x, y, degree=2):
    coefficients = np.polyfit(x, y, degree)
    polynomial = np.poly1d(coefficients)
    return polynomial

# График 1: Зависимость ber от sigma
plt.figure(figsize=(10, 6))
for file in files:
    sigma = data[file]['sigma']
    ber = data[file]['ber']
    
    # Полиномиальная аппроксимация
    poly = polynomial_fit(sigma, ber, degree=2)
    new_sigma = np.arange(sigma.min(), sigma.max(), 0.2)
    fitted_ber = poly(new_sigma)

    plt.plot(new_sigma, fitted_ber, label=file.split('.')[0])

plt.title('BER vs Sigma (Полиномиальная аппроксимация)')
plt.xlabel('Sigma')
plt.ylabel('BER')
plt.legend()
plt.grid(True)
plt.show()

# График 2: Зависимость der от sigma
plt.figure(figsize=(10, 6))
for file in files:
    sigma = data[file]['sigma']
    der = data[file]['der']
    
    # Полиномиальная аппроксимация
    poly = polynomial_fit(sigma, der, degree=2)
    new_sigma = np.arange(sigma.min(), sigma.max(), 0.2)
    fitted_der = poly(new_sigma)

    plt.plot(new_sigma, fitted_der, label=file.split('.')[0])

plt.title('DER (Decoding error rate) vs Sigma (Полиномиальная аппроксимация)')
plt.xlabel('Sigma')
plt.ylabel('DER')
plt.legend()
plt.grid(True)
plt.show()

# График 3: Зависимость avgencodetime и avgdecodetime от b_size в виде столбиков
plt.figure(figsize=(10, 6))
width = 0.35  # Ширина столбиков
x = np.arange(len(files))  # Позиции для столбиков

for i, file in enumerate(files):
    avg_enc_time = data[file]['avgencodetime']
    avg_dec_time = data[file]['avgdecodetime']
    # Используем средние значения для столбиков
    avg_enc = np.mean(avg_enc_time)
    avg_dec = np.mean(avg_dec_time)

    plt.bar(x[i] - width/2, avg_enc, width, label=f'{file.split(".")[0]} - AVG encoding time', color='b')
    plt.bar(x[i] + width/2, avg_dec, width, label=f'{file.split(".")[0]} - AVG decoding time', color='orange')

plt.title('Average Encoding and Decoding Time vs File', fontsize=14)
plt.xlabel('Files', fontsize=12)
plt.ylabel('Time (microseconds)', fontsize=12)  # Изменено на микросекунды
plt.xticks(x, [file.split('.')[0] for file in files])
plt.legend(fontsize=10)
plt.grid(True, linestyle='--', alpha=0.6)
plt.show()
