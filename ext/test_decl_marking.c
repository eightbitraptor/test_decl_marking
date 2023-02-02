#include <ruby.h>

typedef struct simple_values {
    VALUE one;
    VALUE two;
    VALUE three;
    VALUE four;
    VALUE five;
    VALUE six;
    VALUE seven;
    VALUE eight;
    VALUE nine;
    VALUE ten;
    VALUE eleven;
    VALUE twelve;
    VALUE thirteen;
    VALUE fourteen;
    VALUE fifteen;
    VALUE sixteen;
    VALUE seventeen;
    VALUE eighteen;
    VALUE nineteen;
    VALUE twenty;
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
    rb_gc_mark_movable(data->eight);
    rb_gc_mark_movable(data->nine);
    rb_gc_mark_movable(data->ten);
    rb_gc_mark_movable(data->eleven);
    rb_gc_mark_movable(data->twelve);
    rb_gc_mark_movable(data->thirteen);
    rb_gc_mark_movable(data->fourteen);
    rb_gc_mark_movable(data->fifteen);
    rb_gc_mark_movable(data->sixteen);
    rb_gc_mark_movable(data->seventeen);
    rb_gc_mark_movable(data->eighteen);
    rb_gc_mark_movable(data->nineteen);
    rb_gc_mark_movable(data->twenty);
}

void foo_compact(void * obj) {
    values_t *data = (values_t *)obj;
    data->one = rb_gc_location(data->one);
    data->two = rb_gc_location(data->two);
    data->three = rb_gc_location(data->three);
    data->four = rb_gc_location(data->four);
    data->five = rb_gc_location(data->five);
    data->six = rb_gc_location(data->six);
    data->seven = rb_gc_location(data->seven);
    data->eight = rb_gc_location(data->eight);
    data->nine = rb_gc_location(data->nine);
    data->ten = rb_gc_location(data->ten);
    data->eleven = rb_gc_location(data->eleven);
    data->twelve = rb_gc_location(data->twelve);
    data->thirteen = rb_gc_location(data->thirteen);
    data->fourteen = rb_gc_location(data->fourteen);
    data->fifteen = rb_gc_location(data->fifteen);
    data->sixteen = rb_gc_location(data->sixteen);
    data->seventeen = rb_gc_location(data->seventeen);
    data->eighteen = rb_gc_location(data->eighteen);
    data->nineteen = rb_gc_location(data->nineteen);
    data->twenty = rb_gc_location(data->twenty);
}

const size_t value_offsets[] = {
    RUBY_REF_EDGE(simple_values, one),
    RUBY_REF_EDGE(simple_values, two),
    RUBY_REF_EDGE(simple_values, three),
    RUBY_REF_EDGE(simple_values, four),
    RUBY_REF_EDGE(simple_values, five),
    RUBY_REF_EDGE(simple_values, six),
    RUBY_REF_EDGE(simple_values, seven),
    RUBY_REF_EDGE(simple_values, eight),
    RUBY_REF_EDGE(simple_values, nine),
    RUBY_REF_EDGE(simple_values, ten),
    RUBY_REF_EDGE(simple_values, eleven),
    RUBY_REF_EDGE(simple_values, twelve),
    RUBY_REF_EDGE(simple_values, thirteen),
    RUBY_REF_EDGE(simple_values, fourteen),
    RUBY_REF_EDGE(simple_values, fifteen),
    RUBY_REF_EDGE(simple_values, sixteen),
    RUBY_REF_EDGE(simple_values, seventeen),
    RUBY_REF_EDGE(simple_values, eighteen),
    RUBY_REF_EDGE(simple_values, nineteen),
    RUBY_REF_EDGE(simple_values, twenty),
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

void
assign_values(values_t *data)
{
    VALUE string_one = rb_str_new_cstr("a");
    VALUE string_two = rb_str_new_cstr("b");
    VALUE string_three = rb_str_new_cstr("c");
    VALUE string_four = rb_str_new_cstr("d");
    VALUE string_five = rb_str_new_cstr("e");
    VALUE string_six = rb_str_new_cstr("f");
    VALUE string_seven = rb_str_new_cstr("g");
    VALUE string_eight = rb_str_new_cstr("a");
    VALUE string_nine = rb_str_new_cstr("b");
    VALUE string_ten = rb_str_new_cstr("c");
    VALUE string_eleven = rb_str_new_cstr("d");
    VALUE string_twelve = rb_str_new_cstr("e");
    VALUE string_thirteen = rb_str_new_cstr("f");
    VALUE string_fourteen = rb_str_new_cstr("g");
    VALUE string_fifteen = rb_str_new_cstr("a");
    VALUE string_sixteen = rb_str_new_cstr("b");
    VALUE string_seventeen = rb_str_new_cstr("c");
    VALUE string_eighteen = rb_str_new_cstr("d");
    VALUE string_nineteen = rb_str_new_cstr("e");
    VALUE string_twenty = rb_str_new_cstr("f");

    data->one = string_one;
    data->two = string_two;
    data->three = string_three;
    data->four = string_four;
    data->five = string_five;
    data->six = string_six;
    data->seven = string_seven;
    data->eight = string_eight;
    data->nine = string_nine;
    data->ten = string_ten;
    data->eleven = string_eleven;
    data->twelve = string_twelve;
    data->thirteen = string_thirteen;
    data->fourteen = string_fourteen;
    data->fifteen = string_fifteen;
    data->sixteen = string_sixteen;
    data->seventeen = string_seventeen;
    data->eighteen = string_eighteen;
    data->nineteen = string_nineteen;
    data->twenty = string_twenty;
}

VALUE
simple_marking_allocate(VALUE klass) {
    values_t *data;
    VALUE obj = TypedData_Make_Struct(klass, values_t, &foo_callback_data_type, data);

    assign_values(data);

    return obj;
}

VALUE
decl_marking_allocate(VALUE klass) {
    values_t *data;
    VALUE obj = TypedData_Make_Struct(klass, values_t, &foo_decl_data_type, data);

    assign_values(data);

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
