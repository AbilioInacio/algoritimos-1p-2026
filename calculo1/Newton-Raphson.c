#include <stdio.h>
#include <math.h>

// Função f(x) = x³ - 4x - 2
double f(double x) {
    return x*x*x - 4*x - 2;
}

// Derivada f'(x) = 3x² - 4
double df(double x) {
    return 3*x*x - 4;
}

int main() {
    double x0, x1, erro;
    int iter = 0, maxIter = 100;

    printf("Digite o valor inicial x0: ");
    scanf("%lf", &x0);
    erro = 0.000001;

    do {
        x1 = x0 - f(x0) / df(x0);

        printf("Iteracao %d: x = %.10lf\n", iter + 1, x1);

        if (fabs(x1 - x0) < erro)
            break;

        x0 = x1;
        iter++;

    } while (iter < maxIter);

    printf("\nRaiz aproximada = %.10lf\n", x1);
    printf("Numero de iteracoes = %d\n", iter + 1);

    return 0;
}