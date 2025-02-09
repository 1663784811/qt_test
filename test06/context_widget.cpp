#include "context_widget.h"
#include <QLabel>
#include <QVBoxLayout>



ContextWidget::ContextWidget(QWidget *parent)    : QWidget{parent}
{

    QVBoxLayout* verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0,0,0,0);

    QLabel* lab = new QLabel(this);
    lab->setText("ssssssssssssssss");
    lab->setFrameShape(QFrame::Box);
    verticalLayout->addWidget(lab);


}
