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

#include "visualization/KnownMessagesTab.h"

#include "types/FrontWheelsSpeed.h"
#include "types/RearWheelsSpeed.h"
#include "types/Speed1.h"
#include "types/Speed2.h"
#include "types/Speed3.h"
#include "types/Steering1.h"
#include "types/Steering2.h"
#include "types/Brakes.h"
#include "types/Acceleration1.h"
#include "types/Acceleration2.h"
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
  else if (message->instanceOf<Speed1>()) {
    const Speed1& sp = message->typeCast<Speed1>();
    mUi->vsSpinBox1->setValue(sp.mValue);
  }
  else if (message->instanceOf<Speed2>()) {
    const Speed2& sp = message->typeCast<Speed2>();
    mUi->vsSpinBox2->setValue(sp.mValue);
  }
  else if (message->instanceOf<Speed3>()) {
    const Speed3& sp = message->typeCast<Speed3>();
    mUi->vsSpinBox3->setValue(sp.mThrottle);
    mUi->vsSpinBox4->setValue(sp.mSpeed);
  }
  else if (message->instanceOf<Steering1>()) {
    const Steering1& st = message->typeCast<Steering1>();
    mUi->stSpinBox1->setValue(st.mValue);
  }
  else if (message->instanceOf<Steering2>()) {
    const Steering2& st = message->typeCast<Steering2>();
    mUi->stSpinBox2->setValue(st.mValue);
  }
  else if (message->instanceOf<Brakes>()) {
    const Brakes& b = message->typeCast<Brakes>();
    mUi->bSpinBox->setValue(b.mValue);
  }
  else if (message->instanceOf<Acceleration1>()) {
    const Acceleration1& a = message->typeCast<Acceleration1>();
    mUi->a1SpinBox1->setValue(a.mValue1);
    mUi->a1SpinBox2->setValue(a.mValue2);
  }
  else if (message->instanceOf<Acceleration2>()) {
    const Acceleration2& a = message->typeCast<Acceleration2>();
    mUi->a2SpinBox1->setValue(a.mValue1);
    mUi->a2SpinBox2->setValue(a.mValue2);
  }
}
