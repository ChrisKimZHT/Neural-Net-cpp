//
// Created by ChrisKim on 2023/6/8.
//

#include "SavePlaneMesh.h"
#include "TestCaseFile.h"


void save_plane_mesh(double x_start, double x_end, double x_step,
                     double y_start, double y_end, double y_step,
                     Network &network, const std::string &filename) {
    int y_size = ceil((y_end - y_start) / y_step);
    int x_size = ceil((x_end - x_start) / x_step);
    Matrix mesh(y_size, x_size);
    std::vector<double> y_coords(y_size);
    std::vector<double> x_coords(x_size);
    std::cout << "\n[Meshing Plane]" << std::endl;
    std::cout << "mesh x from " << x_start << " to " << x_end << " with step " << x_step << std::endl;
    std::cout << "mesh y from " << y_start << " to " << y_end << " with step " << y_step << std::endl;
    for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < x_size; j++) {
            double y = y_start + i * y_step;
            double x = x_start + j * x_step;
            y_coords[i] = y;
            x_coords[j] = x;
            Matrix dot(2, 1);
            dot[0][0] = y;
            dot[1][0] = x;
            mesh[i][j] = network.predict(dot)[0][0];
            std::cout << "\r" << std::fixed << std::setprecision(0) << std::right
                      << std::setw(3) << ceil(100.0 * (i * x_size + j) / (y_size * x_size)) << "% | "
                      << "mesh[" << std::setw(3) << i + 1 << "][" << std::setw(3) << j + 1 << "] = "
                      << std::fixed << std::setprecision(9) << std::setw(12) << mesh[i][j] << std::flush;
        }
    }
    std::ofstream file(filename);
    for (int i = 0; i < x_size; i++) {
        file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << x_coords[i] << " ";
    }
    file << std::endl;
    for (int i = 0; i < y_size; i++) {
        file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << y_coords[i] << " ";
    }
    file << std::endl;
    for (int i = 0; i < mesh.height(); i++) {
        for (int j = 0; j < mesh.length(); j++) {
            file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << mesh[i][j] << " ";
        }
        file << std::endl;
    }
    file.close();
}


void save_plane_mesh_with_data(const std::string &data_file, const std::string &mesh_file,
                               std::vector<Matrix> &x, std::vector<Matrix> &y, Network &network) {
    save_testcase(data_file, x, y);
    double x_min = 1e18, x_max = -1e18, y_min = 1e18, y_max = -1e18;
    for (auto &input: x) {
        y_min = std::min(y_min, input[0][0]);
        y_max = std::max(y_max, input[0][0]);
        x_min = std::min(x_min, input[1][0]);
        x_max = std::max(x_max, input[1][0]);
    }
    double x_padding = (x_max - x_min) * 0.05;
    double y_padding = (y_max - y_min) * 0.05;
    save_plane_mesh(x_min - x_padding, x_max + x_padding, (x_max - x_min + 2 * x_padding) / 100,
                    y_min - y_padding, y_max + y_padding, (y_max - y_min + 2 * y_padding) / 100,
                    network, mesh_file);
}