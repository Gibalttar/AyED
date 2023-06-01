#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double pi = 0.0;
    double denominator = 1.0;
    int sign = 1;
    int iterations = 0;

    /*se ejecuta indefinidamente hasta que se cumpla la condición de precisión de 6 decimales*/
    while (true) 
    {
        pi += sign / denominator;
        sign *= -1;
        denominator += 2.0;
        iterations++;

        /*Comprobar si los primeros 6 decimales son correctos*/
        if (iterations % 1000000 == 0) 
        {
            double calculated_pi = pi * 4;
            /*Cada millón de iteraciones, se calcula el valor de π multiplicando el resultado acumulado por 4*/
            double error = std::abs(calculated_pi - 3.141592);

            /*Se verifica si los primeros 6 decimales están dentro del rango de precisión requerido*/
            if (error <= 0.000001) {
                std::cout << "π calculado con precisión de 6 decimales después de " << iterations << " iteraciones." << std::endl;
                break;
            }
        }
    }

    return 0;
}