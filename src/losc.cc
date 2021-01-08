#include "losc.h"
#include "psi4/libscf_solver/hf.h"

namespace psi {
namespace losc {

LOSC::LOSC(SharedWavefunction dfa_wfn, std::shared_ptr<SuperFunctional> func)
    : psi::scf::HF(dfa_wfn, func, dfa_wfn->options(), PSIO::shared_object())
{
}

LOSC::LOSC(SharedWavefunction dfa_wfn, std::shared_ptr<SuperFunctional> func,
           Options &options, std::shared_ptr<PSIO> psio)
    : psi::scf::HF(dfa_wfn, func, options, PSIO::shared_object())
{
}

SharedLOSC LOSC::c1_deep_copy(std::shared_ptr<BasisSet> basis)
{
    throw PSIEXCEPTION("Sorry, LOSC::c1_deep_copy() is not implemented.");
}

} // namespace losc
} // namespace psi
