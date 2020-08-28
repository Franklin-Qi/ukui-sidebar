/*
* Copyright (C) 2020 Tianjin KYLIN Information Technology Co., Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
*
*/
#include "calculatorwidget.h"

calculatorWidget::calculatorWidget(QWidget *parent) : QWidget(parent)
{
    initMemberVariables();
    initLayout();
}

calculatorWidget::~calculatorWidget()
{

}

void calculatorWidget::initMemberVariables()
{
    m_IconPathList << KYLIN_CALCULATOR_NORMAL_PATH << KYLIN_CALCULATOR_HOVER_PATH << KYLIN_CALCULATOR_PRESS_PATH;
    m_IconNameList << KYLIN_CALCULATOR_NORMAL_NAME << KYLIN_CALCULATOR_HOVER_NAME << KYLIN_CALCULATOR_PRESS_NAME;

    m_pWidgetButton         = new QWidget();
    m_pWidgetButton->setFixedSize(56, 56);
    m_pWidgetButton->setContentsMargins(0, 0, 0, 0);
    m_pVboxButtonLayout     = new QVBoxLayout();
    m_pVboxButtonLayout->setContentsMargins(0, 0, 0, 0);

    m_pcalculatorButton = new switchButton(m_IconPathList, m_IconNameList);
    m_pcalculatorButton->setFixedSize(56, 56);
    m_pcalculatorButton->setIconSize(QSize(32, 32));
    connect(m_pcalculatorButton, &switchButton::clicked, this, &calculatorWidget::calculatorButtonClickSlots);

    m_pStyleNormal = new customstyle_switchNormalStatus("ukui-default");
    m_pcalculatorButton->setStyle(m_pStyleNormal);

    m_pcalculatorLabel = new QLabel(QObject::tr("计算机"));
    m_pcalculatorLabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(56, 78);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void calculatorWidget::initLayout()
{
    m_pVboxButtonLayout->addWidget(m_pcalculatorButton, 0, Qt::AlignCenter);
    m_pWidgetButton->setLayout(m_pVboxButtonLayout);
    m_pVboxLayout->addWidget(m_pWidgetButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 4));
    m_pVboxLayout->addWidget(m_pcalculatorLabel);
    this->setLayout(m_pVboxLayout);
    return;
}

void calculatorWidget::calculatorButtonClickSlots()
{
    QProcess p(0);
    p.startDetached("mate-calculator");
    p.waitForStarted();
    return;
}
