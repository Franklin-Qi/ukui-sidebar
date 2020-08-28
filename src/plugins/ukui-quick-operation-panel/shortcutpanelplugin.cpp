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
#include "shortcutpanelplugin.h"

shortcutPanelPlugin::shortcutPanelPlugin(QObject *parent)
{
    Q_UNUSED(parent);
    initMemberVariables();      // 初始化插件成员变量
    initShortButtonWidget();    // 初始化8个快捷按钮界面
    setButtonIcon();            // 设置按钮图标
    initsetShortWidget();       // 布局快捷按钮界面
    setWidget();                // 将切换按钮和ListView界面set进插件主界面
}

/* 初始化插件成员变量 */
void shortcutPanelPlugin::initMemberVariables()
{
    m_pMainVLayout = new QVBoxLayout;
    m_pMainVLayout->setContentsMargins(0, 0, 0, 0);
    m_pMainVLayout->setSpacing(0);

    m_pButtonHLaout = new QHBoxLayout;
    m_pButtonHLaout->setContentsMargins(0, 0, 0, 0);
    m_pButtonHLaout->setSpacing(0);

    m_pShortGLayout  = new QGridLayout;
    m_pShortGLayout->setContentsMargins(32, 16, 18, 31);
    m_pShortGLayout->setHorizontalSpacing(35);
    m_pShortGLayout->setVerticalSpacing(16);

    m_pMainWidget  = new MainWidget;
    m_pMainWidget->setContentsMargins(0, 0, 0, 0);
    m_pMainWidget->setFixedSize(392, 486);
    m_pButtonWidget = new QWidget;
    m_pButtonWidget->setContentsMargins(0, 0, 0, 0);
    m_pButtonWidget->setFixedHeight(15);

    /* 账户信息界面 */
    m_PAccountInfoWidget = new AccountInformation();
    m_PAccountInfoWidget->setFixedSize(392, 48);

    /* 快捷操作面板界面 */
    m_pShortWidget   = new QWidget;
    m_pShortWidget->setFixedWidth(380);
    m_pShortWidget->setContentsMargins(0, 0, 0, 0);

    /* 调整音量与屏幕亮度界面 */
    m_pScrollingAreaWidget = new ScrollingAreaWidget();
    m_pScrollingAreaWidget->setFixedSize(392, 56);

    /* 显示天气界面 */
    m_pWeatherWidget = new weatherWidget();
    m_pWeatherWidget->setFixedSize(392, 50);

    m_SpreadButtonIconList << SPREAD_BUTTON_NORMAL << SPREAD_BUTTON_HOVER << SPREAD_BUTTON_PRESS;
    m_FoldButtonIconList   << FOLD_BUTTON_NORMAL   << FOLD_BUTTON_HOVER   << FOLD_BUTTON_PRESS;

    m_SpreadButtonIconNameList << SPREAD_BUTTON_NORMAL_NAME << SPREAD_BUTTON_HOVER_NAME << SPREAD_BUTTON_PRESS_NAME;
    m_FoldButtonIconNameList   << FOLD_BUTTON_NORMAL_NAME << FOLD_BUTTON_HOVER_NAME << FOLD_BUTTON_PRESS_NAME;

    m_pSpreadButton  = new PushButton(m_SpreadButtonIconList, m_SpreadButtonIconNameList);
    connect(m_pSpreadButton, &QPushButton::clicked, this, &shortcutPanelPlugin::spreadClikedSlots);
    m_pSpreadButton->setFixedSize(45, 15);

    m_pfoldButton = new PushButton(m_FoldButtonIconList, m_FoldButtonIconNameList);
    connect(m_pfoldButton, &QPushButton::clicked, this, &shortcutPanelPlugin::foldClikedSlots);
    m_pfoldButton->setFixedSize(45, 15);
    return;
}

/* 初始化8个快捷按钮界面 */
void shortcutPanelPlugin::initShortButtonWidget()
{
    /* 清空链表中的数据，初始化 */
    ShortButtonWidgetList.clear();

    /* 平板模式 */
    m_ppadWidget       = new padWidget();
    ShortButtonWidgetList.append(m_ppadWidget);

    /* Wifi */
    m_pWifiWidget = new WifiWidget();
    ShortButtonWidgetList.append(m_pWifiWidget);

    /* 免打扰 */
    m_pnodisturbWidget = new nodisturbWidget();
    ShortButtonWidgetList.append(m_pnodisturbWidget);

    /* 设置 */
    m_psettingWidget = new settingWidget();
    ShortButtonWidgetList.append(m_psettingWidget);

    /* 蓝牙 */
    m_pbluetoothWidget = new bluetoothWidget();
    ShortButtonWidgetList.append(m_pbluetoothWidget);

    /* 热点 */
    m_photspotWidget = new hotspotWidget();
    ShortButtonWidgetList.append(m_photspotWidget);

    /* 计算器 */
    m_pcalculatorWidget = new calculatorWidget();
    ShortButtonWidgetList.append(m_pcalculatorWidget);

    /* 截图 */
    m_pscreenshotWidget = new screenshotWidget();
    ShortButtonWidgetList.append(m_pscreenshotWidget);

    /* 自动旋转功能 */
    m_pAutomaticRotationWidget = new AutomaticRotationWidget();
    ShortButtonWidgetList.append(m_pAutomaticRotationWidget);

    /* 闹钟 */
    m_pAlarmButtonInterface = new alarmButtonInterface();
    ShortButtonWidgetList.append(m_pAlarmButtonInterface);

    /* 便签本 */
    m_pNoteBookButtonWidget = new notebookButtonWidget();
    ShortButtonWidgetList.append(m_pNoteBookButtonWidget);

    /* 勿扰模式 */
    m_pDiturbModeWidget = new diturbModeWidget();
    ShortButtonWidgetList.append(m_pDiturbModeWidget);
    return;
}

/* 布局8个快捷方式的按钮, 初始化 */
void shortcutPanelPlugin::initsetShortWidget()
{
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(0), 0, 0, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(1), 0, 1, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(2), 0, 2, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(3), 0, 3, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(4), 1, 0, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(5), 1, 1, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(6), 1, 2, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(7), 1, 3, 1, 1);
    }
    if (true&&true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(8), 2, 0, 1, 1);
    }
    if (true&&true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(9), 2, 1, 1, 1);
    }
    if (true&&true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(10), 2, 2, 1, 1);
    }
    if (true&&true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(11), 2, 3, 1, 1);
    }
    return;
}

/* 当收到控制面板发出的gsetting信号值变化时，重新布局按钮界面 */
void shortcutPanelPlugin::resetShortWidget()
{
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(0), 0, 0, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(1), 0, 1, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(2), 0, 2, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(3), 0, 3, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(4), 1, 0, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(5), 1, 1, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(6), 1, 2, 1, 1);
    }
    if (true && true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(7), 1, 3, 1, 1);
    }
    if (true&&true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(8), 2, 0, 1, 1);
    }
    if (true&&true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(9), 2, 1, 1, 1);
    }
    if (true&&true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(10), 2, 2, 1, 1);
    }
    if (true&&true) {
        m_pShortGLayout->addWidget(ShortButtonWidgetList.at(11), 2, 3, 1, 1);
    }
    return;
}

/* 设置按钮图标 */
void shortcutPanelPlugin::setButtonIcon()
{
    /* 设置展开按钮悬浮和点击状态按钮图片 */
    m_pSpreadButton->setIcon(QIcon(":/image/open-normal.svg"));

    /* 设置折叠按钮悬浮和点击状态按钮图片 */
    m_pfoldButton->setIcon(QIcon(":/image/fold-normal.svg"));
    return;
}

/* 将切换按钮和ListView界面set进插件主界面 */
void shortcutPanelPlugin::setWidget()
{
    m_pButtonHLaout->addItem(new QSpacerItem(20, 173));
    m_pButtonHLaout->addWidget(m_pSpreadButton);
    m_pButtonHLaout->addWidget(m_pfoldButton);
    m_pButtonWidget->setLayout(m_pButtonHLaout);
    m_pSpreadButton->setVisible(false);

    m_pShortWidget->setLayout(m_pShortGLayout);

    m_pMainVLayout->addWidget(m_pButtonWidget);
    m_pMainVLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Fixed));
    m_pMainVLayout->addWidget(m_PAccountInfoWidget);
    m_pMainVLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Fixed));
    m_pLinelabel_1 = new QLabel();
    m_pLinelabel_1->setFixedSize(392, 1);
    m_pLinelabel_1->setStyleSheet("QLabel{border: 1px solid rgba(246, 246, 246, 1)};");
    m_pMainVLayout->addWidget(m_pLinelabel_1);

    m_pMainVLayout->addWidget(m_pShortWidget);

    m_pLinelabel_2 = new QLabel();
    m_pLinelabel_2->setFixedSize(392, 1);
    m_pLinelabel_2->setStyleSheet("QLabel{border: 1px solid rgba(246, 246, 246, 1)};");
    m_pMainVLayout->addWidget(m_pLinelabel_2);

    m_pMainVLayout->addWidget(m_pScrollingAreaWidget);

    m_pLinelabel_3 = new QLabel();
    m_pLinelabel_3->setFixedSize(392, 1);
    m_pLinelabel_3->setStyleSheet("QLabel{border: 1px solid rgba(246, 246, 246, 1)};");
    m_pMainVLayout->addWidget(m_pLinelabel_3);

    m_pMainVLayout->addWidget(m_pWeatherWidget);
    m_pMainVLayout->setSpacing(0);
    m_pMainWidget->setLayout(m_pMainVLayout);
    return;
}

/* 获取快捷操作面板界面 */
QWidget* shortcutPanelPlugin::getShortCutPanelWidget()
{
    if (m_pMainWidget == nullptr) {
        return nullptr;
    }
    return m_pMainWidget;
}

/* 获取接口代号 */
InterfaceEnum shortcutPanelPlugin::getInterfaceMark(QString key)
{

    if ("" == key) {
        qDebug() << "获取接口代号失败， 传入参数有误";
        return InterfaceEnum::Else;
    }
    if (m_InterfaceHash.contains(key)) {
        return m_InterfaceHash.value(key);
    } else
        return InterfaceEnum::Else;
}

/* 移除Hash中接口 */
void shortcutPanelPlugin::removeInterfaceMark(QString key)
{
    if ("" == key) {
        qDebug() << "移除Hash中接口失败， 传入参数有误";
        return;
    }
    if (m_InterfaceHash.contains(key))
        m_InterfaceHash.remove(key);
    return;
}

/* 插入接口和代号往Hash表中 */
void shortcutPanelPlugin::insertInterfaceMark(QString key, InterfaceEnum value)
{
    if ("" == key || value < 0) {
        qDebug() << "插入数据失败， 传入参数有误";
        return;
    }
    if (m_InterfaceHash.contains(key)) {
        qDebug() << "此Key值已存在";
        return;
    }
    m_InterfaceHash.insert(key, value);
    return;
}

void shortcutPanelPlugin::setGridLayoutWidgetHide()
{
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (m_pShortGLayout->itemAtPosition(i, j) == nullptr) {
                return;
            } else {
                m_pShortGLayout->itemAtPosition(i, j)->widget()->setVisible(false);
            }
        }
    }
}

void shortcutPanelPlugin::setGridLayoutWidgetShow()
{
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (m_pShortGLayout->itemAtPosition(i, j) == nullptr) {
                return;
            } else {
                m_pShortGLayout->itemAtPosition(i, j)->widget()->setVisible(true);
            }
        }
    }
}

/* 展开按钮槽函数 */
void shortcutPanelPlugin::spreadClikedSlots()
{

    qDebug() << m_pMainWidget->size();
    m_pSpreadButton->setVisible(false);
    m_pfoldButton->setVisible(true);
    setGridLayoutWidgetShow();
    m_pScrollingAreaWidget->setVisible(true);
    m_pWeatherWidget->setVisible(true);
    m_pShortWidget->setFixedHeight(266);
    m_pMainWidget->setFixedSize(392, 486);
    m_pLinelabel_2->setVisible(true);
    m_pLinelabel_3->setVisible(true);
    m_pMainWidget->update();
    return;
}

/* 折叠按钮槽函数 */
void shortcutPanelPlugin::foldClikedSlots()
{

    qDebug() << m_pMainWidget->size();
    m_pSpreadButton->setVisible(true);
    m_pfoldButton->setVisible(false);
    int height = m_pMainWidget->height();
    int width  = m_pMainWidget->width();
    setGridLayoutWidgetHide();
    m_pShortWidget->setFixedHeight(102);
    m_pMainWidget->setFixedSize(width, 184);
    m_pScrollingAreaWidget->setVisible(false);
    m_pWeatherWidget->setVisible(false);
    m_pLinelabel_2->setVisible(false);
    m_pLinelabel_3->setVisible(false);
    qDebug() << "折叠界面大小--->" << m_pButtonWidget->size();
    qDebug() << "账户信息大小--->" << m_PAccountInfoWidget->size();
    qDebug() << "快捷操作界面大小--->" << m_pShortWidget->size();
    m_pMainWidget->update();
    return;
}
