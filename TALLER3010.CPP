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

    // AQUI va tu ciclo para leer cada linea

    std::cout << "Puntos leidos: " << points.size() << '\n';
    return 0;
}

    // AQUI va luego el ciclo que lee cada sensor
while (std::getline(archivo, linea)) {
    std::stringstream ss(linea);
    std::string id, sx, sy;
    std::getline(ss, id, ',');
    std::getline(ss, sx, ___);
    std::getline(ss, sy, ___);

    double x = std::stod(___);
    double y = std::stod(___);

    points.emplace_back(___, ___);
    }
