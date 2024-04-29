import numpy as np
from keras import datasets, utils
from tqdm import tqdm


def convert_mnist_to_txt(sample_rate: float = 1.0):
    (x_train, y_train), (x_test, y_test) = datasets.mnist.load_data()

    x_train = x_train[:int(x_train.shape[0] * sample_rate)]
    y_train = y_train[:int(y_train.shape[0] * sample_rate)]
    x_test = x_test[:int(x_test.shape[0] * sample_rate)]
    y_test = y_test[:int(y_test.shape[0] * sample_rate)]

    with open('../mnist_train.txt', 'w') as f:
        f.write(f"{x_train.shape[0]}\n")
        f.write("784 1\n")
        f.write("10 1\n")
        for i in tqdm(range(x_train.shape[0])):
            x = x_train[i].reshape(-1) / 255.0
            y = utils.to_categorical(y_train[i], 10)
            f.write(" ".join(map(str, x)) + " " + " ".join(map(str, y)) + "\n")

    with open('../mnist_test.txt', 'w') as f:
        f.write(f"{x_test.shape[0]}\n")
        f.write("784 1\n")
        f.write("10 1\n")
        for i in tqdm(range(x_test.shape[0])):
            x = x_test[i].reshape(-1) / 255.0
            y = utils.to_categorical(y_test[i], 10)
            f.write(" ".join(map(str, x)) + " " + " ".join(map(str, y)) + "\n")


if __name__ == '__main__':
    convert_mnist_to_txt(0.1)
