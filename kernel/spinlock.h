// Mutual exclusion lock.
#ifndef SPINLOCK_H
#define SPINLOCK_H
struct spinlock {
    uint locked;       // ¿Está bloqueado el spinlock?
    char *name;        // Nombre del lock
    struct cpu *cpu;   // CPU que tiene el lock
    uint pcs[10];      // Call stack para depuración
};


#endif // SPINLOCK_H