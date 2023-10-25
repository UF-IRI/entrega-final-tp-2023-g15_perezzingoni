#ifndef ARCHIVOS_H
#define ARCHIVOS_H

typedef struct {
    uint idCurso;
    time_t fechaInscripcion;
} Inscripcion;

typedef struct {
    uint idCliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
} Asistencia;

#endif // ARCHIVOS_H
