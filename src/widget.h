/*
* Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
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


#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QDBusInterface>
#include <QPropertyAnimation>
#include <QDBusPendingCallWatcher>
#include <QScreen>
#include <QGSettings>
#include <QGuiApplication>
#include <QPalette>
#include <QStyleOption>
#include "clipboardpluginiface.h"
#include "sidebarSmallPluginInterface.h"
#include "mostgrandwidget.h"
#include "broadsidewidget.h"
#include "smallpluginswidget.h"
#include "pluginsframeworkwidget.h"

#define  TRAY_ICON           ":/data/images/kylin-tool-box.svg"
#define  TRAY_NULL_ICON      ":/data/images/kylin-tool-box-null.svg"
#define  SETTING_ICON        ":/data/images/application-menu.svg"

#define PANEL_DBUS_SERVICE "com.ukui.panel.desktop"
#define PANEL_DBUS_PATH "/"
#define PANEL_DBUS_INTERFACE "com.ukui.panel.desktop"

#define UKUI_PANEL_SETTING "org.ukui.panel.settings"

class QGroupBox;
class QGridLayout;
class QVBoxLayout;

class Widget : public QWidget
{
    Q_OBJECT

    //申明该类有D-BUS服务接口
    Q_CLASSINFO("D-Bus Interface", "com.ukui.panel.sidebar.value")

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget();
    enum PanelStatePosition
    {
        PanelDown = 0,
        PanelUp,
        PanelLeft,
        PanelRight
    };
    //主界面
    void showAnimation();                                                       //show动作
    void hideAnimation();                                                       //hide动作
    void initTaskbarInteraction();                                              //初始化与任务栏交互
    void initscreenProblem();                                                   //初始化屏幕分辨率变化以及屏幕数量变化问题
    void initAnimation();                                                       //初始化动画
    int  ListenClipboardSignal();                                               //监听剪贴板发送的信号
    int  connectTaskBarDbus();                                                  //连接任务栏dbus接口，获取任务栏高度
    int  getPanelSite();                                                        //获取任务栏位置
    int  setClipBoardWidgetScaleFactor();                                       //获取通知中心下半部分高度比例系数

    //系统托盘
    void createAction();                                                        //连接信号和槽函数，设置其动作;
    void createSystray();                                                       //设置menu界面、添加动作 和 创建sysytray实例
    void setIcon(QIcon icon);                                                   //设置图标和提示信息;
    void iconActivated(QSystemTrayIcon::ActivationReason reason);               //获取点击事件
    bool loadNotificationPlugin();                                              //加载通知中心插件
    bool loadClockPlugin();                                                     //加载闹钟插件
    bool loadfeedbackPlugin();                                                  //加载用户反馈程序
    bool loadnotebookPlugin();
    void ModifyScreenNeeds();                                                   //修改屏幕分辨率或者主屏需要做的事情
    void GetsAvailableAreaScreen();                                             //获取屏幕可用区域高度
    void MostGrandWidgetCoordinates();                                          //根据任务栏位置调整侧边栏位置
    void InitializeHomeScreenGeometry();                                        //初始化主屏的X坐标
    void setLayoutBroadChildWidget();                                           //将子界面加入到左右俩个空的widget界面中
    void setMainLayoutWidget();                                                 //将俩个空的Widget界面框架加入到主的widget界面当中

    bool m_bfinish;


protected:
    bool eventFilter(QObject *obj, QEvent *event);                              //设置过滤事件

private:
    //主界面
    QHBoxLayout*                m_pMainQHBoxLayout;                             //主界面垂直布局器
    QDBusInterface*             m_pServiceInterface;                            //获取任务栏的高度
    bool                        m_bShowFlag = false;                            //控制托盘栏点击事件的标志位
    bool                        m_bClipboardFlag = true;                        //剪贴板编辑框打开和关闭时控制侧边栏是否关闭
    int                         m_nScreenWidth;                                 //屏幕分辨率的宽
    int                         m_nScreenHeight;                                //屏幕分辨率的高
    int                         m_nScreen_x;                                    //主屏的起始坐标X
    int                         m_nScreen_y;                                    //主屏的起始坐标Y
    int                         m_pPeonySite;                                   //任务栏位置

    QObject*                    m_pNotificationPluginObject;                    //通知中心插件对象

    SidebarSmallPluginInterface *m_pclock_Plugin;                               //闹钟插件全局变量
    SidebarSmallPluginInterface *m_pPlugin_Plugin;                              //问题反馈全局变量
    SidebarSmallPluginInterface *m_pnotebookPluginObject;
    int                         m_nInitalXPosition;
    QTranslator                 *m_pTranslator;
    QPropertyAnimation          *m_pAnimationShowSidebarWidget;
    QPropertyAnimation          *m_pAnimationHideSidebarWidget;
    QDesktopWidget              *m_pDeskWgt;                                    //桌面问题
    QGSettings                  *m_pPanelSetting = nullptr;

    //系统托盘
    QSystemTrayIcon*            trayIcon;
    QMenu*                      trayIconMenu;
    QAction*                    Open;
    QAction*                    OpenSetUp;
    QTimer*                     m_pUpdateSmallPluginsWidget;
    smallPluginsWidget*         m_pSmallPluginsWidget;

private slots :
    void onResolutionChanged(int);                                              //当改变屏幕分辨率时重新获取屏幕分辨率
    void onNewNotification();                                                   //当没展开时，来了新通知才提示
    void hideAnimationFinish();                                                 //隐藏动画完成
    void showAnimationAction(const QVariant &value);                            //展开动画开始
    void showAnimationFinish();
    void primaryScreenChangedSLot();                                            //主屏发生变化
    void ClipboardShowSlots();                                                  //接受剪贴板信号，将boll值m_bClipboardFlag置为false;
    void ClipboardHideSlots();                                                  //接受剪贴板信号，将boll值m_bClipboardFlag置为true;
    void screenCountChangedSlots(int count);                                    //屏幕数量改变时对应槽函数
    void OpenSidebarSlots();                                                    //打开侧边栏
    void OpenControlCenterSettings();                                           //打开控制中心的通知中心
    void ClickPanelHideSidebarSlots();                                          //左键点击任务栏时隐藏侧边栏
    void updateSmallPluginsClipboardWidget();                                   //切换主题时，定时器槽函数
};

#endif // WIDGET_H
