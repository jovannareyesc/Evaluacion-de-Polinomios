#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>

#define ITER 1000
#define MAX_DEG 1000
#define MIN_DEG 10
#define AUMENTO 10

using namespace std;
using namespace std::chrono;

long double evaluarpolinomio_horner(long double polinomio[], int degree, int x);
long double evaluarpolinomio_estandar(long double polinomio[], int degree, int x);
int randomizer();
long double* crear_polinomio(int degree);

int matriz_tiempos_horner[ITER][MAX_DEG+1];
int matriz_tiempos_estandar[ITER][MAX_DEG+1];

int promedio_horner[MAX_DEG];
int promedio_estandar[MAX_DEG];

int main() {
    srand(time(NULL));

    long double y;

    int iter_aux = 0;
    long double tiempototal_horner = 0;
    long double tiempototal_estandar = 0;

    for (int j = MIN_DEG ; j <= MAX_DEG ; j+=AUMENTO) {
        for(int i = 0; i < ITER; i++) {

            // Se crea el polinomio a evaluar
            long double* polinomio = crear_polinomio(j);
            int x = randomizer();

            // Evaluación en Horner
            auto horner_start = chrono::high_resolution_clock::now();
            y = evaluarpolinomio_horner(polinomio, j, x);
            auto horner_end = chrono::high_resolution_clock::now();
            duration<double> horner_duration = horner_end - horner_start;
            matriz_tiempos_horner[i][j] = horner_duration.count() * 1000000000; // NOTA: CAMBIAR POR TIEMPO ESTANDAR
            tiempototal_horner += horner_duration.count() * 1000000000;



            // Evaluación en Estándar
            auto estandar_start = chrono::high_resolution_clock::now();
            y = evaluarpolinomio_estandar(polinomio, j, x);
            auto estandar_end = chrono::high_resolution_clock::now();
            duration<double> estandar_duration = estandar_end - estandar_start;
            matriz_tiempos_estandar[i][j] = estandar_duration.count() * 1000000000; // NOTA: CAMBIAR POR TIEMPO ESTANDAR
            tiempototal_estandar += estandar_duration.count() * 1000000000;

            delete[] polinomio;

        }

        promedio_horner[iter_aux] = tiempototal_horner / ITER;
        promedio_estandar[iter_aux] = tiempototal_estandar / ITER;

        tiempototal_estandar = 0;
        tiempototal_horner = 0;

        iter_aux++;
    }

    // Crear archivo de evaluación de Horner
    ofstream outFile_horner("evaluacion_horner.csv");
    if (!outFile_horner.is_open()) {
        cerr << "ERROR: Could not open file." << endl;
        return 1;
    }
    outFile_horner << ",";
    for (int i = MIN_DEG; i <= MAX_DEG; i+=AUMENTO) {
        outFile_horner << "Grado " << i << ",";
    }
    outFile_horner << endl;
    for (int i = 0; i < ITER; i++) {
        outFile_horner << i + 1 << ",";
        for (int j = MIN_DEG; j <= MAX_DEG; j+=AUMENTO) {
            outFile_horner << matriz_tiempos_horner[i][j] << ",";
        }
        outFile_horner << endl;
    }
    outFile_horner << "Promedio:,";
    for (int i = 0; i < MAX_DEG/AUMENTO; i++) {
        outFile_horner << promedio_horner[i] << ",";
    }
    outFile_horner.close();

    // Crear archivo de evaluación Estándar
    ofstream outFile_estandar("evaluacion_estandar.csv");
    if (!outFile_estandar.is_open()) {
        cerr << "ERROR: Could not open file." << endl;
        return 1;
    }
    outFile_estandar << ",";
    for (int i = MIN_DEG; i <= MAX_DEG; i+=AUMENTO) {
        outFile_estandar << "Grado " << i << ",";
    }
    outFile_estandar << endl;
    for (int i = 0; i < ITER; i++) {
        outFile_estandar << i + 1 << ",";
        for (int j = MIN_DEG; j <= MAX_DEG; j+=AUMENTO) {
            outFile_estandar << matriz_tiempos_estandar[i][j] << ",";
        }
        outFile_estandar << endl;
    }
    outFile_estandar << "Promedio:,";
    for (int i = 0; i < MAX_DEG/AUMENTO; i++) {
        outFile_estandar << promedio_estandar[i] << ",";
    }
    outFile_estandar.close();

    return 0;
}

long double evaluarpolinomio_horner(long double polinomio[], int degree, int x) {

    long double polyval = polinomio[degree];
    for (int i = 1 ; i <= degree ; i++) {
        polyval = polyval * x + polinomio[degree-i];
    }
    return polyval;
}

long double evaluarpolinomio_estandar(long double polinomio[], int degree, int x) {

    long double polyval = polinomio[0];
    long double term;

    for (int i = 1 ; i <= degree ; i++) {
        term = polinomio[i];
        for (int j = 1 ; j <= i ; j++) {
            term *= x;
        }
        polyval = polyval + term;
    }

    return polyval;
}

int randomizer() {
    return -10 + rand() % 21;
}

long double* crear_polinomio(int degree) {
    long double* polinomio = new long double[degree+1];

    for (int i = 0; i < degree+1; i++) {
        polinomio[i] = randomizer();
    }
    return polinomio;
}
