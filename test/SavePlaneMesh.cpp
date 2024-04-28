//
// Created by ChrisKim on 2023/6/8.
//

#include "SavePlaneMesh.h"


void save_plane_mesh(double x_start, double x_end, double x_step,
                     double y_start, double y_end, double y_step,
                     Network &network, const std::string &filename)
{
    int y_size = (int) ((y_end - y_start) / y_step);
    int x_size = (int) ((x_end - x_start) / x_step);
    Matrix mesh(y_size, x_size);
    std::vector<double> y_coords(y_size);
    std::vector<double> x_coords(x_size);
    std::cout << "mesh x from " << x_start << " to " << x_end << " with step " << x_step << std::endl;
    std::cout << "mesh y from " << y_start << " to " << y_end << " with step " << y_step << std::endl;
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            double y = y_start + i * y_step;
            double x = x_start + j * x_step;
            y_coords[i] = y;
            x_coords[j] = x;
            Matrix dot(2, 1);
            dot[0][0] = y;
            dot[1][0] = x;
            mesh[i][j] = network.predict(dot)[0][0];
            std::cout << "\rmesh[" << std::setw(5) << i << "][" << std::setw(5) << j << "] = "
                      << std::fixed << std::setprecision(9) << std::setw(16) << mesh[i][j] << std::flush;
        }
    }
    std::ofstream file(filename);
    for (int i = 0; i < x_size; i++)
    {
        file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << x_coords[i] << " ";
    }
    file << std::endl;
    for (int i = 0; i < y_size; i++)
    {
        file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << y_coords[i] << " ";
    }
    file << std::endl;
    for (int i = 0; i < mesh.height(); i++)
    {
        for (int j = 0; j < mesh.length(); j++)
        {
            file << std::fixed << std::setprecision(9) << std::left << std::setw(20) << mesh[i][j] << " ";
        }
        file << std::endl;
    }
    file.close();
}
