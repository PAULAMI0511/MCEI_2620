#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;
using Point  = Kernel::Point_2;

int main()
{
    std::ifstream archivo("/home/paula/MCEI_2620/ubicaciones_100_sensores_xy.csv");
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo\n";
        return 1;
    }

    std::string linea;
    std::getline(archivo, linea);   // descarta el encabezado

    std::vector<Point> points;

    // Lee cada sensor: S001,63.943,2.501
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string id, sx, sy;

        std::getline(ss, id, ',');   // S001 (no se usa)
        std::getline(ss, sx, ',');   // "63.943" como texto
        std::getline(ss, sy, ',');   // "2.501" como texto

        double x = std::stod(sx);    // texto -> número
        double y = std::stod(sy);

        points.emplace_back(x, y);   // agrega el punto a la lista
    }

    std::cout << "Puntos leidos: " << points.size() << '\n';
    return 0;
}