/* CirKit: A circuit toolkit
 * Copyright (C) 2009-2015  University of Bremen
 * Copyright (C) 2015-2017  EPFL
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "lhrs_params.hpp"

namespace cirkit
{

/******************************************************************************
 * Types                                                                      *
 ******************************************************************************/

/******************************************************************************
 * Private functions                                                          *
 ******************************************************************************/

/******************************************************************************
 * Public functions                                                           *
 ******************************************************************************/

std::istream& operator>>( std::istream& in, lhrs_mapping_strategy& mapping_strategy )
{
  std::string token;
  in >> token;
  if ( token == "direct" || token == "0" )
  {
    mapping_strategy = lhrs_mapping_strategy::direct;
  }
  else if ( token == "min_db" || token == "1" )
  {
    mapping_strategy = lhrs_mapping_strategy::lut_based_min_db;
  }
  else if ( token == "best_fit" || token == "2" )
  {
    mapping_strategy = lhrs_mapping_strategy::lut_based_best_fit;
  }
  else if ( token == "pick_best" || token == "3" )
  {
    mapping_strategy = lhrs_mapping_strategy::lut_based_pick_best;
  }
  else
  {
    in.setstate( std::ios_base::failbit );
  }
  return in;
}

std::ostream& operator<<( std::ostream& out, const lhrs_mapping_strategy& mapping_strategy )
{
  switch ( mapping_strategy )
  {
  case lhrs_mapping_strategy::direct:
    return out << "direct";
  case lhrs_mapping_strategy::lut_based_min_db:
    return out << "min_db";
  case lhrs_mapping_strategy::lut_based_best_fit:
    return out << "best_fit";
  case lhrs_mapping_strategy::lut_based_pick_best:
    return out << "pick_best";
  }

  return out;
}

std::istream& operator>>( std::istream& in, gia_graph::esop_cover_method& cover_method )
{
  std::string token;
  in >> token;
  if ( token == "aig" || token == "0" )
  {
    cover_method = gia_graph::esop_cover_method::aig;
  }
  else if ( token == "bdd" || token == "1" )
  {
    cover_method = gia_graph::esop_cover_method::bdd;
  }
  else if ( token == "aignew" || token == "2" )
  {
    cover_method = gia_graph::esop_cover_method::aig_new;
  }
  else if ( token == "auto" || token == "3" )
  {
    cover_method = gia_graph::esop_cover_method::aig_threshold;
  }
  else
  {
    in.setstate( std::ios_base::failbit );
  }
  return in;
}

std::ostream& operator<<( std::ostream& out, const gia_graph::esop_cover_method& cover_method )
{
  switch ( cover_method )
  {
  case gia_graph::esop_cover_method::aig:
    return out << "aig";
  case gia_graph::esop_cover_method::bdd:
    return out << "bdd";
  case gia_graph::esop_cover_method::aig_new:
    return out << "aignew";
  case gia_graph::esop_cover_method::aig_threshold:
    return out << "auto";
  }

  return out;
}

std::istream& operator>>( std::istream& in, exorcism_script& script )
{
  std::string token;
  in >> token;
  if ( token == "none" || token == "0" )
  {
    script = exorcism_script::none;
  }
  else if ( token == "def" || token == "1" )
  {
    script = exorcism_script::def;
  }
  else if ( token == "def_wo4" || token == "2" )
  {
    script = exorcism_script::def_wo4;
  }
  else
  {
    in.setstate( std::ios_base::failbit );
  }
  return in;
}

std::ostream& operator<<( std::ostream& out, const exorcism_script& script )
{
  switch ( script )
  {
  case exorcism_script::none:
    return out << "none";
  case exorcism_script::def:
    return out << "def";
  case exorcism_script::def_wo4:
    return out << "def_wo4";
  }

  return out;
}

}

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
