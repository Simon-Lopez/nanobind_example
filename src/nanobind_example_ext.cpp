#include <nanobind/nanobind.h>

namespace nb = nanobind;

using namespace nb::literals;

struct A{};

 bool f(const A &a) {
    return false;
}

NB_MODULE(nanobind_example_ext, m) {
    m.def("add", [](int a, int b) { return a + b; }, "a"_a, "b"_a);
    auto cls = nb::class_<A>(m, "A", "a dummy object");
    cls.def(nb::init<>());
    m.def("f", &f);
}
