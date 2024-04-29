import numpy as np
import matplotlib.pyplot as plt

with open("../test.txt", "r") as f:
    num_samples = int(f.readline().strip())

    input_shape = tuple(map(int, f.readline().strip().split()))
    label_shape = tuple(map(int, f.readline().strip().split()))

    x = []
    y = []
    for i in range(num_samples):
        data = list(map(float, f.readline().strip().split()))
        x_vec = np.array(data[:2])
        y_vec = np.array(list(map(int, data[2:])))
        x.append(x_vec)
        y.append(y_vec)
    x = np.array(x)
    y = np.array(y)

with open("../mesh.txt", "r") as f:
    x_coord = list(map(float, f.readline().strip().split()))
    y_coord = list(map(float, f.readline().strip().split()))
    x_coord = np.array(x_coord)
    y_coord = np.array(y_coord)
    gx, gy = np.meshgrid(x_coord, y_coord)

    mesh = []
    for i in range(y_coord.shape[0]):
        data = list(map(lambda val: 1 if float(val) >= 0 else -1, f.readline().strip().split()))
        data = np.array(data)
        mesh.append(data)

    mesh = np.array(mesh)

plt.xlabel("x")
plt.ylabel("y")
plt.axis("equal")
plt.contourf(gy, gx, mesh, alpha=0.9)
plt.scatter(x[:, 0], x[:, 1], c=y)
plt.show()
