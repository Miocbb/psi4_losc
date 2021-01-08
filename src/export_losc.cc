#include "losc.h"
#include "psi4/libmints/basisset.h"
#include "psi4/libmints/matrix.h"
#include "psi4/libmints/molecule.h"
#include "psi4/libmints/sobasis.h"
#include "psi4/libmints/vector.h"
#include "psi4/libmints/wavefunction.h"
#include "psi4/libfunctional/superfunctional.h"
#include "psi4/pybind11.h"

using namespace psi;
using namespace psi::losc;
using namespace pybind11::literals;
namespace py = pybind11;

void initialize() {}

/**
 * Export psi4 wavefunctions into this LOSC module.
 *
 * @note
 * This function is copied and pasted from `psi4/src/export_wavefunction.cc`.
 * We need this function because `class LOSC` is inherited from
 * `class psi::scf::HF`. To link `class LOSC` with python,
 * we need to link the base class of `psi::scf::HF` and
 * `psi::Wavefunction` as well. In addition, we don't want
 * to directly append the exporting code of LOSC into psi4 code.
 * So, I copy and paste these code in this LOSC module project.
void export_wavefunction(py::module &m);

void export_losc(py::module &losc)
{
    py::object class_HF = (py::object) py::module_::import("psi4.core").attr("HF");


    auto c_losc = py::class_<LOSC, std::shared_ptr<LOSC> >(
        losc, "LOSC", "The class for doing LOSC calculations.", class_HF);
    c_losc.def(
        py::init<SharedWavefunction, std::shared_ptr<SuperFunctional>>());
    c_losc.def("c1_deep_copy", &LOSC::c1_deep_copy,
               "Returns a new wavefunction with internal data converted to C_1 "
               "symmetry, using pre-c1-constructed BasisSet *basis*",
               "basis"_a);
    c_losc.def("mintshelper", &Wavefunction::mintshelper,
               "The MintsHelper object");
}
*/

PYBIND11_MODULE(losc, losc)
{
    losc.doc() = "C++ Innards of LOSC module for Psi4";
    losc.def("initialize", initialize, "Initialize the LOSC module.");

    py::object class_HF = (py::object) py::module_::import("psi4.core").attr("HF");
    py::object class_Wfn = (py::object) py::module_::import("psi4.core").attr("Wavefunction");
    py::object class_SupFunc = (py::object) py::module_::import("psi4.core").attr("SuperFunctional");


    auto class_losc = py::class_<LOSC, std::shared_ptr<LOSC> >(
        losc, "LOSC", "The class for doing LOSC calculations.", class_HF);
    class_losc.def(
        py::init<SharedWavefunction, std::shared_ptr<SuperFunctional>>());
    class_losc.def("c1_deep_copy", &LOSC::c1_deep_copy,
               "Returns a new wavefunction with internal data converted to C_1 "
               "symmetry, using pre-c1-constructed BasisSet *basis*",
               "basis"_a);
    class_losc.attr("mintshelper") = class_Wfn.attr("mintshelper");
}
