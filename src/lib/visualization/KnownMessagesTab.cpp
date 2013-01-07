/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
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

#include "visualization/KnownMessagesTab.h"

#include "types/FrontWheelsSpeed.h"
#include "types/RearWheelsSpeed.h"
#include "types/Speed.h"
#include "types/Steering.h"
#include "types/PRIUSMessage.h"

#include "ui_KnownMessagesTab.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

KnownMessagesTab::KnownMessagesTab() :
    mUi(new Ui_KnownMessagesTab()) {
  mUi->setupUi(this);
}

KnownMessagesTab::~KnownMessagesTab() {
  delete mUi;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void KnownMessagesTab::readMessage(std::shared_ptr<PRIUSMessage> message) {
  if (message->instanceOf<FrontWheelsSpeed>()) {
    const FrontWheelsSpeed& fws = message->typeCast<FrontWheelsSpeed>();
    mUi->fwsLeftSpinBox->setValue(fws.mLeft);
    mUi->fwsRightSpinBox->setValue(fws.mRight);
  }
  else if (message->instanceOf<RearWheelsSpeed>()) {
    const RearWheelsSpeed& rws = message->typeCast<RearWheelsSpeed>();
    mUi->rwsLeftSpinBox->setValue(rws.mLeft);
    mUi->rwsRightSpinBox->setValue(rws.mRight);
  }
  else if (message->instanceOf<Speed>()) {
    const Speed& sp = message->typeCast<Speed>();
    mUi->vsSpinBox->setValue(sp.mSpeed);
  }
  else if (message->instanceOf<Steering>()) {
    const Steering& st = message->typeCast<Steering>();
    mUi->stSpinBox->setValue(st.mAngle);
  }
}
