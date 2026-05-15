#include <stdio.h>
#define MAX_OYENTES 100
#define CANCIONES 10

/* FUNCION PARA LEER LOS VOTOS */
int leerVotos(int votos[MAX_OYENTES][3])
{
    int i = 0;

    printf("Ingrese los votos de los oyentes\n");
    printf("Para terminar escriba -1 en el primer numero\n\n");

    while (i < MAX_OYENTES)
    {
        printf("Oyente %d: ", i);

        scanf("%d", &votos[i][0]);

        if (votos[i][0] == -1)
        {
            break;
        }

        scanf("%d %d", &votos[i][1], &votos[i][2]);

        i++;
    }

    return i;
}

/* FUNCION PARA CALCULAR LOS VOTOS DE CADA CANCION */
void calcularVotos(int votos[MAX_OYENTES][3], int totalOyentes,
                    int puntosCanciones[CANCIONES])
{
    int i;

    for (i = 0; i < CANCIONES; i++)
    {
        puntosCanciones[i] = 0;
    }

    for (i = 0; i < totalOyentes; i++)
    {
        puntosCanciones[votos[i][0]] += 3;
        puntosCanciones[votos[i][1]] += 2;
        puntosCanciones[votos[i][2]] += 1;
    }
}

/* FUNCION PARA MOSTRAR LOS VOTOS */
void mostrarVotos(int puntosCanciones[CANCIONES])
{
    int i;

    printf("\nPuntos por cancion:\n");

    for (i = 0; i < CANCIONES; i++)
    {
        printf("Cancion %d: %d puntos\n", i, puntosCanciones[i]);
    }
}

/* FUNCION PARA OBTENER LAS DOS CANCIONES MAS VOTADAS */
void cancionesGanadoras(int puntosCanciones[CANCIONES],
                        int *primera, int *segunda)
{
    int i;

    *primera = 0;
    *segunda = 0;

    for (i = 0; i < CANCIONES; i++)
    {
        if (puntosCanciones[i] > puntosCanciones[*primera])
        {
            *segunda = *primera;
            *primera = i;
        }
        else if (i != *primera &&
                 puntosCanciones[i] > puntosCanciones[*segunda])
        {
            *segunda = i;
        }
    }
}

/* FUNCION PARA CALCULAR LOS PUNTOS DE LOS OYENTES */
void calcularPuntosOyentes(int votos[MAX_OYENTES][3],
                            int totalOyentes,
                            int primera,
                            int segunda,
                            int puntosOyentes[MAX_OYENTES])
{
    int i, j;

    for (i = 0; i < totalOyentes; i++)
    {
        puntosOyentes[i] = 0;

        int tienePrimera = 0;
        int tieneSegunda = 0;

        for (j = 0; j < 3; j++)
        {
            if (votos[i][j] == primera)
            {
                tienePrimera = 1;
            }

            if (votos[i][j] == segunda)
            {
                tieneSegunda = 1;
            }
        }

        if (tienePrimera)
        {
            puntosOyentes[i] += 30;
        }

        if (tieneSegunda)
        {
            puntosOyentes[i] += 20;
        }

        if (tienePrimera && tieneSegunda)
        {
            puntosOyentes[i] += 10;
        }
    }
}

/* FUNCION PARA OBTENER EL GANADOR */
int obtenerGanador(int puntosOyentes[MAX_OYENTES], int totalOyentes)
{
    int i;
    int ganador = 0;

    for (i = 1; i < totalOyentes; i++)
    {
        if (puntosOyentes[i] > puntosOyentes[ganador])
        {
            ganador = i;
        }
    }

    return ganador;
}

/* FUNCION PARA MOSTRAR LOS PUNTOS DE LOS OYENTES */
void mostrarPuntosOyentes(int puntosOyentes[MAX_OYENTES],
                            int totalOyentes)
{
    int i;

    printf("\nPuntos de los oyentes:\n");

    for (i = 0; i < totalOyentes; i++)
    {
        printf("Oyente %d: %d puntos\n", i, puntosOyentes[i]);
    }
}

int main()
{
    int votos[MAX_OYENTES][3];

    int puntosCanciones[CANCIONES];

    int puntosOyentes[MAX_OYENTES];

    int totalOyentes;

    int primera, segunda;

    int ganador;

    totalOyentes = leerVotos(votos);

    calcularVotos(votos, totalOyentes, puntosCanciones);

    mostrarVotos(puntosCanciones);

    cancionesGanadoras(puntosCanciones, &primera, &segunda);

    printf("\n1ra cancion mas votada: %d\n", primera);
    printf("2da cancion mas votada: %d\n", segunda);

    calcularPuntosOyentes(votos, totalOyentes,
                            primera, segunda,
                            puntosOyentes);

    mostrarPuntosOyentes(puntosOyentes, totalOyentes);

    ganador = obtenerGanador(puntosOyentes, totalOyentes);

    printf("\nGanador: Oyente numero %d\n", ganador);

    return 0;
}
