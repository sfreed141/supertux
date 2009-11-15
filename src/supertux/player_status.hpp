//  SuperTux
//  Copyright (C) 2003 Tobias Glaesser <tobi.web@gmx.de>
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_SUPERTUX_PLAYER_STATUS_HPP
#define HEADER_SUPERTUX_SUPERTUX_PLAYER_STATUS_HPP

#include <memory>
#include "util/serializable.hpp"
#include "video/color.hpp"

namespace lisp{ class Writer; }
namespace lisp{ class Lisp; }
class Surface;

static const float BORDER_X = 10;
static const float BORDER_Y = 10;

enum BonusType {
  NO_BONUS, GROWUP_BONUS, FIRE_BONUS, ICE_BONUS
};
class DrawingContext;

/**
 * This class memorizes player status between different game sessions (for
 * example when switching maps in the worldmap)
 */
class PlayerStatus : public Serializable
{
  static Color text_color;
public:
  PlayerStatus();
  ~PlayerStatus();
  void reset();
  void add_coins(int count, bool play_sound = true);

  void write(lisp::Writer& writer);
  void read(const lisp::Lisp& lisp);

  void draw(DrawingContext& context);

  int  coins;
  BonusType bonus;
  int max_fire_bullets; /**< maximum number of fire bullets in play */
  int max_ice_bullets; /**< maximum number of ice bullets in play */

  void operator= (const PlayerStatus& other);

private:
  // don't use this
  PlayerStatus(const PlayerStatus& other);

  std::auto_ptr<Surface> coin_surface;
};

// global player state
extern PlayerStatus* player_status;

#endif
