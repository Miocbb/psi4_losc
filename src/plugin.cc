/*
 * @BEGIN LICENSE
 *
 * psi4_losc by Psi4 Developer, a plugin to:
 *
 * Psi4: an open-source quantum chemistry software package
 *
 * Copyright (c) 2007-2020 The Psi4 Developers.
 *
 * The copyrights for code used from other parties are included in
 * the corresponding files.
 *
 * This file is part of Psi4.
 *
 * Psi4 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * Psi4 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with Psi4; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * @END LICENSE
 */

/**
 * @brief
 * This file defines all the options for LOSC calculation.
 *
 * @detail
 * The LOSC library is named as `scf.so`, which serves as a plugin
 * for psi4 `SCF` module. All the options for LOSC starts with
 * a prefix `LOSC_` for psi4 `SCF` module.
 */

#include "scf.h"

#include "psi4/psi4-dec.h"
#include "psi4/liboptions/liboptions.h"
#include "psi4/libmints/matrix.h"
#include "psi4/libmints/vector.h"
#include "psi4/libpsi4util/PsiOutStream.h"

namespace psi{ namespace psi4_losc {

/**
 * This function is setting default global options.
 */
extern "C" PSI_API
int read_options(std::string name, Options &options)
{
    /*- LOSC implementation belongs to 'SCF' module in psi4. All
     * the options for LOSC has prefix "LOSC_".
     * The key is case insensitive. -*/
    if (name == "SCF"|| options.read_globals()) {
        /*- The amount of information printed
            to the output file -*/
        options.add_int("losc_print", 1);
        /*- How tightly to converge the localization cost function -*/
        options.add_double("losc_localize_tolerance", 1.0E-10);
    }

    return true;
}

/*- This is just a dummy function to make LOSC module compatible with
 * psi4 plugin functionality.
 * The name of this function should be the same the library's name.
 *
 * @note
 * The library's name is manually changed into `scf.so`. -*/
extern "C" PSI_API
SharedWavefunction scf(SharedWavefunction ref_wfn, Options &options)
{
}

}} // End Namespaces
