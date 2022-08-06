/*
    Copyright 2016 - 2017 Benjamin Vedder	benjamin@vedder.se

    This file is part of VESC Tool.

    VESC Tool is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    VESC Tool is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#include "rtdatatext.h"
#include <QFont>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

RtDataText::RtDataText(QWidget *parent) : QWidget(parent)
{
    mBoxH = 10;
    mBoxW = 10;
    mTxtOfs = 2;

    mValues.packVoltage      = 0.0;
    mValues.packCurrent      = 0.0;
    mValues.soC              = 0;
    mValues.AhCnt            = 0.0;
    mValues.WhCnt            = 0.0;
    mValues.AhCntChg         = 0.0;
    mValues.WhCntChg         = 0.0;
    mValues.AhCntDis         = 0.0;
    mValues.WhCntDis         = 0.0;
    mValues.cVHigh           = 0.0;
    mValues.cVAverage        = 0.0;
    mValues.cVLow            = 0.0;
    mValues.cVMisMatch       = 0.0;
    mValues.loadLCVoltage    = 0.0;
    mValues.loadLCCurrent    = 0.0;
    mValues.loadHCVoltage    = 0.0;
    mValues.loadHCCurrent    = 0.0;
    mValues.chargerVoltage   = 0.0;
    mValues.auxVoltage       = 0.0;
    mValues.auxCurrent       = 0.0;
    mValues.tempBattHigh     = 0.0;
    mValues.tempBattAverage  = 0.0;
    mValues.tempBattLow      = 0.0;
    mValues.tempBMSHigh      = 0.0;
    mValues.tempBMSAverage   = 0.0;
    mValues.tempBMSLow       = 0.0;
    mValues.humidity         = 0.0;
    mValues.opState          = "Unknown.";
    mValues.faultState       = "Unknown.";
}

void RtDataText::setValues(const BMS_VALUES &values)
{
    mValues = values;
    //mValues.opState.remove(0, 11);
    update();
}

QSize RtDataText::sizeHint() const
{
    QSize size;
    size.setWidth(mBoxW + 2 * mTxtOfs);
    size.setHeight(mBoxH + 2 * mTxtOfs);
    return size;
}

void RtDataText::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Paint begins here
    painter.fillRect(event->rect(), QBrush(Qt::transparent));

    QFont font;
    font.setFamily("DejaVu Sans Mono");
    font.setPointSize(11);
    painter.setFont(font);

    QRectF br = painter.boundingRect(QRectF(0, 0, 4000, 4000),
                                    "Fault   : 00000000000000000"
                                    "T\n"
                                    "T\n"
                                    "T\n"
                                    "T\n"
                                    "T\n"
                                    "T\n"
                                    "T\n"
                                    "T\n");

    int boxh_new = br.height();
    //qDebug("boxh_new value is : %d", boxh_new);
    int boxw_new = br.width();
    //qDebug("boxw_new value is : %d", boxw_new);
    int txtofs_new = 5;

    if (mBoxH != boxh_new || mBoxW != boxw_new || mTxtOfs != txtofs_new) {
        mBoxH = boxh_new;
        mBoxW = boxw_new;
        mTxtOfs = txtofs_new;
        updateGeometry();
    }

    QString str;

    const double bbox_w = mBoxW + 2 * mTxtOfs;
    const double bbow_h = mBoxH + 2 * mTxtOfs;
    const double vidw = event->rect().width();
    //qDebug("vidw value is : %f", vidw);

    // Left info box
    str.sprintf("V Pack    : %.2f V\n"
                "I Pack    : %.2f A\n"
                "P Pack    : %.1f W\n"
                "CVHigh    : %.3f V\n"
                "CVAverage : %.3f V\n"
                "CVLow     : %.3f V\n"
                "CMismatch : %.3f V\n"
                "Ah Counter: %.3f Ah\n"
                "Wh Counter: %.3f Wh\n",
                mValues.packVoltage,
                mValues.packCurrent,
                mValues.packCurrent * mValues.packVoltage,
                mValues.cVHigh,
                mValues.cVAverage,
                mValues.cVLow,
                mValues.cVMisMatch,
                mValues.AhCnt,
                mValues.WhCnt);

    painter.setOpacity(0.7);
    painter.fillRect(0, 0, bbox_w, bbow_h, Qt::black);
    painter.setOpacity(1.0);

    painter.setPen(Qt::white);
    painter.drawText(QRectF(mTxtOfs, mTxtOfs, mBoxW, mBoxH),
                     Qt::AlignLeft, str);

    // Middle info box
    str.sprintf("T Batt High    : %.1f \u00B0C\n"
                "T Batt Avrg    : %.1f \u00B0C\n"
                "T Batt Low     : %.1f \u00B0C\n"
                "T BMS High     : %.1f \u00B0C\n"
                "T BMS Avrg     : %.1f \u00B0C\n"
                "T BMS Low      : %.1f \u00B0C\n"
                "Humidity       : %.1f %%\n"
                "Ah Charge Total: %.3f Ah\n"
                "Wh Charge Total: %.3f Wh\n",
                mValues.tempBattHigh,
                mValues.tempBattAverage,
                mValues.tempBattLow,
                mValues.tempBMSHigh,
                mValues.tempBMSAverage,
                mValues.tempBMSLow,
                mValues.humidity,
                mValues.AhCntChg,
                mValues.WhCntChg);

    painter.setOpacity(0.7);
    painter.fillRect(vidw / 2.0 - bbox_w / 2.0 - 50, 0, bbox_w+50, bbow_h, Qt::black);
    painter.setOpacity(1.0);

    painter.setPen(Qt::white);
    painter.drawText(QRectF(vidw / 2.0 - bbox_w / 2.0 + mTxtOfs -50, mTxtOfs, bbox_w +50, mBoxH),
                     Qt::AlignLeft, str);

    // Right info box
    str.sprintf("V Load         : %.1f V\n"
                "P Load         : %.1f W\n"
                "V Charger      : %.1f V\n"
                "P Charger      : %.1f W\n"
                "SoC            : %i %%\n"
                "OpState        : %s\n"
                "FaultState     : %s\n"
                "Ah Disharge Total: %.3f Ah\n"
                "Wh Disharge Total: %.3f Wh\n",
                mValues.loadLCVoltage,
                mValues.packCurrent * mValues.loadLCVoltage,
                mValues.chargerVoltage,
                mValues.packCurrent * mValues.chargerVoltage,
                mValues.soC,
                mValues.opState.toLocal8Bit().data(),
                mValues.faultState.toLocal8Bit().data(),
                mValues.AhCntDis,
                mValues.WhCntDis);

    painter.setOpacity(0.7);
    painter.fillRect(vidw - bbox_w - 100, 0, bbox_w + 100, mBoxH + 2 * mTxtOfs, Qt::black);
    painter.setOpacity(1.0);

    painter.setPen(Qt::white);
    painter.drawText(QRectF(vidw - bbox_w + mTxtOfs -100, mTxtOfs, bbox_w + 100, mBoxH),Qt::AlignLeft, str);
}
