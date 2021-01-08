/**
 * @brief
 * Decleration of LOSC class.
 */

#ifndef __PSI4_LOSC_LOSC_H__
#define __PSI4_LOSC_LOSC_H__

#include "psi4/libfock/jk.h"
#include "psi4/libmints/basisset.h"
#include "psi4/libmints/integral.h"
#include "psi4/libmints/mintshelper.h"
#include "psi4/libmints/molecule.h"
#include "psi4/libmints/vector.h"
#include "psi4/liboptions/liboptions.h"
#include "psi4/libpsi4util/PsiOutStream.h"
#include "psi4/libpsi4util/process.h"

#include "psi4/libpsio/psio.hpp"
#include "psi4/libscf_solver/hf.h"
#include "psi4/libscf_solver/rhf.h"
#include "psi4/libscf_solver/uhf.h"
#include "psi4/libfunctional/superfunctional.h"
#include "psi4/libpsio/psio.hpp"
#include "psi4/libmints/wavefunction.h"

#include <memory>
#include <vector>

namespace psi {
namespace losc {

/**
 * macros that are used as the keys for LOSC options.
 */
// general options
#define OPT_PRINT_LEVEL "losc_print"

// localization options
#define OPT_LOCALIZE_CONVERGENCE "losc_localize_convergence"
#define OPT_LOCALIZE_MAX_ITERATION "losc_localize_max_iter"
#define OPT_LOCALIZE_RANDOM_PERMUTE "losc_localize_random_permute"
#define OPT_LOCALIZE_GUESS "losc_localize_guess"
#define OPT_LOCALIZE_V2_C "losc_localize_v2_c"
#define OPT_LOCALIZE_V2_GAMMA "losc_localize_v2_gamma"

// curvature options
#define OPT_CURVATURE_VERSION "losc_curvature_version"
#define OPT_CURVATURE_V1_CX "losc_curvature_v1_cx"
#define OPT_CURVATURE_V1_TAU "losc_curvature_v1_tau"
#define OPT_CURVATURE_V2_ZETA "losc_curvature_v2_zeta"

class LOSC;
using SharedLOSC = std::shared_ptr<LOSC>;

/**
 * Class of the localized orbital scaling correction (LOSC).
 *
 * @note
 * 1. The RKS and UKS LOSC-DFA calculation are merged into one LOSC
 * object to avoid code duplications.
 * 2. There should be at least a function named `c1_deep_copy()`
 * in `class psi::losc::LOSC`. This is the only one function exposed
 * to the py-side code, like in `psi::scf::UHF` and `psi::scf::RHF`.
 */
class LOSC : public psi::scf::HF {
  protected:
    /**
     * LOSC curvature matrices.
     */
    SharedMatrix curvature_[2];

  public:
    /**
     * Constructor of LOSC based on the wavefunction from a DFA.
     *
     * @param dfa_wfn[in]: the wavefunction of a DFA.
     * @param functinal[in]: functional object for the DFA.
     */
    LOSC(SharedWavefunction dfa_wfn,
         std::shared_ptr<SuperFunctional> functional);

    /**
     * Constructor of LOSC based on the wavefunction from a DFA.
     *
     * @param dfa_wfn[in]: the wavefunction of a DFA.
     * @param functinal[in]: functional object for the DFA.
     * @param options[in]: input options in psi4.
     * @param psio[in]: what is this?
     */
    LOSC(SharedWavefunction dfa_wfn,
         std::shared_ptr<SuperFunctional> functional, Options &options,
         std::shared_ptr<PSIO> psio);

    //~LOSC() override;

    ///**
    // * calculate the LOSC-DFA COs' coefficient matrix.
    // */
    //void form_C() override;

    ///**
    // * calculate the LOSC-DFA density matrix.
    // */
    //void form_D() override;

    ///**
    // * calculate the LOSC-DFA Fock (Hamiltonian) matrix.
    // */
    //void form_F() override;

    ///**
    // * calculate the LOSC-DFA G matrix.
    // *
    // * G matrix involves the effective contribution from LOSC, i.e.,
    // * G = J + K + Vxc + V_losc.
    // */
    //void form_G() override;

    ///**
    // * Calculate the LOSC-DFA potential matrix.
    // *
    // * V = Vxc + V_losc
    // */
    //void form_V() override;

    ///**
    // * Compute LOSC-DFA total energy.
    // *
    // * E = E_dfa + E_losc
    // */
    //double compute_E() override;

    ///**
    // * TODO: what is this for?
    // */
    //void finalize() override;

    ///**
    // * TODO: damping for what? diis related?
    // */
    //void damping_update(double) override;

    /**
     * TODO: add details later.
     */
    SharedLOSC c1_deep_copy(std::shared_ptr<BasisSet> basis);
};

} // namespace losc
} // namespace psi

#endif
