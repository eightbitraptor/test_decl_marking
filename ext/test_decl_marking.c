#include <ruby.h>

typedef struct simple_values {
    VALUE one;
    VALUE two;
    VALUE three;
    VALUE four;
    VALUE five;
    VALUE six;
    VALUE seven;
} values_t;

void foo_mark(void * obj) {
    values_t *data = (values_t *)obj;
    rb_gc_mark_movable(data->one);
    rb_gc_mark_movable(data->two);
    rb_gc_mark_movable(data->three);
    rb_gc_mark_movable(data->four);
    rb_gc_mark_movable(data->five);
    rb_gc_mark_movable(data->six);
    rb_gc_mark_movable(data->seven);
}

void foo_compact(void * obj) {
    values_t *data = (values_t *)obj;
    rb_gc_location(data->one);
    rb_gc_location(data->two);
    rb_gc_location(data->three);
    rb_gc_location(data->four);
    rb_gc_location(data->five);
    rb_gc_location(data->six);
    rb_gc_location(data->seven);
}

const size_t value_offsets[] = {
    RUBY_REF_EDGE(simple_values, one),
    RUBY_REF_EDGE(simple_values, one),
    RUBY_REF_EDGE(simple_values, one),
    RUBY_REF_EDGE(simple_values, one),
    RUBY_REF_EDGE(simple_values, one),
    RUBY_REF_EDGE(simple_values, one),
    RUBY_REF_EDGE(simple_values, one),
    RUBY_REF_END
};

const rb_data_type_t foo_callback_data_type = {
    .wrap_struct_name = "simple_values",
    .function = {
        .dmark = foo_mark,
        .dfree = NULL,
        .dsize = NULL,
        .dcompact = foo_compact
    },
    .flags = RUBY_TYPED_FREE_IMMEDIATELY
};

const rb_data_type_t foo_decl_data_type = {
    .wrap_struct_name = "simple_values",
    .function = {
        .dmark = NULL,
        .dfree = NULL,
        .dsize = NULL,
        .dcompact = NULL
    },
    .flags = RUBY_TYPED_FREE_IMMEDIATELY | RUBY_TYPED_DECL_MARKING,
    .data = (void *)value_offsets
};

VALUE
simple_marking_allocate(VALUE klass) {
    values_t *data;
    VALUE obj = TypedData_Make_Struct(klass, values_t, &foo_callback_data_type, data);

    VALUE string_one = rb_str_new_cstr("a");
    VALUE string_two = rb_str_new_cstr("b");
    VALUE string_three = rb_str_new_cstr("c");
    VALUE string_four = rb_str_new_cstr("d");
    VALUE string_five = rb_str_new_cstr("e");
    VALUE string_six = rb_str_new_cstr("f");
    VALUE string_seven = rb_str_new_cstr("g");

    data->one = string_one;
    data->two = string_two;
    data->three = string_three;
    data->four = string_four;
    data->five = string_five;
    data->six = string_six;
    data->seven = string_seven;

    return obj;
}

VALUE
decl_marking_allocate(VALUE klass) {
    values_t *data;
    VALUE obj = TypedData_Make_Struct(klass, values_t, &foo_decl_data_type, data);

    VALUE string_one = rb_str_new_cstr("a");
    VALUE string_two = rb_str_new_cstr("b");
    VALUE string_three = rb_str_new_cstr("c");
    VALUE string_four = rb_str_new_cstr("d");
    VALUE string_five = rb_str_new_cstr("e");
    VALUE string_six = rb_str_new_cstr("f");
    VALUE string_seven = rb_str_new_cstr("g");

    data->one = string_one;
    data->two = string_two;
    data->three = string_three;
    data->four = string_four;
    data->five = string_five;
    data->six = string_six;
    data->seven = string_seven;

    return obj;
}

void
Init_test_decl_marking(void)
{
    VALUE rb_cSimpleMarking = rb_define_class("SimpleMarking", rb_cObject);
    rb_define_alloc_func(rb_cSimpleMarking, simple_marking_allocate);

    VALUE rb_cDeclMarking = rb_define_class("DeclMarking", rb_cObject);
    rb_define_alloc_func(rb_cDeclMarking, decl_marking_allocate);
}
