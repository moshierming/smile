//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#pragma once

#include <omnetpp.h>
#include "IClock.h"

namespace smile {

class Clock : public omnetpp::cSimpleModule, public IClock
{
 public:
  Clock() = default;
  Clock(const Clock& source) = delete;
  Clock(Clock&& source) = delete;
  ~Clock() override = default;

  Clock& operator=(const Clock& source) = delete;
  Clock& operator=(Clock&& source) = delete;

  omnetpp::SimTime getClockTimestamp() override;
  OptionalSimTime convertToSimulationTimestamp(const omnetpp::SimTime& timestamp) override;

 protected:
  int numInitStages() const final;
};

}  // namespace smile
