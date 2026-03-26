#pragma once
#include <string>

class Libro
{
private:
    int id;
    std::string titulo;
    std::string autor;
    bool prestado;

public:
    Libro();
    Libro(int id, const std::string& titulo, const std::string& autor);

    int getId() const;
    std::string getTitulo() const;
    std::string getAutor() const;
    bool estaPrestado() const;

    void setTitulo(const std::string& titulo);
    void setAutor(const std::string& autor);

    bool prestar();
    bool devolver();

    void mostrar() const;
};