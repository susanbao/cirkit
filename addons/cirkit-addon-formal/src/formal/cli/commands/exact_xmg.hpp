/* CirKit: A circuit toolkit
 * Copyright (C) 2009-2015  University of Bremen
 * Copyright (C) 2015-2016  EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file exact_xmg.hpp
 *
 * @brief Exact XMG synthesis
 *
 * @author Mathias Soeken
 * @since  2.3
 */

#ifndef CLI_EXACT_XMG_COMMAND_HPP
#define CLI_EXACT_XMG_COMMAND_HPP

#include <core/cli/cirkit_command.hpp>

namespace cirkit
{

class exact_xmg_command : public cirkit_command
{
public:
  exact_xmg_command( const environment::ptr& env );

protected:
  bool execute();

public:
  log_opt_t log() const;

private:
  unsigned              objective = 0u;
  unsigned              start = 1u;
  unsigned              timeout;
  std::string           breaking = "CIsalty";
};

}

#endif

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
