/******************************************************************************
 * Copyright (C) 2013 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

/** \file Joystick.h
    \brief This file defines the Joystick class which contains a joystick
           driver.
  */

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <string>

#include "base/Serializable.h"

/** The class Joystick contains a joystick driver.
    \brief Joystick driver
  */
class Joystick {
  /** \name Private constructors
    @{
    */
  /// Copy constructor
  Joystick(const Joystick& other);
  /// Assignment operator
  Joystick& operator = (const Joystick& other);
  /** @}
    */

public:
  /** \name Types definitions
    @{
    */
  /// Joystick state
  struct State :
    public virtual Serializable {
    /// Default constructor
    State() :
        mNumButtons(0),
        mNumAxes(0),
        mButtons(0),
        mAxes(0) {
    }
    /// Destructor
    ~State() {
      if (mButtons)
        delete []mButtons;
      if (mAxes)
        delete []mAxes;
    }
    /// Standard read
    virtual void read(std::istream& stream) {
    }
    /// Standard write
    virtual void write(std::ostream& stream) const {
      stream << "Number of buttons: " << mNumButtons << std::endl
        << "Number of axes: " << mNumAxes << std::endl;
      for (size_t i = 0; i < mNumButtons; ++i)
        stream << "Button[" << i << "]: " << mButtons[i] << std::endl;
      for (size_t i = 0; i < mNumAxes; ++i)
        stream << "Axe[" << i << "]: " << mAxes[i] << std::endl;
    }
    /// File read
    virtual void read(std::ifstream& stream) {
    }
    /// File write
    virtual void write(std::ofstream& stream) const {
    }
    /// Number of buttons
    size_t mNumButtons;
    /// Number of axes
    size_t mNumAxes;
    /// Buttons data
    int16_t* mButtons;
    /// Axes data
    int16_t* mAxes;
  };
  /** @}
    */

  /** \name Constructors/destructor
    @{
    */
  /// Constructs with parameters
  Joystick(const std::string& devicePathStr = "/dev/input/js0");
  /// Destructor
  virtual ~Joystick();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Open the joystick device
  void open();
  /// Close the joystick device
  void close();
  /// Check if open
  bool isOpen() const;
  /// Get driver version
  uint32_t getDriverVersion();
  /// Get identifier string
  std::string getIdentifierString();
  /// Returns the joystick state
  const State& getState();
  /** @}
    */

protected:
  /** \name Protected members
    @{
    */
  /// Path to the joystick device
  std::string mDevicePathStr;
  /// Handle on the device
  ssize_t mHandle;
  /// Joystick state
  State mState;
  /** @}
    */

};

#endif // JOYSTICK_H
