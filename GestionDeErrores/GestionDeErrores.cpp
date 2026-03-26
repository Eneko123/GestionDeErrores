#include <iostream>
#include <string>
#include "Biblioteca.h"

void mostrarMenu()
{
    std::cout << std::endl;
    std::cout << "----- BIBLIOTECA -----" << std::endl;
    std::cout << "1. Agregar libro" << std::endl;
    std::cout << "2. Eliminar libro" << std::endl;
    std::cout << "3. Buscar libro" << std::endl;
    std::cout << "4. Prestar libro" << std::endl;
    std::cout << "5. Devolver libro" << std::endl;
    std::cout << "6. Mostrar todos los libros" << std::endl;
    std::cout << "7. Mostrar disponibles" << std::endl;
    std::cout << "8. Mostrar prestados" << std::endl;
    std::cout << "9. Probar copia de biblioteca" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Opcion: "
}

int main()
{
    Biblioteca biblioteca(3);

    biblioteca.agregarLibro(Libro(1, "1984", "George Orwell"));
    biblioteca.agregarLibro(Libro(2, "El Hobbit", "J.R.R. Tolkien"));
    biblioteca.agregarLibro(Libro(3, "Dune", "Frank Herbert"));

    int opcion = -1;

    while (opcion != 0)
    {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int id;
            std::string titulo;
            std::string autor

            std::cout << "ID: ";
            std::cin >> id;

            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);

            std::cout << "Autor: ";
            std::getline(std::cin, autor);

            biblioteca.agregarLibro(Libro(id, titulo, autor));
            break;
        }
        case 2:
        {
            int id;
            std::cout << "ID del libro a eliminar: ";
            std::cin >> id;

            if (biblioteca.eliminarLibroPorId(id))
            {
                std::cout << "Libro eliminado correctamente." << std::endl;
            }
            else
            {
                std::cout << "No se encontro ningun libro con ese ID." << std::endl;
            }
            break;
        }
        case 3:
        {
            int id;
            std::cout << "ID del libro a buscar: ";
            std::cin >> id;

            Libro* libro = biblioteca.buscarLibroPorId(id);
            libro.mostrar();
            break;
        }
        case 4:
        {
            int id;
            std::cout << "ID del libro a prestar: ";
            std::cin >> id;

            if (biblioteca.prestarLibro())
            {
                std::cout << "Libro prestado correctamente." << std::endl;
            }
            else
            {
                std::cout << "No se pudo prestar el libro." << std::endl;
            }
            break;
        }
        case 5:
        {
            int id;
            std::cout << "ID del libro a devolver: ";
            std::cin >> id;

            if (biblioteca.devolverLibro(id))
            {
                std::cout << "Libro devuelto correctamente." << std::endl;
            }
            else
            {
                std::cout << "No se pudo devolver el libro." << std::endl;
            }
            break;
        }
        case 6:
            biblioteca.mostrarLibros();
            break;

        case 7:
            biblioteca.mostrarDisponibles();
            break;

        case 8:
            biblioteca.mostrarPrestados();
            break;

        case 9:
        {
            Biblioteca copia = biblioteca;

            std::cout << std::endl;
            std::cout << "Biblioteca original:" << std::endl;
            biblioteca.mostrarLibros();

            std::cout << std::endl;
            std::cout << "Copia de la biblioteca:" << std::endl;
            copia.mostrarLibros();

            std::cout << std::endl;
            std::cout << "Prestando un libro en la copia..." << std::endl;
            copia.prestarLibro(1);

            std::cout << std::endl;
            std::cout << "Original tras modificar la copia:" << std::endl;
            biblioteca.mostrarLibros();

            std::cout << std::endl;
            std::cout << "Copia tras modificarse:" << std::endl;
            copia.mostrarLibros();

            break;
        }
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            break;

        default:
            std::cout << "Opcion no valida." << std::endl;
        }
    }

    return 0;
}