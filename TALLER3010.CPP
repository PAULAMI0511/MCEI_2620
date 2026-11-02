#include <CGAL/convex_hull_2.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <iterator>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;
using Point  = Kernel::Point_2;
using Delaunay = CGAL::Delaunay_triangulation_2<Kernel>;

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

        std::vector<Point> hull;
        CGAL::convex_hull_2(points.begin(), points.end(), std::back_inserter(hull));

    std::cout << "Vertices de la envolvente: " << hull.size() << '\n';

        std::cout << "\nVertices de la envolvente (x, y):\n";
    for (const auto& p : hull) {
        std::cout << p.x() << ' ' << p.y() << '\n';
    }

    Delaunay dt;
    dt.insert(points.begin(), points.end());

    std::size_t aristas = std::distance(dt.finite_edges_begin(), dt.finite_edges_end());

    std::cout << "\nVertices de Delaunay: " << dt.number_of_vertices() << '\n';
    std::cout << "Aristas de Delaunay: " << aristas << '\n';
    std::cout << "Caras (triangulos) de Delaunay: " << dt.number_of_faces() << '\n';

    std::cout << "Puntos leidos: " << points.size() << '\n';

        std::ofstream fpuntos("puntos.txt");
    for (const auto& p : points) {
        fpuntos << p.x() << ' ' << p.y() << '\n';
    }

    std::ofstream fhull("hull.txt");
    for (const auto& p : hull) {
        fhull << p.x() << ' ' << p.y() << '\n';
    }

    std::ofstream faristas("aristas.txt");
    for (auto e = dt.finite_edges_begin(); e != dt.finite_edges_end(); ++e) {
        auto cara = e->first;
        int i = e->second;
        Point p = cara->vertex((i + 1) % 3)->point();
        Point q = cara->vertex((i + 2) % 3)->point();
        faristas << p.x() << ' ' << p.y() << ' ' << q.x() << ' ' << q.y() << '\n';
    }

    return 0;
}
