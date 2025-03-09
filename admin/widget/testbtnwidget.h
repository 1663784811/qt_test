#ifndef TESTBTNWIDGET_H
#define TESTBTNWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMovie>
#include <QLineEdit>
#include "basewidget.h"
#include "vd/vdswitch.h"

class TestBtnWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit TestBtnWidget(QWidget *parent = nullptr);


private:
    QVBoxLayout* mainLayout;
    // 文本 省略号
    QGroupBox *textGroup;
    QLabel *defaultTxt;
    QLabel *htmlTxt;

    // gif / 图片
    QGroupBox *imagesGroup;
    QLabel *gifLabel;
    QLabel *imgLabel;

    // 基础按钮
    QGroupBox *baseBtn;
    QPushButton *defaultBtn;
    QPushButton *primaryBtn;

    // 开关
    QGroupBox *switchGroup;
    VdSwitch *defaultSwitch; // 默认开关


    // 文本输入框、密码输入框
    QGroupBox *inputGroup;
    QLineEdit *inputEdit;
    QLineEdit *pwdEdit;

    // 文本域

    // Radio 单选框

    // Checkbox 多选框

    // Select 选择器

    // 日期选择

    // 进度条  Slider 滑块


    // 气泡提示

    // 数字输入框

    // Rate 评分

    // ColorPicker 颜色选择器

    // Message 全局提示

    // Notice 通知提醒

    // Modal 对话框

    // Drawer 抽屉


    // Calendar 日历



    // ============================================
    // 菜单导航
    // 登录框
    // 折叠面板
    // 面板分割
    // Tabs 标签页
    // Dropdown 下拉菜单
    // Page 分页
    // Badge 徽标数
    // Steps 步骤条
    // Form 表单
    // Result 处理结果
    // Avatar 头像
    // Carousel 走马灯
    // Circle 进度环









signals:


};

#endif
