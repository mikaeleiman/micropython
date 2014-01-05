#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "nlr.h"
#include "misc.h"
#include "mpconfig.h"
#include "obj.h"
#include "runtime.h"

typedef struct _mp_obj_cell_t {
    mp_obj_base_t base;
    mp_obj_t obj;
} mp_obj_cell_t;

mp_obj_t mp_obj_cell_get(mp_obj_t self_in) {
    mp_obj_cell_t *self = self_in;
    return self->obj;
}

void mp_obj_cell_set(mp_obj_t self_in, mp_obj_t obj) {
    mp_obj_cell_t *self = self_in;
    self->obj = obj;
}

const mp_obj_type_t cell_type = {
    { &mp_const_type },
    "cell",
    NULL, // print
    NULL, // make_new
    NULL, // call_n
    NULL, // unary_op
    NULL, // binary_op
    NULL, // getiter
    NULL, // iternext
    {{NULL, NULL},}, // method list
};

mp_obj_t mp_obj_new_cell(mp_obj_t obj) {
    mp_obj_cell_t *o = m_new_obj(mp_obj_cell_t);
    o->base.type = &cell_type;
    o->obj = obj;
    return o;
}
