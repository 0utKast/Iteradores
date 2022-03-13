#if 0

#include <array>
#include <cstddef>
#include <iostream>

int main()
{
    // En C++17, el tipo de la variable datos es deducida a std::array:array<int, 7>
    std::array datos{ 0, 1, 2, 3, 4, 5, 6 };
    std::size_t tamanho{ std::size(datos) };

    // loop-while con índice explícito
    std::size_t indice{ 0 };
    while (indice != tamanho)
    {
        std::cout << datos[indice] << ' ';
        ++indice;
    }
    std::cout << '\n';

    // loop-for con índice explícito
    for (indice = 0; indice < tamanho; ++indice)
    {
        std::cout << datos[indice] << ' ';
    }
    std::cout << '\n';

    // loop-for con puntero (Nota: ptr no puede ser const, porque lo incrementamos)
    for (auto ptr{ &datos[0] }; ptr != (&datos[0] + tamanho); ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    //  loop for-each o basado en rangos
    for (int i : datos)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}




#include <array>
#include <iostream>

int main()
{
    std::array datos{ 0, 1, 2, 3, 4, 5, 6 };

    auto inicio{ &datos[0] };
    // observa que esto apunta a una posición posterior al último elemento
    auto final{ inicio + std::size(datos) };

    // for-loop con puntero
    for (auto ptr{ inicio }; ptr != final; ++ptr) // ++ para moverse al siguiente elemento
    {
        std::cout << *ptr << ' '; // Indirecciona para obtener el valor del elemento actual
    }
    std::cout << '\n';

    return 0;
}



#include <array>
#include <iostream>

int main()
{
    std::array datos{ 0.5, 1.3, 2.4 };

    auto inicio{ &datos[0] };
    // observa que esto apunta a una posición posterior al último elemento
    auto final{ inicio + std::size(datos) };

    // for-loop con puntero
    for (auto ptr{ inicio }; ptr != final; ++ptr) // ++ para moverse al siguiente elemento
    {
        std::cout << *ptr << ' '; // Indirecciona para obtener el valor del elemento actual
    }
    std::cout << '\n';

    return 0;
}



#include <array>
#include <iostream>

int main()
{
    std::array array{ 1, 2, 3 };

    // Le pedimos a nuestro array los puntos de inicio y final (a través de las funciones miembro begin y end).
    auto begin{ array.begin() };
    auto end{ array.end() };

    for (auto p{ begin }; p != end; ++p) // ++ para moverse al siguiente elemento.
    {
        std::cout << *p << ' '; // Indirecciona para obtener el valor del elemento actual.
    }
    std::cout << '\n';

    return 0;
}




#include <array>
#include <iostream>
#include <iterator> // Pasar std::begin y std::end

int main()
{
    std::array array{ 1, 2, 3 };

    // Usamos std::begin y std::end para obtener los puntos de inicio y final.
    auto begin{ std::begin(array) };
    auto end{ std::end(array) };

    for (auto p{ begin }; p != end; ++p) // ++ para moverse al siguiente elemento
    {
        std::cout << *p << ' '; // Indirecciona para obtener el valor del elemento actual
    }
    std::cout << '\n';

    return 0;
}





#include <array>
#include <iostream>

int main()
{
    std::array array{ 1, 2, 3 };

    // Esto hace exactamente lo mismo que el loop que usamos antes.
    for (int i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}

#endif








#include <iostream>
#include <vector>

int main()
{
    std::vector v{ 1, 2, 3, 4, 5, 6, 7 };

    auto apunte{ v.begin() };

    ++apunte; // se mueve al segundo elemento
    std::cout << *apunte << '\n'; // correcto: imprime 2

    v.erase(apunte); // borra el elemento sobre el que nos estamos iterando

    // erase() invalida los iteradores al elemento borrado (y a los elementos subsecuentes)
    // de modo que el iterador "it" está ahora invalidado

    ++apunte; // comportamiento indefinido
    std::cout << *apunte << '\n'; // comportamiento indefinido

    return 0;
}

#if 0
#endif