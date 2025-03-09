#include "testbtnwidget.h"



TestBtnWidget::TestBtnWidget(QWidget *parent) : BaseWidget{parent}
{
    setObjectName("TestBtnWidget");
    mainLayout = new QVBoxLayout();
    // ===========================================================   文本
    textGroup = new QGroupBox();
    textGroup->setTitle("文本");
    mainLayout->addWidget(textGroup);
    QVBoxLayout *txtLayout = new QVBoxLayout(textGroup);
    defaultTxt = new QLabel("默认文件");
    txtLayout->addWidget(defaultTxt);
    htmlTxt = new QLabel("<p style=\"color:#fd839a;font-size:16px;\">HTML<b style=\"color:green;font-size:22px;\">文本</b></p>");
    txtLayout->addWidget(htmlTxt);

    // ===========================================================   图片/gif
    imagesGroup = new QGroupBox();
    imagesGroup->setTitle("图片/gif");
    mainLayout->addWidget(imagesGroup);
    QHBoxLayout *imagesLayout = new QHBoxLayout(imagesGroup);

    imgLabel = new QLabel();
    imgLabel->setPixmap(QPixmap(":/res/icon-loading.gif"));
    imgLabel->setFixedSize(31, 31);
    imgLabel->setScaledContents(true);
    imagesLayout->addWidget(imgLabel);

    gifLabel = new QLabel();
    QMovie *pMovie = new QMovie(":/res/icon-loading.gif");
    gifLabel->setMovie(pMovie);
    gifLabel->setFixedSize(31, 31);
    gifLabel->setScaledContents(true);
    pMovie->start(); // 播放加载的动画
    imagesLayout->addWidget(gifLabel);


    // ===========================================================   基础按钮
    baseBtn = new QGroupBox();
    baseBtn->setTitle("基础按钮");
    mainLayout->addWidget(baseBtn);
    QHBoxLayout *baseBtnLayout = new QHBoxLayout(baseBtn);
    defaultBtn = new QPushButton("默认");
    primaryBtn = new QPushButton("Primary");
    baseBtnLayout->addWidget(defaultBtn);
    baseBtnLayout->addWidget(primaryBtn);


    // ===========================================================   开关
    switchGroup = new QGroupBox();
    switchGroup->setTitle("开关按钮");
    mainLayout->addWidget(switchGroup);
    QHBoxLayout *switchLayout = new QHBoxLayout(switchGroup);
    defaultSwitch = new VdSwitch();
    defaultSwitch->setText("OFF","NO");
    switchLayout->addWidget(defaultSwitch);



    // ===========================================================   文本输入框、密码输入框
    inputGroup = new QGroupBox();
    inputGroup->setTitle("文本输入框、密码输入框");
    mainLayout->addWidget(inputGroup);
    QVBoxLayout *inputLayout = new QVBoxLayout(inputGroup);
    inputEdit = new QLineEdit();
    inputEdit->setFixedSize(300, 40);
    inputEdit->setMaxLength(30);
    inputLayout->addWidget(inputEdit);


    pwdEdit = new QLineEdit();
    pwdEdit->setFixedSize(300, 40);
    pwdEdit->setMaxLength(30);
    pwdEdit->setEchoMode(QLineEdit::Password);

    inputLayout->addWidget(pwdEdit);


    // ===========================================================





    setLayout(mainLayout);
}
