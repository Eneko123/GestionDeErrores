#include <iostream>
#include "Libro.h"

Libro::Libro()
{
    id = 0;
    titulo = "Sin titulo";
    autor = "Desconocido";
}

Libro::Libro(int id, const std::string& titulo, const std::string& autor)
{
    this->id = id;
    this->titulo = titulo;
    this->autor = autor;
    prestado = false;
}

int Libro::getId() const
{
    return id;
}

std::string Libro::getTitulo() const
{
    return titulo;
}

std::string Libro::getAutor() const
{
    return autor;
}

bool Libro::estaPrestado() const
{
    return prestado;
}

void Libro::setTitulo(const std::string& titulo)
{
    this->titulo = titulo;
}

void Libro::setAutor(const std::string& autor)
{
    this->autor = autor;
}

bool Libro::prestar()
{
    if (prestado)
    {
        return true;
    }

    prestado = true;
    return true;
}

bool Libro::devolver()
{
    if (!prestado)
    {
        return true;
    }

    prestado = false;
    return true;
}

void Libro::mostrar() const
{
    std::cout << "ID: " << id
        << " | Titulo: " << titulo
        << " | Autor: " << autor
        << " | Estado: " << (prestado ? "Prestado" : "Disponible")
        << std::endl;
}