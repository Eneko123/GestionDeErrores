#pragma once
#include "Libro.h"

class Biblioteca
{
private:
    Libro* libros;
    int capacidad;
    int cantidad;

    void redimensionar();

public:
    Biblioteca();
    Biblioteca(int capacidadInicial);
    Biblioteca(const Biblioteca& other);
    Biblioteca& operator=(const Biblioteca& other);
    ~Biblioteca();

    void agregarLibro(const Libro& libro);
    bool eliminarLibroPorId(int id);
    Libro* buscarLibroPorId(int id);
    bool prestarLibro(int id);
    bool devolverLibro(int id);
    void mostrarLibros() const;
    void mostrarDisponibles() const;
    void mostrarPrestados() const;

    int getCantidad() const;
    int getCapacidad() const;
};