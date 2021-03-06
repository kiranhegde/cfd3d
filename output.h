/*  An open source Navier-Stokes CFD solver.
    Copyright (C) 2015  Michael Nucci (michael.nucci@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef OUTPUTHEADERDEF             //only if the macro OUTPUTHEADERDEF is not defined execute these lines of code
#define OUTPUTHEADERDEF             //define the macro

/* This header contains the function declarations for file output.

It contains function headers to write out the grid at the cell centers in Plot3D format, as well as the Plot3D function files.
It also writes out a master file in Ensight format to name the Plot3D functions.  */

#include <vector>  //vector
#include <string>  //string
#include "vector3d.h" //vector3d
#include "tensor.h" //tensor
#include "plot3d.h" //plot3d
#include "eos.h"
#include "primVars.h" //primVars
#include "procBlock.h" //procBlock
#include "inviscidFlux.h" //inviscidFlux
#include "input.h" //inputVars
#include "boundaryConditions.h" //decomposition
#include <fstream>
#include <iostream>

using std::vector;
using std::string;
using std::ios;
using std::ofstream;
using std::cout;
using std::endl;
using std::cerr;

//function definitions
void WriteCellCenter(const string&, const vector<procBlock> &, const decomposition&);
void WriteCellCenterGhost(const string&, const vector<procBlock> &);
void WriteFun(const string&, const vector<procBlock> &, const idealGas&, const int&, const double&, const double&, const double&, const decomposition&);
void WriteRes(const string&, const int&, const int&);

void WriteResiduals(const input&, genArray&, genArray&, const resid&, const double&, const int&, const int&);

vector<procBlock> Recombine( const vector<procBlock>&, const decomposition& );
int SplitBlockNumber( const vector<procBlock>&, const decomposition&, const int&, const int&, const int&, const int& );

#endif
