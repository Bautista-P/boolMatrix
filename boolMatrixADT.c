#include "boolMatrixADT.h"
#include "stdlib.h"


typedef struct col
{
    size_t col;
    struct col * tail;
}col;

typedef col * TCol;

typedef struct row
{
    TCol col;
    struct row * tail;
    size_t row ;

}row;

typedef row * TRow;

typedef struct boolMatrixCDT
{
    TRow first;
    boolean defaultValue;
}boolMatrixCDT;



/*
 * Crea una matriz con todos los elementos en falso
 */
boolMatrixADT newBoolMatrix(void)
{
    boolMatrixADT ans = calloc(1, sizeof(boolMatrixCDT));
    return ans;
}

TCol addCol(TCol l, size_t col)
{
    if(l == NULL || col < l->col)
    {
        TCol aux = malloc(sizeof(*aux));
        aux->col = col;
        aux->tail = l;
        return aux;
    }
    if(col == l->col)
        return l;
    if(col > l->col)
        l->tail = addCol(l, col);
    return l;
}

TRow addRow(TRow l ,size_t row,size_t col)
{
    if (l == NULL || row < l->row)
    {
       TRow aux = malloc(sizeof(*aux));
       TCol auxCol = malloc(sizeof(*auxCol));
       aux->row = row;
       auxCol->col = col;
       auxCol->tail = NULL;
       aux->col = auxCol;
       aux->tail = l;
       return aux;
    }
    if( l->row == row)
    {
        l->col = addCol(l->col, col);
        return l;
    }
    l->tail = addRow(l->tail, row, col);
    return l;
    
}

TCol deleteCol(TCol l, size_t col)
{
    if(l== NULL || col < l->col )
    {
        return l;
    }
    if(l->col == col)
    {
        TCol aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = deleteCol(l->tail, col);
    return l;
}


TRow deleteRow(TRow l ,size_t row,size_t col)
{
    if(l == NULL || row < l->row)
        return l;
    if(l->row == row)
    {
        l->col = deleteCol(l->col, col);
        if(l->col == NULL)
        {   
            TRow aux = l->tail;
            free(l);
            return aux;
        }
        return l;
    }
    l->tail = deleteRow(l->tail, row, col);
    return l;
}

/*
** Si @value es true entonces m[row][col] = value
** Si @value es false entonces borra m[row][col]
*/
void setValue(boolMatrixADT m, size_t row, size_t col, boolean value)
{
    if(value != m->defaultValue)
    {
        m->first = addRow(m->first, row, col);
    }
    else
    {
        m->first = deleteRow(m->first, row, col);
    }
}

boolean getCol(TCol l , size_t col)
{
    if(l == NULL || l->col > col)
        return FALSE;

    if(l->col == col)
        return TRUE;

    return getCol(l->tail, col);

}

boolean getRow(TRow l, size_t row, size_t col)
{
    if(l == NULL || row < l->row)

        return FALSE;

    if(l->row == row)
        return getCol(l->col, col);

    return getRow(l->tail, row, col);
}

/*
 * Retorna el valor almacenado en m[row][col]
 */
boolean getValue(const boolMatrixADT m, size_t row, size_t col)
{
    return m->defaultValue != getRow(m->first, row, col);
}

void freeCol(TCol l)
{
    if(l == NULL)
        return ;
    freeCol(l->tail);
    free(l);
}

void freeRow(TRow l)
{
    if(l == NULL)
        return ;
    freeRow(l->tail);
    freeCol(l->col);
    free(l);
}
/*
 * Libera toda la memoria reservada
 */
void freeBoolMatrix(boolMatrixADT m)
{
    freeRow(m->first);
    free(m);
}

/*
 * Todos los true pasan a ser false y los false pasan a ser ture
 */
void negate(boolMatrixADT m)
{
    m->defaultValue = !m->defaultValue;
}
