#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>

#include <string>

// YOUR INCLUDES
#include "sample.h"


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace nb = nanobind;
using namespace nb::literals;

NB_MODULE(_core, m) {
    m.doc() = R"pbdoc(
        nanobind example plugin
        -----------------------

        .. currentmodule:: {{cookiecutter.module_name}}

        .. autosummary::
           :toctree: _generate

           Sample
    )pbdoc";
    //
    nb::class_<Sample> PySample(m, "Sample");

    PySample.def(nb::init<int>(), nb::arg("var"))
        .def_static("create_sample", &Sample::create_sample, nb::arg("sample"))
        .def_prop("var", &Sample::get_var, &Sample::set_var)
        .def("__str__", &Sample::str)
        .def("__repr__", [](const Sample& ins) {
            return "<Sample :'" + ins.str() + "'>";
        });

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
