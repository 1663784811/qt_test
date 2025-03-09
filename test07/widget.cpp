#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    // ===================
    ui->cboShape->addItem("Point 点", static_cast<int>(_Point));
    ui->cboShape->addItem("Line 线", static_cast<int>(_Line));
    ui->cboShape->addItem("Rect 矩形", static_cast<int>(_Rect));
    ui->cboShape->addItem("RoundedRect 圆形的矩形", static_cast<int>(_RoundedRect));
    ui->cboShape->addItem("Ellipse 椭圆", static_cast<int>(_Ellipse));
    ui->cboShape->addItem("Polyline 多段线", static_cast<int>(_Polyline));
    ui->cboShape->addItem("Polygon 多边形", static_cast<int>(_Polygon));
    ui->cboShape->addItem("Arc 弧", static_cast<int>(_Arc));
    ui->cboShape->addItem("Pie", static_cast<int>(_Pie));
    ui->cboShape->addItem("Chord 和弦", static_cast<int>(_Chord));
    ui->cboShape->addItem("Path 路径", static_cast<int>(_Path));
    ui->cboShape->addItem("Text 文本", static_cast<int>(_Text));
    ui->cboShape->addItem("Pixmap 像素图", static_cast<int>(_Pixmap));
    // ===================

    // 宽度
    ui->sbPenWidth->setRange(1, 10);
    // 线性
    ui->cboPenStyle->addItem("Solid 实线", static_cast<int>(Qt::SolidLine));
    ui->cboPenStyle->addItem("DashLine 虚线", static_cast<int>(Qt::DashLine));
    ui->cboPenStyle->addItem("DotLine", static_cast<int>(Qt::DotLine));
    ui->cboPenStyle->addItem("DashDotLine", static_cast<int>(Qt::DashDotLine));
    ui->cboPenStyle->addItem("DashDotDotLine", static_cast<int>(Qt::DashDotDotLine));
    ui->cboPenStyle->addItem("NoPen", static_cast<int>(Qt::NoPen));

    ui->cboPenCap->addItem("FlatCap", static_cast<int>(Qt::FlatCap));
    ui->cboPenCap->addItem("SquareCap", static_cast<int>(Qt::SquareCap));
    ui->cboPenCap->addItem("RoundCap", static_cast<int>(Qt::RoundCap));

    ui->cboPenJonin->addItem("MiterJoin", static_cast<int>(Qt::MiterJoin));
    ui->cboPenJonin->addItem("BevelJoin", static_cast<int>(Qt::BevelJoin));
    ui->cboPenJonin->addItem("RoundJoin", static_cast<int>(Qt::RoundJoin));

    //
    ui->cboBrushStyle->addItem("NoBrush", static_cast<int>(Qt::NoBrush));
    ui->cboBrushStyle->addItem("SolidPattern", static_cast<int>(Qt::SolidPattern));
    ui->cboBrushStyle->addItem("Dense1Pattern", static_cast<int>(Qt::Dense1Pattern));
    ui->cboBrushStyle->addItem("Dense2Pattern", static_cast<int>(Qt::Dense2Pattern));
    ui->cboBrushStyle->addItem("Dense3Pattern", static_cast<int>(Qt::Dense3Pattern));
    ui->cboBrushStyle->addItem("Dense4Pattern", static_cast<int>(Qt::Dense4Pattern));
    ui->cboBrushStyle->addItem("Dense5Pattern", static_cast<int>(Qt::Dense5Pattern));
    ui->cboBrushStyle->addItem("Dense6Pattern", static_cast<int>(Qt::Dense6Pattern));
    ui->cboBrushStyle->addItem("Dense7Pattern", static_cast<int>(Qt::Dense7Pattern));
    ui->cboBrushStyle->addItem("HorPattern", static_cast<int>(Qt::HorPattern));
    ui->cboBrushStyle->addItem("VerPattern", static_cast<int>(Qt::VerPattern));
    ui->cboBrushStyle->addItem("CrossPattern", static_cast<int>(Qt::CrossPattern));
    ui->cboBrushStyle->addItem("BDiagPattern", static_cast<int>(Qt::BDiagPattern));
    ui->cboBrushStyle->addItem("FDiagPattern", static_cast<int>(Qt::FDiagPattern));
    ui->cboBrushStyle->addItem("DiagCrossPattern", static_cast<int>(Qt::DiagCrossPattern));
    ui->cboBrushStyle->addItem("LinearGradientPattern", static_cast<int>(Qt::LinearGradientPattern));
    ui->cboBrushStyle->addItem("RadialGradientPattern", static_cast<int>(Qt::RadialGradientPattern));
    ui->cboBrushStyle->addItem("ConicalGradientPattern", static_cast<int>(Qt::ConicalGradientPattern));
    ui->cboBrushStyle->addItem("TexturePattern", static_cast<int>(Qt::TexturePattern));


    connect(ui->cboShape, &QComboBox::activated, this, &Widget::shapeChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::shapeChanged()
{
    int index = ui->cboShape->currentIndex();
    Shape shape = (Shape)ui->cboShape->itemData(index).toInt();

    ui->paintWidget->setShape(shape);
}
