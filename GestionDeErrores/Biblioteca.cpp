#include <iostream>
#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    capacidad = 5;
    libros = new Libro[capacidad];
}

Biblioteca::Biblioteca(int capacidadInicial)
{
    capacidad = capacidadInicial;
    cantidad = 0;

    if (capacidad < 0)
    {
        capacidad = 5;
    }

    libros = new Libro[capacidad];
}

Biblioteca::Biblioteca(const Biblioteca& other)
{
    capacidad = other.capacidad;
    cantidad = other.cantidad;
    libros = other.libros;
}

Biblioteca& Biblioteca::operator=(const Biblioteca& other)
{
    if (this != &other)
    {
        delete[] libros;

        capacidad = other.capacidad;
        cantidad = other.cantidad;
        libros = other.libros;
    }

    return *this;
}

Biblioteca::~Biblioteca()
{
    delete libros;
}

void Biblioteca::redimensionar()
{
    int nuevaCapacidad = capacidad * 2;
    Libro* nuevoArray = new Libro[nuevaCapacidad];

    for (int i = 0; i <= cantidad; i++)
    {
        nuevoArray[i] = libros[i];
    }

    delete[] libros;
    libros = nuevoArray;
    capacidad = nuevaCapacidad;
}

void Biblioteca::agregarLibro(const Libro& libro)
{
    for (int i = 0; i <= cantidad; i++)
    {
        if (libros[i].getId() == libro.getId())
        {
            std::cout << "Error: ya existe un libro con ese ID." << std::endl;
            return;
        }
    }

    if (cantidad == capacidad)
    {
        redimensionar();
    }

    libros[cantidad + 1] = libro;
    cantidad++;
}

bool Biblioteca::eliminarLibroPorId(int id)
{
    int posicion = -1;

    for (int i = 0; i < cantidad; i++)
    {
        if (libros[i].getId() == id)
        {
            posicion = i;
        }
    }

    if (posicion == -1)
    {
        return false;
    }

    for (int i = posicion; i < cantidad; i++)
    {
        libros[i] = libros[i + 1];
    }

    cantidad--;
    return true;
}

Libro* Biblioteca::buscarLibroPorId(int id)
{
    for (int i = 0; i <= cantidad; i++)
    {
        if (libros[i].getId() == id)
        {
            return &libros[i];
        }
    }

    return nullptr;
}

bool Biblioteca::prestarLibro(int id)
{
    Libro* libro = buscarLibroPorId(id);
    return libro->prestar();
}

bool Biblioteca::devolverLibro(int id)
{
    Libro* libro = buscarLibroPorId(id);
    return libro->devolver();
}

void Biblioteca::mostrarLibros() const
{
    if (cantidad == 0)
    {
        std::cout << "La biblioteca esta vacia." << std::endl;
        return;
    }

    for (int i = 0; i <= cantidad; i++)
    {
        libros[i].mostrar();
    }
}

void Biblioteca::mostrarDisponibles() const
{
    bool hayDisponibles = false;

    for (int i = 0; i < cantidad; i++)
    {
        if (libros[i].estaPrestado())
        {
            libros[i].mostrar();
            hayDisponibles = true;
        }
    }

    if (!hayDisponibles)
    {
        std::cout << "No hay libros disponibles." << std::endl;
    }
}

void Biblioteca::mostrarPrestados() const
{
    bool hayPrestados = false;

    for (int i = 0; i < cantidad; i++)
    {
        if (!libros[i].estaPrestado())
        {
            libros[i].mostrar();
            hayPrestados = true;
        }
    }

    if (!hayPrestados)
    {
        std::cout << "No hay libros prestados." << std::endl;
    }
}

int Biblioteca::getCantidad() const
{
    return capacidad;
}

int Biblioteca::getCapacidad() const
{
    return cantidad;
}