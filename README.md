# Neural-Net-cpp

C++ 实现的 ~~极为残废的~~ 人工神经网络，仅用来练手，可能以后会完善，API 风格参考了 Tensorflow.

目前实现的功能：

- 神经网络层: 全连接层
- 激活函数: sigmoid, relu, tanh, linear
- 损失函数: mse
- 数据集: 二维二分类, 多项式拟合

目前存在的问题：

- 功能太少，只能实现简单的模型
- batch_size 功能还没有实现（参数暂时是无效的）

## 效果展示

以下是几个二维二分类问题的数据集与分类边界展示：

| 数据集                                                       | 分类边界                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![](https://assets.zouht.com/img/md/Neural-Net-cpp-cluster_data.png) | ![](https://assets.zouht.com/img/md/Neural-Net-cpp-cluster_mesh.png) |
| ![](https://assets.zouht.com/img/md/Neural-Net-cpp-window_data.png) | ![](https://assets.zouht.com/img/md/Neural-Net-cpp-window_mesh.png) |
| ![](https://assets.zouht.com/img/md/Neural-Net-cpp-circle_data.png) | ![](https://assets.zouht.com/img/md/Neural-Net-cpp-circle_mesh.png) |
| ![](https://assets.zouht.com/img/md/Neural-Net-cpp-whirlpool_data.png) | ![](https://assets.zouht.com/img/md/Neural-Net-cpp-whirlpool_mesh.png) |

## 使用方式

#### 建立模型

使用 Model 类建立模型，可直接向构造函数传入一个 `Vector<Layer>` 类型的参数，直接定义模型层。也可以不传参数，构造好 Model 实例后，调用实例的 `add_layer()` 方法给模型添加层。

模型层暂时只有 FC 全连接层一种，第一个参数为层内节点数，需传入一个整型，第二个参数为激活函数，需传入一个 `ActivationFunction` 对象的引用。

```cpp
#include "activation/Linear.h"
#include "activation/Sigmoid.h"
#include "ann/Layer.h"
#include "ann/Model.h"

Sigmoid sigmoid;
Linear linear;

Model model = Model({
    Layer(100, sigmoid),
    Layer(100, sigmoid),
    Layer(100, sigmoid),
    Layer(100, sigmoid),
});

model.add_layer(Layer(1, linear));
```

#### 编译模型

建立好模型后，调用实例的 `compile()` 方法编译模型，得到类型为 `CompiledModel` 的已编译模型。

`compile()` 方法第一个参数为整型输入层维度，第二个参数为浮点型学习率，~~第三个参数为整型 batch_size~~（暂未实现，该参数值无用），第四个参数为损失函数，需传入一个 `LossFunction` 对象的引用。

```cpp
#include "loss/MeanSquaredError.h"
#include "ann/CompiledModel.h"

CompiledModel cmodel = model.compile(2, 0.01, 1, mse);
```

#### 加载数据集

程序数据集的数据结构为 `std::vector<std::pair<Matrix, Matrix>>`，二元组第一位为数据，第二位为数据标签。

程序内置了两种数据集：平面二分类和多项式拟合。下面以加载平面二分类为例，使用 `load_plane` 加载平面二分类数据，第一个参数为数据量，第二个参数为数据形状，包含四种：

- cluster
- window
- circle
- whirlpool

具体形状可以看上文的图片。

```cpp
#include "test/LoadPlane.h"
#include "matrix/Matrix.h"

std::vector<std::pair<Matrix, Matrix>> train_data = load_plane(1000, "whirlpool");
std::vector<std::pair<Matrix, Matrix>> test_data = load_plane(100, "whirlpool");
```

#### 训练模型

调用已编译模型的 `fit()` 方法来进行模型训练，参数第一个为训练数据，需传入 `std::vector<std::pair<Matrix, Matrix>> &`，第二个为 `epochs` 数，代表训练次数。

```cpp
cmodel.fit(train_data, 100);
```

#### 测试模型

调用已编译模型的 `evaluate()` 方法来测试模型，参数为测试数据，需传入 `std::vector<std::pair<Matrix, Matrix>> &`.

```cpp
cmodel.evaluate(test_data);
```

#### 模型推理

若模型已经训练完成，可以调用模型的 `predict()` 方法进行推理，参数为输入的一个数据，需传入 `Matrix &`，输出为模型结果，类型为 `Matrix`.

```cpp
Matrix data(2, 1), result;
data[0][0] = 1.0;
data[1][0] = 2.0;

result = cmodel.predict(data);
```

------

#### 导入/导出数据集

若不想每次生成随机的数据，可导入/导出数据集至 txt 文件。

导入数据集使用 `load_testcase()`，参数为文件路径，返回值为读入的数据集 `std::vector<std::pair<Matrix, Matrix>> &`.

导出数据集使用 `save_testcase()`，第一个参数为文件路径，第二个参数为数据集 `std::vector<std::pair<Matrix, Matrix>> &`.

```cpp
#include "test/TestCaseFile.h"

std::vector<std::pair<Matrix, Matrix>> dataset = load_testcase("./train.txt");
save_testcase("./train.txt", dataset);
```

如果是二维二分类问题的数据集，导出数据集后，可以使用 `./test/PlotPlaneData.py` 可视化显示数据集（注意要将 `train.txt` 放置在同目录）

#### 导出二维二分类网格

如果要显示二维二分类问题的分类边界，需要先导出模型在一个网格中每个点的输出值。

使用 `save_plane_mesh()` 进行导出，参数分别为 x 起始，x 终止，x 步长，y 起始，y 终止，y 步长，已编译模型，保存文件路径。

```cpp
#include "test/SavePlaneMesh.h"

save_plane_mesh(-15, 15, 0.5,
                -15, 15, 0.5,
                cmodel, "./mesh.txt");
```

导出后，使用 `./test/PlotPlaneData.py` 可视化显示数据集（注意要将 `mesh.txt` 放置在同目录）。

