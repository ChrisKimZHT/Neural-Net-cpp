import numpy as np
import matplotlib.pyplot as plt

with open("train.txt", "r") as f:
    num_samples = int(f.readline().strip())

    input_shape = tuple(map(int, f.readline().strip().split()))
    label_shape = tuple(map(int, f.readline().strip().split()))

    x = []
    y = []
    for i in range(num_samples):
        data = list(map(float, f.readline().strip().split()))
        x_vec = np.array(data[:2])
        y_vec = np.array(data[2:])
        x.append(x_vec)
        y.append(y_vec)
    x = np.array(x)
    y = np.array(y)

plt.xlabel("x")
plt.ylabel("y")
plt.axis("equal")
plt.scatter(x[:, 0], x[:, 1], c=y)
plt.show()
