//====================================================================
// TP de IMPLEMENTACIÓN
// Sudoku
//====================================================================

#include <iostream>
#include "sudoku.h"

using namespace std;

void sudoku_print(Tablero t) {
	cout << "-------------------";
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << "|";
		for (int j = 0; j < 9; j++) {
			if (t[i][j] == 0) {
				cout << " ";
			} else {
				cout << t[i][j];
			}
			cout << "|";
		}
		cout << endl;
		if (i == 8) {
			cout << "+-+-+-+-+-+-+-+-+-+";
		} else {
			cout << "-------------------";
		}
		cout << endl;
	}
}

bool sudoku_esCeldaVacia(Tablero t, int f, int c) {
	return (t[f][c] == 0);
}

void sudoku_vaciarTablero(Tablero t) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			t[i][j] = 0;
		}
	}
}

int sudoku_nroDeCeldasVacias(Tablero t) {
	int cant_celdas_vacias = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (t[i][j] == 0) {
				cant_celdas_vacias++;
			}
		}
	}

	return cant_celdas_vacias;
}

int sudoku_primerCeldaVaciaFila(Tablero t) {
	int i;
	int j;
	int primera_fila_vacia = -1;

	i = 0;
	while (i < 9 && primera_fila_vacia == -1) {
		j = 0;
		while (j < 9 && primera_fila_vacia == -1) {
			if (t[i][j] == 0) {
				primera_fila_vacia = i;
			}
			j++;
		}
		i++;
	}

	return primera_fila_vacia;
}

int sudoku_primerCeldaVaciaColumna(Tablero t) {
	int i;
	int j;
	int primera_columna_vacia = -1;

	i = 0;
	while (i < 9 && primera_columna_vacia == -1) {
		j = 0;
		while (j < 9 && primera_columna_vacia == -1) {
			if (t[i][j] == 0) {
				primera_columna_vacia = j;
			}
			j++;
		}
		i++;
	}

	return primera_columna_vacia;
}

int sudoku_valorEnCelda(Tablero t, int f, int c) {
	return t[f][c];
}

void sudoku_llenarCelda(Tablero t, int f, int c, int v) {
	t[f][c] = v;
}

void sudoku_vaciarCelda(Tablero t, int f, int c) {
	t[f][c] = 0;
}

bool posicionesValidas(Tablero t) {
	int i;
	int j;
	bool en_rango = true;

	i = 0;
	while (i < 9 && en_rango) {
		j = 0;
		while (j < 9 && en_rango) {
			en_rango = (0 <= t[i][j] && t[i][j] <= 9);
			j++;
		}
		i++;
	}

	return en_rango;
}

bool sudoku_esTableroValido(Tablero t) {
	return posicionesValidas(t);
}

// Filas sin repetidos?
bool filasOk(Tablero t) {
	bool son_filas_ok = true;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if ((t[i][j] != 0) && (j != k) && (t[i][j] == t[i][k])) { // Celda no vacía .y. celda distinta de actual .y. celdas iguales
					son_filas_ok = false;
				}
			}
		}
	}

	return son_filas_ok;
}


// Columnas sin repetidos?
bool columnasOk(Tablero t) {
	bool son_columnas_ok = true;

	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			for (int k = 0; k < 9; k++) {
				if ((t[i][j] != 0) && (i != k) && (t[i][j] == t[k][j])) { // Celda no vacía .y. celda distinta de actual .y. celdas iguales
					son_columnas_ok = false;
				}
			}
		}
	}

	return son_columnas_ok;
}

int cantEnRegion(Tablero t, int x, int y, int value) {
	int cant = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <3 ; j++) {
			if (t[3*x+i][3*y+j] == value) {
				cant++;
			}
		}
	}

	return cant;
}

bool regionValida(Tablero t, int x, int y) {
	bool es_region_valida = true;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (t[3*x+i][3*y+j] != 0 && cantEnRegion(t, x, y, t[3*x+i][3*y+j]) > 1) {
				es_region_valida = false;
			}
		}
	}

	return es_region_valida;
}

bool regionesOk(Tablero t) {
	bool son_regiones_ok = true;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!regionValida (t, i, j)) {
				son_regiones_ok = false;
			}
		}
	}

	return son_regiones_ok;
}

bool sudoku_esTableroParcialmenteResuelto(Tablero t) {
	return sudoku_esTableroValido(t) && filasOk(t) && columnasOk(t) && regionesOk(t);
}

bool sudoku_esTableroTotalmenteResuelto(Tablero t) {
	return sudoku_esTableroParcialmenteResuelto(t) && (sudoku_nroDeCeldasVacias(t) == 0);
}

bool sudoku_esSubTablero(Tablero t0, Tablero t1) {
	bool es_subtablero = true;

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			if (t0[i][j] != 0 && t0[i][j] != t1[i][j]) {
				es_subtablero = false;
			}
		}
	}

	return es_subtablero;
}

bool sudoku_tieneSolucion(Tablero t, int &operaciones) {
    if (!sudoku_esTableroParcialmenteResuelto(t)) {
        return false;
    } else {
        if (sudoku_nroDeCeldasVacias(t) == 0) {
            return true;
        } else {

            int f = sudoku_primerCeldaVaciaFila(t);
            int c = sudoku_primerCeldaVaciaColumna(t);

            t[f][c]++;
            operaciones++;

            while (t[f][c] <= 9 && !sudoku_tieneSolucion(t, operaciones)) {
                t[f][c]++;
                operaciones++;
            }

            if (t[f][c] <= 9) {
                return true;
            } else {
                t[f][c] = 0;
                operaciones++;
                return false;
            }

        }
    }
}

bool estaEnRegion(Tablero t, int x, int y, int value) {
	bool existe = false;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (t[3*x+i][3*y+j] == value) {
				existe = true;
			}
		}
	}

	return existe;
}

bool esCandidatoEnRegion(Tablero t, int x, int y, int valor) {
	int nro_celdas_candidatas = 9;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (t[3*x+i][3*y+j] == 0) {
				t[3*x+i][3*y+j] = valor;
				if (!filasOk(t) || !columnasOk(t)) {
					nro_celdas_candidatas--;
				}
				t[3*x+i][3*y+j] = 0;
			} else {
				nro_celdas_candidatas--;
			}
		}
	}

	return (nro_celdas_candidatas != 0);
}

bool esCandidatoEnAlgunaRegion(Tablero t, int valor) {
	bool es_candidato = true;
	int region_x = 0;
	int region_y;

	while (region_x < 3 && es_candidato) {
		region_y = 0;
		while (region_y < 3 && es_candidato) {
			if (!estaEnRegion(t, region_x, region_y, valor)) {
				es_candidato = esCandidatoEnRegion(t, region_x, region_y, valor);
			}
			region_y++;
		}
		region_x++;
	}

	return es_candidato;
}

// Determina si existe un valor para el cual no es posible ubicarlo en alguna region
bool hayValorSinRegion(Tablero t) {
	int valor = 1;

	while (valor <= 9 && esCandidatoEnAlgunaRegion(t,valor)) {
		valor++;
	}

	return (valor <= 9);
}

void sudoku_copiarTablero (Tablero src, Tablero target) {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            target[i][j] = src[i][j];
        }
    }
}

bool sudoku_resolver(Tablero t) {
    if(hayValorSinRegion(t))
    	return false;

    int cant = 0;

    return sudoku_tieneSolucion(t, cant);
}

bool sudoku_resolver(Tablero t, int& count) {
	if(hayValorSinRegion(t))
		return false;

    return sudoku_tieneSolucion(t, count);
}
