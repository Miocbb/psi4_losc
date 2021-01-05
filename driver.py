#
# @BEGIN LICENSE
#
# psi4_losc by Psi4 Developer, a plugin to:
#
# Psi4: an open-source quantum chemistry software package
#
# Copyright (c) 2007-2020 The Psi4 Developers.
#
# The copyrights for code used from other parties are included in
# the corresponding files.
#
# This file is part of Psi4.
#
# Psi4 is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, version 3.
#
# Psi4 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License along
# with Psi4; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
# @END LICENSE
#

import psi4
import psi4.core as psi4_core
import psi4.driver.p4util.exceptions as psi4_exception
from psi4.driver.procrouting import proc as psi4_proc
from psi4.driver.procrouting.dft.dft_builder import functionals


def run_losc_dft(name, **kwargs):
    r"""Function encoding sequence of PSI module and plugin calls so that
    psi4_losc can be called via :py:func:`~driver.energy`. For scf plugins.

    >>> energy('losc b3lyp')

    """
    psi4_core.print_out("\nHello from run_losc_dft()!\n")
    if len(name.split()) != 2:
        raise psi4_exception.ParsingError(
            f'Invalid name of LOSC: "{name}" is not regonized as a LOSC-DFT calculation.')
    dfa_name = name.split()[1]

    # do LOSC-DFA calculations.
    # TODO: we need to modify the `run_scf()` in the python layer to integrate
    # the LOSC into DFT calculations.
    return psi4_proc.run_scf(dfa_name, **kwargs)

def exampleFN():
    # Your Python code goes here
    pass
